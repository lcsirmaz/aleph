/***************************************************************
$  This code is part of Modular javascript ALEPH-M v1.0)
$
$  (C) 2020-2025, L.Csirmaz
$
$  ALEPH-M is a free software, your can redistribute and/or
$  modify it under the terms of the GNU General Public License
$  as published by the Free Software Foundation, either version
$  3 of the License, or (at your option) any later version.
$
$  ALEPH-M is distributed in the hope that it will be useful,
$  but  WITHOUT ANY WARRANTY; without even the implied warranty
$  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
$  the GNU General Public License for more details.
$
$ *************************************************************/

/* Utility fucntions for js runtime environment.

JOBS
  job numbers go from 100 to 999 marking editors, viewers, and running
  ALEPH programs. Jobs can be viewed and, most importantly, killed.

LOCAL STORAGE
  character files can be stored at the local storage, thus retrieving
  whenever reloading the page. 

FILESYSTEM
  creating, listing, maintaining projects and the filesystem under
  projects. Projects and Files have permanent indices in array ob objects
  Project fields:
    name:  project name; null or '' if not in use
    idx:   index starting from zero
    sys:   1 for system entrues (compilers and library files)
    run:   jub number; only one running program per project
  File fields:
    name:  file name; no special characters
    idx:   index
    pr:    project object it belongs to
    buffer:ArrayBuffer containing the data, or null
    as,ar,ad attribute values, 0/1
    type:  'ale','ice','js','txt' (determined from the extension)
    busy:  if passed to the running worker

LAUNCHING
  ALEPH programs run in dedicated Web Workers. Local files are passed
  and retrieved when the program finishes. Async character input/output.
  
*/

"use strict";

/* ****************************************************************** */
/* JOBS
   JOB.next()  -- the next job number, or -1 if out of process numbers
   JOB.del(n)  -- delete
   JOB.get(n)  -- return the job, or null if wrong arg
   JOB.set(n,v)-- replace the job
   JOB.jobs()  -- [] array of current job numbers for listing
*/

var JOB=function(){
  let J={},n=0,last=999;
  function inc(){last++;if(last>=1000)last=100;}
  return {
    jobs:()=>Object.keys(J).map((x)=>parseInt(x)),
    del: (idx)=>{if(J[idx]){delete J[idx];n--;}},
    get: (idx)=>J[idx], // undefined if does not exists
    set: (idx,v)=>{if(v!==null && J[idx])J[idx]=v;},
    next:()=>{if(n>800)return -1;
              do{inc()}while(J[last]);
              J[last]={};return last;}
  }
}();

/* ****************************************************************** */
/* Local storage */

// LS.init()            initialize the filesystem from the local storage
// LS.store(fObj,msg=1) store the fObj; return 1 on error, print if msg=1
// LS.remove(fObj)      remove the fObj from local storage
// LS.list()            list of all stored files
// LS.retrieve(fObj)    if ro=1 then retrieve the content

var LS=function(){
  const WLS=window.localStorage;
  function tr(v){return v>191?v&191:v;}
  function txt2str(a,len){
    let res=""; for(let i=0;i<len;){
      let part="";if(i+256<len){
         for(let j=0;j<128;j++){
           part+=String.fromCharCode(32+tr(a[i++])*200+tr(a[i++]));
         }
      }else{ // last chunk
         while(i<len-1){
           part+=String.fromCharCode(32+tr(a[i++])*200+tr(a[i++]));
         }
         if(i<len){
           part+=String.fromCharCode(32+tr(a[i++])*200);
         }
      }
      res+=part;
    }
    return res;
  };
  function str2txt(s,len,u){
    let i=0,j=0,x=0;
    const v=(s)=>{if(x>0){x--;}
                 else if(s>127){s|=64;x=1+(s>=0xe0)+(s>=0xf0);}
                 u[i++]=s;}
    for(;i<len-1;j++){
      let a=s.charCodeAt(j)-32;v((a/200)|0);v(a%200);
    }
    if(i<len)v(((s.charCodeAt(j)-32)/200)|0);
  };
  function delFile(f){
     const fname='/'+f.pr.name+'/'+f.name;
     WLS.removeItem('attrib'+fname);
     WLS.removeItem('data'+fname);
  };
  function storeFile(f,msg=1){ // return 1 for error (no space left)
     if(!f.as) return 0;
     const fname='/'+f.pr.name+'/'+f.name;
     const len=f.buffer?.byteLength||0;
     const attr=String.fromCharCode(48+(f.ar?1:0)+(f.ad?2:0))+len;
     const data=len==0?'':txt2str(new Uint8Array(f.buffer),len);
     try{
        WLS.setItem('attrib'+fname,attr);
        WLS.setItem('data'+fname,data);
     }catch(error){
        f.as=0; // remove the store attribute
        base.removeFile(f);
        if(msg){aCle.print(2,'No storage space for '+fname);}
        return 1;
     }
     return 0;
  };
  function storeAttrib(f){ // store attrib only
    if(!f.as) return;
    const fname='/'+f.pr.name+'/'+f.name;
    const attr=String.fromCharCode(48+(f.ar?1:0)+(f.ad?2:0))+
            (f.buffer?.byteLength||0);
    try{WLS.setItem('attrib'+fname,attr);}
    catch(error){}
  }
  function readst(nm,y,f){
    const x=WLS.getItem('data/'+nm),len=parseInt(y.substring(1));
    if(len>0 && x){f.buffer=new ArrayBuffer(len);
         str2txt(x,len,new Uint8Array(f.buffer));}
  }
  function init(){
     for(const nm in WLS){
       const c=nm.match(/^attrib\/([^\?\*\{\}\"\s\/]+)\/([^\?\*\{\}\}\s]+)$/);
       if(c && c[2].at(0)!='/'&& c[2].at(-1)!='/'){ // project: c[1], file:c[2]
          const f=FS.ffind(FS.pfind(c[1]),c[2]);
          const y=WLS.getItem(nm),attr=y.charCodeAt(0)-48;
          f.as=1;if(attr&1)f.ar=1;if(attr&2)f.ad=1;
          readst(c[1]+'/'+c[2],y,f);
       }
     }
  };
  function retr(f){
    if(!f.as) return;
    const fname=f.pr.name+'/'+f.name;
    readst(fname,WLS.getItem('attrib/'+fname),f);
  }
  function content(){
    const res=[];
    for(const nm in WLS){
      const c=nm.match(/^attrib\/([^\?\*\{\}\"\s\/]+)\/([^\?\*\{\}\}\s]+)$/);
      if(c && c[2].at(0)!='/'&& c[2].at(-1)!='/'){
        res.push({file:'/'+c[1]+'/'+c[2],attr:WLS.getItem(nm)});
      }
    }
    return res.sort((x,y)=>{return (x.file<y.file?-1:x.file==y.file?0:+1);});
  }
  return {store:storeFile,storeAttr:storeAttrib,remove:delFile,
          retrieve:retr,list:content,LSinit:init};
}();

/* ****************************************************************** */
/* Filesystem, there are many projects
  PROJECT:  AlephProjects[]
     name: project name
     idx:  index
     sys:  1 if system, cannot be modified or listed
     run:  Worker running (job number)
  FILE:      AlephFiles[]
     name: "data/x.bin"  filename, not empty, slash in the middle only
     idx:  index
     pr:   parent project in FS.P
     buffer: ArrayBuffer containing the file data (fixed length), or null
     as,ar,ad:
           attribute values, 1-set; none, 0 or undef-not set
     busy: if buff is passed to a running Worker
     type: 'ale','ice','js','txt' (from extension)
     writing: editor which opened the file for writing
     changed during editing the buffer and the editor window differ
     savef callback function savef(fileobj) when saving in the editor

Aleph filesystem functions
  FS.cd={}     compiler data
  FS.cwp()     return the current project
  FS.cwp(name)  change current project, return null if not found
  FS.fbyidx(idx)             fObj with the given index
  FS.pmatch(pattern,sort=1)  return all matching project indices
  FS.fmatch(pattern)         return all file or project patterns
  FS.pfind(name,force=1)     return the named project or null (force=0)
  FS.ffind(pObj,name,force=1)return the named file or null (force=0)
  FS.qffind(name,force)      find possibly qualified file; create if force=1
  FS.parse(n,how,res)        return res=['pr','f'] or ['','f'] if correct,
                             force no pr if pr=1; otherwise null
  FS.rmfile(fObj)            remove; return 1 on error (cannot remove)
  FS.nver(n)                 create a new version of n for upload
    
*/

var FS=function (){
 const AlephProjects=[{name:'aleph',idx:0},
             {name:'usr',idx:1,sys:1}];
 const AlephFiles=function (){ let cnt=-1; 
     const url='/aleph/lib/',loc='/usr/local/aleph/',bs=AlephProjects[1];
     return ['acomp.js','aopt.js','alink.js','stdlib.ale','stdjs.ice',
        'base','formatprint','getint','getline','hash',
        'putasstring','putint','putline','putstring',
        'stdarg','stdin','stdout','waitfor'].map((n)=>{ cnt++;
          return n.endsWith('.js')?{name:'bin/'+n,idx:cnt,pr:bs,type:'js',ar:1,src:url+n}:
           n.endsWith('.ale')?{name:loc+n,idx:cnt,pr:bs,type:'ale',ar:1,src:url+n}:
           n.endsWith('.ice')?{name:loc+n,idx:cnt,pr:bs,type:'ice',ar:1,src:url+n}:
           (n='ice/'+n+'.ice',{name:loc+n,idx:cnt,pr:bs,type:'ice',ar:1,src:url+n});
     });}();
 let currentwp=AlephProjects[0]; // current working project
 const compilerData={
    comp:   AlephFiles[0],     // comp,opt,link programs; stdlib for comp,
    opt:    AlephFiles[1],     // stdice and -RE for link
    link:   AlephFiles[2],
    stdlib: [AlephFiles[3]],
    stdice: Array.from({length:14},(_,i)=>AlephFiles[i+4]),
    RE:     '--RE=https://lcsirmaz.github.io/aleph/lib/alephRE.js'
 };

 function cwp(n){
    if(n==null)return currentwp;
    let nf=1;
    AlephProjects.forEach((pr)=>{
      if(pr.name==n && !pr.sys){currentwp=pr;nf=0;}});
    return nf?null:currentwp;
 };
 function projectMatch(pattern,sort=1){ // return an array of project indices
    if(!pattern)pattern='*';
    const re=RegExp('^'+pattern // no slash,{},space in project names
       .replace(/[-/\\^$+.()|[\]{}]/g, '\\$&')
       .replace(/\?/g,'.')
       .replace(/\*/g,'.*')+'$');
    let res=[];
    AlephProjects.forEach((pr)=>{
      if(! pr.sys && pr.name && re.test(pr.name)){
           pr.search=1;if(sort)res.push({m:'/'+pr.name,p:0,i:pr});
      }else{pr.search=0;}
      });
    res.sort(function(a,b){return a.m<b.m?-1:a.m>b.m?1:0;});
    return res;
 };
 function fileMatch(pattern){ // pattern can start with /
    let addprj=0;
    if(pattern.at(0)=='/'){// start with a slash
      const i=pattern.indexOf('/',1);
      if(i<0)return projectMatch(pattern.substring(1));
      projectMatch(pattern.substring(1,i),0);
      pattern=pattern.substring(i+1);
      if(!pattern)pattern='*';
      addprj=1;
    }else{ // relative to currentwp
      AlephProjects.forEach((pr)=>{pr.search=0;});
      currentwp.search=1;
    }
    if(pattern.at(-1)=='/'){pattern += '*';}
    const re=RegExp('^'+pattern
      .replace(/[-/\\^$+.()|[\]{}]/g, '\\$&')
      .replace(/\?/g,'[^/]')
      .replace(/\*/g,'[^/]*')+'(?:$|/)');
    let res=[];
    AlephFiles.forEach((f)=>{
      if(f.name && f.pr.search){// project is fine
         const x=re.exec(f.name);
         if(x){res.push({m:addprj?'/'+f.pr.name+'/'+x[0]:x[0],p:2,i:f});}
      }
     });
    if(res.length==0) return res;
    // sort them
    res.sort(function(a,b){return a.m<b.m? -1 : a.m>b.m?+1:0;});
    return res;
 };
 function projectFind(n,force=1){// find the project with name n;
    let nn=null;
    AlephProjects.forEach((pr)=>{if(pr.name==n||(!pr.name && !nn))nn=pr;});
    if(!force &&(!nn || !nn.name)) return null;
    if(nn){if(nn.name!=n){nn.name=n;} return nn;}
    const i=AlephProjects.length;
    AlephProjects.push({name:n,idx:i});
    return AlephProjects[i];
 };
 function fileFind(proj,n,force=1){ // find file with the given name or create
    if(!proj)return null;
    let file=null;
    AlephFiles.forEach((f)=>{if((f.name==n&&f.pr===proj)||(!f.name&&!file)) file=f;});
    if(!force && (!file||!file.name)) return null; // not found
    if(!file){// create new
      const i=AlephFiles.length;AlephFiles.push({name:n,pr:proj,idx:i});
      file=AlephFiles[i];
    } else if(!file.name){// fill in a deleted slot
      Object.assign(file,{name:n,pr:proj,changed:0,busy:0,buffer:null,ro:0});
    } else {return file; }// found
    file.type=n.endsWith('.ale')?'ale':
              n.endsWith('.ice')?'ice':
              n.endsWith('.js') ?'js' : 'txt';
    file.savef=LS.store;
    return file;
 };
 function qFind(n,force){ // find a qualified file; if force==1 then create
                          // check for filename correctness; project is
                          // not created
    let pObj=currentwp;
    if(n.at(0)=='/'){
       const i=n.indexOf('/',1);
       if(i<0)return null; // not found
       pObj=projectFind(n.substring(1,i),0);
       if(!pObj)return null; // not found
       n=n.substring(i+1);
    }
    if(!n)return null;
    let fObj=fileFind(pObj,n,0); if(fObj)return fObj;
    if(force==0 || parseName(0,n)) return null; // cannot create
    return fileFind(pObj,n,1);
 }
 function copyFile(from,to){// two file objects; to is created right now
    // copy from.buffer to to.buffer
    if(from.buffer){to.buffer=from.buffer.slice(0);}
 }
    // how=0: file, 1:project+file, 2: project only
    // return: 0: OK, res[0]=pname, res[1]=fname (for how=0 or how=1)
    //         1: how=1 and project only
    //         2: project name error
    //         3: file name error
 function parseName(how,name,res){ // how=0: file, how=1: project+file, how=2:project
    let prj='';
    if(how==2 && name.at(0)!='/'){name='/'+name;}
    if(how>=1 && name.at(0)=='/'){
      const i=name.indexOf('/',1);
      if(i<0){if(how==1)return 1; // project only
        prj=name.substring(1);name='';
      }else {
        prj=name.substring(1,i);name=name.substring(i+1);
      }
      if(!prj||prj.length>40|| /^[-+]|[\{\}\?\*\"]/.test(prj)) return 2;
      if(how==2){
         if(name)return 2; // contains slash
         if(res){res[0]=prj;}
         return 0;
      }
    }else{// relative to cwpr
      prj=currentwp.name;
    }
    if(!name || /^[\/+-]|^$|\/$|[\{\}\?\*\"]/.test(name)) return 3;
    if(res){res[0]=prj;res[1]=name;}
    return 0;
 };
 function delFile(fObj){// remove the file
    if(fObj.busy||fObj.writing) return 1;
    if(fObj.as){LS.remove(fObj);}
    Object.assign(fObj,{name:null,buffer:null,type:null,as:0,ar:0,ad:0});
    return 0;
 }
 function delProject(pObj){// remove the object
    pObj.name=null;
 }
 function isnotfile(n){// 0 if file n exsist, 1 otherwise
    let nfound=1;
    AlephFiles.forEach((f)=>{if(f.name==n && f.pr==currentwp)nfound=0;});
    return nfound;
 }
 function newVersion(n){// n is correct name; create new version
    if(isnotfile(n)) return n;
    let [,base,ext]=n.match(/^(.+?)(\.[a-zA-Z0-9]+)?$/);// ext can be null
    if(!ext)ext=''; base+='-v';
    for(let ver=1;;ver++){
      const nn=base+ver+ext;if(isnotfile(nn)) return nn;
    }
    return n;// this never happens
 }
 return {
          fbyidx: (idx)=>AlephFiles[idx], // file by index
          cwp:    cwp,                    // set or get current project
          pmatch: projectMatch,
          fmatch: fileMatch,
          pfind:  projectFind,
          ffind:  fileFind,
          qffind: qFind,
          parse:  parseName,
          cpfile: copyFile,
          rmfile: delFile,
          rmproj: delProject,
          nver:   newVersion,		  // new filename version
          cd:     compilerData		  // programs and files to compile
         };
}();


if(document.readState==='loading'){// loading is in progress
     document.addEventListener('DOMContentLoaded',LS.LSinit);}
else{LS.LSinit();}

/* ****************************************************************** */
/* launching a js program as a Web Worker.
  js program (local or system, URL)
  files: {idx; name; RO; <URL> or <ArrayBuffer>}
              RO cannot be deleted or opened for writing; edited
              files are passed as RO (views are detached!) and
              save/reload are disabled.
  arguments:  array of strings

  messages from the Worker:
   'ready' first message, start setting up files
   'write',file:<channel>,data:<str> asyn character 
   'read', file:<channel>
   'stack'   data:<str>,count:nn    StackFrame
   'trace',  data:<str>             TraceRule
   'profile' data:<str>,count:nn    Profile
   'exit',   data:0/1/2/3,msg:<msg>
   'file' filename:FFF,idx:idx,rm:'yes'
   'file' filename:FFF,idx:idx,data:ArrayBuffer
   'terminated' last message

  messages to the Worker:
   'init',job:nnn // first message, wait for 'ready' reply
   'file', filename:"...",url:,ro:1,data:<> [data] setup filesystem
   'run'          // start running the program
   'stdin',file:<channel>,eof:0/1,data:"reply"
   'stdarg',data:<stringarray>
   'trace'        // return stack dump if conpiled with -g
   'kill'         // kill immediately

COMPILING:
    run several programs; use the callback function to chain them
    args: (opts) <ale-1>, <ale-2> ... <ale-k>
    opts: -g, -W, ...
    run for each ale file:
       acomp.js, {<stdarg>, <ale1>...<alek>} (opts) <ale_j>
    this produces an .ice file. Stop when there is an error
       aopt.js {} <ale_j.ice>
    When done,
       alink.js { <stdice> <*.ice> } (opts) <*.ice>

*/

// runProg(pObj,rObj,F[],args[],fn)
//  pObj  project under which the program runs
//  rObj  the program to be run (must have type='js')
//  F     array of file objects to be passed to the worker
//           either sys, or must belong to pObj
//  args  stdarg array of strings
//  fn    callbasck function, called as fn(v,m)
//           v: -1: system error, program not launched, m: message
//               0: normal exit,    m: 0 (number)
//               1: exit command,   m: exit value (number)
//               2: runtime error,  m: message
//               3: program killed, m: 'kill'
//

var LAUNCH=function(){

function runProg(pObj,rObj,F,args,fn){
   function M(m){fn(-1,m);}
   if(pObj.run){M('project is busy'); return;}
   if(rObj.type!='js'){M('wrong program type');return;}
   const jobno=JOB.next();
   if(jobno<0){M('no more process'); return; }
   let w;
   if(rObj.buffer){// 
     const href=URL.createObjectURL(new Blob([rObj.buffer],{type:'text/javascript;charset=utf-8'}));
     w=new Worker(href);
     URL.revokeObjectURL(href);
   } else { // use rObj.src
     w=new Worker(rObj.src);
   }
   // create process description
   JOB.set(jobno,{
      idx:   jobno,    // jobno
      pr:    pObj,     // project
      type:  'run',    // running
      stat:  'i',      // status, i:init, r:running, z:zombie, k: killed, 
      worker:w,        // the worker object
      fidx:  F,        // array of fObj to be passed
      cmd:   rObj.name+' { '+F.map((fObj)=>fObj.name).join(' ')+' } '+args.join(' '), // cmd
      call:  fn        // callback function
      });
   pObj.run=jobno;
   w.onmessage=fromWorker;
   w.onerror=(e)=>{// an uncaught error in worker
      const J=JOB.get(jobno);
      if(J?.stat=='i'){ // haven't started yet, perhaps syntax error
        JOB.del(jobno);
        delete pObj.run;
        M('cannot load program: '+e.message);
      } else if(J && J.stat!='z') { // let's try to recover stored files
        J.stat='z';
        M('runtime error: '+e.message);
        w.postMessage({cmd:'kill'});
        delete pObj.run; // NOT SURE ??? detach it from the project
      }
   };
   w.postMessage({cmd:'init',job:jobno});   // send the first message
   w.postMessage({cmd:'stdarg',data:args}); // set up stdarg (can be empty)
}

function fromWorker(e){ // message from a worker
  const ed=e.data,J=JOB.get(ed?.job),cmd=ed?.cmd;
  if(!cmd || !J){ console.log('unknown worker message-1',ed); return;}
  const w=J.worker;
  if(cmd=='ready'){ // first message received; send files and start running
    if(J.stat!='i'){ console.log('wrong worker message',ed); return;}
    J.fidx.forEach((fObj)=>{
       if(fObj.src){// to be loaded by the worker
         w.postMessage({cmd:'file',idx:fObj.idx,filename:fObj.name,url:fObj.src});
       }else if(!fObj.busy){// fileBuffer, send only once
         let ro=fObj.ar?1:0;
         if(!fObj.buffer){fObj.buffer=new ArrayBuffer(0);}
         if(fObj.writing){ro=1;AE.setSave(fObj,false);}
         w.postMessage({cmd:'file',idx:fObj.idx,filename:fObj.name,ro:ro,data:fObj.buffer},[fObj.buffer]);
         fObj.busy=1;
       }
    });
    J.stat='r';
    w.postMessage({cmd:'run'});
  } else if(cmd=='read'){ // async reading
      const fch=ed.file;
      // replay: {cmd:'stdin',file:fch,data:'',eof:1}
      // set the bacground color to red; don't copy the result
      aCle.read('>> '+J.pr.name,(str,tp)=>{
           if(tp==2){// ^C, kill the program
              J.stat='k';
              J.worker.postMessage({cmd:'kill'}); return; }
           J.worker.postMessage({cmd:'stdin',file:fch,data:str,eof:tp});
      },{bg:'#fed',s:2})
  } else if(cmd=='write'){// async writing
      // ed.file: 'stdout' or 'stderr'; ed.data: string to be printed
      aCle.print(ed.file=='stderr'?2:1,ed.data);
  } else if(cmd=='exit'){ // data: 0-3, msg:nnnn or 'kill'
      // 0-normal, 1-exit, 2-error, 3-kill
      if(J.stat=='r') J.stat='t'; // terminated
      switch(ed.data){
    case 2: // error, print msg
        J.xt=2;J.xm=ed.msg;break;
    case 1: // exit
        if(ed.msg){J.xt=1;J.xm=ed.msg;break;}
    case 0: // normal exit
        J.xt=0;J.xm=0;break;
    default: // kill
        J.xt=3;J.xm=ed.msg;
      }
  } else if(cmd=='file'){ // returning a file after the 'exit' message
      // filename,idx,rm|data
      if(ed.idx<0){ // newly created
        let n=ed.filename.replace(/^[-+\/]|[\?\*\{\}]|\/$/g,'#'); // sanitize:
        const fObj=FS.ffind(J.pr,n);
        delete fObj.busy; // even if it was sent earlier
        LS.store(fObj);
        fObj.buffer=ed.data
      } else if(ed.rm=='yes') { //deleted, ed.idx, filename is globbed
        const fObj=FS.fbyidx(ed.idx);
        if(fObj?.busy){fObj.busy=0;FS.rmfile(fObj);}
        else{console.log('ERR: file rm',ed,fObj);}
      } else { // returned, re-enable saving, remove busy flag
        const fObj=FS.ffind(J.pr,ed.filename);
        if(fObj?.idx!=ed.idx){console.log('ERR: wrong file idx',ed,fObj);}
        else{ fObj.buffer=ed.data;
              fObj.busy=0;
              if(ed.changed)LS.store(fObj);
              else LS.storeAttr(fObj);
              if(fObj.writing){AE.setSave(fObj,true);}
        }
      }
  } else if(cmd=='trace'){ // data: "rule+v1+...+vk"
      // this could be extemely verbose ...
      aCle.print(2,'Calling '+ed.data);
  } else if(cmd=='stack'){ // count: i, data: "rule", starting with cnt=1
                           // cnt==0, data: 'Rule stack" even if empty
      aCle.print(2,(ed.count==0?'':('#'+ed.count)).padEnd(5)+ed.data);
  } else if(cmd=='profile'){// data: 'rule 123'
      aCle.print(2,(ed.count<0?'':(''+ed.count)).padStart(11)+' '+ed.data);
  } else if(cmd=='terminated'){
      // delete the job; clear the project; call the fn() function
      delete J.pr.run; // clear the project;
      JOB.del(J.idx);
      J.call(J.xt,J.xm);
  } else {
    console.log('unknown worker message-2',ed);
  }
}

// pObj: the project, copt[] compile arguments, lopt[] link args
function comperr(v,msg){
   if(v==0) return 0;
   if(v!=1){ aCle.print(2,msg);}
   return 1;
}
function compdone(v,msg){
   if(v==0){aCle.print(1,'compilation done');}
   else if(v!=1){aCle.print(2,msg);}
}
function compileProg(pObj,copt,lopt,F){ // compile all .ale files and link them
   // F[] are all .ale; compile them to .ice, and then link them
   let Fidx=-1;let ice=[];const cmpFiles=F.concat(FS.cd.stdlib);
   if(FS.cd.RE){lopt.push(FS.cd.RE);} // --RE= option, if not the default
//   const jsname=F[0].name.replace(/ale$/,'js');
   function fnc(v,msg){// callback function for compiling;
     // we have compiled Fidx; v is the return for optimization
     if(comperr(v,msg))return; // there was an error
     if(Fidx+1>=F.length){ // linking, --RE=<...js> runtime library
        // collect files to be included
        // these are the ice files plus the library files
        runProg(pObj,FS.cd.link,ice.concat(FS.cd.stdice),lopt,compdone);
     }else{
       const fObj=F[++Fidx]; // next file to be compiled
       const icename=fObj.name.replace(/ale$/,'ice');
       ice.push(FS.ffind(pObj,icename));lopt.push(icename);
       runProg(pObj,FS.cd.comp,cmpFiles,['-o',icename,...copt,fObj.name],fno);
     }
   }
   function fno(v,msg){// callback, after compiling Fidx
     if(comperr(v,msg))return; // some error
     const iceObj=ice[Fidx];
     runProg(pObj,FS.cd.opt,[iceObj],[iceObj.name],fnc);
   }
   fnc(0);// start compiling the first .ale program
}
return {run:runProg,compile:compileProg};
}();

/* ****************************************************************** */


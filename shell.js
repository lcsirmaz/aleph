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

/* 
editor:
   AE.createEditor(fObj,fn,RO), returns gw for closeEditor
   AE.setSave(fObj,how)  disable Save and Reset buttons (editing)
   AE.closeEditor(gw),   also calls fn() specified when creating
   AE.setTabwidth(n)
   AE.setFont(s)

jobs:
   JOB.jobs();  array of living job numbers 
   JOB.del(n)   delete 
   JOB.get(n)   return the associated job
   JOB.set(n)   replace
   JOB.next()   return the next empty JOB slot, or -1 if no more

local storage:
   LS.store(fObj,msg) store the buffer, print message if no more space
   LS.remove(fObj)    remove the storage
   LS.populate()      initial routine to populate the filesystem

filesystem:
   FS.cd              compiler data (program and library files)
   FS.cwp()           return or set the current project
   FS.byidx(idx)      fObj with given idx
   FS.pmatch()        [] or matching projects
   FS.fmath()         [] of matching fiiles
   FS.pfind(name,f)   return the project, create if not found
   FS.ffind(pObj,n,f) return file within project, create if not found
   FS.parse(n,how,res)parse string for correct project/file name
   FS.rmfile(fObj)    remove the file, return 1 on error

console:
   aCcle.print(ch,text,nl=1) print ch=1,2; nl: add nl at the end
   aCle.read(prompt,f(),opt) read, call f() when done
   aCle.font(size)    set font size

*/

"use strict";
var SHELL = function(docm){
// print to the console, channel one
function P(str,nl=1){aCle.print(1,str,nl);}
// general help
function showHelp(f){ // <cmd> -h
   // figure out the command
   let c='?? ';
   Object.keys(COMMANDS).forEach((cmd)=>{if(COMMANDS[cmd]==f)c=cmd+' ';});
   if(f.h.length>1){P(f.h[0],0);P(' Usage: '+c+f.s,0);P(f.h[1]);}
   else {P(f.h[0]);}
}
function cmdhelp(tp,shh){ // check argument numbers
   if(shh)return 0;
   tp=COMMANDS[tp].alias??tp;
   P('usage: '+tp+' '+COMMANDS[tp].s);
   return 1;
}
// commands; help describe projects and files
function helpcmd(args){// help
   if(args.length==0){
      let cmdlist='  ',cnt=0;
      Object.keys(COMMANDS).forEach((cmd)=>{
        if(cnt==6){cmdlist+='\n  ';cnt=0;}
        cmdlist+=' '+cmd.padEnd(10);cnt++;
      });
      let tlist='  ';cnt=0;
      Object.keys(TOPICS).forEach((tp)=>{
        if(cnt==6){tlist+='\n  ';cnt=0;}
        tlist+=' -'+tp.padEnd(9);cnt++;
      });
      P(
'ALEPH PlayGround is an online tool for creating, editing, compiling, and\n'+
'running ALEPH programs. For a quick start enter\n'+
'  help -start\n'+
'at the bottom line of this workspace.\n'+
'To get help on a command use \'help <command>\' or \'<command> -h\'. Use\n'+
'\'help -<topic>\' (with a dash) to get help on a topic. Accepted commands:\n'+
cmdlist+'\n'+
'Topics (start with a dash):\n'+tlist);
      return;} 
   if(cmdhelp('help',(args.length==1||(args.length==2 && args[0]=='-')))){
     return; }
   let f=COMMANDS[args[0]];if(f?.alias){f=COMMANDS[f.alias];}
   if(f){showHelp(f); return;}
   if(args[0].at(0)=='-')f=TOPICS[args[0].slice(1)||args[1]];
   if(!f){P('unknown command or topic');return;}
   P(f);
}
const TOPICS = {
  start:
'Commands for the impatient to start with:\n'+
'  load a1           load the sample ALEPH program \'a1.ale\' (Hello World!)\n'+
'  edit a1.ale       open \'a1.ale\' in an editing window\n'+
'  compile a1.ale    compile it\n'+
'  run a1            and run it (assuming compiled without errors)\n\n'+
'Some basic commands:\n'+
' mkpr, chpr  create a new project, change to the named project\n'+
' load a1, load a2, ... load one of the sample ALEPH programs\n'+
' edit, view  open a character file for editing and viewing\n'+
' stdlib      show the standard ALEPH library\n'+
' dir, ls     list files\n'+
' cp, rm      copy, remove (delete) files\n'+
' compile     compile and link an ALEPH program and modules\n'+
' run         run a compiled ALEPH program',

  cmdline:
'Commands are typed at the bottom line of the workspace. Above this line is\n'+
'the actual project name, then the console window where entered commands and\n'+
'messages sent to the \'stdout\' channel appear. The window at the top is reserved\n'+
'for (typically error) messages and for the \'stderr\' channel. The \'up\' and\n'+
'\'down\' arrows navigate among previously entered commands. Ctrl+C clears this\n'+
'line, while Enter and Ctrl+D executes it. To list all accepted commands type\n'+
'\'help\' without arguments.\n'+
'The command line is also  used as the console input by the running ALEPH programs.\n'+
'This usage is indicated by a different background color; the project name is\n'+
'changed to that of the running program. Hitting ctrl+C kills the running program;\n'+
'finishing the line with ctrl+D instead of Enter closes the channel for further\n'+
'use for this program.\n',

  project: 
'The ALEPH PlayGround is organized around projects. Each project contains all\n'+
'files it works with, and can run one program at a time, which can use files\n'+
'from the project exclusively.\n'+
'Projects are created by \'mkpr\', deleted by \'rmpr\', and changed to by \'chpr\'.\n'+
'The current project name is shown above the command line. The default project\n'+
'is \'aleph\', this project cannot be deleted. A project name cannot contain\n'+
'space nor ?*{}/\'", and cannot start with - or +.',

  file:
'Each PlayGround file belongs to a unique project. Files in the current project\n'+
'can be referred to as \'<filename>\', otherwise use \'/<project>/<filename>\'.\n'+
'A filename cannot contain neither space nor ?*{}\'\", cannot start with\n'+
'+-/ and cannot end with /. To list files use the command \'ls\' or \'dir\'.\n'+
'The type of a file is determined by its extension. The following extensions\n'+
'are recognized; they also indicate that it is a character file:\n'+
'  .ale -- ALEPH program source\n'+
'  .ice -- intermediate ALICE code\n'+
'  .js  -- compiled javascript ALEPH program\n'+
'Files can be uploaded to, downloaded from the PlayGround, manipulated by the\n'+
'running ALEPH programs, but only CHARACTER files can be edited, compiled, run,\n'+
'and saved in the Local Storage. The lifetime of PlayGround files is the\n'+
'current session. However, files saved in Local Storage are restored when\n'+
'starting a new session.\n'+
'Files have attributes which can be manipulated by \'attrib\'. Character files\n'+
'can be edited or created by \'edit\', listed by \'view\'; .ale files can be\n'+
'compiled by \'compile\', and, after compilation, .js files can be run by \'run\'.',

  attrib:
'File attributes are s,r,d for save, readonly and data. They are off when\n'+
'the file is created, and can be manipulated by the \'attrib\' command.\n'+
'To see file attributes use \'ls -l <pattern>\'.\n'+
' +s  save the file at the Local Storage. Saved files are automatically\n'+
'     recovered when the PlayGround is opened or reloaded. Can be used for\n'+
'     character files only. The Local Storage is part of the browser\'s\n'+
'     local cache, and is not saved in incognito mode.\n'+
' +r  the file is passed to a running ALEPH program as \'read only\', thus\n'+
'     the program cannot modify or delete this file. These files, however,\n'+
'     can be edited and deleted using command line tools.\n'+
' +d  the file is automatically made available to the running ALEPH program\n'+
'     in this project. The program, however, can modify or delete this file.',

  pattern:
'Many commands require a pattern as an argument. In a pattern ? matches\n'+
'any character different from the slash (/), and * matches a sequence of\n'+
'such characters, including the empty sequence.\n'+
'Patterns starting with / search all projects; others search files in the\n'+
'current project only. Thus \'ls /*\' lists the name of all projects (no\n'+
'files), while \'ls *\' lists all file names in the current project which have\n'+
'no slash character.',

  edit:
'The command \'edit <file>\' opens the file in a new editor window, creating\n'+
'the file if not found. Use it for character files only, binary files are\n'+
'not handled. The same file can be opened for editing only once, but it can\n'+
'have many view instances. File changes in the background are not tracked.\n'+
'Due to the used technology, selecting and highlighting text in the editing\n'+
'window is limited to a single line.',

  compile:
'To compile the main ALEPH program together with all modules use the command\n'+
'  compile [<flags>] <source files>\n'+
'Source files can be specified using patterns. Compilation is done in many\n'+
'stages. First, all .ale files are compiled into ALICE codes. Second, these\n'+
'intermediate codes are optimized. Finally, the .ice files are linked to the\n'+
'final javascript file. The process stops at the first error. Flags after the\n'+
'\'compile\' command start with a dash (-). Those before \'-X\' are passed to\n'+
'the compiler; and those after \'-X\' are passed to the linker.',

  run:
'Compiled ALEPH programs are executed by dedicated Web Workers. A project can\n'+
'run one program at a time, but different projects can run several programs\n'+
'simultaneously. Running programs have job numbers, living jobs can be listed\n'+
'by the command \'jobs\'. Project files visible to the running program are\n'+
'moved to the Worker, and are retrieved when the Worker terminates by itself.\n'+
'If the Worker job is killed by a \'kill\' command, then those files might be\n'+
'lost and should be recreated. In such cases files in the Local Storage are\n'+
'automatically recovered, others are emptied.',

  jobs:
'Editor and viewer windows as well as running programs have dedicated job\n'+
'entries. Jobs can be listed by \'jobs\'. Jobs can be killed by \'kill\';\n'+
'killing an editor or viewer closes the window immediately discarding\n'+
'any unsaved changes. When killing a running program a "stop" message is sent\n'+
'first to the controlling Worker. This takes effect only when the program\n'+
'either waits for console input or sleeps. A second \'kill\' terminates\n'+
'the Worker itself, but in this case files held by the Worker are lost.\n'+
'Among them those in the Local Storage are automatically recovered, but\n'+
'others are permanently deleted.',

  about:
'ALEPH PlayGround is a command line based runtime environment for editing,\n'+
'compiling and running ALEPH program code. The PlayGround runs locally in the\n'+
'browser without sending data over the internet. The PlayGround and the ALEPH\n'+
'compiler are free software; the source is available at\n'+
'    https://github.com/lcsirmaz/aleph/\n'+
'and is distributed under the GNU General Public License version 3 (or any\n'+
'later version at your option) in the hope that it will be useful, but\n'+
'WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY\n'+
'or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for\n'+
'more details.',
};

/* commands */
// PROJECTS
function chpr(args){ // change project
  let n=args[0];
  if(cmdhelp('chpr',args.length==1)) return;
  if(!FS.cwp(n)){P('project not found');}
}
function mkpr(args){//make a new project and change to it
  let n=args[0],res=[];
  if(cmdhelp('mkpr',args.length==1)) return;
  if(FS.parse(2,n,res)){ P('wrong project name');return;}
  // res[0] is a correct project name
  if(FS.pfind(res[0],0)){ P('project exists');return;}
  FS.cwp(FS.pfind(res[0]).name);
}
function pwpr(args){// print working project
  if(cmdhelp('pwpr',args.length==0))return;
  P(FS.cwp().name);
}
function getattr(o,t){// obj, t=0: project, t=2: file
   if(t==0){return (o.run?'px':'p-')+'---       ';} // project
   return '-'+(o.busy?'x':o.changed?'E':o.writing?'e':'-')+ // busy or just editing
              (o.as?'s':'-')+  // save
              (o.ar?'r':'-')+  // read only
              (o.ad?'d':'-')+  // data
              (''+(o.buffer?o.buffer.byteLength:0)).padStart(6)+' ';
}
function listcmd(args){//ls [-l] <pattern>
   if(cmdhelp('ls',args.length<=2))return;
   let n=args[0],attr=0;
   if(n=='-l'){attr=1;n=args[1];}
   if(!n){n='*';}
   const res=FS.fmatch(n);
   if(res.length==0){P('no file or project found');return;}
   // res is ordered; {m:nnn,p:0/2,i:Obj}
   // the same hit may occur several times
   for(let i=0;i<res.length;i++){
      const x=res[i];
      if(i==0||x.m!=res[i-1].m){
        if(attr){P((x.m.at(-1)=='/'?'d----       ':getattr(x.i,x.p)),0);}
        P(x.m);
      }
   }
}
function delcmd(args){// rm [-r] <file>
  let rec=0;
  if(args[0]=='-r'){rec=1;args.shift();}
  if(cmdhelp('rm',args.length==1))return;
  const res=FS.fmatch(args[0]);
  if(res.length==0 || res[0].p==0){P('no file found');return;}
  if(res.length>1 && rec==0){P('to delete more files use the -r flag');return;}
  res.forEach((r)=>{
    if(FS.rmfile(r.i)){P('file '+r.i.name+' cannot be deleted');}
  });
}
function rmproject(args){//remove project
   let rec=0;if(args[0]=='-f'){rec=1;args.shift();}
   if(cmdhelp('rmpr',args.length==1))return;
   const pObj=FS.pfind(args[0]);
   if(pObj==FS.cwp()|| pObj.run){P('project is busy, cannot be deleted');return;}
   if(pObj.name=='aleph'){P('project "aleph" cannot be deleted');return;}
   let res=FS.fmatch('/'+pObj.name+'/');
   if(rec==0 && res.length>0){P('project is not empty');return;}
   let nempty=0;
   res.forEach((x)=>{if(FS.rmfile(x.i))nempty=1;});
   if(nempty){P('project is not empty');return;}
   FS.rmproj(pObj);
}
function copycmd(args){// cp <from> <to>
   if(cmdhelp('cp',args.length==2))return;
   // copy args[0] to args[1]; the latter should not exist
   const from=FS.qffind(args[0],0);
   if(!from){P('source file not found');return;}
   if(from.busy){P('source is busy, cannot copy');return;}
   if(FS.qffind(args[1],0)){P('target file exists');return;}
   const to=FS.qffind(args[1],1); // create a new one
   if(!to){P('wrong target file name');return;}
   FS.cpfile(from,to);
}
function setAttrib(fObj,AA){// AA.s,AA.r,AA.d
   if(AA.r<0){fObj.ar=0;}if(AA.r>0){fObj.ar=1;}
   if(AA.d<0){fObj.ad=0;}if(AA.d>0){fObj.ad=1;}
   // now set the store flag
   if(AA.s!=0 && fObj.busy){P('file '+fObj.name+' is busy, try later');}
   else if(AA.s<0 && fObj.as){fObj.as=0;LS.remove(fObj);}
   else if(AA.s>0 && !fObj.as){fObj.as=1;LS.store(fObj);}
}
function attribcmd(args){// set attribs
   // attrib +<attr> -<attr> <pattern>
   const AA={s:0,r:0,d:0};let ok=1,y=0;
   const setAA=(a,v)=>{for(let i=1;i<a.length;i++){
       if(AA[a.at(i)]!=undefined){AA[a.at(i)]=v;y=1;}
       else if(ok){ok=0;P('unknown attribute '+a.at(i));break;}}
   };
   while(args.length>0){
     if(args[0].at(0)=='-'){setAA(args.shift(),-1);}
     else if(args[0].at(0)=='+'){setAA(args.shift(),+1);}
     else break;
   }
   if(ok==0 || cmdhelp('attrib',args.length==1))return;
   const res=FS.fmatch(args[0]);
   if(res.length==0 || res[0].p!=2){P('no file found');return;}
   res.forEach((r)=>{setAttrib(r.i,AA);});
}

/* ======================================================== */

function getjobno(){ // local for edit, view, and run commands
   const jn=JOB.next();if(jn<0){P('no more jobs');}
   return jn;
}
function editcmd(args){// edit <file>
   if(cmdhelp('edit',args.length==1))return;
   const fObj=FS.qffind(args[0],1);
   if(!fObj){ P('wrong file name');return;}
   if(fObj.busy){P('file busy, cannot edit');return;}
   const jobno=getjobno();if(jobno<0)return;
   JOB.set(jobno,{
     idx:    jobno,
     pr:     fObj.pr,  // project
     type:   (fObj.writing?'view':'edit'),
     cmd:    'edit '+args[0],
     gw:     AE.createEditor(fObj,jobno)
   });
}
function viewcmd(args){// view file
   if(cmdhelp('view',args.length==1))return;
   const fObj=FS.qffind(args[0],0);
   if(!fObj){P('file not found');return;}
   if(fObj.busy){P('file is busy, cannot view');return;}
   const jobno=getjobno();if(jobno<0)return;
   JOB.set(jobno,{
      idx:   jobno,
      pr:    fObj.pr,
      type:  'view',
      cmd:   'view '+args[0],
      gw:    AE.createEditor(fObj,jobno,1)
   });   
}
function startstdview(fObj){
   if(!fObj.buffer){P('error loading stdlib.ale');return;}
   const jobno=getjobno();if(jobno<0)return;
   JOB.set(jobno,{
     idx:  jobno,
     pr:   FS.cwp(),
     type: 'view',
     cmd:  'stdlib',
     gw:   AE.createEditor(fObj,jobno,1)
   });
}
function viewstdlib(args){// stdlib
   if(cmdhelp('stdlib',args.length==0))return;
   const fObj=FS.cd.vw; // the data
   if(fObj.buffer){startstdview(fObj);return;}
   const xhr=new XMLHttpRequest();
   xhr.open('get',fObj.src,true);
   xhr.responseType='arraybuffer';
   xhr.addEventListener('loadend',()=>{
     if(xhr.status==200){fObj.buffer=xhr.response;}
     startstdview(fObj);
   },false);
   xhr.send();
}
// load a sample ALEPH program
// args[0]: a1 .. a19, load one or more files as a<n>.ale, a<n>m<j>.ale
function loadFile(n,url){
   if(FS.ffind(FS.cwp(),n,0)){P('file '+n+' exists, not overwritten');return;}
   const fObj=FS.ffind(FS.cwp(),n);
   const xhr=new XMLHttpRequest();
   xhr.open('get',url,true); // async reading
   xhr.responseType='arraybuffer';
   xhr.addEventListener('loadend',()=>{
     if(xhr.status!=200){P('error loading '+n);FS.rmfile(fObj);}
     else{fObj.buffer=xhr.response;}
   },false);
   xhr.send();
}
function sample(args){
  const modules={a18:2,a19:3,a20:2},maxsample=20;
  if(cmdhelp('load',args.length==1 && /^a\d\d?$/.test(args[0])))return;
  const n=parseInt(args[0].slice(1));
  if(n>maxsample){cmdhelp('load',false);return;}
  loadFile('a'+n+'.ale','sample/a'+n+'.ale');
  const jj=modules['a'+n]??0;
  for(let j=1;j<=jj;j++){
    loadFile('a'+n+'m'+j+'.ale','sample/a'+n+'m'+j+'.ale');
  }
}

// for upload add the element
// <input type="file" accept=".ale,.ice,.txt,.js" style="display:none">
function mkuplink(callf){
  const l=docm.createElement('input');
  l.setAttribute('type','file');
  l.setAttribute('accept','.ale,.ice,.txt,.js');
  l.setAttribute('style','display:none');
  l.multiple=true;
  l.cB=callf;
  l.addEventListener('change',(e)=>{
    const l=e.currentTarget;
    if(l.cB && l.files.length>0){
        for(let i=0;i<l.files.length;i++){
           if(l.files[i]){l.cB(l.files[i]);}}
        l.cB=null;}
    });
  return l;
}
function upcmd(args){
   if(cmdhelp('upload',args.length==0))return;
   function loaded(e,n){// now n is the new filename
      const fr=e.target;
      if(fr.result){FS.ffind(FS.cwp(),FS.nver(n)).buffer=fr.result;}
   }
   mkuplink((chup)=>{
     const n=(chup.name||'#').slice(0,60).replace(
                                /^[-+\/]|[\?\*\{\}]|\/$/g,'#');
     const fr=new FileReader();fr.addEventListener('loadend',(e)=>loaded(e,n));
     fr.readAsArrayBuffer(chup);
   }).click();
}
const downlink=docm.createElement('a');
function downcmd(args){
   if(cmdhelp('download',args.length==1))return;
   const fObj=FS.qffind(args[0],0);
   if(!fObj){P('file not found');return;}
   if(fObj.busy || !fObj.buffer?.byteLength){P('file is empty or busy');return;}
   downlink.href=URL.createObjectURL(new Blob([fObj.buffer],{type:'text/plain;charset=utf-8'}));
   // file.name
   downlink.download=fObj.name.substring(1+fObj.name.lastIndexOf('/'));
   downlink.type='text/plain';
   downlink.click();
   URL.revokeObjectURL(downlink.href);
}
function jobscmd(args){// jobs
   if(cmdhelp('jobs',args.length==0))return;
   let cnt=0;
   JOB.jobs().forEach((idx)=>{cnt++;
     let J=JOB.get(idx),t=J.type;if(t=='run'){t+='+'+J.stat;}
     if(t=='edit'&&J.gw.aechanged){t+='*';}
     if(cnt==1){P('### type project command');}
     P(`${idx} ${t} ${J.pr.name} "${J.cmd}"`);
     });
   if(cnt==0){P('no jobs');}
}
function killcmd(args){// kill <nnn>
   if(cmdhelp('kill',args.length==1))return;
   const J=JOB.get(parseInt(args[0]));
   if(!J){P('job '+args[0]+' not found'); return; }
   if(J.type=='run'){
     if(J.stat=='r'||J.stat=='i'){J.stat='k';J.worker.postMessage({cmd:'kill'});}
     else if(J.stat=='k'){ // terminate, we lost all files; try recovering some of them
        const lostfiles=[];
        J.worker.terminate();
        J.fidx.forEach((fObj)=>{if(!fObj.src && fObj.busy){
           fObj.busy=0;
           fObj.buffer=null;
           if(!fObj.as)lostfiles.push(fObj.name);
           LS.retrieve(fObj);
           if(fObj.writing){AE.setSave(fObj,true);}
        }});
        delete J.pr.run; // clear the project
        JOB.del(J.idx);
        J.call(-2,'progam killed'+(lostfiles.length==0?'':'. Files lost: '+lostfiles.join()));
     }
   }else{AE.closeEditor(J.gw);}
}

/* --------------------------------------------------------------- */
// running an aleph program
function endrun(type,msg){ // callback function when run ends
   // type==-1: cannot launch the program
   // type== 0: program terminated normally
   // type== 1: exit with non-zero value in msg
   // type== 2: runtime error
   // type== 3: killed
   switch(type){
     case -2:case -1:case 2: aCle.print(2,msg); break;
     case 1: P('terminated with exit value '+msg); break;
     case 3: P('killed'); break;
     default: break;
   }
}
function runcmd(args){
   if(cmdhelp('run',args.length>0))return;
   const pObj=FS.cwp();
   if(pObj.run){P('project is busy, job #'+pObj.run);return;}
   let rObj=FS.ffind(pObj,args[0]+'.js',0);
   if(!rObj){ rObj=
       args[0]=='comp' ? FS.cd.comp :
       args[0]=='opt'  ? FS.cd.opt  :
       args[0]=='link' ? FS.cd.link :
       FS.ffind(pObj,args[0],0);
   }
   if(!rObj){P('program not found');return;}
   if(rObj.type!='js'){P('wrong program type');return;}
   const F=rObj==FS.cd.comp?FS.cd.stdlib.slice(0) :
           rObj==FS.cd.link?FS.cd.stdice.slice(0) : [],C=[];
   let bracket=0,addd=0;
   for(let i=1;i<args.length;i++){
     if(i==1 && args[i]=='{'){bracket=1;}
     else if(bracket==1){
       if(args[i]=='}')bracket=2;
       else if(args[0]=='+'){addd=1;}
       else{// it is a pattern, add all files
          let br=0; const res=FS.fmatch(args[i]);
          if(res.length==0){P('file '+args[i]+' not found');return;}
          res.forEach((x)=>{
             if(br)return;
             if(x.p==0 || x.i.pr!=pObj){br=1;P('file '+x.i.name+' not in the current project');}
             else {F.push(x.i);}
          });
          if(br)return;
       }
     }else{ C.push(args[i]);}
   }
   if(bracket==1){P('missing closing }');return;}
   if(bracket==0||addd){// get all +d files in this project
      let fObj;
      for(let i=0;fObj=FS.fbyidx(i);i++){
        if(fObj.pr==pObj && fObj.ad){F.push(fObj);}
      }
   }
   LAUNCH.run(pObj,rObj,F,C,endrun);
}
function compcmd(args){
   if(cmdhelp('compile',args.length>0))return;
   // <compiles flags> -X <linker flags> <.ale files>
   const pObj=FS.cwp(); if(pObj.run){P('project is busy, job #'+pObj.run);return;}
   const copt=[],lopt=[],files=[];let h=0;
   for(let i=0;i<args.length;i++){
      if(h==0){if(args[i]=='-X'){h=1;continue;}
               else if(args[i].startsWith('-')){copt.push(args[i]);}
               else{h=2;}}
      if(h==1){if(args[i].startsWith('-')){lopt.push(args[i]);}
               else{h=2;}}
      if(h==2){
        let br=0; let res=FS.fmatch(args[i]);
        // if no extension, add .ale
        if(res.length==0 && ! /^.+\.[a-zA-Z0-9]+$/.test(args[i]) ){
           res=FS.fmatch(args[i]+'.ale');
        }
        if(res.length==0){P('file '+args[i]+' not found'); return;}
        res.forEach((x)=>{
           if(br)return;
           if(x.p==0 || x.i.pr!=pObj){br=1;P('file '+x.i.name+' not in the current project');}
           else if(x.i.type!='ale'){br=1;P('file '+x.i.name+' not .ale');}
           else if(files.indexOf(x.i)<0){files.push(x.i);}
        });
        if(br)return;
      }
   }
   if(cmdhelp('compile',files.length>0))return;
   LAUNCH.compile(pObj,copt,lopt,files);
}
/* --------------------------------------------------------------- */
const COMMANDS={
  help:      {f:helpcmd,s:'[<command>|-<topic>]',h:[
              'give help on a specific command or topic.','']},
  '?':       {alias:'help'},
  sample:    {alias:'load'},
  load:      {f:sample,s:'a1 .. load a20',h:['load a sample ALEPH program.','\n'+
              'These ALEPH programs represent different features, starting from the\n'+
              '"Hello World!" in \'a1\' and advancing. The main program is aN.ale, the\n'+
              'modules, if any, are aNm1.ale, aNm2.ale, etc. Use\n'+
              '  edit aN.ale      to open this program in an editing window\n'+
              '  compile aN*.ale  to compile with all modules, finally\n'+
              '  run aN           to run the result.']},
  chpr:      {f:chpr,s:'<project>',h:['change to the specified project.','']},
  mkpr:      {f:mkpr,s:'<project>',h:['create a new empty project and change to it.','']},
  lspr:      {f:pwpr,s:'',h:['print the current project name.','']},
  pwpr:      {alias:'lspr'},
  delpr:     {alias:'rmpr'},
  rmpr:      {f:rmproject,s:'[-f] <project>',h:['delete a project. Usage:\n'+
              '  rmpr <project>    delete an empty project\n'+
              '  rmpr -f <project> delete all files in the project first.']},
  rm:        {f:delcmd,s:'[-r] <pattern>',h:['remove files in a project. Usage:\n'+
              '  rm <file>         delete a single file\n'+
              '  rm -r <pattern>   delete all matching files\n'+
              'Files which are edited or used by a running program cannot be deleted.']},
  del:       {alias:'rm'},
  list:      {alias:'ls'},
  dir:       {alias:'ls'},
  ls:        {f:listcmd,s:'[-l] <pattern>',h:['list projects and files.','\n'+
              '  In the pattern ? matches any non-slash character and * matches\n'+
              '  any sequence of non-slash characters. Patterns starting with \'/\'\n'+
              '  search all projects; others search the current project only.\n'+
              '  \'ls /*\' lists all projects. The -l flag lists file attributes.']},
  copy:      {alias:'cp'},
  cp:        {f:copycmd,s:'<source> <dest>',h:['copy a file.','']},
  attrib:    {f:attribcmd,s:'+<attr> -<attr> <pattern>',h:['manipulate file attributes.','\n'+
              '  set (+) or clear (-) one or more of these attributes:\n'+
              '     s  -- store as character file locally and retrieve automatically\n'+
              '     r  -- read only, pass to running programs as \'read only\'\n'+
              '     d  -- data, pass to running programs automatically.']},
  edit:      {f:editcmd,s:'<file>',h:[
              'edit or create a new character file.','']},
  view:      {f:viewcmd,s:'<file>',h:[
              'view an existing character file.','']},
  stdlib:    {f:viewstdlib,s:'',h:['show standard ALEPH library.','']},
  upload:    {f:upcmd,s:'',h:['upload character files to the current project.','']},
  download:  {f:downcmd,s:'<file>',h:['save a character file on the local machine.','']},
  jobs:      {f:jobscmd,s:'',h:['list all running jobs.','']},
  kill:      {f:killcmd,s:'<jobno>',h:['kill the specified job.','']},
  run:       {f:runcmd,s:'<program> {<files>} <args>',h:['run an ALEPH program.','\n'+
              '  <program>  compiled program with or without the .js extension\n'+
              '  {<files>}  list of + and file patterns. These files are made available\n'+
              '             for the running program. + means files with attribute +d.\n'+
              '             If this part is missing, it is equivalent to {+}\n'+
              '  <args>     command line arguments.\n'+
              'Both the <program> and all <files> must be in the current project.']},
  compile:   {f:compcmd,s:'[<compiler flags>] [-X <linker flags>] <.ale files>',
                    h:['compile and link the main ALEPH program and optional modules.\n','\n'+
              'compiler flags:\n'+
              '  -W          --warninglevel=3 (default is 4)\n'+
              '  -Wall       --warninglevel=0\n'+
              '  -l          same as --list=on\n'+
              '  -d          same as --dictionary=on\n'+
              '  --xxxx=zzz  parsed as \'pragmat\'xxxx=zzz. (no spaces allowed)\n'+
              'linker flags:\n'+
              '  -W          report unused public items (can be verbose)\n'+
              '  -noasync    no async rules (e.g., console input, msleep)\n'+
              '  -g          link with call stack tracing\n'+
              'files:\n'+
              '  ALEPH modules (optional) and main program to be compiled. These\n'+
              '  must be .ale files in the current project. Can be specified using\n'+
              '  file patterns.']},
 'font-size':{alias:'fontsize'},
  fontsize:  {f:(b)=>{const x=parseFloat(b[0]||'');if(isNaN(x) || !(0.5<=x && x<=2.0)){
                     P("usage: fontsize <s> with 0.5<= s <=2.0");}
                   else{ aCle.font(x);}},
              s:'<s> where 0.5<= s <= 2.0',h:['change console font size.','']},
 'edit-size':{alias:'editsize'},
  editsize:  {f:(b)=>{const x=parseFloat(b[0]||'');if(isNaN(x) || !(0.5<=x && x<=2.0)){
                     P("usage: editsize <s> with 0.5<= s <=2.0");}
                   else{ AE.setFont(x);}},
              s:'<s> where 0.5<= s <=2.0',h:['change edit window font size.','']},   
  storage:   {f:()=>{let sum=0;LS.list().forEach((v)=>{
                     const attr=parseInt(v.attr.at(0)),len=v.attr.slice(1);
                     sum+=parseInt(len);
                     P('--s'+((attr&1)?'r':'-')+((attr&2)?'d':'-')+
                     len.padStart(7)+' '+v.file);});
                   P('Total storage: '+sum);},
              s:'',h:['list files in the Local Storage.','']},
};

function EXEC(str){
   let b=[];
   str.split(/(?:\s+|\s*([{}])\s*)/).forEach((x)=>{if(x)b.push(x);});
   if(b.length>0){
     const cmd=b.shift();
     let f=COMMANDS[cmd];if(f?.alias){f=COMMANDS[f.alias];}
     if(f){
       // check help arguments
       if(b[0]?.startsWith('-h')|| b[0]?.startsWith('--h')){showHelp(f); }
       else {f.f(b);}
     }else if(cmd.startsWith('-') && (f=TOPICS[cmd.slice(1)])){
        P(f)
     }else{P("unknown command, use 'help' for a list of commands");}
   }
}
return EXEC;
}(document);



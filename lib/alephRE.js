/* ALEPH javascript runtime environment
* This code is part of ALEPH-M (Modular javascript ALEPH v1.0)
*
*  (C) 2020-2025, L.Csirmaz
*
*  ALEPH-M is a free software, your can redistribute and/or
*  modify it under the terms of the GNU General Public License
*  as published by the Free Software Foundation, either version
*  3 of the License, or (at your option) any later version.
*
*  ALEPH-M is distributed in the hope that it will be useful,
*  but  WITHOUT ANY WARRANTY; without even the implied warranty
*  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
*  the GNU General Public License for more details.
*/

/* ALEPH javascript runtime environment for a compiled aleph
   program and standard library.

1) class for arrays: a_Array
    name           aleph tag for debugging and error messages
    get(i)         take an element with ALEPH index i
    put(i,v)       set the element with ALEPH index i
    alwb,aupb,vlwb,vupb,calibre
                   the corresponding values
    offs           difference between real and virtual indices
    buffer         the Int32Array containing the array elements
    extension(i)   add i additional elements to the top, return the
                   real index of the first free slot
    checkidx(i,rno)check index and throw exeption if out of bounds
    free()         release buffer
    chomp()        realloc to free extra memory, used by stdarg only

2) string handling routines
    a_CompareString(A1,idx1,A2,idx2)
                   compare two packed strings
    a_CompareStringN(A1,idx1,A2,idx2,n)
                   compare two packed integers up to n UTF-8 chars
    a_StringElem(A,idx,n,Res)
                   n-th UTF-8 character 
    a_PackString(A,n,S)
                   convert n UTF-8 chars to the top of S
    a_UnpackString(A,idx,S)
                   decode the UTF-8 string into characters
    a_CopyString(A,idx,S)
                   copy a packed string to the top of S
    a_PushString(S,len,f)
                   f(0)...,f(len-1) return UTF-8 chars, pack them
                   at the top of S (used by stdarg)
    a_cmpToStr(A,idx,"str")
                   check if "str" and the packed strings are the same (wait)
*   a_Ite(A,idx,f) call f() for each UTF-8 char in the packed string
*   a_Str(A,idx)   convert a packed string into a js string

3) timeout
    a_async_a_sleep(ms)
                   return after ms milliseconds

4) filesystem
  Available file descriptors are stored in the a_FD[] array (written: F)
    path     fully qualified name; <<xxx>>> for standard character files
    idx      fObj index, -1 if URL, -2 if created
    openw    -1 if RO (no writing, unlink), 1 if opened for writing
    openr    -1 if cannot be opened for reading; number of opens
    type     0: buffer based, 1: async message input, 2: async message output
    channel  string, when type=1 or type=2, stdin,stdout,stderr
    tmpfile  1 if created by mktemp
    changed  0/1 indicating changes of the underlying buffer
    ff       when opened for writing the associated aleph FILE
    buff     the underlying ArrayBuffer
    bufflen  valid only when *not* opened for writing


  Class for charfile and datafile (written: f): a_CharFile, a_DataFile
    name     ALEPH name (debugging and error messages)
    errno    result of last operation
    direction 0:not opened, 1:read, 2:write
    type     0:datafile, 1:charfile
    arg      {dir,T,ptr} from the declaration; dir=4 for external
    fix      index of the file descriptor in FD[] if opened
    eof      valid when reading, cleared when positioned
    fpos     valid when reading, file position
    setareas() for dataFile only, function to add areas (called after
             initializing all lists)

  character writing
    async (F.type==2), line buffered
      f.CollectLine[] js string, to be sent to F.channel
    sync (no positioning)
      f.fpos    next index to write to
      f.buffer  Uint8Array view of F.buffer

  character reading
    async (F.type=1), reading a complete line (no newline character)
      f.lineBuf[]  string of characters of the line
      f.linePtr    index of the next position
      f.lineEOF    if ctrl+D was hit after consuming lineBuf[]
    sync (reading from an ArrayBuffer)
      f.buffer     Uint8Array view of F.buffer
      f.nextch     the next UTF-8 character to be read
      f.fpos       recent position, looking at f.nextch or EOF
      f.nextpos    position after the next UTF-8 character

  data reading and writing
    each 32 bit data is extended by a single bit indicating pointer.
    Pointers are positive, null is zero, EOF is -1. Data is stored
    in blocks of 1024 words; the first 32 word is reserved for storing
    pointer indicators.
      F.areas[]    array of {vlwb,vupb} of declared areas
      f.buffer     Int32Array view of the current block of 1024 words
      f.fpos       file pointer to write into
      f.iflag      32 bit data (pointer flags) for 32 consecutive words
      f.inareas[]  when reading, array of {lwb,upb,off} to correct
                   pointer offsets
      f.startpos   when reading, the very first position (for offset 0)

  opening and closing
    a_openfile(af,mode,A,ptr)
                   af: aleph file, mode: /r/ or /w/, (A,ptr): name
*   a_tryopen(af,mode)
                   try to open an aleph file, return 1 if OK success
    a_opentmp(af,A,ptr)
                   create a tmp file and open it for writing. The ending
                   XXXXXX in (A,ptr) is replaced by random letgits
    a_closefile(af) close; if opened for writing, fix ArrayBuffer length
    a_unlinkfile(A,ptr)
                   if found, prepend "./Trash/" to filename
    a_setfilepos(af,pos)
                   set position when buffered and opened for reading

*   a_closeAll()   close all files; called when the program terminates
*   returnFiles()  return files using messages
*   a_addFile(fname,idx,ro,buff)
                   populate a_FD with the specified file; idx=-1 when URL
*   loadFile(fname,URL)
                   load the file from the given URL as RO

  character input/output
    a_aheadchar(af,P)
                   get the next UTF-8 char to P[0] but do not advance
    a_async_a_aheadchar(af,P)
                   async version
    a_getchar(af,P) get the next UTF-8 char to P[0], advance
    a_async_a_getchar(af,P)
                   async version
*   aChkIn(af)     check character input, return 1 on error, 0 on OK
*   aChPos(F,f)    advance character position, read next UTF-8 char
*   a_WaitForNextLine(channel)
                   promise which reolves to the received message
*   a_SendLineBuffer(channel,str)
                   sent the string to the channel
*   flushStdout()  before prompting at stdin, flush stdout
*   asChar(f,F,P)  async character reading; return 0 on error or EOF,
                   1 if next char is in P[0]
    a_putchar(af,ch)
                   add next character to the file

  data input/output
    a_putdatap(af,data,type)
                   add data with type to the file; open implicitly,
                   Return 0 on fail, 1 on success
    a_putdata(af,data,type)
                   if fail, throw an exception
    a_getdata(af,P) return the next data in P[0], type in P[1]. Return
                   1 on success, 0 on failure, set af.errno

5) track, trace, profile, errors
    a_WaitLock(str)
                   called if waitfor("str") causes a deadlock
    a_PrintStackFrame()
                   called directly by backtrack(), and by the error routines
    a_TraceRule(rn,n,...)
                   trace rule call, a_Rulenames[rn](...) with n argument
                   following
*   dump_Profile(pf) dump profiling information linked throut the index.
                   Uses the global a_PROFILE
    a_AreaFailed(val,str)
                   called when no part of an area succeeded
    a_exit(v)      'exit' rule, with optional backtrack

6) synchronizing, communicating with the main thread
  The first message is 'init' with a 'ready' response; receiving the ID of the
  running job. All further messages have this job number.
  The next messages populate stdarg, and the filesystem. Files are either
  ArrayBuffer based (when the result should be passed back), or URL based which
  are downloaded (rely on the browser's caching), followed by 'run'.
  Since download is async, the 'run' command might be deferred.
*   runmsg()       calls runRoot() after waiting all donwloads complete
*   runRoot()      runs the root of the ALEPH program; closes and returns files;
                   then deletes the worker.
*/

let a_StdargArray=[];   // command line arguments, set by initial message
let a_Job=-1;           // the job number, sent with each message
let a_Ret=0;            // return value: 0: OK, 1: exit, 2: error, 3: kill
let a_Exv=0;            // the exit value, if set

// constants 
const a_MaxListSize=1e6;// maximal size of an ALEPH list in bytes
const a_MaxFileSize=1e6;// opening a file for writing
const a_CharBufExt=4096;// bytes character files are extended

/* ******************************************************************** */
/* Errors are reported as exceptions using a string 'cause' field */
function toss(...args){
   const w=args.pop();
   throw Error(args.join(' '),{cause:w});
}
/* ******************************************************************** */
// const a_PROFILE=null;      head of the profile chain
// const a_RuleNames=[];      rule names for profile,backtrack,index check
// const a_ROOT=function()    the main root, can be async
// function a_Tr()            returns either null or stack info {rule,next}
/* ******************************************************************** */
/* new a_Array() creates table or stack (including external ones) */
class a_Array {
   constructor(type,string,cal,lwb,upb,fillsize){
      this.type = type,   // 0: table, 1: stack
      this.name = string, // list name for error messages as a string
      this.calibre=cal,   // calibre, typically 1
      this.vlwb = lwb,    // virtual lower bound
      this.vupb = upb,    // virtual upper bound
      this.alwb = lwb,    // actual lower bound
      this.aupb = lwb-cal,// actual upper bound, empty
      this.offs = cal-lwb-1, // see get() and set()
      this.buffer = new ArrayBuffer(0, {maxByteLength:a_MaxListSize}),
      this.data = new Int32Array(this.buffer),
      this.size=0,        // allocated size in words
      this.extension(fillsize);
   }
   extension(i){ // add i additional elements in blocks of size 1024
      let ns=this.aupb+this.calibre-this.alwb+i; // new size
      if(ns>this.size){
          if(this.aupb+i>this.vupb){ // would go beyond upper bound
             toss('extending',this.name,'by',i,'from',this.aupb,
                  'would go beyond',this.vupb,'extension');
          }
          // make it a multiple of 1024, but don't go beyond vupb
          ns=Math.min((ns+1023)& ~0x3ff,this.vupb+this.calibre-this.alwb);
          if(4*ns>a_MaxListSize){
              toss('stack',this.name,'size',ns,'exceeds max memory','extension');
          }
          this.size=ns;
          this.buffer.resize(this.size*4);
      }
      return this.aupb+this.offs+1;
   }
   get(i) { return this.data[i+this.offs]; }
   checkidx(i,rno) {
      if(i+this.offs<0 || i>this.aupb){
         toss("index error",this.name,"[",i,']',"in rule",a_RuleNames[rno],"indexing");
      }
      return i+this.offs;
   }
   put(i,v){ this.data[i+this.offs]=v; }
   free(){ // free the allocated buffer
      this.aupb=this.vlwb;
      this.alwb=this.aupb+this.calibre;
      this.size=0; 
      this.buffer.resize(0);
   }
  // set vupb and buffer size to the actual content
   chomp(){
      this.vupb=this.aupb;
      this.size=this.vupb+this.calibre-this.alwb;
      this.buffer.resize(this.size*4);
      return this.vupb;
   }
}
function a_RequestSpace(A,i){
    if(A.aupb+i>A.vupb){ return 0; }
    const oldsize=A.size;
    try{A.extension(i);}
    catch{ A.size=oldsize; return 0; }
    return 1;
}
// populate ALEPH lists
function a_FillLists(FillA){
  for(let idx=0;typeof(FillA[idx]) == "object";idx++){
    let ST=FillA[idx++];let STx=ST.offs+ST.aupb+1;
    for(let cnt=0;FillA[idx]!=0;){
       let x=FillA[idx++];
       if(0<x)for(cnt=x,ST.aupb+=cnt;0<x;x--)ST.data[STx++]=FillA[idx++];
       else for(;-1>x;x++){
         ST.aupb+=cnt;
         for(let i=0;i<cnt;i++)ST.data[STx]=ST.data[STx-cnt],STx++}
    }
}}
/* ******************************************************************** */
/* String routines */
/* A string is stored using UTF-8 encoding, 4 bytes in each 32 bit slot.
   idx: width, idx-1: length, idx-width+1: first four bytes */
function a_CompareString(A1,idx1,A2,idx2) {
    const i1=A1.offs+idx1,  i2=A2.offs+idx2;  // real indices
    const w1=A1.data[i1]-1, w2=A2.data[i2]-1; // width -1
    if(w1<2||i1<w1||w2<2||i2<w2){toss(
      A1.name,"[",idx1,"] or ",A2.name,"[",idx2,"] not a string","compare string");
    }
    const u1 = new Uint8Array(A1.buffer,4*(i1-w1),4*w1),
          u2 = new Uint8Array(A2.buffer,4*(i2-w2),4*w2);
    let i=0;
    while(u1[i]==u2[i] && u1[i]!=0) i++;
    return u1[i]-u2[i];
}
function a_CompareStringN(A1,idx1,A2,idx2,n) {
    const i1=A1.offs+idx1,  i2=A2.offs+idx2;  // real indices
    const w1=A1.data[i1]-1, w2=A2.data[i2]-1; // width -1
    if(w1<2||i1<w1||w2<2||i2<w2){toss(
      A1.name,"[",idx1,"] or ",A2.name,"[",idx2,"] not a string","compare stringN");
    }
    const u1 = new Uint8Array(A1.buffer,4*(i1-w1),4*w1),
          u2 = new Uint8Array(A2.buffer,4*(i2-w2),4*w2);
    let i=0;
    while(n>0 && u1[i]==u2[i] && u1[i]!=0){
       if((u1[i]&0xC0)!=0x80) n--;
       i++;
    }
    return n ? u1[i]-u2[i] : 0;
}
// get the cnt-th character from a string
function a_StringElem(A,idx,cnt,Res){
    const ii=A.offs+idx; const w=A.data[ii]-1; // index and width-1
    if(w<2||ii<w||w>32000){toss(A.name,'[',idx,'] not a string','string elem');}
    if(cnt<0 || cnt>=A.data[ii-1]) return 0;
    const u = new Uint8Array(A.buffer,4*(ii-w),4*w);
    for(let i=0;i<4*w;cnt--){
       let c=u[i++];
       const eb=(c>191)+(c>223)+(c>239); // 0,1,2,3
       if(cnt<=0){
          c &= [255,31,15,15][eb];
          (3>eb)||(c=(c<<6)|u[i++]&63);
          (2>eb)||(c=(c<<6)|u[i++]&63);
          (1>eb)||(c=(c<<6)|u[i]&63);
          Res[0]=c; return 1;
       }
       i+=eb;
    }
    toss(A.name,'[',idx,'] not a string, cnt=',cnt,'string elem');
}
// compress a list of characters
function a_PackString(A,n,S) {
    if(n<0 || n>32000){toss(
     'pack string+',A.name,'+',n,'+',S.name,'wrong length','pack string');}
    const ai=A.offs+A.aupb-n+1;   // start index A.data[ai .. ai+al]
    a_PushString(S,n,(x)=>{return A.data[ai+x]});
}
// unpack characters from the string at A[idx] to the top of S
function a_UnpackString(A,idx,S) {
    const n=A.data[A.offs+idx-1]; // number of characters
    if(n==0) return;
    if(n<0||n>32000){toss(
       'unpack string+',A.name,'+',idx,'+',S.name,'not a string','unpack string');}
    let Si=S.extension(n); S.aupb+=n; // extend the stack
    a_Ite(A,idx,(c)=>{S.data[Si++]=c;});
}
// copy a packed string at A[idx] to the top of S as a string
function a_CopyString(A,idx,S) {
    let ai=A.offs+idx; // string index
    let w=A.data[ai];  // width
    ai -= w-1;
    if(ai<0||w<2||w>10000){toss(
       'copy string+',A.name,'+',idx,'+',S.name,'not a string','copy string');}
    let Si=S.extension(w); S.aupb+=w; // extend the stack
    for(;w>0;w--){ S.data[Si++]=A.data[ai++]; }
}
/* **************************************************************** */
// INTERNAL string routines
// a_Ite(A,idx,fn)
//    call fn(chr) for each character in the packed string
// a_PushString(S,len,fn)
//    fn(0),...,fn(len-1) return character values, pack the string
//    at the top of the stack S. Uses two passes for the fn() calls
// a_cmpToStr(A,idx,"string")
//    check if the packed string is the same as the provided one
// a_Str(A,idx)
//    return the packed string as a javascript string
function a_Ite(A,idx,fn){
    // unpack the string and call fn for each character
    // throw error if there is an error in string
    const ii=A.offs+idx;const w=A.data[ii]-1;//index and width
    let n=A.data[ii-1]; // string length
    if(w<2||ii<w||w>10000||n<0||n>32000){toss(
      A.name,'[',idx,'] not a string','iterate ALEPH string');}
    const u=new Uint8Array(A.buffer,4*(ii-w),4*w);
    for(let i=0;n>0;n--){
      if(i>4*w-4){toss(
        A.name,'[',idx,'] not a string','iterate ALEPH string');}
      let c=u[i++];
      const eb=(c>191)+(c>223)+(c>239);
      c &= [255,31,15,15][eb];
      3>eb||(c=(c<<6)|u[i++]&63);
      2>eb||(c=(c<<6)|u[i++]&63);
      1>eb||(c=(c<<6)|u[i++]&63);
      if(c==0)toss(
       A.name,'[',idx,'] not a string','iterate ALEPH string');
      fn(c);
    }
}
function a_PushString(S,len,fn){
    // pack len many characters as an ALEPH string at the top of S
    let bw=12; // determine the number of bytes
    for(let i=0;i<len;i++){
      const c=fn(i);
      if(c<1||c>0x10FFFF) toss(
       'invalid charcode',c,'to string at',S.name,'pack string');
      bw+=1+(c>=0x80)+(c>=0x800)+(c>=0x10000);
    }
    bw >>= 2;
    const Si=S.extension(bw);S.aupb+=bw;S.data[Si+bw-3]=0;
    const u=new Uint8Array(S.buffer,Si*4,bw*4);
    let ui=0; const w= (v)=>{u[ui++]=v;};
    for(i=0;i<len;i++){
      const c=fn(i);
      switch((c>=0x80)+(c>=0x800)+(c>=0x10000)){
           default: w(c); break; // zero
           case 1: w(0xC0|(c>>6)); w(0x80|(c&0x3F)); break;
           case 2: w(0xE0|(c>>12)); w(0x80|((c>>6)&0x3F)); 
                    w(0x80|(c&0x3f)); break;
           case 3: w(0xF0|(c>>18)); w(0x80|((c>>12)&0x3F));
                    w(0x80|((c>>6)&0x3F)); w(0x80|(c&0x3F)); break;
        }
    }
    w(0);S.data[Si+bw-2]=len; S.data[Si+bw-1]=bw;
}
function a_cmpToStr(A,idx,jstr){
   // check if the packed string A[str] is the same as jstr
   // used by waitfor
   return jstr==a_Str(A,idx);
}
function a_Str(A,idx){
   // create a java string from the packed ALEPH string
   let res="";a_Ite(A,idx,(c)=>{
       res+=String.fromCodePoint(c);});
   return res;
}

/* ************************************************************* */
/* msleep() function */
function a_msleep(ms){
  // sync program calling sleep
  toss('sleep(',ms,'), use -async for linking','sleep');
}
async function a_async_a_msleep(ms){ // wait ms milliseconds
  await new Promise((resolve)=>{setTimeout(resolve,ms)});
}
/* ************************************************************* */
/* File: async input (stdin), async output (stdout,stderr)
   Other files are ArrayBuffer based. All input files must be provided
   by the outer layer; all not tmp output files are passed to the outer
   layer for saving.
Fields in a_FilesAvaiable[] 
   F=a_FD[idx]
   F.path:  the path string, identifying the file path
   F.idx:   received fileObj index; -1 if URL, null if created
   F.openw: -1: read only; +1: opened for writing; 0: can be opened for writing
   F.openr: -1: write only; >=0: number of aleph FILEs opening
   F.tmpfile    1 if created as tmp, otherwise undefined
   F.changed    1 if a putchar or putdata is executed
   F.ff:    if opened for writing, the associated aleph FILE
   F.type:  1 -- stdin, 2 -- stdout, {channel:"stdXX"} filled
            0 -- ArrayBuffer based, buff and bufflen are filled
   F.buff:    the underlying ArrayBuffer; resized to the true length when closing
   F.bufflen: if received ArrayBuffer, the length of the underlying buffer (bytes)
              also set when closing
Aleph file fields:
   f.name:      aleph FILE name (for debugging and errors)
   f.errno:     last file error
   f.direction: 0: not opened, 1: opened for read, 2: opened for write
   f.type:      1: charFile, 0:dataFile
   f.arg:       {dir:,T:,ptr:} declaration arguments
   f.fidx:      associated FileAvailable index if opened
   f.fpos:      actual file position, valid only when reading
   f.eof:       eof was hit; cleared when positioned
---------------------------------
character writing and reading
Async writing: (no positioning)
   f.CollectLine[]: string of js characters to be sent; newline buffered
            the to send to is from F.channel; also flush() and close()
Sync writing: (no positiong)
   f.fpos:      next free position
Async reading: (no positioning)
   f.lineBuf[]  string of characters of the next line
   f.linePtr    index of the next position (ahead)
   f.lineEOF    if over the line buf, set f.eof (ctrl+D was hit)
Sync character reading 
   f.fpos:      recent position, looking at the char f.nextchar of EOF
   f.buffer:    associated Uint8Array
   f.nextch:    next character
   f.nextpos:   position after the character
-----------------------------------
data writing and reading
   F.areas[]  {R.lwb,R.upb}
   F.buff     ArrayBuffer,
   F.bufflen  size of F.buff in bytes
   f.bfpos:   buffer counter, increases by 4*1024
   f.buffer:  Int32Array of size 1024
   f.fpos:    actual data counter
   f.iflag:   data/pointer flags, shifted to the sign position
   f.inareas: arrays of {lwb,upb,diff} to correct the offsets
   f.startpos:when reading the very first position (for setting 0)
*/
const a_FD=[
// stdin, stdout, stderr
{path:"<<stdin>>",openw:-1,openr:0,type:1,changed:0,channel:"stdin"},
{path:"<<stdout>>",openw:0,openr:-1,type:2,changed:0,channel:"stdout",ff:null},
{path:"<<stderr>>",openw:0,openr:-1,type:2,changed:0,channel:"stderr",ff:null}
];

const IOERR={ // IO error codes
  EOPENED:	1,//open+F+ where F is opened
  ENOTFOUND:	2,//"file" not found
  EBUSY:	3,//"file" is opened for write or read only
  EREADONLY:	4,//"file" cannot be opened for writing
  EDIRECTION:	5,//Direction mismatch in file declaration
                  //read on a file opened for writing or other way
  EFILETYPE:    6,//char op on a datafile or the other way around
  ENOTOPENED:	7,//not opened
  EWRONGPTR:	8,//put data pointer not in any areas
  EDATATRUNC:	9,//data file truncated
  EEOF:        10,//End of file
  ENOTALEPH:   11,//not and aleph binary file
  ENOSEEK:     12,//cannot set position
  ESEEK:       13,//wrong position value
  ETEMP:       14,//open temp file string
};

const readArg=114;  //"r".charCodeAt(0);
const writeArg=119; //"w".charCodeAt(0);
const tempArg=88;   //"X".charCodeAt(0); in openTemp()
const codeA=65;     //"A".charCodeAt(0);

/* ================================================================= */

class a_CharFile {
   constructor(name,dir,table,ptr){
      this.name=name,
      this.type=1, // datafile: 0
      this.errno=0,
      this.direction=0, // 0:not opened, 1:writing, 2:reading,
      this.fpos=-1,
      this.arg={d:dir,T:table,idx:ptr}
      // dir=4 for external, otherwise 0,1,2,3
   }
   init(){} // called after this.table has been populated
}

class a_DataFile {
   constructor(name,dir,table,ptr,areano){
      this.name=name;
      this.type=0, // charfile: 1
      this.errno=0,
      this.fpos=-1,
      this.direction=0,//not opened yet
      this.arg={d:dir,T:table,idx:ptr},
      this.inareas=[]; //for reading
      if(areano>=32){toss(
        'datafile',name,'maximal number of areas exceeded','datafile init');}
   }
   setarea(aa){ // array, can be empty
      this.areas=[];
      for(const T of aa){
         this.areas.push({lwb:T.vlwb,upb:T.vupb});
      }
   }
}

/* ***************************************************************** */
/* Character input
a_WaitForNextLine(<channel>)
   sending:    {cmd:"read",file:<channel>} ("stdin")
   waiting for:{cmd:"stdin",file:<channel>,eof:0/1,data:"reply"}
   newline char is added automatically when eof=0
aChPos(F,f)
   character input file, peek at the next incoming character
aChkIn(f)
   check file f for character input
*/
function a_WaitForNextLine(fstr){//channel
   return new Promise((resolve)=>{
     const listener=(e)=>{
       const ed=e.data;if(ed.cmd=="stdin"
             && ed.file==fstr){// answer received
          self.removeEventListener("message",listener);
          resolve(ed);
       }}
       self.addEventListener("message",listener);
       self.postMessage({cmd:"read",job:a_Job,file:fstr});
});}

//f is an opened a_CharFile, advance the character position
function aChPos(F,f){
    f.fpos=f.nextpos;
    if(f.fpos>=F.bufflen){f.fpos=F.bufflen;f.eof=1;return;}
    const u=f.buffer;let i=f.fpos;let c=u[i++];
    const cc=(c>191)+(c>223)+(c>239);
    f.nextpos=f.fpos+1+cc;if(f.nextpos>F.bufflen){
       f.pos=F.bufflen;f.eof=1;return;}
    c &= [255,31,15,15][cc];
    3>cc||(c=(c<<6)|u[i++]&63);
    2>cc||(c=(c<<6)|u[i++]&63);
    1>cc||(c=(c<<6)|u[i]&63);
    f.nextch=c;
}
function aChkIn(f){
   if(f.type!=1){f.errno=IOERR.EFILETYPE;return 1;}
   if(f.direction==0){if(!a_tryopen(f,readArg)){return 1;}}
   else if(f.direction!=1){f.errno=IOERR.EDIRECTION;return 1;}
   if(f.eof){f.errno=IOERR.EEOF;return 1;}
   return 0;
}
function flushStdout(){
   for(F of a_FD){
     if(F.type==2 && F.channel=="stdout" && F.openw>0 && F.ff.CollectLine){
        a_SendLineBuffer(F.channel,F.ff.CollectLine);
        F.ff.CollectLine=""; }}
}
async function asChar(f,F,aP){
   if(f.linePtr>=f.lineBuf.length){
      if(f.lineEOF){f.eof=1;f.errno=IOERR.EEOF; return 0;} // EOF reached, no next character
      // before waiting flush stdout, if not empty ...
      flushStdout();
      const nx=await a_WaitForNextLine(F.channel);
      f.lineEOF=nx.eof;f.lineBuf.length=0;// clear it
      for(const cc of nx.data){f.lineBuf.push(cc.codePointAt(0));}
      if(!f.lineEOF){f.lineBuf.push(10);} // add a newline char
      f.linePtr=0;
      if(f.lineBuf.length==0){f.eof=1;f.errno=IOERR.EEOF; return 0; }
   }
   f.errno=0;aP[0]=f.lineBuf[f.linePtr];
   return 1;
}
// peek at the next character
async function a_async_a_aheadchar(f,aP){
   if(aChkIn(f)) return 0;
   const F=a_FD[f.fidx];
   if(F.type==0){f.errno=0;aP[0]=f.nextch; return 1;}
   return await asChar(f,F,aP);
}
function a_aheadchar(f,aP){
   if(aChkIn(f)) return 0;
   if(a_FD[f.fidx].type==0){f.errno=0;aP[0]=f.nextch;return 1;}
   toss(f.name,'attached to <<stdin>>, use -async for linking','ahead char');
   return 0;
}
//'p'get char+""f"+char>.
async function a_async_a_getchar(f,aP){
   if(aChkIn(f)) return 0;
   const F=a_FD[f.fidx];
   if(F.type==0){f.errno=0;aP[0]=f.nextch;aChPos(F,f);
         return 1;}
   if(await asChar(f,F,aP)){f.linePtr++; return 1;}
   return 0;
}
function a_getchar(f,aP){
   if(aChkIn(f)) return 0;
   const F=a_FD[f.fidx];
   if(F.type==0){f.errno=0;aP[0]=f.nextch;aChPos(F,f);return 1;}
   toss(f.name,'attached to <<stdin>>, use --async for linking','get char');
   return 0;
}

/* ------------------------------------------------------------------ */
/* character output */
function a_SendLineBuffer(chan,str){
   self.postMessage({cmd:"write",job:a_Job,file:chan,data:str});
}
//'a'putchar+""f+>ch
function a_putchar(f,ch){
    if(f.type!=1){ f.errno=IOERR.EFILETYPE; return;}
    if(f.direction==0){ // not opened yet
      if(!a_tryopen(f,writeArg)){ return; }
    } else if(f.direction==1){f.errno=IOERR.EDIRECTION; return;}
    // it is opened
    f.errno=0;ch|=0;// normalize the value to be written
    const F=a_FD[f.fidx];F.changed=1;
    if(F.type==2){//line buffered
       if(ch==10){
          a_SendLineBuffer(F.channel,f.CollectLine);f.CollectLine="";return;
       } else{f.CollectLine+=String.fromCodePoint(ch); return;}}
    const bw=1+(ch>=0x80)+(ch>=0x800)+(ch>=0x10000);
    if(f.fpos+bw>=F.bufflen){//extend the charfile
       F.bufflen+=a_CharBufExt;F.buff.resize(F.bufflen);}
    let i=f.fpos;f.fpos+=bw;const w=(v)=>{f.buffer[i++]=v;}
    switch(bw){
      default: w(ch);break;
      case 2:w(0xC0|(ch>>6));w(0x80|(ch&0x3F));break;
      case 3:w(0xE0|(ch>>12));w(0x80|((ch>>6)&0x3F));
              w(0x80|(ch&0x3F));break;
      case 4:w(0xF0|(ch>>18));w(0x80|((ch>>12)&0x3F));
              w(0x80|((ch>>6)&0x3F));w(0x80|(ch&0x3F));break;
    }
}

/* ******************************************************************* */
/* data transput */

//'p'put datap+""f+>data+>type
function a_putdatap(f,data,dt){
    if(0!=f.type){f.errno=IOERR.EFILETYPE;return 0;}
    if(0==f.direction){if(!a_tryopen(f,writeArg)){return 0;}}
    else if(f.direction!=2){f.errno=IOERR.EDIRECTION;return 0;}
    // it is opened for writing
    if(dt!=0 && data!=0 && data!=-1){// pointer, check where it is
      let cnt=0;
      for(;cnt<f.areas.length 
          && (data<f.areas[cnt].lwb||data>f.areas[cnt].upb);cnt++);
      if(cnt>=f.areas.length){f.errno=IOERR.EWRONGPTR;return 0;}
    }
    f.errno=0;
    if((1023==(f.fpos&1023))){// buffer is full, flush it
       f.buffer[31]=f.iflag;f.fpos++;
       const F=a_FD[f.fidx];
       F.changed=1;
       F.bufflen=(f.fpos+1024)*4;
       F.buff.resize(F.bufflen);
       f.buffer=new Int32Array(F.buff,f.fpos*4,1024);
       f.fpos+=32;f.iflag=0;
    }else if((f.fpos&31)==31){// next 32 values
       f.buffer[31&(f.fpos>>5)]=f.iflag;
       f.iflag=0;f.fpos++;
    }else{//make room for the next flag
       f.iflag<<=1;f.fpos++;
    }
    f.buffer[f.fpos&1023]=data; if(dt){f.iflag |=1;}
    return 1;
}
//'a'put data+""f+>data+>type
function a_putdata(f,data,dt){
   if(!a_putdatap(f,data,dt)){toss(
      'put data+',f.name,'+',data,'+',dt,'error code',f.errno,'put data');}
}
//'p'get data+""f+data>+type>
function a_getdata(f,aP){// aP[0],aP[1]
   if(f.type!=0){f.errno=IOERR.EFILETYPE;return 0;}
   if(f.direction==0){if(!a_tryopen(f,readArg)){return 0;}}
   else if(f.direction!=1){f.errno=IOERR.EDIRECTION;return 0;}
   if(f.eof){f.errno=IOERR.EEOF;return 0;}
   const F=a_FD[f.fidx];
   // advance f.fpos
   if((f.fpos&1023)==1023){
      if(F.bufflen<f.fpos*4+4096){f.errno=IOERR.EDATATRUNC;return 0;}
      f.fpos++;
      f.buffer=new Int32Array(F.buff,f.fpos*4,1024);
      f.fpos+=32;f.iflag=f.buffer[1];
   }else if((f.fpos&31)==31){
      f.fpos++;f.iflag=f.buffer[(f.fpos>>5)&31];
   }else{f.fpos++;f.iflag<<=1;}
   f.errno=0;
   aP[0]=f.buffer[f.fpos&1023];aP[1]=0;
   if(f.iflag&0x80000000){// pointer
      aP[1]=1;
      if(aP[0]==-1){f.errno=IOERR.EEOF;return 0;}// EOF
      if(aP[0]==0){return 1;}// null pointer
      let DO=1;
      f.inareas.forEach((V)=>{
         if(DO && V.lwb<=aP[0]&&aP[0]<=V.upb){DO=0;aP[0]+=V.diff;}});
      if(DO){f.errno=IOERR.WRONGVALUE;return 0;}
   }
   return 1;
}

/* ******************************************************************* */
function a_tryopen(file,mode){
    // not opened yet, check direction compability, then
    // open with the specified string
    const towrite=(mode==writeArg);
    switch(file.arg.d){
      case 2: if(towrite) break;
      case 0: file.errno=IOERR.EDIRECTION; return 0;
      case 1: if(towrite){ file.errno=IOERR.EDIRECTION; return 0; }
      default: break;
    }
    return a_openfile(file,mode,file.arg.T,file.arg.idx);
}
//'p'openfile+""f+>dir+T[]+>ptr
function a_openfile(file,mode,A,ptr,tmpfile=0){
   // check if we have a file with this name
   if(file.direction){ file.errno=IOERR.EOPENED; return 0; }
   file.errno=0;
   const towrite=(mode==writeArg);
   const fname=a_Str(A,ptr);
   let i=0;
   while(i<a_FD.length){
      if(a_FD[i].path==fname) break;
      i++;
   }
   if(i==a_FD.length){ // not found
      if(!towrite){file.errno=IOERR.ENOTFOUND; return 0; }
      a_FD.push(
        {path:fname,idx:-2,openw:0,openr:0,changed:0,type:0,buff:null,bufflen:0,ff:null});
   }
   // a_FileAvailable[i] is the file entry, let's see what to do
   const F=a_FD[i];
   if(towrite){// open for writing
     if(F.openw<0){file.errno=IOERR.READONLY;return 0;}
     if(F.openw!=0 || F.openr>0){file.errno=IOERR.EBUSY; return 0;}
     F.buff=null;
     if(file.type==1){ //charfile, write (or create)
        if(F.type==2){file.CollectLine="";file.fpos=-1;} // direct output
        else{
          F.buff=new ArrayBuffer(a_CharBufExt,{maxByteLength:a_MaxFileSize});
          F.bufflen=a_CharBufExt;file.buffer=new Uint8Array(F.buff);
        }
        file.fpos=0;
     } else {//datafile write
        if(F.type==2){file.errno=IOERR.EBUSY;return 0;}
        F.buff=new ArrayBuffer(4*1024,{maxByteLength:a_MaxFileSize});
        F.bufflen=4*1024;file.buffer=new Int32Array(F.buff,0,1024);
        file.iflag=0;file.fpos=32;
        const n=file.areas.length;
        file.buffer[file.fpos++]=n;
        for(let i=0;i<n;i++){
          file.buffer[file.fpos++]=i;
          file.buffer[file.fpos++]=file.areas[i].lwb;
          file.buffer[file.fpos++]=file.areas[i].upb;
        }
        file.startpos=file.fpos;
     }
     F.ff=file;F.openw++;file.direction=2;file.fidx=i;
     if(tmpfile)F.tmpfile=1;
     return 1;
   } else { //open for reading
     if(F.openw>0||F.openr<0){file.errno=IOERR.EBUSY;return 0;}
     if(file.type==1){//charfile, read
       if(F.type==1){ // stdin
         if(F.openr!=0){file.errno=IOERR.EBUSY; return 0; }// only one can read it
         file.lineEOF=0;file.lineBuf=[];file.linePtr=1;
         file.eof=0;file.fpos=-1;
       }else{//for ArrayBuffer
         file.fpos=0;file.eof=0;
         file.buffer=new Uint8Array(F.buff);
         file.nextpos=0;
         aChPos(F,file);
         // this can set eof to 1 if there is no character in it
       }
       file.direction=1;file.fidx=i;F.openr++;
       return 1;
     } else {// datafile read
       file.eof=0;
       if(F.bufflen<4096){file.errno=IOERR.ENOTALEPH;return 0;}
       file.buffer=new Int32Array(F.buff,0,1024);
       file.fpos=32;const n=file.buffer[file.fpos++];
       if(n<0 || n>=32){file.errno=IOERR.ENOTALEPH;return 0;}
       const VA=file.areas;file.inareas=[];
       for(let i=0;i<n;i++){
          if(i!=file.buffer[file.fpos++]){file.errno=IOERR.ENOTALEPH;return 0;}
          const lw=file.buffer[file.fpos++];const up=file.buffer[file.fpos++];
          if(i<VA.length){file.inareas.push({lwb:lw,upb:up,diff:VA[i].lwb-lw});}
       }
       file.startpos=file.fpos;
       file.iflag=file.buffer[(file.fpos>>5)&31]<<(file.fpos&31);
       file.direction=1;file.fidx=i;F.openr++;
     }
   }
   return 1;
}
//'p'open temp file+""f"+A[]+>ptr
function a_opentmp(file,A,ptr){
// the last 6 characters in the string must be XXXXXX, 
// they are replaced by some random 1 byte characters
   const ii=A.offs+ptr;const w=A.data[ii]-1;
   if(w<2||ii<w||A.data[ii-1]<6){toss(
     A.name,'[',ptr,'] not a string','open temp file');}
   const u=new Uint8Array(A.buffer,4*(ii-w),4*w);
   let i=0;while(i<4*w-4 && u[i]!=0){i++;}
   // we must have i>=6, u[i]=0, u[i-1]...u[i-6]=/X/, these are
   // replaced. If this is not the case, return 0
   if(u[i]!=0 || i<6 || u[i-1]!=tempArg || u[i-2]!=tempArg ||
      u[i-5]!=tempArg|| u[i-6]!=tempArg){
        file.errno=IOERR.ETEMP;return 0; }
   // replace them by random letters
   for(j=i-6;j<i;j++){u[j]=codeA+(Math.random()*26|0);}
   return a_openfile(file,writeArg,A,ptr,1);
}

//'a'close file+""f
function a_closefile(file){
   if(file.direction==0){file.errno=IOERR.ENOTOPENED;return;}
   const F=a_FD[file.fidx];
   file.errno=0;
   if(file.type==1){//charfile
      if(file.direction==1){ // reading
         F.openr--;file.direction=0;file.buffer=null;file.eof=0;
         return;
      }else{//writing
         if(F.type==2){// line buffered
           if(file.CollectLine!="")a_SendLineBuffer(F.channel,file.CollectLine);
           file.CollectLine="";
         }else{
           file.buffer=null;F.bufflen=file.fpos;F.buff=F.buff.transferToFixedLength(F.bufflen);
         }
         F.openw--;file.direction=0;F.ff=null;
         return;
      }
   } else {// datafile
      if(file.direction==1){//reading
        F.openr--;file.direction=0;file.buffer=null;file.eof=0;
        return;
      }else{//writing
        let ret=a_putdatap(file,-1,1);
        while(ret && (file.fpos&31)!=31){ret=a_putdatap(file,-1,1);}
        file.buffer[(file.fpos>>5)&31]=file.iflag;file.buffer=null;
        // detach from F.buff
        F.buff=F.buff.transferToFixedLength();F.changed=1;F.openw--;
        file.direction=0;F.ff=null;
        return;
      }
   }
}
//'a'set file pos+""f+>pos
function a_setfilepos(f,p){
   if(f.direction==0){f.errno=IOERR.ENOTOPENED;return;}
   const F=a_FD[f.fidx];
   if(f.direction!=1||F.type!=0){f.errno=IOERR.ESEEK;return;}
   if((p|=0)<0){f.errno=IOERR.ESEEK;return;}
   if(f.type==1){//charfile, reading
      f.errno=0;f.eof=0;f.nextpos=p;aChPos(F,f);
   }else{//datafile
      if(p==0){p=f.startpos;}
      if((p&1023)<32){f.errno=IOERR.ESEEK;return;}
      f.errno=0;
      if(p==f.fpos){return;}
      f.eof=0;
      if((p&~1023)!=(f.fpos & ~1023)){// read the block
          const offs=(p&~1023)*4;
          if(F.bufflen<offs+4096){f.errno=IOERR.ESEEK;return;}
          // when reading the next data it loads the block
          if((p&1023)==1023){f.fpos=p;return;}
          f.buffer=new Int32Array(F.buff,offs,1024);
      }
      f.fpos=p;f.iflag=f.buffer[(p>>5)&31]<<(p&31);
   }
}
//'a'unlink file+A[]+>ptrl; do not unlink RO files
function a_unlinkfile(A,ptr){
   const fname=a_Str(A,ptr);
   for(let i=0;i<a_FD.length;i++){
    if(fname==a_FD[i].path){
       const F=a_FD[i];
       if(F.openw>=0){F.path="/.Trash/"+fname;
         if(F.openw==0 && F.openr==0 && F.buff){F.buff=null;F.bufflen=0;}}
       return;
   }}
}
// when the program ends, close all files opened for writing
function a_closeAll(){
   a_FD.forEach((F)=>{
     if(F.openw>0 && F.ff){
      a_closefile(F.ff);}
   });
}

/* ************************************************************* */
// received an ArrayBuffer, populate the filesystem
//   replace then entry with the same path string
function addFile(fname,idx,ro,fbuff){
   let i=0,flen=fbuff.byteLength;
   for(;i<a_FD.length;i++){ if(fname==a_FD[i].path) break;}
   if(i==a_FD.length){a_FD.push({});}
   ro=ro?-1:0;
   Object.assign(a_FD[i],{
     path:fname,// filename with extension
     idx: idx,  // fObj index; -1 for URL based files
     openw:ro,	// -1 if cannot be opened for writing and cannot be deleted
     openr:0,   // no reading yet
     changed:0, // not changed
     type:0,    // ArrayBuffer 
     buff:fbuff,// the ArrayBuffer
     bufflen:flen,// specified length in bytes
     ff:null    //associated aleph FILE, always null
   });
}
// when the program ends, return files; skip URL and tmp files
// first return deleted files, after the rest;
// one can delete <f> and later create another <f>
function returnFiles(){
   a_FD.forEach((F)=>{
     if(F.type==0 && F.idx!=-1 && !F.tmpfile && F.path.startsWith('/.Trash/')){
        self.postMessage({cmd:'file',job:a_Job,idx:F.idx,filename:F.path,
               rm:'yes'});
   }});
   a_FD.forEach((F)=>{
     if(F.type==0 && F.idx!=-1 && !F.tmpfile && !F.path.startsWith('/.Trash/')){
        self.postMessage({cmd:'file',job:a_Job,idx:F.idx,changed:F.changed?1:0,
               filename:F.path,data:F.buff},[F.buff]);
   }});
}
/* ------------------------------------------------------------- */
// buffering the 'run' message until all files are loaded 
let waitingForFiles=0,startRunning=0;

function loadFile(fname,url){
   let xhr=new XMLHttpRequest();
   xhr.open('get',url,true);// true means async
   xhr.responseType='arraybuffer';
   waitingForFiles++;
   xhr.addEventListener('loadend',()=>{
     if(xhr.status!=200){self.postMessage({cmd:'error loading',url:url,status:xhr.status});}
     else{addFile(fname,-1,1,xhr.response);}
     waitingForFiles--; if(waitingForFiles<=0 && startRunning){runRoot();}
   },false);
   xhr.send();
}
// start program run after loading finishes
function runmsg(){
   if(waitingForFiles){startRunning=1;}
   else{runRoot();}
}
/* ************************************************************* */
// send the actual running stack 
function a_PrintStackFrame(){ // tr = {rule:idx,next:ptr}
   let tr=a_Tr(); let cnt=1;
   if(tr){
     self.postMessage({cmd:'stack',job:a_Job,count:0,data:'Rule stack'});
     while(tr){
       if(tr.rule>=0){ self.postMessage({cmd:"stack",job:a_Job,count:cnt,
          data:a_RuleNames[tr.rule]}); cnt++; }
       tr=tr.next;}}
}
// trace rule calls; can be extremely verbose.
function a_TraceRule(rn,n){
// a_Ruleames[rn] is rule name, n: number of arguments 
//   followed by n args
   let msg=a_RuleNames[rn];
   for(let i=0;i<n;i++){
      const v=arguments[i+2];
      msg += '+'+(typeof v=='object' ? v.name : v);
   }
   self.postMessage({cmd:"trace",job:a_Job,data:msg});
}
// when profiling enabled, statistics is sent
function dump_Profile(pf){
   if(!pf)return;
// sort profile, this is a bubble sort
   let doing=1,head={next:pf};
   while(doing){
     doing=0; let p=head,q=head.next,r;
     while(q && (r=q.next)){
       if(q.count<r.count){
          doing=1;p.next=r;q.next=r.next;r.next=q;p=r;}
       else{p=q;q=r;}
     }
   }
   pf=head.next;
   self.postMessage({cmd:'profile',job:a_Job,data:'Call counts',count:-1});
   while(pf){
      self.postMessage({cmd:"profile",job:a_Job,
        data:a_RuleNames[pf.rule],count:pf.count});
      pf=pf.next;
   }
}
// fatal runtime errors
function a_WaitLock(str){ // fatal error, cannot continue
// dead lock in waitFor, str is the module waiting for
   toss('Deadlock for module',str,"waitfor");
}
function a_AreaFailed(val,str){// fatal error
// str is a string with rule name, val is the offending value,
    toss('Classification failed in rule',str,'with value',val,'classification');
}
function a_exit(v){ // exit called
    a_Exv=v;
    toss('exit with value',v,"exit");
}
/* ************************************************************* */
// start the ALEPH program; takes care of errors
async function runRoot(){
    let ret=0;
    try{await a_ROOT();}
    catch(error){// exit or error
          if(error.cause=="exit"){// exit code is in a_Exv
            ret=1;
          } else {// error, probably from a toss()
            ret=2; a_Exv="Error: "+error.message+", type: "+error.cause;
          }
    }
    terminate(ret,a_Exv); // disable forthcoming 'kill' messages
}
// 0: terminated, 1: exit, 2: error, 3: kill; mm: message (number or string)
function terminate(ret,mm){
    a_closeAll();
    self.postMessage({cmd:'exit',job:a_Job,data:ret,msg:mm});
    if(ret!=0) a_PrintStackFrame();
    if(ret<=1) dump_Profile(a_PROFILE);
    returnFiles();
    self.postMessage({cmd:'terminated',job:a_Job});
    self.close();
}

/* received messages:
    init, job:nnn
    stdarg  ed.data is the array of runtime arguments

    stdin    input from stdin, file:FFF (as in the request)
              this request is listened to separately
    file     filename, idx, ro, ArrayBuffer filename, idx, url
    run      run the program
    kill     kill the running program (only if interactive and waiting)


sent messages:
  ready
  read,  file:FFF            read from channel FFF (stdin),
  write, file:FFF, data:str  write the channel FFF (stdout,stderr)

  file   filename:FFF,idx, data:ArrayBuffer return a file when finished
  file   filename:FFF,idx,rm:'yes' (idx==-2 for a new file)
  stack  count:n,data:'rulename'
  trace  data:'rule+a1+a2'  tracerule messages, can be huge
  profile  data:'rule',count:nnn  profile information at the end

  exit   data:0/1/2/3,mgs:'error or kill'
  terminated                last message before closing

*/

function DM(...args){
  self.postMessage({cmd:'DM',msg:args.join(',')});
}

self.addEventListener("message",(e)=>{
   const ed=e.data;
   if(ed.cmd=='init'){ // first message, store job number
       a_Job=ed.job;
       self.postMessage({cmd:'ready',job:a_Job});
   }else if(ed.cmd=="stdarg"){// store stdarg array
       a_StdargArray=ed.data;
   }else if(ed.cmd=="file"){// populate the filesystem
       if(ed.url){loadFile(ed.filename,ed.url);}
       else{addFile(ed.filename,ed.idx,ed.ro,ed.data);}
   }else if(ed.cmd=="run"){  runmsg();
   }else if(ed.cmd=='kill'){ terminate(3,'program killed');
   }else if(ed.cmd!='stdin'){// stdin is handled
       self.postMessage({cmd:'unknown cmd received',msg:ed.cmd}); }
});


/* ************************************************************* */

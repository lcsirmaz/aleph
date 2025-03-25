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

/* Console routines: resizeable text areas for standard streams 
   (stdin, stdout, stderr). Outputs are read only, scrolled down
   to the last written line; chopping the total number of written
   lines between HighWater and LowWater. The input is a single
   line with a history of previous ccBufLen entered lines. Input
   ends by hitting Enter, ctrl+C or ctrl+D when the supplied
   ballback function is called. New read requests interrupt the
   current one (when an Aleph program reads from <<stdin>>), and
   resumes editing. Stdin also provides a 'prompt' field

   It provides a single object aCle with the following three fields:

aCle.print(tg,text,nl=1)
   tg     target 1-stdout, 2-stderr
   text   the string to be printed, split at \r?\n
   nl     if zero, then no newline at the end (next line will continue)

aCle.read(prompt,fg,opt)
   prompt text above the input line
   fg()   callback function, called as fg(str,tp) where str is the
          entered string, and tp=0,1,2 for Enter, ^D, ^C. With ^C
          str is cleared; ^D signals EOF
   opt{}  structure with the following fields:
      bg: "#eee" background color; default 'field'
      s:  0: don't show, 1: ^C and non-empty lines, 2: all lines; default 0
      p:  lines are preceded by it
      x:  low profile request, remember the line in history

aCle.font(size)
   set font size; meaningful values are 0.6 -- 1.2 

It expects the following structure:
  <div class="console-wrap">
    <div class="console-inner" style="width:40em;height:40em;">
      <textarea id="con-stderr" readonly></textarea>
      <textarea id="con-stdout" readonly></textarea>
      <div class="con-impt">
       <span id="con-prompt">aleph</span>
       <textarea id="con-stdin" rows="1" disabled></textarea>
      </div>
    </div>
    ... additional matrial below the resizable console part ...  
  </div>

*/

var aCle = function(doc){
   // HighWater: when reaching that many lines in stdout or stderr
   //    linies are chopped to LowWater
   // ccBufLen: number of lines remembered in ccBuffer
   const HighWater=750,LowWater=550,ccBufLen=50;
   // channels, 0,1,2 for aCle.print()
   const CHS=[null,                   // stdin
              {lines:1,eol:1,D:null}, // stdout
              {lines:1,eol:1,D:null}  // stderr
             ];
   // iD=con-stdin; iPmt=con-prompt, filled by aCle.init()
   let iD=null,iPmt=null;
   // initialize the routines; wait until page loads
   function gE(id){return doc.getElementById('con-'+id);}
   function initConsole(){
      CHS[1].D=gE('stdout');
      CHS[2].D=gE('stderr');
      iD=gE('stdin');
      iD.addEventListener("keydown",handleKey);
      iPmt=gE('prompt');
    }
   function showBottom(ta){ta.scrollTop=ta.scrollHeight;}
   function printto(target,txt,ctrlnl=1){
   // target: 1--stdout 2--stderr, txt: a string, ctrlnl: add newline at the end
      const ch=CHS[target];let addstr='',addnl=ch.eol,cnt=-addnl;
      txt.split(/\r?\n/).forEach((x)=>{addstr += (addnl?x:'\n'+x);addnl=0;cnt++;});
      // cnt: number of lines added; addstr: the new string to be added
      ch.eol=ctrlnl?0:1;
      if(cnt+ch.lines>HighWater){ // chop the oldest lines
         ch.D.value=(ch.D.value+addstr).split('\n').slice(-LowWater).join('\n');
         ch.lines=LowWater;
      }else{
         ch.D.value += addstr;
         ch.lines+=cnt;
      }
      showBottom(ch.D);
   }
   // circular buffer for command line history
   const ccBuffer=new Array(ccBufLen).fill(""); // circular buffer
   let ccBufPtr=0,ccBufCirc=-1,ccLastLine="";   // save the last partial line
   function ccDown(){ // down, next content
      if(ccBufCirc==ccBufPtr){ccBufBirc=-1; return ccLastLine;}
      if(ccBufCirc>=0){
        ccBufCirc=(ccBufCirc+1)%ccBufLen; return ccBuffer[ccBufCirc];
      }
      return null; // cannot go down
   }
   function ccUp(line){ // up, previous content
      if(ccBufCirc<0){ccBufCirc=ccBufPtr;ccLastLine=line}
      else{const nc=(ccBufCirc+ccBufLen-1)%ccBufLen;
           if(nc!=ccBufPtr && ccBuffer[nc])ccBufCirc=nc;}
      return ccBuffer[ccBufCirc];
   }
   function ccSet(line,r){ // remember the line
      ccBufCirc=-1;if(!line || !r)return; // empty line
      if(ccBuffer[ccBufPtr]==line)return; // same as before
      ccBufPtr=(ccBufPtr+1)%ccBufLen;
      ccBuffer[ccBufPtr]=line;
   }
   function handleKey(e){
      const key=e.key;
      if(key=='ArrowDown'||key=='Down'){
         killEvent(e);
         const nl=ccDown(); if(nl!=null){iD.value=nl;}
      }else if(key=='ArrowUp' || key=='Up'){
         killEvent(e);
         iD.value=ccUp(iD.value);
      }else if(key=='Enter'){
         killEvent(e);sendLine(0);
      }else if(e.ctrlKey && key=='c'){ // ctrl+C
         killEvent(e);iD.value="";sendLine(2);
      }else if(e.ctrlKey && key=='d'){ // ctrl+D
         killEvent(e);sendLine(1);
      }else{ ccBufCirc=-1;}
   }
   // we store all pending input requests in PendingInput[]. When a new one
   // comes in, it is pushed to the top; when reading finished, the old
   // one is restored
   function sanitize(str){
      return str.replaceAll('&','&#38;')
               ?.replaceAll('<','&lt;')
               ?.replaceAll('>','&gt;');}
   function killEvent(e){e.cancelBubble=true;e.preventDefault();}
   const PendingInput=[];
   // PI={prompt:""   the prompt above the input line
   //     f:     f()  callback function with string and type
   //     bg:    ""   background color of the textarea
   //     str:   ""   content to be restored
   //     pos:   0    editing position
   //     sh:    0    show the result in stdout
   //     px:    ""   prefix of the result in stdout
   //     r:          store the line in the History
   //    }
   function sendLine(how){ // 0: Enter, 1: ^D, 2: ^C
      const str=iD.value,PI=PendingInput.pop(),il=-1+PendingInput.length;
      ccSet(str,PI.r);
      if(!PI) return;
      if(il<0){
         iD.style.background='field';
         iD.setAttribute('disabled',1);
         iPmt.innerHTML='';
      } else {
         iPmt.innerHTML=PendingInput[il].prompt;
         iD.style.background=PendingInput[il].bg;
      }
      // showing in stdout
      if(PI.sh>1||(PI.sh>0&&(how==2||str!=''))){
        printto(1,PI.px,0);printto(1,str,0);
        printto(1,how>1?'^C':how?'^D':'',1);
      }
      iD.value=PI.str;iD.setSelectionRange(PI.pos,PI.pos);
      iD.focus();PI.f(str,how);
   }
   // if opt.x wait until the queue is empty
   function readfrom(pmt,fg,opt){
      const newpmt=sanitize(pmt),PI={
        prompt:newpmt,
        f:     fg,
        bg:    opt.bg||'field',
        str:   '',
        sh:    opt.s||0,
        px:    opt.p||'',
        r:     opt.x||0,
        pos:   0};
      if(PendingInput.length>0){
        if(opt.x){PendingInput.unshift(PI);return;}
        PI.str=iD.value;
        PI.pos=iD.selectionStart;
      }
      PendingInput.push(PI);iD.value='';
      iD.style.background=PI.bg;iPmt.innerHTML=newpmt;
      iD.removeAttribute('disabled');iD.focus();
   }
   function setfontsize(x){
      doc.querySelector(':root').style.setProperty('--con-fontsize',x+'em');
   }
   // call initialization after the page loaded
   if (doc.readyState === "loading") { // Loading hasn't finished yet
      doc.addEventListener("DOMContentLoaded",initConsole);
   } else { // `DOMContentLoaded` has already fired
      initConsole();
   }
   // exported interface
   return {print:printto,read:readfrom,font:setfontsize};
}(document);

/* EOF */

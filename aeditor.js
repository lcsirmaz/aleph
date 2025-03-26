/***************************************************************
$  This code is part of ALEPH-M (Modular ALEPH-v2.2)
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

/* ALEPH text editor with syntax hightlighting.

Multiple resizable and movable editor windows. Each window
is associated with a fileObj with the following fields:

  name     string, the file name
  type     string, indicating file type, one of "ale","ice","js","txt"
  buffer   an ArrayBuffer containing the UTF-8 encoded text
  writing  editor DOM which opened this file for writing
  changed  set to 1 when there are unsaved changes
  savef    a callback function; called after handling "Save"
  
Each editor window has <save>, <reset> and <close> buttons at the top,
The first one saves the content, the second re-reads the old content
discarding all changes, the third one closes the window. Next to file
name a * shows whether the content has unsaved changes. For read-only
editors there are no <save> and <reset> buttons, and all textarea are
readonly. Editor windows can be moved around by grabbing at the
filename area, and can be resized.

AE.createEditor(fileObj,jobno,readonly=0)
   creates a new editor window and presents the file content. If neither
   "readonly" nor "fileObj.writing" is set, opened for writing, otherwise RO.
   Returns the DOM gw which remembers the jobno
AE.setSave(fObj,how)
   enables (how=true) or disables (how=false) the save and reload buttons when
   opened for editing.
AE.closeEditor(gw)
   closes the editor associated with this DOM (returnd by createEditor)
AE.setTabwidth(count) (global)
   global value; set tab width when creating and editing; tab chars
   are replaced by spaces, and no tab chars are written back. The
   default value is 8.
AE.setFont(size)
   changes the used font size for all editors (global)
---------------------------------------------------------------------

The overall DOM structure for all editor windows is the following:
  <div id="AEDITORS">
    <div style="position:absolute;"> **first windows** </div>
    <div style="position:absolute;"> **second window ** </div>
    <div style="position:absolute."> **third window ** </div>
  </div>

The #AEDITORS element is created and inserted at the beginning of the body
if not found. Each editor window is structured as

  <div class="container" id="id" style="position:fixed;z-index:1;top:0px;left:0px">
    <div class="gutter-wrapper">
      <div class="aetitle"> top line</div>
      <div class="double-line"> first line </div>
      <div class="double-line"> second line </div>
      ...
      <div class="double-line"> last line </div>
    </div>
    <dialog class="aeyesno"> ... </dialog>
  </div>

Each .container has z-index: from 1 upwards, the actual one 128. Clicking inside
an editor window changes the z-indices. For more than 126 windows it breaks.

The editor top line has buttons and title:
     [save]  ...  file-title  ...    [reset] [close]

using the <file-title> area the window can be moved around. For RO files the
[save] and [reset] buttons are missing.

The .double-line editor lines have three elements: linenumber, pre, and textarea:
   <div class="linenumber">12</div>
   <pre><code>highlighted content</code></pre>
   <textarea rows="1">editable content</textarea>

The <pre> and <textarea> elements mirror the same content on top of each
other with <textarea> on the top, transparent, except for the pointer. Data in
<pre> is formatted using <span>...</span> elements for syntax highlighting.
The method based partially on ideas from: https://github.com/speed-highlight

*/


var AE=function(document){
  "use strict";
 // helper functions
 const cE=(t)=>{return document.createElement(t);};
 const nD=(cl)=>{const n=cE("div");n.className=cl;return n;};
 const tA=(n)=>{// cloned textarea, these should be added by hand
   n.addEventListener("input",function(){updateTo(this,this.value);});
   n.addEventListener("keydown",keyhit);
 };
 const ROOT=(force)=>{// find the root, if not found, create
    let n=document.getElementById('AEDITORS');
    if(n || !force) return n;
    n=cE('div');n.id='AEDITORS';
    document.body.prepend(n);
    return n;
 };
 function removeEditor(gw){ // we are closing the editor gw
   const fo=gw.fileObj;gw.fileObj=null;
   if(!gw.ro){
      if(fo.writing!==gw){console.log("closing: should be ===",gw,fo.writing);}
      fo.writing=null; fo.changed=0;
   }
   JOB.del(gw.jobno); // delete the associated job
   let ed=gw.parentElement.parentElement;
   ed.parentElement.removeChild(ed);
 }
 function newEditor(){// start a new editor
   let n=ROOT(1);// get editor root node
   n=n.appendChild(cE('div'));
   n.style.position='absolute';
   n=n.appendChild(nD('container'));
   n.style.top='0px';n.style.left='0px';n.style['z-index']=1;
   raiseToTop(n); // rearrange z-index values
   return n;
 }
 // add the text to the specified and subsequent lines.
 // replace tab characters with spaces; renumber lines
 function updateTo(node,txt){
   // node is a <textarea>, nn is the <code> below it;
   // dl is the enclosing "double-line" div
   // gw is the "gutter-wrapper" div
   // ndl is the next "double-line" or null if dl is the last
   const nn=node.previousElementSibling.firstElementChild,
         dl=node.parentElement,
         gw=dl.parentElement;
   if(txt.indexOf('\n')!=-1){
     node.value='';nn.innterHTML='';
     const lines=txt.split(/\r?\n/);txt=lines[0];
     const ndl=dl.nextElementSibling;
     for(let i=1;i<lines.length;i++){
       const newn=dl.cloneNode(true);
       const n=newn.querySelector("textarea");
       tA(n);gw.insertBefore(newn,ndl);updateTo(n,lines[i]);
       if(i==1){n.focus();n.setSelectionRange(0,0);}
     }
     renumber(dl.parentElement);
   }
   nn.innerHTML=tokenize(node.getAttribute("asyntax"),node.value=retab(txt));
   gw.aechanged=1;if(gw.fileObj){ gw.fileObj.changed=1;}
   gw.querySelector(".aechanged").style.visibility='visible';
 }
//return a string generated from the UTF-8 encoded buffer
 function decodeBuffer(fObj){
    const buff=fObj.buffer;
    if(!buff || buff.byteLength==0) return ''; // empty string
    return new TextDecoder().decode(buff);
 }
 // save, reload, quit; if the dialog say "yes" call function f
 function askyn(gw,f){//
   const dg=gw.parentElement.querySelector("dialog");
   dg.callfunc=(g)=>{f(g);};// this function will be called
   dg.showModal(); // show the dialog
 }
 function refreshWindow(gw){// refresh the file view
   if(gw.ro) return;
   let dl=null;
   gw.querySelectorAll(".double-line").forEach((n)=>{
   if(!dl){dl=n;} else {gw.removeChild(n);}});
   updateTo(gw.querySelector("textarea"),decodeBuffer(gw.fileObj));
   gw.querySelector('.aechanged').style.visibility='hidden';
   gw.aechanged=0; gw.fileObj.changed=0; // updateTo sets it to 1
 }
 function reloadFile(gw){ //reload button, or refresh request
    if(gw.ro){console.log("read only reload");return;}
    if(!gw.aechanged) return;
    askyn(gw,(gw)=>{refreshWindow(gw);});
 }
 function saveFile(gw){ // save button
    if(gw.ro){console.log("read only save");return;}
    if(!gw.aechanged) return;
    let str=""; // collect the complete text to this string
    gw.querySelectorAll("textarea").forEach((n)=>
         {if(str!="")str+="\n";str+=n.value;});
    const buff=new ArrayBuffer(3*str.length);
    const written=new TextEncoder().encodeInto(str,new Uint8Array(buff)).written;
    const fo=gw.fileObj;
    fo.buffer=buff.transferToFixedLength(written);
    if(!fo.savef(fo)){
      gw.querySelector(".aechanged").style.visibility='hidden';
      gw.aechanged=0;fo.changed=0;
    }
 }
 function closeFile(gw){ // close button
    if(gw.aechanged){// file changed, ask to proceed
       askyn(gw,(gw)=>{removeEditor(gw);});
    } else {
       removeEditor(gw);
    }
 }
 function raiseToTop(node){ // .container, set its z-index to 2
   if(node.style['z-index']==128) return;
   let zidx=[];
   ROOT(0).querySelectorAll('.container').forEach((n)=>{
      if(n!=node)zidx[parseInt(n.style['z-index'])]=n;});
   let v=1;
   zidx.forEach((n)=>{n.style['z-index']=v;v++;});
   node.style['z-index']=128;
 }
 function focusOnLastLine(gw){// clicked on an empty place, focus on last line
   if(gw.clientHeight==gw.scrollHeight)gw.lastElementChild.querySelector('textarea').focus();
 }
 var _={
   tw: 8, // tab width to apply
   /* createEditor(fileObj,readonly) 
    *  fileObj object with the following fields:
    *     name    the file name, shown at the top line
    *     type    the file type, one of "ale", "ice","js","txt"
    *     buffer  an ArrayBuffer containing the UTF-8 encoded content
    *     changed set to 1 if edited but not saved, 0 otherwise
    *     savef   callback function after saving; called as f(fileObj);
    *             it returns 1 on error when storing the buffer
   */
   createEditor: function(fileObj,jobno,readonly=0){
       const syntax=fileObj.type=="ale"?0:
                    fileObj.type=="ice"?1:
                    fileObj.type=="js"?2:9;
       // create the DOM structure with a single <textarea> line
       // top: .container <div> with z-index, moving around
       // gw:  .gutter-wrapper <div>
       // aet: .aetitle <div>, top editor line
       // gw.fileObj, gw.aechanged, gw.ro, gw.jobno
       const top=newEditor(),gw=top.appendChild(nD("gutter-wrapper")),
             aet=gw.appendChild(nD("aetitle"));
       const ro=fileObj.writing ? 1 : readonly;// read only attrib
       if(!ro){fileObj.writing=gw;gw.fileObj=fileObj;}
       gw.aechanged=0;gw.ro=ro;gw.jobno=jobno;
       gw.addEventListener("click",(e)=>{if(e.target==gw)focusOnLastLine(gw);raiseToTop(e.currentTarget.parentElement);});
       // aet is the editor's top line;
       // [save]  ...title...  [reload] [close]
       // the ...title.. part moves the window around
       const grabtxt='<span class="aefile" title="move the editor around">'+sanitize(fileObj.name)+
                      '<span class="aechanged">*</span></span>';
       const closebt='<button type="button" class="aeclose">close</button></span>';
       if(ro){// [] ...title... [close]
         aet.innerHTML=
          '<span class="aesave"></span>'+grabtxt+
          '<span class="aequit">'+closebt;
       } else {// [save] ...title... [reset][close]
          aet.innerHTML=
          '<span class="aesave"><button type="button">save</button></span>'+grabtxt+
          '<span class="aequit"><button type="button" class="aereset">reset</button> '+closebt;
          aet.querySelector(".aereset").addEventListener("click",(e)=>{reloadFile(gw);});
          aet.querySelector(".aesave button").addEventListener("click",(e)=>{saveFile(gw);});
       }
       aet.querySelector(".aeclose").addEventListener("click",(e)=>{closeFile(gw);});
       // moving the editor window around
       aet.querySelector(".aefile").addEventListener("mousedown",(e)=>{
          e.preventDefault();e.stopPropagation();
          const tg=e.currentTarget; // this is the aet
          tg.style.cursor='grabbing';
          raiseToTop(top);
          // this is to prevent the windows from resizing when it hits the
          // right margin
          if(!gw.style.width)gw.style.width=gw.offsetWidth+'px';
          let offx=e.clientX-parseInt(top.style.left||'0px'),
              offy=e.clientY-parseInt(top.style.top||'0px');
          document.onmouseup=function(e){
             e.preventDefault();
             document.onmouseup=null;document.onmousemove=null;
             tg.style.cursor='grab'; };
          document.onmousemove=function(e){
            // don't move the window out of the visible area
            if(e.clientX<15||e.clientY<15||
               e.clientX>document.documentElement.clientWidth-15) return;
            e.preventDefault();e.stopPropagation();
            top.style.top=e.clientY-offy+'px';
            top.style.left=e.clientX-offx+'px';
          };
         });
       // a single editor line which is to be cloned
       const dl=gw.appendChild(nD("double-line"));
       dl.appendChild(nD("linenumber"));
       const pre=cE("pre");pre.appendChild(cE("code"));
       dl.appendChild(pre);
       const n=dl.appendChild(cE("textarea"));
       n.value="";n.setAttribute("rows",1);
       n.setAttribute("autocomplete","off");
       n.setAttribute("spellcheck","false");
       n.setAttribute("autocorrect","off");
       n.setAttribute("autocapitalize","off");
       n.setAttribute("translate","no");
       n.setAttribute("asyntax",syntax);tA(n);
       if(ro){n.setAttribute("readonly","readonly");}
       // fill the content ..
       updateTo(n,decodeBuffer(fileObj));
       renumber(dl);//linenumber for the first line with one line content
       // clear the changed flag
       gw.querySelector(".aechanged").style.visibility='hidden';
       gw.aechanged=0; if(!ro)fileObj.changed=0;
       // finally create the dialog box as
       // <dialog class="aeyesno"><p> text </p>
       //   <div><button no> <span></span> <button yes> </div>
       // </dialog>
       const dg=cE("dialog");dg.className="aeyesno";dg.innerHTML=
        '<p>file changed, proceed?</p><div style="display:grid;grid-template-columns:auto 1fr auto;"><button type="button">Cancel</button><span> </span><button type="button">OK</button></div>';
       // the buttons close the dialog; when the dialog closes, calls a function
       let i=0;dg.querySelectorAll("button").forEach((b)=>{
          b.addEventListener("click",i==0 ? (e)=>{e.preventDefault();dg.close("no");}
                                          : (e)=>{e.preventDefault();dg.close("yes");});
          i=1;});
       dg.addEventListener('close',(e)=>{
         dg.returnValue=='yes'&& dg.callfunc && dg.callfunc(gw);});
       top.appendChild(dg);
       // no clicking as the command line steals the focus()
       return gw;
   },
   /* enable or disable the Save and Refresh buttons or an editing window */
   setSave: function(fObj,how){// how=false: disable, true: enable
      let gw=fObj.writing; if(!gw)return;
      if(how){
        gw.querySelector(".aereset").disabled=false;
        gw.querySelector(".aesave button").disabled=false;
      } else {
        gw.querySelector(".aereset").disabled=true;
        gw.querySelector(".aesave button").disabled=true;
      }
   },
   /* close an editing instance without asking */
   closeEditor: function(gw){removeEditor(gw);},
   /* setTabwidth(n) sets globally the tabstop positions */
   setTabwidth: function(n){if(n>0){_.tw=n;}},
   /* setFont(size) change font size globally */
   setFont: function(x){
     document.querySelector(':root').style.setProperty('--edit-fontsize',x+'em');
   }
 };
 // adding line numbers
 const renumber=function(node){
   let cnt=1;
   node.querySelectorAll(".linenumber").forEach((n)=>{n.innerHTML=cnt;cnt++;});
 };
 // replace tabs by spaces, use the fixed _.tw value; txt is a single line
 const retab=function(txt){
   if(txt.indexOf('\t')===-1)return txt;
   let pos=0;let res="";
   for(const c of txt){
     if(c!='\t'){pos++;res+=c;}
     else do{pos++;res+=' ';}while(pos%_.tw!=0);}
   return res;
 };
 // key handling: up, down arrows, Backspace and Delete
 // up, down goes to the previous/next line at the same position
 // Backspace and Delete at the beginning / end join the line
 const killkey=function(e){e.preventDefault();e.stopPropagation();};
 const keyhit=function(e){
   const key=e.key,node=e.target;if(node.type!='textarea')return;
   if(key=='ArrowDown' || key=='Down'){
      killkey(e);
      const next=node.parentElement.nextElementSibling?.querySelector("textarea");
      if(next){
        const pos=node.selectionStart;
        next.focus();next.setSelectionRange(pos,pos);
      }
   } else if(key=='ArrowUp'|| key=='Up'){
      killkey(e);
      const prev=node.parentElement.previousElementSibling?.querySelector('textarea');
      if(prev){
        const pos=node.selectionStart;
        prev.focus();prev.setSelectionRange(pos,pos);
      }
   } else if(key=='Backspace'){
      if(node.selectionEnd!=0)return;
      killkey(e);
      const dl=node.parentElement,
       prev=dl.previousElementSibling?.querySelector('textarea');
      if(!prev)return;
      const top=dl.parentElement;
      const pos=prev.value.length;
      const txt=prev.value+node.value;
      updateTo(prev,txt);node.parentElement.remove();
      prev.focus();prev.setSelectionRange(pos,pos);
      renumber(top);
   } else if(key=='Delete' || e.keyCode==46){
      if(node.selectionStart<node.value.length) return;
      killkey(e);
      const dl=node.parentElement,next=dl.nextElementSibling;
      if(!next)return;
      const pos=node.value.length;
      const txt=node.value+next.querySelector('textarea').value;
      next.remove();updateTo(node,txt);
      node.setSelectionRange(pos,pos);
      renumber(dl.parentElement);
   }
 };
 // syntax highlighter: aleph, ice, javascript
 // ideas from: https://github.com/speed-highlight
 const asyntax = [
  [ // aleph syntax highlighter; executed in reverse order, index 0
  { type: "err", // error
    match: /"[^"]*$/g},
  { type: "comm",// comment 
    match: /#\s*[a-zA-Z][a-zA-Z0-9\s]*/g},
  { type: "kwd", // keyword
    match: /'(?:a|act|action|charfile|cons|constant|datafile|e|end|exit|external|f|func|function|p|pragmat|pred|predicate|q|que|question|root|stack|static|table|var|variable|x)'/g},
  { type: "err",
    match: /'[a-z]*'?/g,
    redo: 1},
  { type: "num",  // number
    match: /-?(?:[1-9]\d*|0[xX][0-9a-fA-F]+|0\d*)/g},
  { type: "idr",
    match: /[a-zA-Z][\sa-zA-Z0-9]*/g},
  { type: "num",
    match: /\/.\//g},
  { type: "lim",  // limit
    match: /<<(?![<>])|<>(?!>)|>>(?!>)/g},
  { type: "opt",  // operator
    match: /=|!=|<=|>=|<(?=[<>][<>])|<(?![<>])|>(?=>>)|>(?!>)/g},
  { type: "arr",  // arrow
    match: /->/g},
  { type: "comm", redo: 1, // these must go to the end; we start with these
    match: /\$[^\$]*(?:\$|$)/g},
  { type: "str", redo: 1, // string, $..."...$ is not a string
    match:/"[^"]*"/g},
 ],
 [ // ice file syntax highlighter, index 1
  { type:  "comm",
    match: /^\$.*$/g},
  { type:  "num",
    match: /X-?[0-9]+/g},
  { type:  "kwd",
    match: /'[a-z]+'/g},
  { type:  "str",
    match: /T?"[^"]*"/g},
  { type:  "typ",
    match: /<[a-z][a-z\s]*[a-z]>/g},
  { type:  "idx",
    match: /I[0-9]+/g},
 ],
 [ // javascript syntax highlighter, index 2
  { type: "comm",
    match: /\/\*.*?(?:\*\/|$)/g},
  { type: "comm",
    match: /\/\/.*$/g},
  { type: "num",
    match: /(\.e?|\b)\d(e-|[\d.oxa-fA-F_])*(\.|\b)/g},
  { type: "str",
    match: /(["'])(\\[^]|(?!\1)[^\r\n\\])*\1?/g},
  { type: "kwd",
    match: /=>|\b(this|set|get|as|async|await|break|case|catch|class|const|constructor|continue|debugger|default|delete|do|else|enum|export|extends|finally|for|from|function|if|implements|import|in|instanceof|interface|let|var|of|new|package|private|protected|public|return|static|super|switch|throw|throws|try|typeof|void|while|with|yield)\b/g},
  { type: "num",
    match: /\b(NaN|null|undefined|[A-Z][A-Z_]*)\b/g},
  { type: "func",
    match: /[a-zA-Z$_][\w$_]*(?=\s*((\?\.)?\s*\(|=\s*(\(?[\w,{}\[\])]+\)? =>|function\b)))/g},
 ]
 ];
 function sanitize(str){
  return str.replaceAll('&', '&#38;')?.replaceAll('<', '&lt;')?.replaceAll('>', '&gt;');
 }
 function toSpan(str, token){
  str=sanitize(str);
  return token ? `<span class="snx-${token}">${str}</span>` : str;}
 function tokenize(sytx,src) {
    if(sytx>=3)return sanitize(src);// no hightlighting
    let m,part,first = {},match,cache = [],i = 0,
    // make a fast shallow
    arr = [...asyntax[sytx]];
    let result="";
    while (i < src.length) {
      first.index = null;
      for (m = arr.length; m-- > 0;) { // going backward
        part = arr[m];
        // do not call again except if the previous result is sufficient
        if (cache[m] === undefined || cache[m].match.index < i || m.redo) {
           part.match.lastIndex = i;
           match = part.match.exec(src);
           if (match === null) {
             // no more match with this regex, can be disposed
             arr.splice(m, 1);
             cache.splice(m, 1);
             continue;
           }
           // save match for later use
           cache[m] = { match, lastIndex: part.match.lastIndex };
	}
	// check if it the first match in the string
	if (cache[m].match[0] && (cache[m].match.index <= first.index || first.index === null))
	  first = {
		part: part,
		index: cache[m].match.index,
		match: cache[m].match[0],
		end: cache[m].lastIndex
  	  };
	}
      if (first.index === null) break; // no more to highligh
      result +=toSpan(src.slice(i, first.index),null);
      i = first.end;
      result +=toSpan(first.match, first.part.type);
    }
    result +=toSpan(src.slice(i, src.length), null);
    return result;
 }

 return _;
}(document);

/* EOF */

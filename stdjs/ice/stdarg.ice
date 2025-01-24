$ ICE file, produced by ALEPH compiler v2.2
'module' "stdlib" "jslib stdarg" 32 
4 48 "stdarg"
49 129 "stdlib"
.
<rule> I1 16640 45 0 "stdlib" "@root"
<table> I2 20 43 1 1 "stdlib" "STDARG"
.
'front'"function a_SetupStdArg(a){%n a.vlwb=a_VirtualMax+16;a.alwb=a.vlwb+a.calibre;%n a.vupb=a_VirtualMax+65536;a.aupb=a.vlwb;a.offs=-a.aupb-1;%n for(let i=a_StdargArray.length-1;i>=0;i--){%n  const s=[];%n  for(const c of a_StdargArray[i]) s.push(c.codePointAt(0));%n  a_PushString(a,s.length,(x)=>{return s[x]});%n a_VirtualMax=a.chomp()+16;%n}".
'external'I2 "a_SetupStdArg".
'rule'I1 0 0 0.

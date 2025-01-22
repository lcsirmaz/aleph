$ ICE file, produced by ALEPH compiler v2.2
'module' "stdlib" "jslib waitfor" 32 
4 47 "aleph-stdwait"
48 128 "stdlib"
.
<rule> I1 16640 44 0 "stdlib" "@root"
<rule> I2 276 32 2<formal table> 1 1<formal in> "stdlib" "waitfor"
.
'front'"a_cmpToStr(A,idx,str){%n const ai=A.offs+idx;const n=A.data[ai-1];%n if(n!=str.length){return 0;} const ui=ai-A.data[ai]+1;const u=new Uint8Array(A.buffer,ui*4,n*4); for(let i=0;i++;i<n){  if(u[i]!=str[i])return 0;} return 1;}".
'external'I2 "@@waitfor".
'rule'I1 0 0 0.

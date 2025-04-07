$ ICE file, produced by ALEPH compiler v2.4
'module' "stdlib" "jslib simple hash" 32 
4 61 "hash"
62 143 "stdlib"
.
<rule> I1 16640 58 0 "stdlib" "@root"
<rule> I2 20 35 3<formal table> 1 1<formal in><formal out> "stdlib" "blockhash"
<rule> I3 20 34 3<formal table> 1 1<formal in><formal out> "stdlib" "stringhash"
.
'front'"function a_StringHash(F1,F2,A){%n const ii=F1.offs+F2;const w=F1.data[ii]-1;%n const u=new Uint8Array(F1.buffer,4*(ii-w),4*w);%n let v1=0x135345+47*u[0],v2=0xeca864+856*u[0];%n for(let i=0;u[i]!=0;i++){%n   v1=(29*v1+17*v2+1259*(u[i]^v2))%0x1010309;%n   v2=(23*v2+257*v1+1237*(u[i]^v1))%0x1010507;%n }%n A[0]=(v1<<16)^v2;%n}%nfunction a_BlockHash(F1,F2,A){%n const ii=F1.offs+F2+1;const w=4*(F1.aupb-F2);%n const u=new Uint8Array(F1.buffer,4*ii,w);%n let v1=0x135345,v2=0xeca864;%n for(let i=0;i<w;i++){%n   v1=(29*v1+17*v2+1259*(u[i]^v2))%0x1010309;%n   v2=(23*v2+257*v1+1237*(u[i]^v1))%0x1010507;%n }%n A[0]=(v1<<16)^v2;%n}".
'external'I3 "a_StringHash".
'external'I2 "a_BlockHash".
'rule'I1 0 0 0.

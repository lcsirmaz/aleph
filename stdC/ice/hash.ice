$ ICE file, produced by ALEPH compiler v2.2
'module' "stdlib" "stdlib stdhash" 32 
4 66 "hash"
67 147 "stdlib"
.
<rule> I1 16640 63 0 "stdlib" "@root"
<rule> I2 20 35 3<formal table> 1 1<formal in><formal out> "stdlib" "blockhash"
<rule> I3 20 34 3<formal table> 1 1<formal in><formal out> "stdlib" "stringhash"
.
'back'"static void a_stringhash(int F1,int F2,int A[1]){ int *ptr=to_LIST(F1)->offset+F2; unsigned char *v=(unsigned char*)&ptr[1-ptr[0]]; unsigned v1=0x135345+47u*(*v), v2=0xeca864+856u*(*v); while(*v){  v1=(29*v1+17*v2+1259u*(((unsigned)*v)^v2)) % 0x1010309;  v2=(23*v2+257*v1+1237u*(((unsigned)*v)^v1)) % 0x1010507;  v++; } A[0]=(int)((v1<<16)^v2);}%nvoid a_blockhash(int F1,int F2,int A[1]){ unsigned char *v=(unsigned char*)(to_LIST(F1)->offset+F2+1); unsigned v1=0x135345+47u*(*v), v2=0xeca864+856u*(*v); int cnt=sizeof(int)*(to_LIST(F1)->aupb-F2); for(;cnt>0;cnt--){  v1=(29*v1+17*v2+1259u*(((unsigned)*v)^v2)) % 0x1010309;  v2=(23*v2+257*v1+1237u*(((unsigned)*v)^v1)) % 0x1010507;  v++; } A[0]=(int)((v1<<16)^v2);}".
'front'"static void a_stringhash(int,int,int[1]);static void a_blockhash(int,int,int[1]);".
'external'I3 "a_stringhash".
'external'I2 "a_blockhash".
'rule'I1 0 0 0.

/* Stop an ADX stream and return its native current position. */
typedef unsigned char u8;typedef signed char s8;typedef int s32;typedef struct S3FCC S3FCC;
extern char gAdxDiagnostic_004BB378[],gAdxDiagnostic_004BB3A0[];
extern void func_003FB510(s32,s32,s32,s32,s32),func_003FB128(void*),func_00400740(s8*),func_003F9630(void),func_003F9660(void),func_003FCC80(S3FCC*);extern s32 func_00400B58(s32*,s32*);
s32 func_003FD138(void*object){u8*p=(u8*)object;s32 size;
 func_003FB510(5,0,(s32)p,-1,-1);
 if(!p){func_003FB128(gAdxDiagnostic_004BB378);return -3;}
 if(*(s8*)(p+1)==1)return *(s32*)(p+0x14);
 if(*(s8*)(p+1)==3){p[1]=1;return *(s32*)(p+0x14);}
 if(!*(s32*)(p+4)){func_003FB128(gAdxDiagnostic_004BB3A0);return -1;}
 func_00400740((s8*)*(s32*)(p+4));func_003F9630();func_00400B58((s32*)*(s32*)(p+4),&size);*(s32*)(p+0x20)=size;func_003FCC80((S3FCC*)p);p[1]=1;func_003F9660();
 func_003FB510(5,1,(s32)p,-1,-1);return *(s32*)(p+0x14);
}

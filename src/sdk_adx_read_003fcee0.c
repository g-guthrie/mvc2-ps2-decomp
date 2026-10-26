/* Validate the native ADX read request and forward it to the existing reader. */
typedef unsigned char u8;typedef signed char s8;typedef int s32;typedef struct A {u8 p0[4];s32 w4;u8 p8[4];s32 wC;u8 p10[4];s32 w14; s32 w18,w1C,w20;u8 p24[8];s32 w2C,w30;} A;
extern char gAdxDiagnostic_004BB218[],gAdxDiagnostic_004BB240[],gAdxDiagnostic_004BB270[];
extern void func_003FB128(void*);extern s32 func_003FCDE0(A*,s32,s32);
s32 func_003FCEE0(void*object,s32 n,s32 x){
 A *p=(A*)object;
 if(!p){func_003FB128(gAdxDiagnostic_004BB218);return -3;}
 if(n<0){func_003FB128(gAdxDiagnostic_004BB240);return -3;}
 if(!x){func_003FB128(gAdxDiagnostic_004BB270);return -3;}
 {s32 result=0;if(((s8*)p)[1]==2)return result;result=func_003FCDE0(p,n,x);((u8*)p)[2]=1;return result;}
}

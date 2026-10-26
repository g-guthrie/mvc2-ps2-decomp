typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef float f32;
typedef struct {u8 p0[0x1C];s16 h1C;u8 pa[0x14];f32 f34,f38;u8 p1[0x20];f32 f5C,f60;u8 p2[4];f32 f68,f6C;u8 p3[0xE1];s8 b151;} PF;
extern void func_00214DD0(PF*);
void func_00214D60(u8*p) {
 ++p[6];*(s16*)(p+0x1C)=0;
 *(float*)(p+0x5C)=16.66666603088379f;*(float*)(p+0x68)=-0.4166666567325592f;
 *(float*)(p+0x60)=12.857142448425293f;*(float*)(p+0x6C)=-1.0714285373687744f;
 if(!p[0x1E6]) {*(float*)(p+0x5C)=-*(float*)(p+0x5C);*(float*)(p+0x68)=-*(float*)(p+0x68);}
 func_00214DD0((PF*)p);
}

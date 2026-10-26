typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern s16 D_00449FF0[][8],D_00449FF2[][8];
extern s32 D_00449FF4[][4],D_00449FF8[][4];
extern s8 D_00449FFC[][16];
extern void func_00197600(void);
extern int func_00417A40(void),func_00175580(u8*,int,int,int);
void func_001964A0(u8 *p,u8 *q) {
 ++p[5];
 if(p[0x21]<2) {
  float dx,vx;
  func_00197600();*(s16*)(p+0x140)=*(s16*)(q+0x140);
  *(float*)(p+0x34)=*(float*)(q+0x34);*(float*)(p+0x38)=*(float*)(q+0x38);
  dx=(5.0f/3.0f)*(float)(D_00449FF0[p[0x21]][0]*256)/256.0f;
  *(float*)(p+0x38)+=(15.0f/7.0f)*(float)(D_00449FF2[p[0x20]][0]*256)/256.0f;
  vx=(5.0f/3.0f)*(float)D_00449FF4[p[0x21]][0]/65536.0f;
  *(float*)(p+0x60)=(15.0f/7.0f)*(float)D_00449FF8[p[0x21]][0]/65536.0f;
  *(s8*)(p+0x31)=D_00449FFC[p[0x21]][0];
  if(*(s16*)(p+0x140)==0){dx=-dx;vx=-vx;}
  *(float*)(p+0x6C)=0;*(float*)(p+0x68)=0;*(float*)(p+0x34)+=dx;*(float*)(p+0x5C)=vx;
  func_00175580(p,27,8,func_00417A40()&3);
 }
}

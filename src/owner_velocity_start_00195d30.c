typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
extern s16 D_00449FC0[4][3],D_00449FC2[4][3];
extern s8 D_00449FC4[4][6];
extern void func_00197600(void);
extern unsigned func_00417A40(void);
extern int func_00175580(u8*,int,int,int);
void func_00195D30(u8 *p,u8 *q) {
 ++p[5];
 if(p[0x21]<4) {
  func_00197600();
  *(s16*)(p+0x140)=*(s16*)(q+0x140);
  *(float*)(p+0x34)=*(float*)(q+0x34);*(float*)(p+0x38)=*(float*)(q+0x38);
  *(float*)(p+0x5C)=(5.0f/3.0f)*(float)(D_00449FC0[p[0x21]][0]*256)/256.0f;
  *(float*)(p+0x60)=(15.0f/7.0f)*(float)(D_00449FC2[p[0x21]][0]*256)/256.0f;
  p[0x31]=D_00449FC4[p[0x21]][0];
  if(!*(s16*)(p+0x140))*(float*)(p+0x5C)=-*(float*)(p+0x5C);
  func_00175580(p,27,8,func_00417A40()&3);
 }
}

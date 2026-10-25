typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct {s16 x,y;signed char z;u8 pad[3];} E8;
extern s16 D_0044A220[4][8],D_0044A222[4][8],D_0044A224[4][8],D_0044A22C[4][8],D_0044A22E[4][8];
extern E8 *D_0044A228[4][4];
extern void func_00197600(void);
extern int func_001754A0(u8*,int,int);
void func_00194E40(u8 *p,u8 *q) {
 u8 *work=p+0x88;
 ++p[5];
 if(p[0x21]<4) {
  func_00197600();
  *(s16*)(p+0x140)=*(s16*)(q+0x140);
  *(float*)(p+0x34)=*(float*)(q+0x34);*(float*)(p+0x38)=*(float*)(q+0x38);
  *(float*)(work+0x18)=(5.0f/3.0f)*(float)(D_0044A220[p[0x21]][0]*256)/256.0f;
  *(float*)(work+0x1C)=(15.0f/7.0f)*(float)(D_0044A222[p[0x21]][0]*256)/256.0f;
  *(s16*)(work+4)=D_0044A224[p[0x21]][0];
  *(E8**)(work+8)=D_0044A228[p[0x21]][0];
  *(s16*)(work+12)=D_0044A22C[p[0x21]][0];
  *(s16*)(work+14)=D_0044A22E[p[0x21]][0];
  if(!*(s16*)(p+0x140))*(float*)(work+0x18)=-*(float*)(work+0x18);
  *(float*)(p+0x34)+=*(float*)(work+0x18);*(float*)(p+0x38)+=*(float*)(work+0x1C);
  func_001754A0(p,27,8);
 }
}

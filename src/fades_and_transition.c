typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {float x,y;} Vec2;
extern Vec2 D_004404A0[3];
extern float D_00443C20[],D_00443C24[],D_00443C28[];
extern float D_004442D0[],D_004442D8[];
extern void func_0032D5F0(u8 *);
extern void func_00170DF0(u32);
void func_0013C800(u8 *p)
{
 *(float*)(p+0x74)+=0.0500000007450580596923828125f;
 if(!(*(float*)(p+0x74)<=1.0f))*(float*)(p+0x74)=1.0f;
 --*(s16*)(p+0x1C);
 if(*(s16*)(p+0x1C)<=0) {
  p[4]++;
  *(float*)(p+0x34)=D_004404A0[p[0x20]].x;
  *(float*)(p+0x38)=D_004404A0[p[0x20]].y;
  *(float*)(p+0x3C)=230.0f;
  *(float*)(p+0x74)=1.0f;
  if(p[0x20]==0)(*(u8**)(p+0x14))[4]=1;
 } else {
  *(float*)(p+0x34)+=*(float*)(p+0x5C);
  *(float*)(p+0x5C)+=*(float*)(p+0x68);
  *(float*)(p+0x38)+=*(float*)(p+0x60);
  *(float*)(p+0x60)+=*(float*)(p+0x6C);
  func_0032D5F0(p);
 }
}
void func_00149900(u8 *p)
{
 u8 state=p[4];
 switch(state) {
 case 0:
  p[4]=state+1;
  *(s16*)(p+0x1C)=0;*(s16*)(p+0x1E)=0;
  *(float*)(p+0x78)=D_00443C20[0];
  *(float*)(p+0x7C)=D_00443C24[0];
  *(float*)(p+0x80)=D_00443C28[0];
  func_00170DF0((u32)*(u32*)(p+0x84));
  break;
 case 1:
  if(++*(s16*)(p+0x1C)>=2000)*(s16*)(p+0x1C)=0;
  if(++*(s16*)(p+0x1E)>=2000)*(s16*)(p+0x1E)=0;
  *(u32*)(p+0xD0)|=0x20000;
  *(float*)(p+0xE0)=(float)(1.0-0.001*(double)*(s16*)(p+0x1C));
  *(float*)(p+0xE4)=(float)(1.0-0.0005*(double)*(s16*)(p+0x1E));
  break;
 }
}
void func_0014E100(u8 *p)
{
 if(*(u32*)(p+0xDC)!=0) {
  p[0x13C]=1;
  *(float*)(p+0x74)=0.0f;
  *(s16*)(p+0x1C)=10;
  if(p[4]==1) {
   *(float*)(p+0x38)=3.3399999141693115234375f+D_004442D0[0];
   *(float*)(p+0x60)=-0.33399999141693115234375f;
   *(s16*)(p+0x1E)=-1;
  } else {
   *(float*)(p+0x38)=D_004442D8[0]-3.3399999141693115234375f;
   *(float*)(p+0x60)=0.33399999141693115234375f;
   *(s16*)(p+0x1E)=3;
  }
 } else {
  p[0x13C]=1;
  *(s16*)(p+0x1C)=10;
  if(p[4]==1)*(float*)(p+0x60)=-0.33399999141693115234375f;
  else *(float*)(p+0x60)=0.33399999141693115234375f;
 }
 p[5]++;
}

#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x34];f32 x,y,z;u8 gap40[0x10];f32 scaleX,scaleY;u8 gap58[4];f32 vx,vy,vz,ax,ay;u8 gap70[0xa8];f32 fade;u8 gap11c[0x24];s16 facing;u8 gap142[0x72];s8 flash;} Motion;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_001E7F60(u8 *);
extern void func_001E3710(u8 *,s32);
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern u8 *D_004C2840 __attribute__((section(".sdata")));
#define RESET_ACTION(p,code) do {u32 counterAddress; (p)[0x1b5]=(code);(p)[0x1b2]=*(u16 *)((p)+0x1c0)=0;*(u32 *)((p)+0x1d8)=0;counterAddress=(p)[2]*2;counterAddress+=(u32)D_004C2794;counterAddress+=0x7c;++*(s16 *)counterAddress;}while(0)

void func_0036D220(u8 *p) {
 Motion *m=(Motion *)p;
 p[0x13c]=1;
 m->facing=*(s16 *)(*(u8 **)(p+0x14)+0x140);
 m->x=*(f32 *)(*(u8 **)(p+0x14)+0x34);
 m->y=*(f32 *)(*(u8 **)(p+0x14)+0x38);
 m->z=*(f32 *)(*(u8 **)(p+0x14)+0x3c);
 p[0x24]=13;m->ax=0;m->ay=0;m->scaleX=1.399999976158142f;m->scaleY=1.399999976158142f;
 m->y-=96.0f;
 if(p[0x23]) {
  f32 offset;
  if(m->facing)offset=112.0f;
  else {offset=112.0f;offset=-offset;}
  m->x+=offset;func_001757E0(p,23,3);
 }else {
  f32 offset;
  if(m->facing)offset=-18.66666603088379f;
  else {offset=-18.66666603088379f;offset=-offset;}
  m->x+=offset;func_001757E0(p,23,60);
 }
}

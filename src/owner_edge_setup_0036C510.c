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
extern void func_001E3710(u8 *,u8);
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern u8 *D_004C2840 __attribute__((section(".sdata")));
#define RESET_ACTION(p,code) do {u32 counterAddress; (p)[0x1b5]=(code);(p)[0x1b2]=*(u16 *)((p)+0x1c0)=0;*(u32 *)((p)+0x1d8)=0;counterAddress=(p)[2]*2;counterAddress+=(u32)D_004C2794;counterAddress+=0x7c;++*(s16 *)counterAddress;}while(0)

extern f32 D_004F1FC8 __attribute__((section(".bss")));
extern f32 D_004F1FCC __attribute__((section(".bss")));
void func_0036C510(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 Motion *m=(Motion *)p;
 p[0x13c]=1;
 m->x=*(f32 *)(*(u8 **)(p+0x18)+0x34);
 m->y=*(f32 *)(*(u8 **)(p+0x18)+0x38);
 m->z=*(f32 *)(*(u8 **)(p+0x18)+0x3c);
 m->facing=*(s16 *)(*(u8 **)(p+0x18)+0x140);
 if((*(u8 **)(p+0x18))[0x1b7]==0) {
  f32 offset;
  if(m->facing)offset=186.66665649414062f;
  else offset=-186.66665649414062f;
  m->x+=offset;
 }else{
  f32 offset;
  if(m->facing)offset=373.33331298828125f;
  else offset=-373.33331298828125f;
  m->x+=offset;
 }
 if(m->facing) {
  if(D_004F1FCC<m->x)m->x=D_004F1FCC-80.0f;
 }else {
  if(!(D_004F1FC8<=m->x))m->x=80.0f+D_004F1FC8;
 }
 owner[0x2cc]=1;p[0x1b0]=66;p[0x1b1]=66;RESET_ACTION(p,63);
 m->ax=0;m->ay=0;p[0x24]=0;m->scaleY=0;*(s16 *)(p+0x1e)=4;
 func_001E3710(p,76);func_001757E0(p,23,31);
}

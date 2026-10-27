#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {u8 prefix[0x14];u8 *link,*owner;u8 gap1c[0x18];f32 x,y,z;u8 gap40[0x10];f32 scaleX,scaleY;u8 gap58[4];f32 vx,vy,vz,ax,ay;u8 gap70[0xa8];f32 fade;u8 gap11c[0x24];s16 facing;u8 gap142[0xf];s8 ownerPhase;} Motion;
typedef struct {f32 vx,ax,vy,ay;} MotionCoefficients;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_001E7F60(u8 *);
extern void func_001E3710(u8 *,s32);
extern u8 *D_004C2794 __attribute__((section(".sdata")));
#define RESET_ACTION(p,code) do {u32 counterAddress; (p)[0x1b5]=(code);(p)[0x1b2]=*(u16 *)((p)+0x1c0)=0;*(u32 *)((p)+0x1d8)=0;counterAddress=(p)[2]*2;counterAddress+=(u32)D_004C2794;counterAddress+=0x7c;++*(s16 *)counterAddress;}while(0)

extern f32 D_00463B80[];
extern s32 func_0036F5A0(u8 *,u8 *,s32 *);
void func_0036F120(u8 *p,u8 *context,s32 *contact) {
 Motion *m=(Motion *)p;f32 *offsets=D_00463B80;
 u8 *owner=m->owner;
 if(((s8 *)owner)[0x151]==12) {
  if(*contact){p[5]++;func_0036F5A0(p,context,contact);return;}
  p[4]++;p[0x13c]=0;return;
 }
 if(((s8 *)owner)[0x151]>0) {
  f32 offset;
  m->x=*(f32 *)(owner+0x34);
  m->y=*(f32 *)(m->owner+0x38);
  m->z=*(f32 *)(m->owner+0x3c);
  m->x+=*(s16 *)(m->owner+0x140) ? 148 : -148;
  m->y+=165.0f;
  owner=m->owner;
  if(*(s16 *)(owner+0x140))offset=offsets[((s8 *)owner)[0x151]];
  else offset=-offsets[((s8 *)owner)[0x151]];
  m->x+=offset;
 }
 func_0036F5A0(p,context,contact);
}

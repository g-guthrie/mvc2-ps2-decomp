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

extern MotionCoefficients D_00463BF0;
void func_0036C740(u8 *p) {
 Motion *m=(Motion *)p;
 MotionCoefficients *motion=&D_00463BF0;
 p[0x13c]=1;
 m->x=*(f32 *)(*(u8 **)(p+0x18)+0x34);
 m->y=*(f32 *)(*(u8 **)(p+0x18)+0x38);
 m->z=*(f32 *)(*(u8 **)(p+0x18)+0x3c);
 m->x+=*(s16 *)(*(u8 **)(p+0x18)+0x140) ? 112 : -112;
 m->y+=176.0f;
 p[0x1b0]=66;p[0x1b1]=66;RESET_ACTION(p,49);
 *(u16 *)(p+0x1c0)|=0x200;
 *(s16 *)(p+0x1c)=80;m->ax=0;m->ay=0;p[0x24]=0;
 m->vx=motion->vx;m->ax=motion->ax;m->vy=motion->vy;m->ay=motion->ay;
 {f32 value; if(*(s16 *)(*(u8 **)(p+0x18)+0x140))value=m->vx;else value=-m->vx; m->vx=value;}
 {f32 value; if(*(s16 *)(*(u8 **)(p+0x18)+0x140))value=-m->ax;else value=m->ax; m->ax=value;}
 func_001757E0(p,23,34);
}

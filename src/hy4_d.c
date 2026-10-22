#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef double f64;
typedef struct T41C {u8 pad[0x1c];s32 w1C;u8 pad20[0x170-0x20];} T41C;
typedef struct A41B {s32 w0;u32 w4;s32 w8,wC;u16 h10,h12;} A41B;
extern T41C D_005BF2F0[];
extern s32 func_003DD030(s32);
extern void func_0041BAD0(A41B *);
extern u8 *func_0041BBB0(A41B *);
extern void func_0041BB30(A41B *);
extern f32 func_00417440(u32);
typedef struct {f32 x,y,z;} Point3;
typedef struct {u8 *actor;s32 phase;} WaveContext;
void func_0013E570(u8 *p,u8 *q,s32 context) {
 WaveContext *state=(WaveContext *)(u32)context;
 u8 *actor=state->actor;
 s32 phase=state->phase;
 Point3 *point;
 s32 resource=((A41B *)q)->w0-1;
 u8 *base=(u8 *)(u32)func_003DD030(((T41C *)((u8 *)&D_005BF2F0+resource*0x170))->w1C);
 u16 *ranges=(u16 *)(u32)func_003DD030(((A41B *)q)->w8);
 u16 *offsets=(u16 *)(u32)func_003DD030(((A41B *)q)->wC);
 func_0041BAD0((A41B *)q);
 while((point=(Point3 *)func_0041BBB0((A41B *)p))!=0 && func_0041BBB0((A41B *)q)!=0) {
  f32 y=point->y;
  f32 z=point->z;
  u32 turn=(u16)(u32)(s32)(0.5+(65536.0*(f64)(*(s16 *)(actor+0x1e)+phase))/360.0);
  z+=0.019999999552965164f*y*y*func_00417440(turn);
  phase+=0x14;
  {u16 start=ranges[2* *(s16 *)(q+0x10)];
   u16 count=ranges[2* *(s16 *)(q+0x10)+1];
   s32 i;
   for(i=0;i<count;i++,start++)*(f32 *)(base+offsets[start]+8)=z;
  }
 }
 state->phase=phase;
 ((A41B *)p)->h12=0;((A41B *)p)->h10=0;((A41B *)q)->h12=0;((A41B *)q)->h10=0;
 func_0041BB30((A41B *)q);
}

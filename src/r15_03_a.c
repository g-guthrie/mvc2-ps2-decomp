/* func_00341DF0: wave/colour effect callback. MW 3.0.3, -O3 -Op -fp off -sdatathreshold 0.
   The third colour channel keeps its 96/64 constants in named block locals under
   opt_dead_assignments off, which gives retail's constant scheduling and f1/f2 colouring. */
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
extern f32 D_004605B8[];
extern s32 func_003DD030(s32);
extern void func_0041BAD0(A41B *);
extern u8 *func_0041BBB0(A41B *);
extern void func_0041BB30(A41B *);
extern f32 func_00117240(f32);
extern f32 func_00417440(u32);
typedef struct {u8 *actor;s32 phase;u32 a1,a2,a3;} WaveContext;
#pragma push
#pragma opt_dead_assignments off
void func_00341DF0(u8 *p,u8 *q,s32 context) {
 WaveContext *state=(WaveContext *)(u32)context;
 u8 *actor=state->actor;
 s32 phase=state->phase;
 u32 t1=state->a1;
 u32 t2=state->a2;
 u32 t3=state->a3;
 f32 *point;
 s32 resource=((A41B *)q)->w0-1;
 u8 *base=(u8 *)(u32)func_003DD030(((T41C *)((u8 *)&D_005BF2F0+resource*0x170))->w1C);
 u16 *ranges=(u16 *)(u32)func_003DD030(((A41B *)q)->w8);
 u16 *offsets=(u16 *)(u32)func_003DD030(((A41B *)q)->wC);
 func_0041BAD0((A41B *)q);
 while((point=(f32 *)func_0041BBB0((A41B *)p))!=0 && func_0041BBB0((A41B *)q)!=0) {
  f32 x=*point;
  f32 c1,c2,c3,amp;
  u32 turn=(u32)(s32)(0.5+65536.0*(f64)*(s16 *)(actor+0x1e)/360.0)&0xFFFFu;
  amp=2000.0f*D_004605B8[actor[0x20]]*(1.0f+0.5f*func_00417440(turn));
  x+=amp*func_00117240(0.017453292f*(f32)(*(s16 *)(actor+0x1c)/4+phase));
  t1+=0x800;
  phase+=30;
  t2+=0x800;
  t3+=0x800;
  c1=96.0f+64.0f*func_00417440(t1&0xFFFF);
  c2=96.0f+64.0f*func_00417440(t2&0xFFFF);
  c3=func_00417440(t3&0xFFFF);
  {f32 k96,k64; k96=96.0f; k64=64.0f; c3=k96+k64*c3;}
  {u16 count; u16 start; s32 i;
   i=0;start=ranges[2* *(s16 *)(q+0x10)];count=ranges[2* *(s16 *)(q+0x10)+1];
   for(;i<count;i++,start++) {
    f32 *v=(f32 *)((u32)(base+offsets[start])|0x20000000);
    v[0]=x; v[4]=c1; v[5]=c2; v[6]=c3;
   }
  }
 }
 state->phase=phase;
 state->a1=t1;
 state->a2=t2;
 state->a3=t3;
 ((A41B *)p)->h12=0;((A41B *)p)->h10=0;((A41B *)q)->h12=0;((A41B *)q)->h10=0;
 func_0041BB30((A41B *)q);
}
#pragma pop

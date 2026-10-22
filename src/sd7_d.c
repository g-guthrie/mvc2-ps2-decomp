/* sd7_d: ./try.sh src/sd7_d.c "-O4,p -sdatathreshold 8" */
#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct T41C {u8 pad[0x1c];s32 w1C;u8 pad20[0x170-0x20];} T41C;
typedef struct A41B {s32 w0;u32 w4;s32 w8,wC;u16 h10,h12;} A41B;
typedef struct { u32 w0; f32 f4; f32 f8; } R41B;
extern T41C D_005BF2F0[];
extern s32 func_003DD030(s32);
extern void func_0041BAD0(A41B *);
extern R41B *func_0041BBB0(A41B *);
extern void func_0041BB30(A41B *);
void func_003311A0(u8 *p, u8 *q, s32 cn) {
 u8 *c=(u8 *)(u32)cn;
 s32 resource=((A41B *)q)->w0-1;
 u8 *base=(u8 *)(u32)func_003DD030(((T41C *)((u8 *)&D_005BF2F0+resource*0x170))->w1C);
 u16 *ranges=(u16 *)(u32)func_003DD030(((A41B *)q)->w8);
 u16 *offsets=(u16 *)(u32)func_003DD030(((A41B *)q)->wC);
 R41B *v;
 func_0041BAD0((A41B *)q);
 while((v=func_0041BBB0((A41B *)p))!=0) {
  f32 x=v->f4;
  f32 y=v->f8;
  if (x < -50.0f) {
   f32 s=(f32)*(s16 *)(c+0x1E);
   x=x*(100.0f-0.5f*s)/100.0f;
   y=y*(100.0f+10.0f*(0.5f*s))/100.0f;
  }
  {u16 start=ranges[2* *(s16 *)(q+0x10)];
   u16 count=ranges[2* *(s16 *)(q+0x10)+1];
   s32 i;
   for(i=0;i<count;i++,start++){
    f32 *dst=(f32 *)(base+offsets[start]);
    dst[1]=x;
    dst[2]=y;
   }
  }
 }
 ((A41B *)p)->h12=0;((A41B *)p)->h10=0;((A41B *)q)->h12=0;((A41B *)q)->h10=0;
 func_0041BB30((A41B *)q);
}

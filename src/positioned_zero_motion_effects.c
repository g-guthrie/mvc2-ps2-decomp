/* Initialize positioned effects with their preset scale and zero motion. */
typedef unsigned char u8;
#include "mvc2_effect_vectors.h"
typedef Mvc2EffectVector Vec3;
extern u8 *func_003DA750(int,int,int);
extern void *D_004C2838;
extern Mvc2EffectVector D_00444D20;
extern void func_00158CD0(u8 *);
void func_00158EE0(Vec3 *position) {
 u8 *p=func_003DA750(0,0x21,1);
 if (p) {
  p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_00158CD0;
  *(short *)(p+0xcc)=66; *(void **)(p+0x84)=D_004C2838;
  *(int *)(p+0xd0)=0x800011;
  *(Vec3 *)(p+0x34)=*position;
  *(Vec3 *)(p+0x50)=D_00444D20;
  *(float *)(p+0x74)=0.0f;
  *(float *)(p+0x78)=0.0f; *(float *)(p+0x7c)=0.0f; *(float *)(p+0x80)=0.0f;
 }
}
extern void func_00158F90(u8 *);
void func_001591A0(Vec3 *position) {
 u8 *p=func_003DA750(0,0x21,1);
 if (p) {
  p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_00158F90;
  *(short *)(p+0xcc)=67; *(void **)(p+0x84)=D_004C2838;
  *(int *)(p+0xd0)=0x800011;
  *(Vec3 *)(p+0x34)=*position;
  *(Vec3 *)(p+0x50)=D_00444D20;
  *(float *)(p+0x74)=0.0f;
  *(float *)(p+0x78)=0.0f; *(float *)(p+0x7c)=0.0f; *(float *)(p+0x80)=0.0f;
 }
}
extern void func_00159250(u8 *);
void func_00159460(Vec3 *position) {
 u8 *p=func_003DA750(0,0x21,1);
 if (p) {
  p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_00159250;
  *(short *)(p+0xcc)=68; *(void **)(p+0x84)=D_004C2838;
  *(int *)(p+0xd0)=0x800011;
  *(Vec3 *)(p+0x34)=*position;
  *(Vec3 *)(p+0x50)=D_00444D20;
  *(float *)(p+0x74)=0.0f;
  *(float *)(p+0x78)=0.0f; *(float *)(p+0x7c)=0.0f; *(float *)(p+0x80)=0.0f;
 }
}
extern void func_00159510(u8 *);
void func_00159720(Vec3 *position) {
 u8 *p=func_003DA750(0,0x21,1);
 if (p) {
  p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_00159510;
  *(short *)(p+0xcc)=69; *(void **)(p+0x84)=D_004C2838;
  *(int *)(p+0xd0)=0x800011;
  *(Vec3 *)(p+0x34)=*position;
  *(Vec3 *)(p+0x50)=D_00444D20;
  *(float *)(p+0x74)=0.0f;
  *(float *)(p+0x78)=0.0f; *(float *)(p+0x7c)=0.0f; *(float *)(p+0x80)=0.0f;
 }
}

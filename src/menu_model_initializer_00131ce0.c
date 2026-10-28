typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned short u16;typedef unsigned int u32;typedef int s32;typedef float f32;
#include "model_callback_api.h"
typedef struct { f32 x,y,z; } V3;
extern u8 *func_003DA750(s32,s32,s32);
extern void func_00132BD0(u8 *);
extern void func_00131E20(u8 *,u8 *,s32);
extern u8 D_004BF330[8];
extern f32 data_f32_one_0043DF58[3];
extern u8 D_004F20B0[], D_004F24D5[], D_004F24E4[];
extern u8 *D_004C2834 __attribute__((section(".sdata")));
void func_00131CE0(u8 *parent,s32 n) {
 u8 *o=func_003DA750(0,14,1);
 if(o) {
  u8 *res; EL_d *elements; ND_d *node;
  o[0x13c]=1;*(void (**)(u8 *))(o+0x10)=func_00132BD0;
  *(u16 *)(o+0xcc)=D_004BF330[n];
  *(u8 **)(o+0x84)=D_004C2834;
  *(V3 *)(o + 0x50) = *(const V3 *)(const void *)data_f32_one_0043DF58;
  *(u32 *)(o+0xd0)=0x10c10;
  *(u8 **)(o+0xc8)=parent+0x88;
  o[2]=parent[2];o[0x20]=(u8)n;
  o[0x21]=D_004F24D5[n*0x5b8];*(s16 *)(o+0x1e)=*(s16 *)(D_004F24E4+n*0x5b8);
  *(u8 **)(o+0x18)=D_004F20B0+n*0x5b8;*(u8 **)(o+0x14)=parent;
  res=*(u8 **)(o+0x84);
  node=((ND_d **)*(u8 **)(res+0x1c))[*(s16 *)(o+0xcc)];
  elements=*(EL_d **)(res+0x14);
  func_00170E60(elements,node,elements,node,func_00131E20,(s32)(u32)&n);
 }
}

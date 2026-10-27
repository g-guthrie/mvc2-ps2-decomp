typedef unsigned char u8; typedef signed short s16; typedef unsigned short u16; typedef unsigned int u32; typedef float f32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_001757E0(u8 *,int,int);
void func_001B2C50(u8 *p) { *(f32 *)(p+0x34)+=*(f32 *)(p+0x5c); if ((*(s16 *)(p+0x1c))-- <= 0) p[5]++; }
void func_002E7BD0(u8 *p) { p[6]++; *(f32 *)(p+0x38)=*(f32 *)(p+0x430); p[0x20d]=0; *(f32 *)(p+0x5c)=0.0f; *(f32 *)(p+0x60)=0.0f; *(f32 *)(p+0x68)=0.0f; *(f32 *)(p+0x6c)=0.0f; func_001757E0(p,20,0); }
void func_002C7370(u8 *p,void *owner) { u8 *q=owner; p[6]++; p[0x13c]=0; q[4]=1; *(f32 *)(p+0x38)=*(f32 *)(p+0x430)+171.428558349609375f; func_001757E0(p,18,0); }
void func_0027E8D0(u8 *p) { p[6]++; p[0x20d]=0; p[0x1b5]=48; p[0x1b2]=*(u16 *)(p+0x1c0)=0; *(u32 *)(p+0x1d8)=0; {u32 a=p[2]*2; a+=(u32)D_004C2794; a+=0x7c; ++*(s16 *)a;} func_001757E0(p,21,4); }

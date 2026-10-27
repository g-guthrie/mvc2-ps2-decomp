typedef unsigned char u8; typedef signed short s16; typedef float f32;
extern int func_001757E0(u8 *,int,int);
extern void func_002B9A60(u8 *);
extern void func_0037F000(u8 *, void *);
extern void func_00155490(void *);
void func_001F0220(u8 *p) { p[6]++; func_001757E0(p,18,0); }
void func_002B9A40(u8 *p) { *(f32 *)(p+0x5c)=0.0f; *(f32 *)(p+0x60)=0.0f; *(f32 *)(p+0x68)=0.0f; *(f32 *)(p+0x6c)=0.0f; p[6]++; func_002B9A60(p); }
void func_0037EFE0(u8 *p, void *owner) { u8 *q=owner; p[5]++; *(f32 *)(p+0x38)=*(f32 *)(q+0x430); *(f32 *)(p+0x54)=1.5f; func_0037F000(p, owner); }
void func_0027F9E0(u8 *p) { p[6]++; p[0x20d]=0; *(f32 *)(p+0x5c)=0.0f; *(f32 *)(p+0x60)=0.0f; *(f32 *)(p+0x68)=0.0f; *(f32 *)(p+0x6c)=0.0f; p[0x13c]=0; *(s16 *)(p+0x1c)=270; *(s16 *)(p+0x1e)=0; func_00155490(p); }

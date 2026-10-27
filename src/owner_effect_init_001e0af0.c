#pragma padloop on
typedef unsigned char u8; typedef signed char s8; typedef signed int s32; typedef unsigned int u32; typedef float f32;
typedef struct {f32 x,y,z;} V3;
extern void func_001E0B90(u8 *,u8 *);
void func_001E0AF0(u8 *p,void *owner) {
 u8 *q=owner; s32 n; s32 *d,*s; u32 t=p[4];
 s=(s32 *)(q+0xec);d=(s32 *)(p+0xec);n=49;p[4]=t+1;
 do {*d=*s;n--;s++;d++;}while(n>0);
 p[0x13c]=1;p[2]=q[2];p[1]=q[1];*(f32 *)(p+0x50)=*(f32 *)(q+0x50);*(f32 *)(p+0x54)=*(f32 *)(q+0x54);p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8 *)(p+0x30)=*(s8 *)(q+0x30);*(V3 *)(p+0x50)=*(V3 *)(q+0x50);*(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 func_001E0B90(p,q);
}

#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef signed short s16;typedef signed int s32;typedef float f32;typedef struct {f32 x,y,z;} V3;
extern int func_001757E0(u8 *,int,int);
void func_00354E90(u8 *p,void *owner) {u8 *q=owner;u8 *r; s32 n; s32 *d,*s;
 s=(s32 *)(q+0xec);d=(s32 *)(p+0xec);n=49;do{*d=*s;n--;s++;d++;}while(n>0);
 p[0x13c]=1;p[2]=q[2];p[1]=q[1];*(f32 *)(p+0x50)=*(f32 *)(q+0x50);*(f32 *)(p+0x54)=*(f32 *)(q+0x54);p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8 *)(p+0x30)=*(s8 *)(q+0x30);*(V3 *)(p+0x50)=*(V3 *)(q+0x50);*(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 p[4]++;p[0x13c]=0;*(s16 *)(p+0x140)=p[0x21] ? 0 : 1;p[0x1b0]=66;p[0x1b1]=66;r=*(u8 **)(p+0x14);*(V3 *)(p+0x34)=*(V3 *)(r+0x34);func_001757E0(p,23,(u8)(*(s16 *)(p+0x1c)+16));}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x,y,z; } V3;
typedef struct { u32 words[49]; } Payload;
extern s32 func_001754A0(u8 *,u8,u8);
extern void func_001BFC20(u8 *);
void func_001BFB30(u8 *p) {
 u8 *q;
 p[4]++;
 *(unsigned short *)(p+0x26)=0x1902;
 q=*(u8 **)(p+0x18);
 *(Payload *)(p+0xEC)=*(Payload *)(q+0xEC);
 p[0x13C]=1;
 p[2]=q[2];p[1]=q[1];
 *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
 *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
 p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
 *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 p[0x13C]=0;
 p[0x24]=7;
 *(f32 *)(p+0x118)=0.7f;
 func_001754A0(p,27,1);
 func_001BFC20(p);
}

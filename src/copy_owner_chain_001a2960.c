typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x,y,z; } V3;
typedef struct { u32 words[49]; } Payload;
#pragma padloop on
void func_001A2960(u8 *p,u8 *q) {
 s32 i,count;
 count=*(s16 *)(p+0x1E);
 for(i=0;i<count;i++) {
  *(Payload *)(p+0xEC)=*(Payload *)(q+0xEC);
  p[0x13C]=1;
  p[2]=q[2];p[1]=q[1];
  *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
  *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
  p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
  *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
  *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
  *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  p[0x31]=8;
  *(V3 *)(p+0x34)=*(V3 *)(q+0x34);
  p=*(u8 **)(p+0xC);
 }
}

void func_001A60D0(u8 *p,u8 *q) {
 s32 i,count;
 count=*(s16 *)(p+0x1E);
 for(i=0;i<count;i++) {
  *(Payload *)(p+0xEC)=*(Payload *)(q+0xEC);
  p[0x13C]=1;
  p[2]=q[2];p[1]=q[1];
  *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
  *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
  p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
  *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
  *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
  *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  p[0x31]=8;
  *(V3 *)(p+0x34)=*(V3 *)(q+0x34);
  p=*(u8 **)(p+0xC);
 }
}

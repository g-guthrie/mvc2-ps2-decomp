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

void func_001A16D0(u8 *p,u8 *q) {
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
  p[0x13C]=0;
  *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  p[0x31]=8;
  *(V3 *)(p+0x34)=*(V3 *)(q+0x34);
  p=*(u8 **)(p+0xC);
 }
}

extern u32 D_0044A620[];
extern void func_00198960(u8 *);
extern s32 func_001754A0(u8 *, u8, u8);

void func_00198730(u8 *p)
{
    u8 *q;
    p[4]++;
    p[0x13C] = 1;
    q = *(u8 **)(p + 0x18);
    *(Payload *)(p + 0xEC) = *(Payload *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    p[0x30] = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    ((void (*)(u8 *))D_0044A620[p[0x20]])(p);
    func_00198960(p);
}

void func_001BAA10(u8 *p, u8 *owner)
{
    p[4]++;
    p[0x13C] = 1;
    *(Payload *)(p + 0xEC) = *(Payload *)(owner + 0xEC);
    p[0x13C] = 1;
    p[2] = owner[2];
    p[1] = owner[1];
    *(f32 *)(p + 0x50) = *(f32 *)(owner + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(owner + 0x54);
    p[0x1B7] = owner[0x1B7];
    p[0x1B8] = owner[0x1B8];
    p[0x30] = *(s8 *)(owner + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(owner + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(owner + 0x24);
    p[0x24] = 0;
    *(V3 *)(p + 0x34) = *(V3 *)(owner + 0x34);
    func_001754A0(p, 0x1B, 5);
    *(f32 *)(p + 0x118) = 1.0f;
}

void func_001B9B60(u8 *p) {
    u8 *q;
    p[4]++;
    p[0x13C] = 1;
    q = *(u8 **)(p + 0x18);
    *(Payload *)(p + 0xEC) = *(Payload *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s16 *)(p + 0x1C) = *(s16 *)(*(u8 **)(p + 0x18) + 0x1E);
    *(f32 *)(p + 0x118) = 0.5f;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    p[0x24] = 10;
    if (p[0x20] != 0)
        func_001754A0(p, 23, 4);
    else
        func_001754A0(p, 23, 3);
}

void func_001BA3A0(u8 *p) {
    u8 *q;
    p[4]++;
    p[0x13C] = 1;
    q = *(u8 **)(p + 0x18);
    *(Payload *)(p + 0xEC) = *(Payload *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s16 *)(p + 0x1C) = *(s16 *)(*(u8 **)(p + 0x18) + 0x1E);
    *(f32 *)(p + 0x118) = 0.5f;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = (s8)(p[0x31] - 2);
    if (p[0x20] != 0)
        func_001754A0(p, 23, 9);
    else
        func_001754A0(p, 23, 8);
}

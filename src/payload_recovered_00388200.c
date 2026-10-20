typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u16 D_00464A2E[];
extern int func_001757E0(u8 *, s32, s32);
extern void func_00388310(u8 *);

typedef struct { u32 words[49]; } Payload;
#pragma padloop on
void func_00388200(u8 *p)
{
    u8 *q;
    u16 code;
    u32 t;
    code = 0x1C04;
    t = p[4];
    q = *(u8 **)(p + 0x18);
    p[4] = t + 1;
    *(u16 *)(p + 0x26) = code;
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
    p[0x13C] = 1;
    *(s8 *)(p + 0x31) = -1;
    *(u16 *)(p + 0x1E) = D_00464A2E[p[0x20]];
    func_001757E0(p, 0x17, 9);
    func_00388310(p);
}

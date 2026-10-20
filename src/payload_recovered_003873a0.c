typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 D_00464930[];
extern int func_001757E0(u8 *, s32, s32);
extern void func_003874C0(u8 *);

typedef struct { u32 words[49]; } Payload;
#pragma padloop on
void func_003873A0(u8 *p)
{
    u8 *q;
    u8 *tbl;
    u16 code;
    u32 t;
    code = 0x1C03;
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
    tbl = D_00464930 + p[0x20] * 6;
    func_001757E0(p, tbl[4], tbl[5]);
    p[0x24] = 0xB;
    *(s8 *)(p + 0x31) = *(s8 *)tbl;
    func_003874C0(p);
}

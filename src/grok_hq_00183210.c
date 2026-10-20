typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_0018C6B0(u8 *, s8);
extern s32 func_00327CF0(u8 *, s32);
extern void func_00157830(V3 *, s16, s32, s32);
extern void func_0016EDA0(s32, s32);
extern void func_001E3BB0(u8 *, s32);
extern void func_001E3710(u8 *, s32);
extern void func_001E3210(u8 *, s32);
extern void func_00183A70(u8 *);
extern void func_001356F0(u8 *, s32);
extern void func_00175C00(u32, s32);

typedef struct { u32 a, b, c; } T3;
extern T3 D_004D18B8[];
extern u8 *D_004C2794;

void func_00183210(u8 *p, V3 *off, s32 amt)
{
    V3 pos;
    p[0x33B] = 1;
    D_004C2794[0x76] = (u8)((*(s8 *)(p + 2) << 4) | 1);
    p[0x33C] = 0x10;
    func_0018C6B0(p, (s8)amt);
    if (func_00327CF0(p, 0) == 0)
        return;
    pos = *(V3 *)(p + 0x34);
    pos.y += off->y;
    if (*(s16 *)(p + 0x140) == 0)
        pos.x += off->x;
    else
        pos.x -= off->x;
    func_00157830(&pos, *(s16 *)(p + 0x140), 0, 0);
    func_0016EDA0(p[2], 5);
    func_001E3BB0(p, 0);
    func_001E3710(p, 0x1E);
    func_001E3210(p, 0x2B);
    func_00183A70(p);
    func_001356F0(p, 0);
    func_00175C00(D_004D18B8[p[2] ^ 1].a, 2);
    func_00175C00(D_004D18B8[p[2] ^ 1].b, 2);
    func_00175C00(D_004D18B8[p[2] ^ 1].c, 2);
}

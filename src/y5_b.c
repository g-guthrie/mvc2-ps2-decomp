typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3_5db;
extern u32 D_004C2838;

void func_0015DB20(V3_5db *pos, s16 val)
{
    extern void *func_003DA750(void *, s32, s32);
    extern void func_0015DF20(u8 *);
    u8 *p;
    u32 t;
    if ((p = func_003DA750(0, 9, 1)) != 0) {
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 0x10) = func_0015DF20;
        *(s16 *)(p + 0xCC) = 0xAB;
        *(u32 *)(p + 0x84) = D_004C2838;
        *(V3_5db *)(p + 0x34) = *pos;
        *(u32 *)(p + 0xD0) = 0x800025;
        *(s16 *)(p + 0x1C) = 0;
        *(s16 *)(p + 0x1E) = 0;
        *(u32 *)(p + 0x74) = 0;
        *(s16 *)(p + 0x140) = val;
        if (*(s16 *)(p + 0x140) != 0) t = 0x8000; else t = 0;
        *(u32 *)(p + 0x44) += t;
    }
}

s32 func_002F6120(u8 *p)
{
    extern s32 func_001E7FD0();
    s32 r;
    if (p[0x20D] == 1) return 0;
    if ((*(u16 *)(p + 0x20E) & 0xC00) == 0) return 0;
    if (p[0x1B7] == 0) return 0;
    if (p[0x20D] == 2 && p[0x212] == 1) return 0;
    if ((r = func_001E7FD0(p)) == 0) return r;
    p[0x22] = (s32)(*(u16 *)(p + 0x20E) & 0x3C00) >> 10;
    if (p[0x20D] == 2) {
        p[0x20B] = 3;
    } else if (p[0x212] == 0) {
        p[0x20B] = 2;
    } else {
        p[0x20B] = 1;
    }
    return r;
}

s32 func_00190B50(u8 *p)
{
    if (p[5] != 0) return 1;
    if (p[0x20D] == 2) return 1;
    if (p[0x20D] == 3) return 1;
    if (p[0x1E4] == 0xC) return 1;
    if (*(s16 *)(p + 0x434) == 0) return 1;
    p[0x297] = *(s8 *)(p + 0x292);
    p[0x294] += (*(u8 **)(p + 0x1D0))[0xF];
    if (p[0x294] < p[0x293]) return 0;
    p[0x294] = 0;
    p[0x295] = 0;
    *(s32 *)(p + 0x2A4) = 0;
    *(s32 *)(p + 0x2A8) = 0;
    return 1;
}

extern u8 D_004531B0[];

s32 func_0024DCC0(u8 *p)
{
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    u8 *q;
    q = p + 0x2B8;
    if (func_00189310(p, D_004531B0, p + 0x3B0) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (p[0x20D] == 2) {
        if (*(volatile s8 *)(p + 0x1E8) != 0 && p[0x210] == 0) return 0;
        p[0x1E8] = *(s8 *)(p + 0x1E8) + 1;
    }
    func_0018A990(p, p + 0x3B0);
    q[5] = 0;
    p[5] = 0;
    if (p[0x20D] == 2) p[6] = 1;
    else p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 6;
    func_00186A60(p, 0x1D);
    return 1;
}


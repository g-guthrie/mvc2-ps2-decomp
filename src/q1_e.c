typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00189310(u8 *, void *, u8 *);
extern void func_00186A60(u8 *, s32);
extern u8 D_0045DDA0[];
extern u8 D_004511E0[];
extern u8 D_0045AEF0[];
extern s32 func_0018A990(u8 *, u8 *);

s32 func_00322650(u8 *p)
{
    if (func_00189310(p, D_0045DDA0, p + 0x398) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    p[0x13C] = 1;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 5;
    func_00186A60(p, 0x1D);
    p[0x216] = 0x80;
    *(s32 *)(p + 0xD0) = 10;
    return 1;
}

s32 func_0021D0B0(u8 *p)
{
    if (func_00189310(p, D_004511E0, p + 0x398) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (p[0x20D] == 2) {
        s8 t = *(s8 *)(p + 0x1E8);
        if (t != 0) return 0;
        if (p[0x210] == 0) p[0x1E8] = t + 1;
    }
    p[0x26C] = 3;
    return 1;
}

s32 func_002E12C0(u8 *p)
{
    if (func_00189310(p, D_0045AEF0, p + 0x3A0) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s8 t = *(s8 *)(p + 0x1E8);
            if (t != 0) return 0;
            p[0x1E8] = t + 1;
        }
    }
    func_0018A990(p, p + 0x3A0);
    p[5] = 0;
    func_00186A60(p, 0x15);
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 7;
    p[0x213] = 0;
    return 1;
}


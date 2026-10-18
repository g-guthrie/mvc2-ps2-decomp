typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00275D50(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00275A40(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00275A40(p);
    p[0x40C] = 2;
    p[0x33C] = 5;
    {
        s16 v = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v < 0) {
            p[6]++;
            if (p[0x20D] == 2) {
                p[0x168] = 5;
                *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
            } else {
                p[0x168] = 2;
            }
            func_001757E0(p, 0x16, p[0x168]);
        }
    }
}

extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_00316170(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001266A0(u8 *, s32, s32);
    if ((s8)func_00175700(p) < 0) {
        u8 *q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x1B5] = 0x22;
        p[0x1B5] = 0x22;
        q[0x20A] = 1;
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        func_001E3710(p, 0x30);
        p[6]++;
        func_001757E0(p, 0xF, 0xF);
        *(u32 *)(p + 0x5C) = 0x41195555;
        *(u32 *)(p + 0x68) = 0xBD555555;
        *(u32 *)(p + 0x60) = 0x413C9249;
        *(u32 *)(p + 0x6C) = 0xBF22DB6D;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        func_001266A0(p, 0, 0);
    }
}

void func_001CCA50(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001CCB50(u8 *);
    if (p[5] == 0) {
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x38) <= *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
            p[5]++;
            *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
            func_001E3710(p, 0x34);
            func_001757E0(p, 0x17, (u8)(p[0x21] + 0x42));
            return;
        }
    } else {
        func_00175700(p);
        if (*(*(u8 **)(p + 0x18) + 0x1E4) != 0x16)
            func_001CCB50(p);
    }
}

extern u8 D_00453530[];

static s32 func_00254480(u8 *p)
{
    if (p[0x20D] != 2)
        return 1;
    if (p[0x210] != 0)
        return 1;
    if (*(s8 *)(p + 0x1E8) != 0)
        return 0;
    *(s8 *)(p + 0x1E8) = *(s8 *)(p + 0x1E8) + 1;
    return 1;
}

s32 func_002546F0(u8 *p)
{
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_0018A990(u8 *, u8 *);
    extern void func_00186A60(u8 *, s32);
    if (func_00189310(p, D_00453530, p + 0x380) == 0)
        return 0;
    if (func_00254480(p) == 0)
        return 0;
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 1;
    func_00186A60(p, 0x15);
    return 1;
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s32 D_004C2838;
extern f32 D_00444C70[];
extern f32 D_00444C74[];
extern f32 D_00444C78[];

u8 *func_00157330(V3 *a, s32 b)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00157290();
    u8 *o;
    if ((o = func_003DA750(0, 9, 1)) != 0) {
        o[0x13C] = 1;
        *(s32 *)(o + 0x10) = (s32)func_00157290;
        *(s16 *)(o + 0xCC) = b + 0x2C;
        *(s32 *)(o + 0x84) = D_004C2838;
        *(s32 *)(o + 0xD0) = 0x800401;
        *(V3 *)(o + 0x34) = *a;
        *(f32 *)(o + 0x34) += D_00444C70[b * 3];
        *(f32 *)(o + 0x38) += D_00444C74[b * 3];
        *(f32 *)(o + 0x3C) += D_00444C78[b * 3];
        *(f32 *)(o + 0x5C) = -D_00444C70[b * 3] / 15.0f;
        *(f32 *)(o + 0x60) = -D_00444C74[b * 3] / 15.0f;
        *(f32 *)(o + 0x64) = -D_00444C78[b * 3] / 15.0f;
        *(u32 *)(o + 0x50) = 0x3F800000;
        *(u32 *)(o + 0x54) = 0x3F800000;
        *(u32 *)(o + 0x58) = 0x3F800000;
        *(u32 *)(o + 0x78) = 0x3F800000;
        *(u32 *)(o + 0x7C) = 0x3F800000;
        *(u32 *)(o + 0x80) = 0x3F800000;
    }
}

void func_00187840(u8 *p)
{
    extern void func_00175C00(u8 *, s32);
    extern void func_00185490(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00183D50(u8 *);
    f32 t;
    func_00175C00(p, 1);
    func_00185490(p);
    if (p[0x20] == 0) {
        t = *(f32 *)(p + 0x430);
        if (*(f32 *)(p + 0x38) < t + 68.57142639160156f) {
            *(f32 *)(p + 0x38) = t;
        }
        p[0x20D] = 2;
        p[0x1EC] = 0;
        p[0x210] = 0;
        p[0x1E8] = 0;
        p[0x1E9] = 0;
        p[0x1EA] = 0x11;
        p[0x1ED] = 0;
        *(u32 *)(p + 0x5C) = 0x413AAAAA;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x413C9249;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        p[0x1E7] = 1;
        func_001757E0(p, 0xD, 0x20);
    } else {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 1;
        p[0x1EC] = 0;
        p[0x210] = 0;
        p[0x1E8] = 0;
        p[0x1E9] = 0;
        *(u32 *)(p + 0x5C) = 0x41555555;
        *(u32 *)(p + 0x68) = 0xBFA00000;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001757E0(p, 0xD, 0x21);
        func_00183D50(p);
    }
}

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G24;
extern G24 *D_004C2794;

void func_0024F000(u8 *p)
{
    extern void func_001861B0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_0018C4B0(u8 *, s32);
    extern void func_00183D90(u8 *);
    extern void func_001863F0(u8 *);
    extern s8 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    u32 t;
    f32 f;
    f32 z;
    z = 0.0f;
    if (p[6] == 0) {
        func_001861B0(p);
        t = p[6];
        p[6] = t + 1;
        p[0x20D] = 1;
        func_001757E0(p, 0x14, 3);
        p[0x1B5] = 0x35;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001E3710(p, 0x16);
        func_0018C4B0(p, 5);
    }
    if (p[0x213] == 3) {
        func_00183D90(p);
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    f = *(s8 *)(p + 0x151);
    if (f != z) {
        p[0x151] = 0;
        f *= (p[0x1E6] != 0) ? 1.6666666269302368f : -1.6666666269302368f;
        *(f32 *)(p + 0x34) += f;
    }
}

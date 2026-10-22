typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 f0; u8 pad1[0x33]; s8 f34[1]; } GA;
typedef struct { u8 pad[0xAA]; s8 fAA; u8 padAB[2]; s8 fAD; } GB;
typedef struct { u8 pad[0x2B4]; s16 f2B4; u8 pad2[0x17E]; s16 f434; } OB;
typedef struct { OB *tab[3]; } GE;
typedef struct { u8 pad[0x18]; GE e[1]; } GC;
extern GA *D_004C2794;
extern GB *D_004C2840;
extern s8 D_004F7F3F[];

s32 func_00188C70(u8 *p)
{
    extern s32 func_0018AC30();
    extern s32 func_00174170();
    extern s32 func_0018AA50(u8 *, s32, s16 *, s32);
    extern s32 func_0018A580(u8 *);
    extern void func_00186A60(u8 *, s32);
    GA *ga;
    GB *gb;
    OB *o;
    OB **t;
    s32 r;
    u8 s;
    s16 tmp;
    s32 d;

    if (p[0x20D] == 2 || p[0x20D] == 3) return 0;
    ga = D_004C2794;
    if (ga->f0 >= 5) return 0;
    if (ga->f34[p[2]] > 1) return 0;
    if (*(s8 *)(p + 0x205) != 0) return 0;
    if (*(s8 *)(p + 0x539) != 0) {
        if (p[0x471] == 0) return 0;
        if (*(s8 *)(p + 0x45C) != 0x7A) return 0;
        s = func_0018AC30(p);
        goto l8df8;
    }
    gb = D_004C2840;
    if (gb->fAA != 0) {
        d = D_004F7F3F[0];
        if (d > 0 && (d & (1 << p[2])) == 0 && gb->fAD != 0) {
            if (*(s16 *)(p + 0x434) > 0x14) return 0;
            s = (func_00174170() & 1) + 1;
            goto l8df8;
        }
    }
    s = 1;
    if (func_0018AA50(p, 0x240, &tmp, 0) == 0) {
        s = 2;
        if (func_0018AA50(p, 0x120, &tmp, 0) == 0) return 0;
    }
l8df8:
    if (func_0018A580(p) == 0) return 0;
    t = (OB **)((u8 *)(p[2] * 12) + (s32)D_004C2794 + 0x18);
    o = t[s];
    if (o->f2B4 != 0) return 0;
    if (o->f434 == 0) {
        s ^= 3;
        o = t[s];
        if (o->f2B4 != 0) return 0;
        if (o->f434 == 0) return 0;
    }
    p[0x26B] = s;
    func_00186A60(p, 0x1C);
    p[7] = 0;
    p[6] = 0;
    p[0x26A] = 0;
    return 1;
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001D6890(u8 *p, u8 *q) {
    extern s32 func_00175700(u8 *);
    u16 *r;
    p[0x24] = *(s8*)(q+0x24) + *(s8*)(p+0x31);
    r = (u16*)(p+0xD0);
    if (*(s8*)(p+0x24) > 7) p[0x24] = 7;
    if (*(s8*)(p+0x24) < 0) p[0x24] = 0;
    func_00175700(p);
    *(f32*)(p+0x34) = *(f32*)(q+0x34);
    *(f32*)(p+0x38) = *(f32*)(q+0x38);
    *(f32*)(p+0x34) += *(f32*)(p+0x5C);
    if (*(u16*)(q+0x168) != *r) { u32 t = p[4]; p[4] = t + 1; return; }
}

typedef struct { s16 x, y; } P2_001D7800;

typedef struct { u8 p0[0xD8]; s32 fd8; } SA_1D7800;
typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p1[0x104]; s16 f140; u8 p2[0x1E]; s16 f160; u8 p3[0x2A]; P2_001D7800 *f18c; u8 p4[0x144]; s32 f2d4; } SB_1D7800;

void func_001D7800(u8 *a, u8 *b)
{
    extern u8 *func_003DA750(u8 *, s32, s32);
    extern void func_001D7940(void);
    u8 *o;
    P2_001D7800 *e;
    s16 y, x;
    s16 f;

    o = func_003DA750(a, 3, 2);
    if (o != 0) {
        *(void **)(o + 0x10) = (void *)func_001D7940;
        *(u8 **)(o + 0x18) = a;
        *(s16 *)(o + 0x26) = 0x2F04;
        o[0x20] = 1;
        o[0x21] = 0;
        o[0x22] = *(s8 *)(a + 0xD8);
        f = 0;
        if ((b[0x15A] & 0xE0) != 0) f = 1;
        o[0x23] = f;
        *(u8 **)(o + 0x88) = b;
{ s32 i = ((SA_1D7800 *)a)->fd8 + ((SB_1D7800 *)b)->f160 * 6; e = ((SB_1D7800 *)b)->f18c; e += i; x = e->x; y = e->y; }
        if (((SB_1D7800 *)b)->f2d4 == 3) {
            x = x + 8;
            y = y + 8;
        }
        if (((SB_1D7800 *)b)->f140 != 0) x = -x;
        *(f32 *)(o + 0x34) = *(f32 *)(b + 0x34) - 1.6666666269302368f * (f32)x;
        *(f32 *)(o + 0x38) = *(f32 *)(b + 0x38) + 2.142857074737549f * (f32)y;
    }
}

void func_002E6670(u8 *p, u8 *q) {
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00183d50(u8 *);
    if (*(s8 *)(p + 0x151) == 0) {
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    } else if ((s8)func_00175700(p) < (s8)0) {
        q[5] = 0;
        func_001757E0(p, 0x15, 9);
    }
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(s8 *)(q + 5) = -1;
        *(f32 *)(p + 0x5C) = 0;
        *(f32 *)(p + 0x60) = 0;
        *(f32 *)(p + 0x68) = 0;
        *(f32 *)(p + 0x6C) = 0;
        func_00183d50(p);
        func_001757E0(p, 0x15, 0xB);
        return;
    }
}

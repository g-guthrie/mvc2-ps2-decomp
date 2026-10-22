typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 f0, f4, f8, fC, f10, f14; s32 e[12]; } Rb;
typedef struct { s32 f0, f4, f8, fC, f10, f14; } Ab;
typedef struct { u8 p0[8]; s32 f8; u8 pC[4]; s32 f10; u8 p14[4]; s16 f18; s16 f1A; s32 f1C; s32 f20; u8 p24[4]; s32 f28; } Bb;

s32 func_003EABA0(Ab *a, Bb *b, s32 c)
{
    extern s32 func_003DCFE0(s32, s32);
    extern s32 func_003DD030(s32);
    extern s32 func_003DB9C0(s32);
    extern void func_003DCDC0(s32, s32, s32);
    extern void func_003EB210(s32, s32, s32, s32, s32);
    extern void func_003EAEF0(Ab *, Rb *, s32, s32);
    extern void func_003ED0D0(char *);
    extern char D_004BAA00[];
    Rb r;
    s32 t;
    s32 lx, ly, lz;

    b->f28 = func_003DCFE0(b->f8, 2);
    r.f4 = a->f4;
    r.f8 = a->f8;
    r.f14 = a->f14;
    r.f0 = a->f0;
    r.fC = r.f4 * r.f14;
    switch (b->f1C) {
    default:
        func_003ED0D0(D_004BAA00);
        break;
    case 0x14:
        if (b->f20 == 0) {
            r.f10 = func_003DD030(b->f28);
            lz = b->f8;
            lx = r.f10;
            ly = a->f10;
            func_003DCDC0(lx, ly, lz);
        } else {
            t = func_003DD030(b->f28);
            r.f10 = func_003DB9C0(b->f8);
            lz = b->f8;
            lx = r.f10;
            ly = a->f10;
            func_003DCDC0(lx, ly, lz);
            func_003EB210(b->f18, b->f1A, r.f10, t, 0);
        }
        break;
    case 0x13:
        if (b->f20 == 0) {
            r.f10 = func_003DD030(b->f28);
            lz = b->f8;
            lx = r.f10;
            ly = a->f10;
            func_003DCDC0(lx, ly, lz);
        } else {
            t = func_003DD030(b->f28);
            r.f10 = func_003DB9C0(b->f8);
            lz = b->f8;
            lx = r.f10;
            ly = a->f10;
            func_003DCDC0(lx, ly, lz);
            func_003EB210(b->f18, b->f1A, r.f10, t, 1);
        }
        break;
    case 2: {
        s32 *p6c, *p84, *p74, *p7c;
        r.f10 = func_003DD030(b->f28);
        r.e[0] = 5;
        *(p6c = &r.e[1]) = 0xA;
        r.e[2] = 0x1F;
        p74 = &r.e[3]; *p74 = 5;
        r.e[4] = 5;
        p7c = &r.e[5]; *p7c = 0x1F;
        r.e[6] = 5;
        p84 = &r.e[7]; *p84 = 0;
        r.e[8] = 0x1F;
        r.e[9] = 1;
        r.e[10] = 0xF;
        r.e[11] = 1;
        *p6c = 0;
        *p84 = 0xA;
        *p74 = 5;
        *p7c = 0x1F;
        func_003EAEF0(a, &r, 0, c);
        break;
    }
    case 1: {
        s32 *p6c, *p84;
        r.f10 = func_003DD030(b->f28);
        r.e[0] = 8;
        *(p6c = &r.e[1]) = 0x10;
        r.e[2] = 0xFF;
        r.e[3] = 8;
        r.e[4] = 8;
        r.e[5] = 0xFF;
        r.e[6] = 8;
        p84 = &r.e[7]; *p84 = 0;
        r.e[8] = 0xFF;
        r.e[9] = 0;
        r.e[10] = 0;
        r.e[11] = 0;
        *p6c = 0;
        *p84 = 0x10;
        func_003EAEF0(a, &r, 0, c);
        break;
    }
    case 0: {
        s32 *p6c, *p84;
        r.f10 = func_003DD030(b->f28);
        r.e[0] = 8;
        *(p6c = &r.e[1]) = 0x10;
        r.e[2] = 0xFF;
        r.e[3] = 8;
        r.e[4] = 8;
        r.e[5] = 0xFF;
        r.e[6] = 8;
        p84 = &r.e[7]; *p84 = 0;
        r.e[8] = 0xFF;
        r.e[9] = 8;
        r.e[10] = 0x18;
        r.e[11] = 0xFF;
        *p6c = 0;
        *p84 = 0x10;
        func_003EAEF0(a, &r, 0, c);
        break;
    }
    }
    return 1;
}

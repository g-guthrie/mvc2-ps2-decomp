#pragma opt_propagation off
#pragma opt_lifetimes off
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0x8];
    s32 f8;
    u8 padC[0x18 - 0xC];
    s16 f18;
    s16 f1A;
    u8 pad1C[4];
    s32 f20;
    u8 pad24[4];
    s32 f28;
    u8 pad2C[0x40 - 0x2C];
} E40;

typedef struct {
    u8 pad0[0x14];
    s32 f14;
    u8 pad18[0x50 - 0x18];
} B50;

extern E40 D_006207A0[];
extern E40 D_0061C7A0[];

u32 func_00418200(s32 p0, s32 p1)
{
    extern u32 func_003E8F90();
    extern void func_003F4C10(B50 *, s32);
    extern void func_003E8C00(B50 *, u32, s32);
    extern s32 func_003DCFE0(s32, s32);
    extern s32 func_003DD030(s32);
    extern s32 func_003F5070(s32);
    extern s32 func_003F5080(s32);
    extern void func_003DCDC0(s32, s32, s32);
    extern void func_003EB210(s32, s32, s32, s32, s32);
    extern u32 func_003E93A0();
    extern void func_003F4E70(B50 *, s32);
    extern void func_003E9110(B50 *, u32, s32);
    extern void func_003E9250(u32, s32);
    extern void func_003E8DF0(u32, s32);
    B50 b1;
    B50 b2;
    E40 *e;
    s32 *t;
    s32 a1 = p1;
    s32 a0 = p0;
    u32 r2;
    u32 r1;
    s32 h;
    s32 v;

    r2 = 0;
    r1 = func_003E8F90();
    { s32 k = -1; e = &D_006207A0[(r1 & 0xFFFF) + k]; }
    func_003F4C10(&b1, a0);
    func_003E8C00(&b1, r1, a1);
    e->f28 = func_003DCFE0(e->f8, 2);
    t = &b1.f14;
    switch (*t) {
    case 0:
    case 1:
        r2 = func_003DD030(e->f28);
        v = func_003F5070(a0);
        if (e->f20 == 0) {
            func_003DCDC0(r2, v, e->f8);
        } else {
            func_003EB210(e->f18, e->f1A, v, r2, *t);
        }
        r2 = func_003E93A0();
        e = &D_0061C7A0[((r2 & 0xFFFF0000) >> 16) - 1];
        func_003F4E70(&b2, a0);
        func_003E9110(&b2, r2, a1);
        e->f28 = func_003DCFE0(e->f8, 2);
        h = func_003DD030(e->f28);
        func_003DCDC0(h, func_003F5080(a0), e->f8);
        func_003E9250(r2, a1);
        break;
    case 4:
        h = func_003DD030(e->f28);
        func_003DCDC0(h, func_003F5070(a0), e->f8);
        break;
    default:
        h = func_003DD030(e->f28);
        func_003DCDC0(h, func_003F5070(a0), e->f8);
        break;
    }
    func_003E8DF0(r1, a1);
    return r1 | r2;
}

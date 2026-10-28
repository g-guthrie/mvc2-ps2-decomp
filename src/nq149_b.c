typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x18 - 0xC]; s16 f18; s16 f1a; u8 pad2[0x28 - 0x1C]; s32 f28; u8 pad3[0x40 - 0x2C]; } E149b;
typedef struct { u8 pad0[8]; s32 f8; s32 fc; s32 f10; u8 pad1[0x50 - 0x14]; } W149b;
extern E149b D_006207A0[];
extern E149b D_0061C7A0[];

s32 func_00415B00(u8 *p, s32 q) {
    extern u32 func_003E8F90();
    extern void func_00415CE0(W149b *, u8 *);
    extern void func_003E8C00(W149b *, u32, s32);
    extern s32 func_003DCFE0(s32, s32);
    extern s32 func_003DD030(s32);
    extern void func_003DCDC0(s32, s32, s32);
    extern void func_003DD1D0(s32, s32, s32);
    extern u32 func_003E93A0();
    extern void func_00415F30(W149b *, u8 *);
    extern void func_003E9110(W149b *, u32, s32);
    extern void func_00416110(s32, s32, W149b *);
    extern void func_003E9250(u32, s32);
    extern void func_003E8DF0(u32, s32);
    W149b a;
    W149b b;
    u32 h;
    u32 r;
    E149b *e;
    s32 o;
    s32 s6;
    s32 r2;
    r = 0;
    h = func_003E8F90();
    e = &D_006207A0[(h & 0xFFFF) - 1];
    func_00415CE0(&a, p);
    func_003E8C00(&a, h, q);
    e->f28 = func_003DCFE0(e->f8, 2);
    switch (*(u32 *)(p + 4) & 0xF0) {
    case 0:
        s6 = a.f10;
        o = func_003DD030(e->f28);
        func_003DCDC0(o, s6, a.fc * a.f8);
        if ((*(u32 *)(p + 4) & 0xF) == 4) {
            func_003DD1D0(o, e->f18, e->f1a);
        }
        break;
    case 0x10:
    case 0x20:
        r2 = a.f10;
        func_003DCDC0(func_003DD030(e->f28), r2, a.fc * a.f8);
        r = func_003E93A0();
        e = &D_0061C7A0[((r & 0xFFFF0000) >> 16) - 1];
        func_00415F30(&b, p);
        func_003E9110(&b, r, q);
        e->f28 = func_003DCFE0(e->f8, 2);
        o = b.f10;
        func_00416110(o, func_003DD030(e->f28), &b);
        func_003E9250(r, q);
        break;
    }
    func_003E8DF0(h, q);
    return r | h;
}

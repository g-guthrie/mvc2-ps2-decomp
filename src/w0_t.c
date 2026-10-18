typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    s32 f0; s32 f4; s32 f8; s32 fC; s16 f10; s16 f12; s16 f14; s16 f16; s16 f18; s16 f1A; s32 f1C;
    s32 f20; s32 f24; s32 f28; s16 f2C; s16 f2E; s32 f30; s32 f34; s32 f38; s32 f3C;
} E;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; } P;
extern E D_0061C7A0[];
s32 func_003E9110(P *p, u32 packed, s32 x) {
    extern void func_003ED0D0();
    extern s16 func_003EAA30();
    extern s16 func_003EAB40();
    extern s32 func_003EA990();
    extern u8 D_004BA920[];
    extern u8 D_004BA960[];
    E *e = &D_0061C7A0[((packed & 0xFFFF0000) >> 16) - 1];
    if (p->f8 != 1) {
        func_003ED0D0(D_004BA920);
        return 0;
    }
    switch (p->f14) {
    default:
        func_003ED0D0(D_004BA960);
        return 0;
    case 2:
        e->f1C = 2;
        e->fC = 2;
        break;
    case 3:
        e->f1C = 1;
        e->fC = 3;
        break;
    case 4:
        e->f1C = 0;
        e->fC = 4;
        break;
    }
    if (p->f4 == 0x100) {
        e->f18 = 0x10;
        e->f1A = 0x10;
    } else {
        e->f18 = 8;
        e->f1A = 2;
    }
    e->f4 = p->f0;
    e->f0 = x;
    e->f2C = 1;
    e->f14 = func_003EAA30(e->f18);
    e->f16 = func_003EAA30(e->f1A);
    e->f10 = func_003EAB40(e);
    e->f8 = func_003EA990(e);
    e->f20 = 0;
    e->f28 = 0;
    e->f30 = 0;
    e->f34 = 0;
    return 1;
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3b;
extern s8 D_004D1900;
extern V3b D_00444BA0;

void func_00156520(V3b *p, s32 a1, s32 a2, s32 a3, s32 a4) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00156750();
    extern void func_001567A0(u8 *, s32);
    extern void func_001568A0(u8 *, s32);
    extern void func_001569C0(u8 *, s32);
    extern void func_00156AD0(u8 *, s32);
    extern void func_001550D0(V3b *, s32, s32, s32);
    u8 *o;
    if ((o = func_003DA750(0, a4, 1)) != 0) {
        D_004D1900++;
        o[0x13C] = 0;
        *(void **)(o + 0x10) = (void *)func_00156750;
        *(V3b *)(o + 0x34) = *p;
        *(s32 *)(o + 0xD0) = 0x800181;
        if (a2 == 1) {
            *(s32 *)(o + 0xD0) |= 0x10;
            *(V3b *)(o + 0x50) = D_00444BA0;
        }
        func_001567A0(o, a4);
        func_001568A0(o, a4);
        func_001569C0(o, a4);
        func_00156AD0(o, a4);
        func_001550D0(p, a2, a3, a4);
    }
}

void func_002F6620(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_002F6450(u8 *);
    extern void func_00126400();
    extern void func_001E3A40(u8 *);
    s32 v;
    if (p[7] == 0) {
        if (*(s8 *)(p + 0x151) > 0) {
            *(s8 *)(p + 0x151) = 0;
            v = *(s16 *)(p + 0x140) ^ 1;
            *(s16 *)(p + 0x140) = v;
            *(s8 *)(p + 0x1E6) = *(s8 *)(p + 0x140);
        }
        if (*(s8 *)(p + 0x151) >= 0) {
            func_00175700(p);
        }
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[7]++;
            p[0x20D] = 0;
        }
    } else {
        if (func_00175700(p) < 0) {
            func_002F6450(p);
            return;
        }
        if (p[0x15B] != 0) {
            (*(u8 **)(p + 0x1DC))[0x20A] = 0xB;
            (*(u8 **)(p + 0x1DC))[0x1B5] = p[0x15B];
            *(u8 **)(*(u8 **)(p + 0x1DC) + 0x1C8) = p;
            p[0x15B] = 0;
            func_00126400();
            func_001E3A40(*(u8 **)(p + 0x1DC));
        }
    }
}

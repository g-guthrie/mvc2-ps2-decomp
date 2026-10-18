typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern void (*D_0043CBF8[])(void);
extern void func_0016E960(void);
extern void func_00152720(void);
extern void func_00152660(void);
extern void func_003D7310(void (*f)(void));
extern void func_003DA6F0(s32 n);
void func_00127140(void) {
    if (*(s8*)(D_004C2840 + 0x90) != 0) {
        func_0016E960();
        if (*(s8*)(D_004C2840 + 0x92) < 2) {
            func_003D7310(func_00152720);
        }
        func_003D7310(func_00152660);
    } else {
        D_0043CBF8[*(s8*)(D_004C2840 + 4)]();
        func_003DA6F0(6);
        func_003DA6F0(0xD);
        func_003D7310(func_00152720);
    }
}

extern u8 D_004C0858[4];
extern u32 func_00174170(void);
void func_00280A30(u8 *p) {
    u32 t = p[0x452];
    switch (t) {
    case 0: {
        u32 r;
        u32 w;
        u32 o;
        p[0x452] = t + 1;
        r = func_00174170();
        o = p[0x472];
        w = D_004C0858[p[0x470]] + r % (*(s8*)(p + 0x45D) + 1) + 1;
        p[0x472] = o + (w & 0xFF);
        break;
    }
    case 1: {
        u32 v = p[0x472] - 1;
        p[0x472] = v;
        if ((u8)v == 0) p[0x451] = 1;
        break;
    }
    }
}

extern void (*D_004C2010[2])(u8*,s32);
extern void (*D_00474128[])(u8*,s32);
extern void (*D_004C2018[2])(u8*,s32);
void func_003B6470(u8 *p, s32 q) { switch (p[0x20]) {
    case 0: D_004C2010[p[5]](p,q); break;
    case 1: D_00474128[p[5]](p,q); break;
    case 2: D_004C2018[p[5]](p,q); break;
    }
}

extern u8 *D_004C2840;
extern s8 D_004C2604;
extern void func_0012D830(void);
extern void func_0012DA00(void);
extern void func_00129060(s32 a, void (*f)(void));
extern s32 func_001316D0(void);
extern void func_001E3CE0(s32 a);
extern void func_003298B0(u32 a, s32 b, s32 c);
void func_0012D950(void) {
    *(s16*)(D_004C2840 + 0xE) = *(s16*)(D_004C2840 + 0xE) - 1;
    if (*(s16*)(D_004C2840 + 0xE) == 0) {
        D_004C2840[7] = 0;
        D_004C2840[6] = D_004C2604;
        D_004C2840[5] = 1;
        func_00129060(8, func_0012D830);
    }
    if (func_001316D0() != 0) {
        func_001E3CE0(3);
        D_004C2840[5] = 3;
        func_003298B0(0xFF000000, 10, 1);
        func_00129060(8, func_0012DA00);
    }
}

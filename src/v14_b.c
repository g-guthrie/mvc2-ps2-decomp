typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3_001CB680;

void func_00177820(u8 *p) {
    extern void func_0018F320();
    extern void func_00175700();
    extern s32 func_001864A0();
    extern void func_001E3B30();
    extern void func_00158C70();
    extern void func_001757E0();
    func_0018F320(p);
    func_00175700(p);
    if (*(f32 *)(p + 0x60) <= 0.0f) {
        if (func_001864A0(p) != 0) {
            u32 t = p[6];
            p[6] = t + 1;
            *(f32 *)(p + 0x60) = -(*(f32 *)(p + 0x60) / 2.0f);
            func_001E3B30(p);
            func_00158C70(p + 0x34, p[2]);
            p[0x20D] = 2;
            *(s16 *)(p + 0x1C) = 0;
            func_001757E0(p, 0xD, 0x1C);
        }
    }
}

extern void func_001CB680(u8 *p, u8 *o);

/* func_001CBBC0: not yet matched without a stand-in callee. */

void func_00362E20(u8 *p, u8 *q) {
    extern void func_00175700();
    extern void func_001757E0();
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= 171.4285583f + *(f32 *)(q + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x17, 0x1E);
    }
}

void func_00362D50(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    s16 v;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x5C) /= 2.0f;
        *(f32 *)(p + 0x60) /= 2.0f;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x17, 0x1D);
    }
}

void func_00224120(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_00224200();
    s16 v;
    f32 f;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        if (p[0x1E6] != 0)
            f = 6.666666507720947f;
        else
            f = -6.666666507720947f;
        *(f32 *)(p + 0x5C) = f;
        func_001757E0(p, 2, 2);
        func_00224200(p);
        return;
        func_001757E0(p, 2, 2);
        func_00224200(p);
    }
}

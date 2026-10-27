typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00323780(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, u8);
    extern void func_003C9F30(u8 *, s32, s32);
    extern void func_00183d50(u8 *);
    u32 s0;
    s32 *s1, *s2, *s3, *s4;
    s32 a0, a1;
    u32 t;
    f32 f;
    func_00175700(p);
    s1 = (s32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    s3 = (s32 *)(p + 0x68);
    s2 = (s32 *)(p + 0x60);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    s4 = (s32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x150) != 0) {
        a1 = p[0x1B7];
        a0 = 0x200; if (a1 != 0) a0 = 0x100;
        if ((*(u16 *)(p + 0x35E) & a0) == 0) {
            s0 = p[0x15B];
            func_001757E0(p, 0x15, (a1 & 0xFF) + 0xE);
            goto common;
        }
    }
    if (*(s8 *)(p + 0x151) != 0) {
        s0 = p[0x15B];
    common:
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        func_003C9F30(p, p[0x1B7], s0);
    }
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        if (p[0x20D] == 2) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[0x20D] = 0;
            *s1 = 0;
            *s2 = 0;
            *s3 = 0;
            *s4 = 0;
            func_00183d50(p);
        }
    }
}

void func_003AC580(u8 *a, u8 *b) {
    extern void func_00182C30(u8 *, s32);
    extern void func_00182DB0(u8 *, s32);
    extern u8 *func_003AD580(u8 *, u8 *, s16 *);
    extern void func_001D8580(u8 *, s32, s32);
    extern void func_00329220(u8 *, s32, s32);
    extern void func_003AC6F0(u8 *, u8 *);
    u8 *x, *q, *r;
    u8 *s0;
    s32 s1;
    u8 *s2;
    s32 s3;
    s0 = *(u8 **)(a + 0x18);
    x = *(u8 **)(s0 + 0x1DC);
    *(s8 *)(x + 0x24E) = *(s8 *)(x + 0x24E) + 2;
    a[5] = 5;
    *(s16 *)(b + 8) = 0;
    *(s16 *)(a + 0x1C) = 0x3C;
    func_00182C30(x, 0x18);
    func_00182DB0(s0, 6);
    if (s0[6] == 9) *(s16 *)(b + 0x30) = 1;
    else *(s16 *)(b + 0x30) = 2;
    s2 = a;
    q = b;
    s3 = 0;
    for (s1 = 0; *(s8 *)(b + 0xF) >= s1; s1++) {
        *(s16 *)(q + 0xA) = s3;
        if (s3 != 0 && ((s16)s3 & 1) == 0) {
            r = func_003AD580(s2, a, (s16 *)(b + 8));
            if (r != 0) {
                *(s16 *)(r + 0x1C) = 2;
                *(s16 *)(r + 0x1E) = *(s8 *)(b + 0xF) - s1;
                r[0x21] = *(s8 *)(b + 0x30);
            }
        }
        s2 = *(u8 **)(s2 + 0xC);
        s3 = (s16)(s3 - 1);
        q = s2 + 0x88;
    }
    func_001D8580(s0, 0, 0);
    func_001D8580(s0, 0, 1);
    func_00329220(s0, *(s32 *)(b + 0x28), 0);
    func_003AC6F0(a, b);
}

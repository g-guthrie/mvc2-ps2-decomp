typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2660;
extern u8 *D_004C2840;
extern f32 D_00474280[];
extern f32 D_00474284[];
extern f32 D_004F1FC8[];
extern f32 D_004F1FCC[];

extern void func_003DAA40(void *p);
extern void func_003298B0(u32 a, s32 b, s32 c);
extern void func_001ABAD0(void *p, void *owner);
extern void func_001757E0(void *p, s32 a, s32 b);

void func_003B7FC0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    f32 d, e;
    if (p[0x20] == 0) {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = 218.5714264f + *(f32 *)(q + 0x38);
        d = 81.66666412f;
        if (q[0x1E6] == 0) d = -d;
        *(f32 *)(p + 0x34) += d;
    } else {
        u8 *r = *(u8 **)(p + 0x14);
        *(f32 *)(p + 0x34) = *(f32 *)(r + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(r + 0x38) + D_00474284[q[0x1B7] * 2];
        e = D_00474280[q[0x1B7] * 2];
        if (q[0x1E6] == 0) e = -e;
        *(f32 *)(p + 0x34) += e;
    }
}

void func_0016BDC0(void) {
    if (D_004C2660 != 0) {
        s16 v = *(s16 *)(D_004C2840 + 8) - 1;
        *(s16 *)(D_004C2840 + 8) = v;
        if (v == 0) {
            if (D_004C2660 != 0) func_003DAA40(D_004C2660);
            D_004C2660 = 0;
            *(s16 *)(D_004C2840 + 8) = 0x20;
            func_003298B0(0xFF000000, 0x20, 1);
        }
    } else {
        s16 v = *(s16 *)(D_004C2840 + 8) - 1;
        *(s16 *)(D_004C2840 + 8) = v;
        if (v == 0) {
            D_004C2840[5] = 5;
            *(s16 *)(D_004C2840 + 8) = 0xF0;
            func_003298B0(0xFF000000, 0x20, 0);
        }
    }
}

void func_001ABA00(u8 *p, u8 *owner) {
    s16 h;
    func_001ABAD0(p, owner);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    h = *(s16 *)(p + 0x140);
    if ((h == 0 && *(f32 *)(p + 0x34) <= 46.66666412f + D_004F1FC8[0]) ||
        (h != 0 && !(*(f32 *)(p + 0x34) < D_004F1FCC[0] - 46.66666412f))) {
        u32 t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0x17, 0x15);
    }
}

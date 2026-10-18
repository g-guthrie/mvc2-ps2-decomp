typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern f32 D_004F1FC8;
extern f32 D_004F1FCC;
typedef struct { f32 x, y, z; } V3;
extern u8 *D_004D18BC;
extern u8 D_004D18A0;
extern f32 D_004F1FD4;
extern f32 D_004F1F4C;

s32 func_00381710(u8 *p) {
    s32 r = 1;
    s16 h = *(s16 *)(p + 0x140);
    if ((h == 0 && *(f32 *)(p + 0x34) < D_004F1FC8 - 1.6666666269302368f * (f32)(u32)p[0x14F]) ||
        (h != 0 && !(*(f32 *)(p + 0x34) <= D_004F1FCC + 1.6666666269302368f * (f32)(u32)p[0x14F])))
        r = 0;
    return r;
}

void func_0015C190(u8 *p) {
    u8 *q;
    f32 c = 100.0f;
    f32 v, w;
    q = D_004D18BC;
    p[0x13C] = 0;
    if (q[0] != 0 && q[0x269] == 8 && D_004D18A0 == 4 && *(s8 *)(q + 0x13C) != 0) p[0x13C] = 1;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    *(f32 *)(p + 0x38) += 2.1428570747375488f * (f32)(u32)q[0x14C] * *(f32 *)(q + 0x54);
    w = *(f32 *)(p + 0x38) + c;
    *(f32 *)(p + 0x38) = w;
    v = c + D_004F1FD4;
    if (w <= v) *(f32 *)(p + 0x38) = v;
}

void func_00271160(u8 *p) {
    extern void func_00175700();
    extern void func_00271700(u8 *);
    extern void func_001757E0(u8 *, s32, u8);
    s16 v;
    f32 *q = (f32 *)(p + 0x2B8);
    f32 a, b;
    *(f32 *)(p + 0x34) += D_004F1F4C - *q;
    *q = D_004F1F4C;
    func_00175700();
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    a = *(f32 *)(p + 0x38);
    b = *(f32 *)(p + 0x430);
    if (a <= b) {
        func_00271700(p);
        return;
    }
    if (222.8571319580078f + b <= a) {
        if (*(s8 *)(p + 0x211) != 0) {
            p[6]++;
            v = p[0x1E6] ^ 1;
            *(s16 *)(p + 0x140) = v;
            p[0x1E6] = v;
            func_001757E0(p, 0x15, p[0x1B7] + 0xE);
        }
    }
}

void func_001E0B90(u8 *p, u8 *q) {
    extern void func_0015B200();
    extern void func_001E0CA0(u8 *, u8 *);
    f32 v[3];
    if (q[5] == 0) {
        if (q[0x1E4] == 0x15 && q[0x1FD] == 9) {
            p[0x13C] = 1;
            *(s32 *)(p + 0x154) = *(s32 *)(q + 0x154);
            *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
            *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
            *(f32 *)(q + 0x38) = *(f32 *)(q + 0x430) + 2.1428570747375488f * (f32)(u32)q[0x15B];
            return;
        }
    } else {
        v[0] = *(f32 *)(p + 0x34);
        v[1] = 102.85713958740234f + *(f32 *)(q + 0x430);
        v[2] = *(f32 *)(p + 0x3C);
        func_0015B200(p, v, 1, 8);
    }
    func_001E0CA0(p, q);
}

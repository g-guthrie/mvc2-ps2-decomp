typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001E3710();
extern u8 func_001E3940(u8 *p);
extern u8 D_004D1820[];
extern u8 D_0061BEE0[];
extern u8 D_004F1FEC[];
extern u8 D_004F1FF8[];
extern u8 D_004F2034;
extern u8 D_004F2035;
extern void func_00126970(u8 *a, u8 *b);
extern void func_001757E0(u8 *p, s32 a, s32 b);

void func_003D7D10(u8 *d, u8 *s) {
    f32 t;
    if (*(s16 *)(s + 0x140) != 0) goto other;
    *(f32 *)(d + 0x34) = *(f32 *)(s + 0x34);
    goto done;
other:
    *(f32 *)(d + 0x34) = *(f32 *)(s + 0x34);
done:
    t = *(f32 *)(s + 0x38);
    *(f32 *)(d + 0x38) = 274.2857f + t;
}

void func_002E8B20(u8 *p) {
    f32 x = 10.714285f;
    { u32 t = p[6]; p[6] = t + 1; }
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) = x;
    *(f32 *)(p + 0x6C) = -x / 16.0f;
    func_001757E0(p, 13, 29);
}

void func_001258A0(void) {
    D_004F2034 = 0;
    D_004F2035 = 0;
    func_00126970(D_004F1FEC, D_004F1FF8);
    *(f32 *)D_004F1FF8 = *(f32 *)D_004F1FEC;
}

void func_00228D50(u8 *p) {
    f32 a = -13.333333f;
    f32 b = 0.41666666f;
    if (*(s16 *)(p + 0x140) != 0) {
        a = -a;
        b = -b;
    }
    *(f32 *)(p + 0x5C) = a;
    *(f32 *)(p + 0x60) = 12.8571424f;
    *(f32 *)(p + 0x68) = b;
    *(f32 *)(p + 0x6C) = -0.535714269f;
}

void func_00364E70(u8 *d) {
    u8 *q = *(u8 **)(d + 0x1C4);
    s32 n;
    *(f32 *)(d + 0x34) = *(f32 *)(q + 0x34);
    n = q[0x14C];
    *(f32 *)(d + 0x38) = *(f32 *)(q + 0x38) + 2.142857f * (f32)(n / 2);
}

f32 func_001AC390(u8 *p, s32 n) {
    if (*(s16 *)(p + 0x140) == 0) {
        return *(f32 *)(p + 0x34) + 1.6666666f * (f32)n;
    }
    return *(f32 *)(p + 0x34) - 1.6666666f * (f32)n;
}

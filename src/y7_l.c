typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_004000D0(s32 a0) { return a0 + 0x58; }



void func_001C2E80(u8 *a, u8 *b) {
    extern void func_00175700();
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
    func_00175700(a);
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    if (b[0x1E4] != 0x16) {
        a[7] = 4;
    } else if (*(s16 *)(a + 0x140) == 0) {
        if (*(f32 *)(a + 0x34) <= 80.0f + *(f32 *)(b + 0x34)) {
            u32 t = a[7];
            a[7] = t + 1;
            *(s16 *)(b + 0x1C) = 0;
        }
    } else {
        if (!(*(f32 *)(a + 0x34) < *(f32 *)(b + 0x34) - 80.0f)) {
            u32 t = a[7];
            a[7] = t + 1;
            *(s16 *)(b + 0x1C) = 0;
        }
    }
}

s32 func_00165900(u8 *a, u8 *b) {
    extern s32 func_0016B250();
    extern void func_0016B0C0();
    extern void func_00186CE0();
    u16 s1;
    s32 v;
    if (func_0016B250(a, 5) == 0) return 0;
    func_0016B0C0(a, b, 0);
    func_0016B0C0(a, b, 1);
    v = *(s32 *)(a + 0x4C8);
    switch (v) {
    case 0:
        s1 = 0x2800;
        break;
    case 0xFF:
        s1 = 0x2000;
        break;
    case 1:
        s1 = 0x2400;
        break;
    }
    a[0x1E7] = v;
    *(s16 *)(a + 0x35E) = s1;
    func_00186CE0(a, 0xD);
    *(s16 *)(a + 0x35E) = 0;
    if (s1 & 0xC00) s1 = s1 ^ (a[0x1E6] * 3 << 10);
    *(s16 *)(a + 0x4F0) = s1;
    return 0;
}

s32 func_00165720(u8 *a, u8 *b) {
    extern s32 func_0016B240();
    extern void func_0016B0C0();
    extern void func_00186CE0();
    u16 s1;
    s32 v;
    if (func_0016B240(a, 0) == 0) return 0;
    func_0016B0C0(a, b, 0);
    func_0016B0C0(a, b, 1);
    v = *(s32 *)(a + 0x4C8);
    switch (v) {
    case 0:
        s1 = 0x2800;
        break;
    case 0xFF:
        s1 = 0x2000;
        break;
    case 1:
        s1 = 0x2400;
        break;
    }
    a[0x1E7] = v;
    *(s16 *)(a + 0x35E) = s1;
    func_00186CE0(a, 2);
    *(s16 *)(a + 0x35E) = 0;
    if (s1 & 0xC00) s1 = s1 ^ (a[0x1E6] * 3 << 10);
    *(s16 *)(a + 0x4F0) = s1;
    return 0;
}

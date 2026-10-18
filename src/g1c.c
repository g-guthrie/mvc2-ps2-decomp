typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_003DAA40();
extern s8 D_004F7F4C;
extern s8 D_004F7F33;
extern void func_00176160();
extern void func_00186A60();

s32 func_0038D220(s32 a) {
    s32 r;
    switch (a) {
    case 0: r = 0; break;
    case 1: r = 0x754; break;
    case 2: r = 0; break;
    case 3: r = 0; break;
    case 4: r = 0xDD4; break;
    default: r = 0; break;
    }
    return r;
}

void func_003CF8C0(u8 *p) {
    if (D_004F7F4C != 4) {
        func_003DAA40(p);
    } else if (D_004F7F33 != p[0x21]) {
        u32 f = 0x3F333333;
        *(u32 *)(p + 0x80) = f;
        *(u32 *)(p + 0x7C) = f;
        *(u32 *)(p + 0x78) = f;
    } else {
        u32 f = 0x3F800000;
        *(u32 *)(p + 0x80) = f;
        *(u32 *)(p + 0x7C) = f;
        *(u32 *)(p + 0x78) = f;
    }
}

void func_00212DE0(u8 *a, u8 *b) {
    s8 v = *(s8 *)(b + 7) - 1;
    *(s8 *)(b + 7) = v;
    if (v < 0) {
        s32 x;
        u32 n;
        *(s8 *)(b + 7) = 1;
        n = (a[0x25] << 1) + 0x50;
        x = *(s8 *)(b + 6) ^ 1;
        *(s8 *)(b + 6) = x;
        if ((s8)x) n += 1;
        func_00176160(a, 0, n, 1);
    }
}

void func_0028D730(u8 *a) {
    u8 *c;
    a[5] = 0;
    a[7] = 0;
    a[6] = 0;
    c = a + 0x2B8;
    switch (*(s8 *)(a + 0x4DD)) {
    case 0:
        a[0x1FD] = 0;
        a[0x20D] = 0;
        c[2] = 2;
        break;
    case 1:
        a[0x1FD] = 2;
        a[0x1B7] = 1;
        break;
    case 2:
        a[0x1FD] = 0;
        a[0x20D] = 0;
        c[2] = 2;
        break;
    }
    func_00186A60(a, 0x15, c);
}

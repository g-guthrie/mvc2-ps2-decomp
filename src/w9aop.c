typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(void *p);
void func_00258690(u8 *p) {
    f32 f;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x151) == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        if (p[0x1E6] != 0) {
            f = 0.41666666f;
        } else {
            f = -0.41666666f;
        }
        *(f32 *)(p + 0x68) = f;
    }
    func_00175700(p);
}

extern s32 func_001746D0(void *p);
extern void func_001E7F60(void *p);
void func_003826D0(u8 *p) {
    p[0x13C] = 0;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (func_001746D0(p) == 0) {
        u32 t = p[4];
        p[4] = t + 1;
    } else {
        p[0x13C] = 1;
        func_001E7F60(p);
    }
}

extern void func_001A0B20(void *p, s32 a);
void func_00235360(u8 *p) {
    s8 a;
    f32 v;
    u32 t;
    p[0x209] = 2;
    func_00175700(p);
    a = p[0x151];
    if (a & 1) {
        p[0x151] = a ^ 1;
        v = 53.333332f;
        if (p[0x1E6] != 0) v = -v;
        *(f32 *)(p + 0x34) += v;
    }
    if (*(s8 *)(p + 0x151) & 2) {
        t = p[7];
        p[7] = t + 1;
        p[0x151] = p[0x151] ^ 2;
        func_001A0B20(p, 1);
    }
}

extern void func_001757E0(void *p, s32 a, s32 b);
void func_00380970(u8 *p) {
    f32 k;
    u32 t;
    s8 r;
    if (p[6] == 0) {
        p[6] = p[6] + 1;
        p[0x24] = 10;
        p[0x31] = 0;
        k = 1.2f;
        *(f32 *)(p + 0x50) = k * *(f32 *)(p + 0x64);
        *(f32 *)(p + 0x54) = k * *(f32 *)(p + 0x70);
        *(u32 *)(p + 0x118) = 0x3F000000;
        func_001757E0(p, 0x17, 5);
    }
    r = func_00175700(p);
    if (r < 0) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}

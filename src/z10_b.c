typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3_6D700;
void func_0026D700(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_001843A0();
    f32 z = 0.0f;
    s8 r;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (z != *(f32 *)(p + 0x6C)) {
        *(f32 *)(p + 0x6C) = *(f32 *)(p + 0x6C) - 1.0f;
    }
    *(f32 *)(p + 0x50) = *(f32 *)(p + 0x298) + *(f32 *)(p + 0x6C) / *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x54) = *(f32 *)(p + 0x29C) + *(f32 *)(p + 0x6C) / *(f32 *)(p + 0x68);
    r = func_00175700(p);
    if (r < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        *(V3_6D700 *)(p + 0x50) = *(V3_6D700 *)(p + 0x298);
        func_001843A0(p);
    }
}

void func_00359C70(u8 *p, s32 q) {
    extern int func_00175700(u8 *);
    extern void func_0035ADE0();
    extern void func_0035AE70();
    extern void func_0035A7B0();
    extern void func_0035ACA0();
    u8 *o = *(u8 **)(p + 0x18);
    f32 t;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_0035ADE0(p, q);
    t = 34.28571319580078f + *(f32 *)(o + 0x430);
    if (t > *(f32 *)(p + 0x38)) {
        *(f32 *)(p + 0x38) = t;
        p[0x21] = 0;
        func_0035AE70(p, q);
    }
    func_0035A7B0(p, q);
    func_0035ACA0(p, q);
}

extern f32 D_004F1FC8;
extern f32 D_004F1FCC;
void func_00163B70(u8 *p) {
    extern u8 *func_003DA750();
    extern void func_00163C70();
    u8 *o;
    s32 n;
    f32 f;
    if ((o = func_003DA750(0, 0x2F, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_00163C70;
        *(s32 *)(o + 0xD0) = 0x800405;
        switch (*(s8 *)(p + 0x211)) {
        case 1:
            *(f32 *)(o + 0x34) = D_004F1FCC;
            break;
        case 2:
            *(f32 *)(o + 0x34) = D_004F1FC8;
            break;
        }
        n = p[0x14C];
        f = 2.142857074737549f * (f32)(n / 2);
        *(f32 *)(o + 0x38) = *(f32 *)(p + 0x38) + f * *(f32 *)(p + 0x54);
        *(u32 *)(o + 0x78) = 0x3F800000;
        *(u32 *)(o + 0x7C) = 0x3F800000;
        *(u32 *)(o + 0x80) = 0x3F800000;
        *(s32 *)(o + 0x44) = (*(s16 *)(p + 0x140) != 0) ? 0x4000 : 0xC001;
        *(s32 *)(o + 0xD4) = 3;
    }
}

typedef struct { f32 x, y, z; } V3_1448E0;
extern V3_1448E0 D_004B3200[];
void func_001448E0(u8 *p) {
    V3_1448E0 *a = &D_004B3200[p[0x20] * 2];
    V3_1448E0 *b = &D_004B3200[p[0x20] * 2 + 1];
    *(f32 *)(p + 0x34) = a->x + (f32)*(s16 *)(p + 0x1C) * (b->x - a->x) / 90.0f;
    *(f32 *)(p + 0x38) = a->y + (f32)*(s16 *)(p + 0x1C) * (b->y - a->y) / 90.0f;
    *(f32 *)(p + 0x3C) = a->z + (f32)*(s16 *)(p + 0x1C) * (b->z - a->z) / 90.0f;
    *(f32 *)(p + 0x34) /= 10.0f;
    *(f32 *)(p + 0x38) /= 10.0f;
    *(f32 *)(p + 0x3C) /= 10.0f;
}

void func_0024F570(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_001757E0();
    s16 v;
    f32 a, b;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        if (p[0x1E6] != 0) {
            a = -13.33333301544189f;
        } else {
            a = 13.33333301544189f;
        }
        *(f32 *)(p + 0x5C) = a;
        if (p[0x1E6] != 0) {
            b = 0.4166666567325592f;
        } else {
            b = -0.4166666567325592f;
        }
        *(f32 *)(p + 0x68) = b;
        func_001757E0(p, 2, 3);
    }
}

typedef struct { f32 x, y, z; } V3_299E80;
extern V3_299E80 D_00583B80;
void func_00299E80(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_00186A20();
    extern u8 *func_001C8FD0(u8 *, s32);
    extern void func_001830D0();
    V3_299E80 v;
    u32 t;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 2) {
        v = D_00583B80;
        t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0x2D;
        *(s16 *)(p + 0x1E) = 0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(u32 *)(p + 0x60) = 0x41892492;
        func_00186A20(p);
        func_001C8FD0(p, 1);
        p[0x404] = 0;
        p[0x405] = 0;
        v.x += 33.33333206176758f;
        v.y += 85.71427917480469f;
        func_001830D0(p, &v, 1);
    }
}

extern f32 D_004F1FDC;
extern f32 D_004F1FD8;
void func_00180E20(u8 *p) {
    extern void func_00191210();
    extern void func_0011D8F8();
    extern void func_001E3210();
    f32 c;
    u8 z;
    p[0] = 0;
    p[0x13C] = 0;
    p[4] = 1;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x249] = 0;
    func_00191210(p);
    p[0x1E5] = 0;
    p[0x1E4] = 0;
    p[0x206] = 0;
    p[0x207] = 0;
    p[0x15A] = 0;
    p[0x20D] = 0;
    func_0011D8F8(p + 0x378, 0, 0x68);
    *(s16 *)(p + 0x360) = 0;
    *(s16 *)(p + 0x362) = 0;
    *(s16 *)(p + 0x35E) = 0;
    *(s16 *)(p + 0x356) = 0;
    *(s16 *)(p + 0x35C) = 0;
    *(s16 *)(p + 0x354) = 0;
    c = 106.66666412353516f;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    *(f32 *)(p + 0x34) = c + D_004F1FDC;
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x34) = D_004F1FD8 - c;
    }
    p[0x33B] = 0;
    z = p[0x33C] = 0;
    p[0x214] = 0;
    *(s16 *)(p + 0x3FE) = z;
    p[0x402] = 0;
    *(s16 *)(p + 0x3FA) = z;
    p[0x403] = 0;
    *(s16 *)(p + 0x3FC) = z;
    p[0x40D] = 0;
    p[0x40C] = 0;
    p[0x404] = 0;
    p[0x405] = 0;
    func_001E3210(p, 0x2B);
}

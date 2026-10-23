typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern s16 D_004BF518[2];
extern void (*D_0045DB00[])(void *);

extern void func_001757E0(void *p, s32 a, s32 b);
extern s32 func_00175700(void *p);
extern void func_00175C00(void *p, s32 a);
extern void func_00184540(void *p);
extern s32 func_001864A0(void *p);
extern void func_001865B0(void *p);

void func_003CE3D0(u8 *p, u8 *owner_unused) {
    u8 *q = *(u8 **)(p + 0x1C4);
    f32 z, z2;
    if (q != 0) {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + *(f32 *)(p + 0x60);
    }
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    z = 0.0f;
    *(f32 *)(p + 0x6C) -= 2.142857075f;
    if (*(f32 *)(p + 0x6C) < z) *(f32 *)(p + 0x6C) = z;
    z2 = 0.0f;
    *(f32 *)(p + 0x118) -= 0.01999999955f;
    if (*(f32 *)(p + 0x118) < z2) {
        p[4] = 3;
        p[0x13C] = 0;
        *(f32 *)(p + 0x118) = z2;
    }
}

void func_0036D340(u8 *p) {
    f32 d, k;
    p[0x13C] = 1;
    *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 0x14) + 0x140);
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x14) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x14) + 0x3C);
    if (*(s16 *)(p + 0x140) != 0) d = 74.66666412f; else { k = 74.66666412f; d = -k; }
    *(f32 *)(p + 0x34) += d;
    *(f32 *)(p + 0x38) -= 12.0f;
    p[0x24] = 12;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x50) = 0x3FB33333;
    *(u32 *)(p + 0x54) = 0x3FB33333;
    func_001757E0(p, 0x17, 0x37);
}

void func_0031CB00(u8 *p) {
    switch (p[0x1FC]) {
    case 0:
    case 1:
    {
        s8 r = func_00175700(p);
        if (r < 0) {
            func_00184540(p);
        } else if (func_001864A0(p) != 0) {
            func_001865B0(p);
        }
    }
        break;
    case 2:
        D_0045DB00[p[6]](p);
        break;
    }
}

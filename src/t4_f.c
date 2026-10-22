typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef float f32;

extern void func_001757E0(void *p, s32 a, s32 b);

extern s32 func_001CB180();
extern s32 func_001CB5A0();
extern s32 func_001CB5D0();

void func_001CB3D0(u8 *p, u8 *q) {
    f32 d;
    f32 z;
    if (p[5] == 0) {
        p[5] = p[5] + 1;
        *(s32 *)(p + 0xD4) = *(s16 *)(q + 0x274);
        func_001CB180(p);
        z = 0.0f;
        d = *(f32 *)(q + 0x34) - *(f32 *)(p + 0x34);
        if (d < z) d = -d;
        if (d <= 213.3333282f) {
            func_001CB5A0(p, 0x1B, 0x4F);
        }
    }
    if (*(s16 *)(q + 0x274) != *(s32 *)(p + 0xD4)) p[5] = 0;
    func_001CB5D0(p);
}

s32 func_00267E40(u8 *p) {
    f32 c = -23.33333206f;
    u32 s = p[0x1E6];
    u8 *q;
    f32 a, b;
    if (s != 0) c = -c;
    q = *(u8 **)(p + 0x220);
    a = *(f32 *)(p + 0x34);
    b = *(f32 *)(q + 0x34) + c;
    if (!(b < a) && s != 0) return 0;
    if (b < a && s == 0) return 0;
    p[0x20D] = 0;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[6] = 1;
    p[7] = 2;
    func_001757E0(p, 0x16, 0x1F);
    return 1;
}

extern void *func_001BC660(void *, int);

void func_0027A0A0(u8 *p) {
    u32 t;
    u16 h;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        func_001BC660(p, 2);
    }
    h = *(u16 *)(p + 0x160);
    if (h != 0) {
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x34) += 1.6666666f * (f32)(s16)h;
        } else {
            *(f32 *)(p + 0x34) -= 1.6666666f * (f32)(s16)h;
        }
        *(s16 *)(p + 0x160) = 0;
    }
}

extern u8 *D_004C2840[2];
extern void func_003DAA40();

void func_00140DC0(u8 *p) {
    f32 c;
    f32 z;
    switch (p[4]) {
    case 0:
        if (*(s16 *)(D_004C2840[0] + 0xA) >= 0x190) {
            p[4] = p[4] + 1;
        }
        break;
    case 1:
        c = 0.01f;
        z = 0.0f;
        *(f32 *)(p + 0x78) -= c;
        *(f32 *)(p + 0x7C) -= c;
        *(f32 *)(p + 0x80) -= c;
        if (*(f32 *)(p + 0x78) <= z) {
            u32 t = p[4];
            p[4] = t + 1;
            *(f32 *)(p + 0x78) = z;
            *(f32 *)(p + 0x7C) = z;
            *(f32 *)(p + 0x80) = z;
        }
        break;
    case 2:
        func_003DAA40(p);
        break;
    }
}

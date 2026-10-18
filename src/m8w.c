typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00189310(void *p, void *t, void *q);
extern void func_0018A990(void *p, void *q);
extern void func_00186A60(void *p, s32 a);
extern u8 D_0045DDC0[];

s32 func_003223A0(u8 *p) {
    if (func_00189310(p, D_0045DDC0, p + 0x380) == 0) {
        return 0;
    }
    func_0018A990(p, p + 0x380);
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            if (*(s8 *)(p + 0x1E8) != 0) {
                return 0;
            }
            *(s8 *)(p + 0x1E8) += 1;
        }
    }
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

extern u8 *D_004C2840;

void func_00150D70(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = v;
    v = *(s16 *)(p + 0x1C) % 30;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[4];
        p[4] = t ^ 1;
    }
    if (p[0x20] != 0) {
        if (*(s8 *)(D_004C2840 + 6) == p[0x21]) {
            p[0x13C] = 0;
        } else {
            p[0x13C] = p[4];
        }
    } else {
        if (*(s8 *)(D_004C2840 + 6) == 0) {
            p[0x13C] = 0;
        } else {
            p[0x13C] = p[4];
        }
    }
}

extern s32 func_00175700(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_0019D740(void *p, s32 a);
extern u8 D_00451A40[];

void func_0022A0E0(u8 *p) {
    s16 v;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[6];
        f32 *e;
        f32 a;
        p[6] = t + 1;
        e = (f32 *)(D_00451A40 + (p[0x1B7] << 4));
        a = e[0];
        if (*(s16 *)(p + 0x140) == 0) {
            a = -a;
        }
        *(f32 *)(p + 0x5C) = a;
        *(f32 *)(p + 0x60) = e[1];
        *(u32 *)(p + 0x6C) = 0;
        func_001757E0(p, 0x15, 0x2E);
        *(u32 *)(p + 0x2DC) = 4;
        func_0019D740(p, 1);
    }
}

extern u32 D_004C2794;

void func_002B5C60(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        s16 *e;
        p[6] = t + 1;
        p[0x151] = 0;
        p[0x1B5] = 0x41;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        e = (s16 *)((p[2] << 1) + D_004C2794);
        e[0x3E] = e[0x3E] + 1;
    }
}

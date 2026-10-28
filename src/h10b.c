typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_00175700();
extern void func_001757E0();
extern void func_0030A450();
extern void func_00175C00();
extern void func_001846B0();
extern void func_0019A3D0();
extern void func_00352670();
extern void func_001845F0();
extern void func_00183d50();
extern void func_001843A0(u8 *);
extern void func_001830D0();
extern void func_0036BFF0();
extern void func_001B0F40();
extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
extern u8 D_00451D40[];

extern s32 func_0030A450x();
void func_002C7720(u8 *p) {
    s16 v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1E) = 0x3C;
        func_001757E0(p, 0x13, 4);
    }
    func_00175700(p);
}

void func_00214830(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_00175C00(p, 0);
        func_001846B0(p);
    } else if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        func_0019A3D0(p, 7);
    }
}

void func_003C3940(u8 *p, void *owner) {
    u8 *q = *(u8 **)(p + 0x14);
    func_00175700(p);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    if (q[0xD4] != 0) {
        u32 t = p[5];
        p[5] = t + 1;
        func_001757E0(p, 0x16, 0x1B);
    }
}

void func_002125B0(u8 *p, u8 *q) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        q[1] = 0x20;
        *(s16 *)(q + 2) = 0xD;
        func_00352670(p, 0, 0, 0);
        q[4] = 0xFF;
    }
}

void func_002204C0(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (p[0x20D] == 2) {
        *(u32 *)(p + 0x60) = 0xBF4DB6DB;
        *(s8 *)(p + 0x1E7) = -1;
        func_001845F0();
        func_00183d50(p);
    } else {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001843A0(p);
    }
}

void func_0029E1B0(u8 *p) {
    f32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    {
        u32 t = p[6];
        p[6] = t + 1;
    }
    p[0x404] = 0;
    p[0x405] = 0;
    *(u32 *)&v[1] = 0x4322DB6D;
    v[0] = 0;
    v[2] = 0;
    func_001830D0(p, v, 1);
}

void func_0025F080(u8 *p) {
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_0036BFF0(p, 2, 0x13, 2);
        func_001B0F40(p, 4);
        *(s8 *)(p + 0x151) = 0;
        if (p[0x1B7] == 0) *(s16 *)(p + 0x1C) = 0x10; else *(s16 *)(p + 0x1C) = 0x10;
    }
    func_00175700(p);
}

s32 func_0022CD30(u8 *p) {
    if (func_00189310(p, D_00451D40, p + 0x3A0) == 0) return 0;
    func_0018A990(p, p + 0x3A0);
    p[0x206] = 3;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 2;
    func_00186A60(p, 0x15);
    return 1;
}

extern void func_002C40D0();
extern void func_001820A0(u8 *);
extern void (*D_004582A0[])(u8 *);

void func_00222950(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0:
        p[0x1FD] = 1;
        *(s16 *)(p + 0x2DA) = 1;
        break;
    case 1:
        p[0x1FD] = 0;
        break;
    case 2:
        p[0x1FD] = 0;
        break;
    }
    p[0x1B7] = 1;
    func_00186A60(p, 0x15);
}

void func_0029F690(u8 *p) {
    if (p[0x20D] == 2) {
        func_001820A0(p);
        if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    }
    D_004582A0[p[6]](p);
}

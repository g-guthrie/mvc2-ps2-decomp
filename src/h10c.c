typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_00175700();
extern void func_001757E0();
extern s32 func_001891F0();
extern s32 func_00189310();
extern void func_00186A60();
extern void (*D_0045B080[])(u8 *);
extern u8 D_004580A0[];

s32 func_002E4290(u8 *p) {
    u8 *q = p + 0x2B8;
    if (func_001891F0(p, 6) == 0) return 0;
    if (*(s8 *)(q + 9) != 0) return 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 6;
    func_00186A60(p, 0x15);
    return 1;
}

s32 func_0029B380(u8 *p) {
    if (func_00189310(p, D_004580A0, p + 0x388) == 0) return 0;
    if (**(s8 **)(p + 0x420) <= 0) return 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 3;
    func_00186A60(p, 0x1D);
    return 1;
}

void func_0026DA50(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0) {
            u32 t;
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            t = p[6];
            p[6] = t + 1;
            p[7] = 0;
            func_001757E0(p, 0x16, 4);
        }
    }
}

void func_003C39B0(u8 *p, u8 *q) {
    u8 *r = *(u8 **)(p + 0x14);
    u8 *e = r + 0xD0;
    func_00175700(p);
    *(f32 *)(p + 0x34) = *(f32 *)(r + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(r + 0x38);
    if (q[0x2C5] != 0) p[0x13C] = 0;
    if (e[4] == 0) {
        u32 t = p[4];
        p[4] = t + 1;
    }
}

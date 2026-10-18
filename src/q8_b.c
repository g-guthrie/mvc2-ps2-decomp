typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_001C1630();

extern void func_001C1630();
void func_001C1590(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (q[6] > 2) {
        p[4] = 2;
        p[0x13C] = 0;
    } else {
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        if (p[0x20] == 0) {
            *(f32 *)(p + 0x38) = 304.2857055664f + *(f32 *)(q + 0x38);
        } else {
            func_001C1630();
        }
    }
}
extern void func_00175670(u8 *);
void func_001A7C50(u8 *p) {
    func_00175670(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) > 0.0f) {
        u32 t = p[5];
        p[5] = t + 1;
    }
}

extern void func_003DAA40();
void func_0033E600(u8 *p) {
    switch (p[4]) {
    case 0: {
        u32 t = p[4];
        p[4] = t + 1;
        *(s16 *)(p + 0x1E) = 0x78;
        break;
    }
    case 1: {
        s16 v;
        *(f32 *)(p + 0x50) += 0.1f;
        *(f32 *)(p + 0x58) += 0.1f;
        v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
        if (v >= *(s16 *)(p + 0x1E)) {
            func_003DAA40();
        }
        break;
    }
    }
}

extern void func_00220840();
extern void func_002207B0();
void func_00220420(u8 *p) {
    f32 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    v = 896.0f + *(f32 *)(p + 0x430);
    if (*(f32 *)(p + 0x38) > v) {
        *(f32 *)(p + 0x38) = v;
    }
    if (*(s8 *)(p + 0x1B2) & 1) {
        u32 t = p[0x2C7];
        p[0x2C7] = t + 1;
        if (p[0x2C0] == 2) {
            func_00220840();
        } else {
            func_002207B0();
        }
    } else {
        func_00220840();
    }
}

extern s32 func_00175700();
extern void func_001843A0();
void func_00275060(u8 *p) {
    f32 *a = (f32 *)(p + 0x5C);
    f32 *b = (f32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < 0.0f)) {
        *a = 0.0f;
        *b = 0.0f;
    }
    if ((s8)func_00175700(p) < 0) {
        *(s32 *)a = 0;
        *(s32 *)b = 0;
        func_001843A0(p);
    }
}

extern s32 func_00175700();
void func_001F4C70(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x60) < 0.0f) {
        u32 t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x68) = 0x40F00000;
        if (p[0x1E6] == 0) {
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}

extern void func_001741D0();
s32 func_00174810(u8 *p) {
    f32 loc[2];
    u32 n;
    f32 v;
    func_001741D0(p + 0x34, loc);
    n = p[0x14C];
    v = loc[1] - (34.2857131958f + 2.1428570747f * (f32)n * *(f32 *)(p + 0x54));
    return !(v > 480.0f);
}

typedef struct { f32 x, y, z; } V3;
extern void func_001830D0();
extern s32 func_00175700();
void func_002C3520(u8 *p) {
    V3 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v = *(V3 *)(p + 0x34);
        *(u32 *)&v.x = 0;
        *(u32 *)&v.y = 0x4340DB6D;
        func_001830D0(p, &v, 1);
    }
}

extern s32 func_00175700();
extern void func_001843A0();
extern void func_00183920();
void func_001ECEE0(u8 *p) {
    f32 v[4];
    if ((s8)func_00175700() < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) < 0) {
        p[0x151] = 0;
        *(u32 *)&v[0] = 0x41C80000;
        *(u32 *)&v[1] = 0x43250000;
        func_00183920(p, v);
    }
    if (*(s8 *)(p + 0x150) != 0) {
        f32 d;
        if (p[0x1E6] != 0) {
            d = 3.3333332539f;
        } else {
            d = -3.3333332539f;
        }
        *(f32 *)(p + 0x34) += d;
    }
}

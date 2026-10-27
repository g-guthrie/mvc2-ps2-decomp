typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001757E0(u8 *, s32, s32);
extern int func_00175700(u8 *);
extern s32 func_0018AA50(u8 *, s32, s16 *, s32);
extern void func_0011D8F8(u8 *, s32, s32);
extern void func_002AA0E0(u8 *);
extern void func_00394780(u8 *, s32, s32);
static f32 func_002ADC20(u8 *p) {
    f32 v = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += v;
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    return *(f32 *)(p + 0x5C) * v;
}
extern void func_00183DF0(u8 *, s32);

void func_00394080(u8 *p) {
    f32 v;
    p[5] = 6;
    if (*(s16 *)(p + 0x140) != 0) v = -13.33333302f; else v = 13.33333302f;
    *(f32 *)(p + 0x5C) = v;
    *(f32 *)(p + 0x68) = 0.0f;
    *(u32 *)(p + 0x60) = 0x40892492;
    *(u32 *)(p + 0x6C) = 0xBD092492;
    func_001757E0(p, 0x17, 0xF);
}

void func_002AEFC0(u8 *p) {
    f32 r;
    func_00175700(p);
    r = func_002ADC20(p);
    if (r < 0.0f) {
        *(f32 *)(p + 0x5C) = 0.0f;
        *(f32 *)(p + 0x68) = 0.0f;
        p[6] = 4;
        func_001757E0(p, 0x15, 3);
    } else {
        func_00183DF0(p, 3);
    }
}

void func_00361F90(u8 *p) {
    u8 *q = p + 0xD0;
    if (*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) > 0.0f) {
        f32 v = -*(f32 *)(q + 4);
        *(f32 *)(q + 4) = v;
        *(f32 *)(p + 0x5C) = v;
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        q[8] ^= 1;
    }
    if (q[8] == 0) p[0x24] = 0; else p[0x24] = 7;
}

void func_001F50E0(u8 *p) {
    u8 *q = p + 0x2B8;
    s32 r = func_00175700(p);
    if ((s8)r < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        q[2] = 0;
        func_001757E0(p, 0xF, 0x2C);
    }
}

extern void func_0016B0C0(u8 *, u8 *, s32);
extern s32 func_00174170();
extern void func_00184540(u8 *);
extern void func_002DC1B0(u8 *);
void func_002DAB10(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        if (p[0x20D] == 2) func_00184540(p);
        else func_002DC1B0(p);
    }
}

extern void func_001CCC90(u8 *, s32);
extern void func_00396C80(u8 *, f32, f32);
void func_002B16C0(u8 *p) {
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if ((s8)p[0x151] & 0x80) {
        p[0x151] = 0;
        t = p[6];
        p[6] = t + 1;
        func_001CCC90(p, 9);
        func_00396C80(p, -195.0f, 113.5714264f);
    }
}

extern int func_00175700(u8 *);
void func_003721C0(u8 *p) {
    u32 t;
    if ((s8)p[0x151] == 1) {
        f32 v = *(f32 *)(p + 0x118) - 0.05999999866f;
        *(f32 *)(p + 0x118) = v;
        if (v < 0.0f) *(f32 *)(p + 0x118) = 0.0f;
    }
    func_00175700(p);
    if ((s8)p[0x153] < 0) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}

extern void func_00186A60(u8 *, s32);
extern void func_00175670();
void func_001BB360(u8 *p) {
    s16 v;
    func_00175670();
    *(s32 *)(p + 0x48) += 0x2000;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        p[4] = 3;
        *(s16 *)(p + 0x1C) = 9;
        *(s32 *)(p + 0x48) = 0;
    } else {
        p[0x13C] = (*(s16 *)(p + 0x1C) % 2) ? 1 : 0;
    }
}

extern void func_002CFA20(u8 *);
extern void func_0015D010(u8 *, f32 *);
void func_002E0660(u8 *p) {
    f32 v[4];
    if (*(u16 *)(p + 0x20E) & 0x800) {
        *(s16 *)(p + 0x140) ^= 1;
        p[0x1E6] ^= 1;
    }
    v[0] = -106.6666641f;
    v[1] = 235.7142792f;
    func_0015D010(p, v);
    p[0x1B4] = 0xA;
    p[6] = 0;
    p[7] = 0;
    func_001757E0(p, 0xF, 0);
}

void func_003C4840(u8 *p, u8 *q) {
    u8 *s = q + 0x2B8;
    u8 *r;
    f32 v;
    u32 t;
    func_00175700(p);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    if (q[6] == 1) {
        r = *(u8 **)(q + 0x220);
        v = *(f32 *)(r + 0x38);
        *(f32 *)(p + 0x38) = v;
        *(f32 *)(p + 0x38) = v - 17.1428566f;
    }
    if (s[0x13] != 0) {
        p[0x13C] = 0;
        t = p[4];
        p[4] = t + 1;
    }
}

void func_002BF510(u8 *p) {
    u8 *q;
    f32 v;
    u32 t;
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 2;
        q[0x1B5] = 0x24;
        if (p[0x1E6] != 0) v = -6.666666508f; else v = 6.666666508f;
        *(f32 *)(p + 0x5C) = v;
        *(u32 *)(p + 0x60) = 0x41092492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
}

extern u8 *D_004D3690[];
extern void func_00152560(u8 *);
extern void func_00152180(u8 *, s32);
void func_001520E0(s32 a) {
    u8 *p = D_004D3690[(u8)a];
    while (p != 0) {
        if ((s8)p[0x13C] != 0 && *(s32 *)(p + 0x84) != 0) {
            if (*(s32 *)(p + 0x28) != 0) func_00152560(p);
            func_00152180(p, a);
        }
        p = *(u8 **)(p + 0xC);
    }
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern f32 D_004F1F40[];
extern f32 D_004F1FC8;
extern f32 D_004F1FCC;
extern f32 D_004F1FD0;

s32 func_00237BC0(u8 *p, u8 *q) {
    f32 *g = D_004F1F40;
    f32 lim;
    f32 y = *(f32 *)(p + 0x430);
    u8 flag = q[0x19];
    f32 py;
    lim = y;
    if (flag) {
        f32 t = g[0x94 / 4];
        if (!(t <= y)) lim = t;
    }
    py = *(f32 *)(p + 0x38);
    if (102.85713958740234f + py < lim && !(q[0x1D] & 4)) {
        *(f32 *)(p + 0x38) = lim;
        q[0x1B] |= 4;
        return 4;
    }
    lim = g[0x90 / 4];
    if (!flag) lim = 977.142822265625f + y;
    lim += 512.0f;
    if (flag) py += 137.14285278320312f;
    if (!(py <= lim)) {
        if (!(q[0x1D] & 8)) {
            *(f32 *)(p + 0x38) = lim - 240.0f;
            q[0x1B] |= 8;
            return 8;
        }
    }
    return 0;
}

void func_00380B40(u8 *p, u8 *q) {
    f32 vx = *(f32 *)(p + 0x5C);
    f32 vz;
    if (vx < 0.0f) {
        if (*(f32 *)(p + 0x34) < 80.0f + D_004F1FC8) {
            *(f32 *)(p + 0x5C) = -vx;
            p[0x20] = 1;
        }
    } else {
        if (!(*(f32 *)(p + 0x34) <= D_004F1FCC - 80.0f)) {
            *(f32 *)(p + 0x5C) = -vx;
            p[0x20] = 1;
        }
    }
    vz = *(f32 *)(p + 0x60);
    if (!(vz < 0.0f)) {
        if (!(*(f32 *)(p + 0x38) <= D_004F1FD0 - 102.85713958740234f)) {
            *(f32 *)(p + 0x60) = -vz;
            p[0x21] = 1;
        }
    } else {
        if (*(f32 *)(p + 0x38) < 102.85713958740234f + *(f32 *)(q + 0x430)) {
            *(f32 *)(p + 0x60) = -vz;
            p[0x21] = 1;
        }
    }
}


extern u8 D_00450EB0[];
typedef struct { f32 x, y, z; } V3;

void func_00218E00(u8 *p) {
    extern s8 func_00175700();
    extern void func_00219250();
    extern void func_002192B0();
    extern void func_00219490();
    extern void func_00183D10();
    extern void func_001843A0();
    u8 *q = p + 0x2B8;
    if (func_00175700(p) < 0) {
        if (q[1] != 0) {
            u16 v = *(s16 *)(p + 0x354) & 0x3C00;
            if (v != 0) {
                u16 idx = (u32)v >> 10;
                u8 t = D_00450EB0[idx];
                if (t != 0) {
                    if ((idx & (1 << p[0x1E6])) == 0) {
                        p[0x22] = t - 1;
                        p[0x20D] = 2;
                        p[7] = 0;
                        q[0] = 1;
                        q[1] = 0;
                        func_00219250(p);
                        func_002192B0(p);
                        func_00219490(p);
                        func_00183D10(p);
                        return;
                    }
                }
            }
        }
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        p[0x210] = 0;
        p[0x20D] = 0;
        func_001843A0(p);
    } else {
        u16 v = *(s16 *)(p + 0x354) & 0x360;
        if (v != 0) q[1] = 1;
    }
}

void func_003BA5D0(u8 *p) {
    extern void func_003BD4A0();
    extern void func_00175700();
    extern void func_001E7F60();
    u8 *s = *(u8 **)(p + 0x18);
    if (s[0x169] != 7 || s[0x168] != 2) {
        func_003BD4A0(p);
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    {
        f32 y = *(f32 *)(s + 0x430);
        if (!(y <= *(f32 *)(p + 0x38))) {
            *(f32 *)(p + 0x38) = y;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x6C) = 0;
        }
    }
    if (*(s8 *)(p + 0x150) >= 0) {
        u32 t = p[6];
        u32 c = 0xC0092492;
        p[6] = t + 1;
        *(u32 *)(p + 0x6C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = c;
        {
            f32 k = 6.666666507720947f;
            if (s[0x1E6] == 0) k = -k;
            *(f32 *)(p + 0x5C) = k;
        }
    }
    func_001E7F60(p);
}

typedef struct { u8 *a; u8 *b; u8 *c; } E;
extern E D_004D18BC[];
extern E D_004D18C0[];

void func_001B09E0(u8 *p) {
    extern void func_001754A0();
    if (*(s8 *)(*(u8 **)(p + 0x18) + 0x151) == 2) func_001754A0(p, 0x1B, 0x11);
    if (*(s8 *)(*(u8 **)(p + 0x18) + 0x151) == 3) func_001754A0(p, 0x1B, 0x12);
    if (*(s8 *)(*(u8 **)(p + 0x18) + 0x151) == 4) func_001754A0(p, 0x1B, 0x13);
    if (*(s8 *)(*(u8 **)(p + 0x18) + 0x151) == 5) func_001754A0(p, 0x1B, 0x14);
    if (*(s8 *)(*(u8 **)(p + 0x18) + 0x151) == 6) func_001754A0(p, 0x1B, 0x15);
    if (*(s8 *)(*(u8 **)(p + 0x18) + 0x151) == 7) func_001754A0(p, 0x1B, 0x15);
    if (*(s8 *)(*(u8 **)(p + 0x18) + 0x151) == 8) func_001754A0(p, 0x1B, 0x16);
    if (*(s8 *)(*(u8 **)(p + 0x18) + 0x151) == 9) {
        u32 t = p[4]; p[4] = t + 1;
    }
}


void func_003B83A0(u8 *p) {
    extern void func_003B9220();
    extern s32 func_00174170();
    extern void func_001757E0();
    u8 *r = *(u8 **)(p + 0x14);
    u8 *s0 = p + 0xD0;
    func_003B9220(p);
    if (r[0x1E6] != 0) {
        *(f32 *)(p + 0x34) = 53.33333206176758f + D_004F1FCC;
    } else {
        *(f32 *)(p + 0x34) = D_004F1FC8 - 53.33333206176758f;
    }
    *(f32 *)(p + 0x38) = 137.14285278320312f + D_004F1FD0;
    p[0x22] = func_00174170() & 0x1F;
    if (p[0x21] == 0) {
        *(u32 *)(s0 + 4) = 0xC2555555;
        *(u32 *)(s0 + 8) = 0x432D5555;
        p[0x24] = 7;
        func_001757E0(p, 0x12, 0x16);
    } else {
        *(u32 *)(s0 + 4) = 0x42555555;
        *(u32 *)(s0 + 8) = 0x432D5555;
        p[0x24] = 0;
        func_001757E0(p, 0x12, 0x25);
    }
}

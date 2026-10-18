typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_003BF050();
extern s32 func_001E7FD0();
extern void func_001757E0();
extern u32 D_004C2794;
typedef struct { float x, y, z; } Float3;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_0033E600();
extern void func_0033C240();
extern u32 D_004C283C;
extern Float3 D_004B8280;
extern Float3 D_0045ECE0[];
extern s8 func_00175700();
extern void func_003CA340();
extern void func_00185490();
extern void func_00175C00();
extern void func_0018C1A0();
extern void func_0018D340();
typedef float f32;
extern void func_001FED30();
extern void func_00183D10();
extern void func_002004B0();
extern void func_0035ACA0();
extern void func_0035A7B0();
extern f32 D_004F1FD0[];
extern void func_003359E0();
extern void func_00335640();
extern Float3 D_004B7F30[];
extern void func_001266A0();
extern void func_0015D010();
extern void func_0018C6E0();
extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
extern u8 D_0044FBA0[];
extern void func_00176160();
extern u32 D_0044FDE0[];
extern void func_00394B60();
extern s32 func_00174470();
extern void func_00395890();
extern void func_001E7F60();
extern u8 *D_004C29D8;
extern void func_001843A0();
extern void func_001754A0();
typedef struct { u8 pad[0x18]; u32 t[2][3]; } S18;
extern S18 D_004D18A0;
extern void func_001E86B0();
extern void func_001505F0();
extern u32 D_004C27E8;
extern void func_00134E40();
extern Float3 D_0043E950[];
extern u32 D_004C2834;
extern u8 *D_004C2840;
extern void func_00135140();
extern void func_0018A920();

void func_003BEFE0(u8 *a, s32 b) {
    u8 *o;
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        *(void **)(o + 0x10) = func_003BF050;
        *(u8 **)(o + 0x18) = a;
        o[1] = a[1];
        *(s16 *)(o + 0x26) = 0x3602;
        o[0x20] = (u16)b >> 8;
        o[0x21] = b;
    }
}

s32 func_002FB2B0(u8 *p) {
    s32 r;
    u8 *q = p + 0x2B8;
    u8 t = (*(u16 *)(p + 0x20E) & 0xC00) >> 10;
    p[0x22] = t;
    if (t != 0) {
        if (p[0x212] == 0 && p[0x1B7] == 1) {
            if (q[0x16] != 0) return 0;
            if ((r = func_001E7FD0(p)) != 0) {
                p[0x20B] = 0;
                return r;
            }
        }
    }
    return 0;
}

void func_0023BDD0(u8 *p) {
    u32 t = p[6];
    s16 *q;
    p[6] = t + 1;
    p[0x20D] = 2;
    *(u32 *)(p + 0x5C) = 0xC1F00000;
    if (p[0x1E6] != 0) *(float *)(p + 0x5C) = -*(float *)(p + 0x5C);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0xBE892492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    p[0x1B5] = 0x3C;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    q = (s16 *)((p[2] << 1) + D_004C2794);
    q[0x3E] += 1;
    func_001757E0(p, 0x14, 0);
}

void func_0033E560(Float3 *a) {
    u8 *p;
    if ((p = func_003DA750(0, 6, 1)) != 0) {
        p[0x13C] = 1;
        *(void **)(p + 0x10) = func_0033E600;
        *(s16 *)(p + 0xCC) = 5;
        *(u32 *)(p + 0x84) = D_004C283C;
        *(u32 *)(p + 0xD0) = 0x811;
        *(Float3 *)(p + 0x34) = *a;
        *(Float3 *)(p + 0x50) = D_004B8280;
    }
}

void func_0033C250(u8 *a, s32 idx) {
    u8 *p;
    if ((p = func_003DA750(0, 6, 1)) != 0) {
        p[0x13C] = 1;
        *(void **)(p + 0x10) = func_0033C240;
        *(s16 *)(p + 0xCC) = 0x1D;
        *(u32 *)(p + 0x84) = D_004C283C;
        *(Float3 *)(p + 0x34) = D_0045ECE0[idx];
        *(u32 *)(p + 0xD0) = 0x803;
        *(u8 **)(p + 0x14) = a;
        *(u8 **)(p + 0xC8) = a + 0x88;
    }
}

void func_00325620(u8 *p) {
    s16 v;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    v = *(s16 *)(p + 0x1E);
    if (v != 0) {
        v = v - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v <= 0) func_003CA340(p);
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x16, 0x12);
    }
}

void func_0018C0F0(u8 *a, u8 *b) {
    u32 t = a[0x225];
    a[0x225] = t + 1;
    *(s8 *)(a + 0x1B3) |= 0x80;
    *(s8 *)(b + 0x1B2) |= 1;
    if (*(s8 *)(b + 0x1B0) & 1) {
        *(s8 *)(*(u8 **)(a + 0x1CC) + 0x1B2) |= 1;
    }
    func_00185490(a);
    func_00175C00(a, 1);
    func_0018C1A0(a, b);
    func_0018D340(a, b);
    *(s8 *)(a + 0x1B2) &= -0x7F;
}

void func_002005C0(u8 *p) {
    u32 t;
    s16 *q;
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    t = p[7];
    p[7] = t + 1;
    func_001FED30(p);
    func_00183D10(p);
    p[0x1B5] = 0x3B;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    q = (s16 *)((p[2] << 1) + D_004C2794);
    q[0x3E] += 1;
    func_00175C00(p, 0);
    func_001757E0(p, 0x16, 5);
    func_002004B0(p);
}

void func_00287EC0(u8 *p) {
    u32 t;
    f32 *a;
    f32 *c;
    func_00175700(p);
    a = (f32 *)(p + 0x60);
    c = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(u32 *)a = 0;
        *(u32 *)c = 0;
        p[0x20D] = 0;
        func_001757E0(p, 2, 3);
    }
}

void func_00336A50(void) {
    u8 *p;
    s32 i = 0;
    do {
        if ((p = func_003DA750(0, 6, 1)) == 0) break;
        p[0x23] = i;
        p[0x13C] = 1;
        *(void **)(p + 0x10) = func_003359E0;
        *(s16 *)(p + 0xCC) = 0x23;
        *(u32 *)(p + 0x84) = D_004C283C;
        *(u32 *)(p + 0xD0) = 0x805;
        *(s16 *)(p + 0x140) = 1;
        *(Float3 *)(p + 0x34) = D_004B7F30[p[0x23]];
        func_00335640(p);
        i++;
    } while (i < 3);
}

void func_001F62F0(u8 *p) {
    u8 *q;
    u32 v[3];
    if (*(u16 *)(p + 0x2B8) & 0x400) {
        *(s16 *)(p + 0x140) ^= 1;
        p[0x1E6] = *(s8 *)(p + 0x140);
        q = *(u8 **)(p + 0x1DC);
        *(s16 *)(q + 0x140) ^= 1;
        q[0x1E6] = *(s8 *)(q + 0x140);
    }
    p[0x1B4] = 10;
    p[7] = 0;
    p[6] = 0;
    func_001266A0(p, 5, 5);
    v[0] = 0xC312AAAA;
    v[1] = 0x432B6DB6;
    func_0015D010(p, v);
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 0);
}

void func_001FE660(u8 *p) {
    s16 v;
    u32 t;
    func_00175700(p);
    if (*(s8 *)(p + 0x150) != 0) {
        p[0x150] = 0;
        func_00176160(p, 0, p[0x15B] + D_0044FDE0[p[0x25]], 1);
        v = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = v - 1;
        if (v == 0) {
            func_00176160(p, 0, D_0044FDE0[p[0x25]] + 4, 1);
            t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0x12, 2);
        }
    }
}

void func_00394A50(u8 *p) {
    if (*(s8 *)(p + 0x1B2) != 0 || *(s8 *)(p + 0x1B3) != 0) {
        func_00394B60(p);
        return;
    }
    if (func_00174470() == 0) {
        D_004C29D8[2] = 0;
        func_00395890(p);
    } else {
        p[0x24] = 0;
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_001E7F60(p);
    }
}

void func_002ADC70(u8 *p) {
    u32 t;
    s16 *q;
    if (p[6] == 0) {
        t = p[6];
        p[6] = t + 1;
        func_00185490(p);
        func_00175C00(p, 0);
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        p[0x1B5] = 0x3C;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        q = (s16 *)((p[2] << 1) + D_004C2794);
        q[0x3E] += 1;
        func_001757E0(p, 0x14, 0);
    } else {
        if (func_00175700(p) < 0) func_001843A0(p);
    }
}

void func_001C96B0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x14);
    s16 h;
    *(s8 *)(p + 0x31) = -8;
    if (p[0x22] != 2) {
        *(u32 *)(p + 0x34) = 0xC2555555;
        *(u32 *)(p + 0x38) = 0;
    } else {
        *(u32 *)(p + 0x34) = 0xC1E2AAAA;
        *(u32 *)(p + 0x38) = 0x422B6DB6;
    }
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x68) = 0xBD555555;
    *(u32 *)(p + 0x6C) = 0x3D892492;
    h = *(s16 *)(q + 0x140);
    *(s16 *)(p + 0x140) = h;
    if (h == 0) {
        *(f32 *)(p + 0x34) = -*(f32 *)(p + 0x34);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    *(f32 *)(p + 0x34) += *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) += *(f32 *)(q + 0x38);
    func_001754A0(p, 0x1B, 0x3B);
}

void func_00150530(u8 *a, s16 b, f32 x, f32 y, f32 z) {
    u8 *p;
    if ((p = func_003DA750(0, 0xD, 1)) != 0) {
        p[0x13C] = 1;
        *(void **)(p + 0x10) = func_001505F0;
        *(s16 *)(p + 0xCC) = 0xA;
        *(u32 *)(p + 0x84) = D_004C27E8;
        *(u32 *)(p + 0xD0) = 0x31;
        *(f32 *)(p + 0x34) = x;
        *(f32 *)(p + 0x38) = y;
        *(f32 *)(p + 0x3C) = z;
        *(u32 *)(p + 0x50) = 0x3F800000;
        *(u32 *)(p + 0x54) = 0x3F800000;
        *(u32 *)(p + 0x58) = 0x3F800000;
        *(s16 *)(p + 0x1E) = b;
        *(u8 **)(p + 0x14) = a;
        *(u8 **)(p + 0xC8) = a + 0x88;
        *(u8 **)(p + 0x18) = a;
    }
}

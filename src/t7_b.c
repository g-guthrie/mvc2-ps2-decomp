typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u16 D_004C1C88[2];
extern u8 *D_0043B6F8[];
extern u8 D_0045A890[];
extern u8 *D_004C28DC;
extern u8 *D_004C2840;
extern u16 D_004F4480[];
extern u16 D_004F4494[];
extern s32 func_001757E0();
extern s32 func_00175700();
extern void func_0011B7A8();
extern void func_00120A30();
extern void func_00185490();
extern void func_00183D10();
extern void func_0018C4B0();
extern u8 *func_003DA750();
extern void func_0030A4F0();
extern void func_003A0F00();
extern void func_0030A450();
extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
extern void func_00238B70();
extern void func_001830D0();
extern void func_001843A0();
extern void func_00183920();
extern void func_00175C00();
extern void func_002F8FC0();
typedef struct { f32 x, y, z; } V3;
typedef struct { f32 x, y, z, w; } V4;
extern V3 D_00443BF8;
extern V4 D_00443C10;
extern u16 D_004BF3B8[4];
extern u32 D_004C2804;
extern u8 *D_004C2794;
typedef struct { u8 pad[0x18]; u8 *e[2][3]; } G18;
extern G18 D_004D18A0;
extern void func_001A7990();
extern f32 func_001A8CB0();
extern void func_001A8610();
extern void func_001498E0();
extern void func_001E7F60();
extern void func_0036A8A0();
extern void func_003DE720();
extern void func_00254100();
extern s32 func_0018AB10();
extern void func_0018F6B0();
extern u8 *D_004C2710;
extern void func_001CCB50();
extern void func_00175670();
extern void func_001754A0();
extern void func_001E3210();
extern void func_0039E450();
extern f32 func_00417440(s16);
extern void func_0039AD00();
extern void func_0011D8F8();
extern u8 D_00458AD0[];
extern void func_001266A0();
extern void func_0015D010();
extern void func_0018C6E0();
extern void func_0016BF10();

void func_00228E20(u8 *p) {
    extern s32 func_001757E0(u8 *, s32, u8);
    u8 v;
    u32 t = p[6];
    p[6] = t + 1;
    func_00185490(p);
    func_00183D10(p);
    func_0018C4B0(p, 5);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    v = 0x21;
    if (p[0x1B7] != 0) v = 0x30;
    func_001757E0(p, 0x15, v);
}

void func_003A0E80(u8 *a, u8 *b, u8 c, u8 d) {
    u8 *o;
    if ((o = func_003DA750(0, 1, 1)) != 0) {
        *(u16 *)(o + 0x26) = 0x2B01;
        o[0x20] = c;
        o[0x21] = d;
        *(void **)(o + 0x10) = (void *)func_003A0F00;
        *(u8 **)(o + 0x14) = a;
        *(u8 **)(o + 0x18) = b;
    }
}

void func_0016B720(void) {
    s16 v = *(s16 *)(D_004C2840 + 0xE) - 1;
    *(s16 *)(D_004C2840 + 0xE) = v;
    if (v == 0) {
        s8 t = *(s8 *)(D_004C2840 + 5);
        *(s8 *)(D_004C2840 + 5) = t + 1;
        *(s16 *)(D_004C2840 + 0xE) = 0x18;
    }
    {
        s8 f = D_004C2840[0x88];
        if (f & 1) {
            if (D_004F4480[0] & 0x8000) goto L1;
        }
        if (f & 2) {
            if (D_004F4494[0] & 0x8000) {
L1:
                func_0016BF10();
            }
            return;
        }
    }
}

s32 func_002D90D0(u8 *p) {
    if (func_00189310(p, D_0045A890, p + 0x378) == 0) return 0;
    func_0018A990(p, p + 0x378);
    if (p[0x20D] == 2 && p[0x210] == 0) {
        if (*(s8 *)(p + 0x1E8) != 0) return 0;
        *(s8 *)(p + 0x1E8) += 1;
    }
    p[0x1FD] = 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

void func_002362B0(u8 *p, u8 *q) {
    func_00175700(p);
    func_00238B70(p, q);
    if (q[5] != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x5C) = 0xC0700000;
        *(u32 *)(p + 0x68) = 0xBFA00000;
        *(u32 *)(p + 0x60) = 0xC0892492;
        *(u32 *)(p + 0x6C) = 0;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        func_0018C4B0(p, 5);
    }
}

void func_001EC3F0(u8 *p) {
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x150) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x150] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0x42A00000;
        v[1] = 0x43092492;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}

void func_0031A0D0(u8 *p) {
    u32 v[4];
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        v[1] = 0x432B6DB6;
        v[0] = 0;
        func_00183920(p, v);
    }
    if (*(s8 *)(p + 0x150) != 0) {
        f32 k;
        *(s8 *)(p + 0x150) = 0;
        k = -53.3333320618f;
        if (*(s16 *)(p + 0x140) != 0) k = -k;
        *(f32 *)(p + 0x34) += k;
    }
}

static void func_002F8DE0(u8 *p) {
    if (p[0x20D] == 2) {
        *(f32 *)(p + 0x5C) /= 8.0f;
        *(f32 *)(p + 0x68) /= 8.0f;
        *(f32 *)(p + 0x60) /= 8.0f;
        *(f32 *)(p + 0x6C) /= 8.0f;
    }
}

void func_002F8F10(u8 *p, u8 *q) {
    u32 t = p[6];
    p[6] = t + 1;
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_00175C00(p, 0);
    if (p[0x20D] != 2) func_00183D10(p);
    func_001757E0(p, 0x15, 0);
    func_002F8DE0(p);
    q[6] = 0;
    q[7] = 0;
    q[8] = 0;
    q[9] = 0;
    q[0xA] = 0;
    q[0xB] = 0;
    q[0xC] = 0;
    func_002F8FC0(p, q);
}

void func_002C9710(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    p[0x13C] = 0;
    p[0x209] = 1;
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0) {
            u32 t = p[6];
            p[6] = t + 1;
            p[0x13C] = 1;
            func_0039AD00(p);
            func_00185490(p);
            func_001757E0(p, 0x15, 0x11);
        }
    }
}

void func_002B04A0(u8 *p) {
    u32 v[4];
    s8 f;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    f = *(s8 *)(p + 0x151);
    if (f & 1) {
        u32 t;
        *(s8 *)(p + 0x151) = f & ~1;
        t = p[6];
        p[6] = t + 1;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0x41D55555;
        v[1] = 0x4311B6DB;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}

void func_00205010(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) < 0 || (*(s8 *)(p + 0x539) == 0 && (*(u16 *)(p + 0x35E) & 0x400) != 0)) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 2, 2);
    }
}

void func_00202580(u8 *p) {
    u32 v[4];
    u8 *q = (u8 *)((s32)p + 0x2B8);
    if (*(u16 *)(p + 0x20E) & 0x400) {
        s8 a = *(s8 *)(p + 0x1E6);
        s16 b;
        *(s8 *)(p + 0x1E6) = a ^ 1;
        b = *(s16 *)(p + 0x140);
        *(s16 *)(p + 0x140) = b ^ 1;
    }
    func_001266A0(p, 5, 5);
    p[0x1B4] = 10;
    p[6] = 0;
    v[0] = 0xC2555555;
    v[1] = 0x43092492;
    func_0015D010(p, v);
    q[0x1B] = 0;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 7);
}

void func_002E2180(u8 *p) {
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        p[0x13C] = 1;
        func_001757E0(p, 0, 0);
    }
    if (p[6] == 1 && *(u8 *)&D_004D18A0 >= 2) {
        u32 u = p[6];
        p[6] = u + 1;
        func_001757E0(p, 0x12, 0);
    }
    if (p[6] == 2) {
        if ((s8)func_00175700(p) < 0) {
            u32 w = p[5];
            p[5] = w + 1;
        }
    }
}

void func_001CC1B0(u8 *p) {
    u8 *a;
    if (*(u16 *)D_004C2710 != *(u16 *)((a = *(u8 **)(p + 0x18)) + 0x168)) {
        func_001CCB50();
        return;
    }
    if (*(s8 *)(a + 0x150) <= 0) {
        p[0x13C] = 0;
        return;
    }
    p[0x13C] = 1;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    {
        s8 *q = (s8 *)(D_004C2710 + 2);
        s8 v;
        if (*q == (v = *(s8 *)(*(u8 **)(p + 0x18) + 0x150))) {
            func_00175670();
        } else {
            *q = v;
            func_001754A0(p, 0x1B, D_004C2710[2]);
        }
    }
}

void func_00251680(u8 *p) {
    u32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(s8 *)(p + 0x151) = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001E3210(p, 0x18);
        v[0] = 0x422D5555;
        v[1] = 0x4322DB6D;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}

void func_0027BB50(u8 *p) {
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x38) += 2.14285707474f * (256000.0f * (1000.0f * func_00417440(((0x48 - *(s16 *)(p + 0x1E)) & 0x3F) << 10)) / 125000.0f / 256.0f);
    *(s16 *)(p + 0x1E) += 1;
    *(s16 *)(p + 0x1E) &= 0x3F;
}

void func_001C65D0(u8 *p, u8 *q) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        func_00175700(p);
        return;
    } else {
        f32 x, c, d;
        if (*(s16 *)(p + 0x140) == 0) {
            x = 80.0f + *(f32 *)(q + 0x34);
        } else {
            x = *(f32 *)(q + 0x34) - 80.0f;
        }
        c = *(f32 *)(p + 0x34);
        *(f32 *)(p + 0x34) = c + (x - c) / 8.0f;
        d = *(f32 *)(p + 0x38);
        *(f32 *)(p + 0x38) = d + (*(f32 *)(q + 0x430) - d) / 8.0f;
    }
}

void func_001A8550(u8 *p, u8 *q) {
    u8 *o;
    u32 t = p[5];
    p[5] = t + 1;
    *(s16 *)(p + 0x1E) = 10;
    if ((o = func_003DA750(p, 4, 2)) != 0) {
        *(void **)(o + 0x10) = (void *)func_001A7990;
        *(u8 **)(o + 0x18) = q;
        *(s16 *)(o + 0x1E) = *(s16 *)(p + 0x1E) - 1;
        if (func_001A8CB0(p) >= 80.0f) {
            o[0x20] = 0xB;
        } else {
            o[0x20] = 0xC;
        }
    }
    func_001A8610(p, q);
}

void func_00149820(s32 a) {
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_001498E0;
        o[0x23] = a;
        *(u16 *)(o + 0xCC) = D_004BF3B8[a];
        *(u32 *)(o + 0x84) = D_004C2804;
        *(V3 *)(o + 0x50) = D_00443BF8;
        *(V4 *)(o + 0x74) = D_00443C10;
        *(u32 *)(o + 0xD0) = 0x431;
    }
}

void func_0036A1D0(u8 *p) {
    if (*(s8 *)(p + 0x1B3) != 0) {
        u32 t = p[5];
        s16 *q;
        p[5] = t + 1;
        p[0x13C] = 1;
        *(s16 *)(p + 0x1C) = 0x3C;
        *(s16 *)(p + 0x1E) = 1;
        p[0x1B5] = 0x45;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        q = (s16 *)((p[2] << 1) + (u32)D_004C2794);
        q[0x7C / 2] += 1;
        func_001757E0(p, 0x17, 0x1F);
        return;
    }
    func_001E7F60();
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            func_0036A8A0(p);
        }
    }
}

void func_003DDD00(f32 *p) {
    f32 v0, v1;
    f32 x, y;
    func_003DE720(&v0, &v1);
    x = p[0];
    y = p[1];
    p[0] = x * v1 - y * v0;
    p[1] = x * v0 + y * v1;
    x = p[4];
    y = p[5];
    p[4] = x * v1 - y * v0;
    p[5] = x * v0 + y * v1;
    x = p[8];
    y = p[9];
    p[8] = x * v1 - y * v0;
    p[9] = x * v0 + y * v1;
}

void func_00253C80(u8 *p) {
    u8 *s = *(u8 **)(p + 0x1DC);
    s16 v;
    func_00175700(p);
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v == 0 || *(s16 *)(s + 0x434) == 0 || *(u8 *)&D_004D18A0 >= 5) {
        func_00254100(p);
        return;
    }
    if (*(s8 *)(p + 0x539) != 0) {
        if (func_0018AB10(p) == 0) return;
    } else if ((*(u16 *)(p + 0x362) & 0x300) == 0) {
        return;
    }
    {
        u32 t = p[6];
        p[6] = t + 1;
    }
}

void func_0018FFB0(u8 *p) {
    s32 i;
    for (i = 0; i < 3; i++) {
        u8 *e = D_004D18A0.e[p[2] ^ 1][i];
        if (e[0] != 0 && e[5] == 2) {
            u32 t = e[0x20A];
            if ((t == 0 || (u8)t == 0xD) && p == *(u8 **)(e + 0x1DC)) {
                func_0018F6B0(e);
            }
        }
    }
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00367C70(u8 *p) {
    extern void func_00175700();
    extern void func_00367F60(u8 *);
    extern u8 *D_004C2978[2];
    f32 v;
    func_00175700(p);
    *(f32 *)(p + 0x118) -= 0.050000001f;
    if (*(f32 *)(p + 0x118) <= 0.0f) {
        D_004C2978[0][2] = 0;
        func_00367F60(p);
    }
}

void func_00269FD0(u8 *p) {
    extern void func_0015D010(u8 *, u32 *);
    extern void func_0018C6E0(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    u32 v[4];
    if (p[0x22] & 2) {
        u32 t = p[0x1E6];
        p[0x1E6] = t ^ 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    v[0] = 0xC2555555;
    v[1] = 0x432B6DB6;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_0018C6E0(p);
    func_001266A0(p, 0xD, 7);
    func_001757E0(p, 0xF, 5);
    func_001E3210(p, 4);
}

void func_003965E0(u8 *p, u8 *q) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(q + 0x430) <= *(f32 *)(p + 0x38))) {
        u32 t = p[5];
        p[5] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        func_001757E0(p, 0x13, 7);
    }
}

void func_001A2310(u8 *p) {
    extern void func_00175910(u8 *, s32, s32, s32);
    extern void func_00178F20(u8 *, u32);
    extern u8 D_0044AF20[];
    s32 i;
    s32 n;
    n = *(s16 *)(p + 0x1E);
    i = 0;
    if (i < n - 1) do {
        func_00175910(p, 0x17, (u8)(D_0044AF20[p[0x23]] + 0x10), p[0x22]);
        i++;
        p = *(u8 **)(p + 0xC);
    } while (i < n - 1);
    func_00175910(p, 0xF, 0xA, ((p[0x22] + 2) & 0x1F) >> 2);
    func_00178F20(p, *(u32 *)(p + 0x1DC));
}

typedef struct { f32 x, y, z; } V3;
void func_00253410(u8 *p) {
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_0018C6E0(u8 *);
    extern void func_0015D010(u8 *, u32 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00179160(u8 *, u32);
    u32 v[4];
    func_001266A0(p, 6, 6);
    func_0018C6E0(p);
    p[0x1B4] = 10;
    v[0] = 0xC2B40000;
    v[1] = 0x431A4924;
    v[2] = 0;
    func_0015D010(p, v);
    func_001757E0(p, 0xF, 0);
    *(V3 *)v = *(V3 *)(p + 0x34);
    func_00179160(p, *(u32 *)(p + 0x1DC));
    *(V3 *)(p + 0x34) = *(V3 *)v;
}

void func_0015FEB0(u8 *p) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0015FB30();
    extern s32 func_00417A40();
    extern V3 D_004454F8[1];
    extern s32 D_004C283C;
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(u32 *)(o + 0x10) = (u32)func_0015FB30;
        *(u32 *)(o + 0xD0) = 0x41D;
        *(s16 *)(o + 0xCC) = 0x59;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(u8 **)(o + 0x14) = p;
        *(u32 *)(o + 0x78) = 0x3F800000;
        *(u32 *)(o + 0x7C) = 0;
        *(u32 *)(o + 0x80) = 0;
        *(s16 *)(o + 0x1E) = func_00417A40() % 0x168;
        *(V3 *)(o + 0x50) = D_004454F8[0];
    }
}

void func_00364AF0(u8 *p, u8 *q) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 lim;
    func_00175700(p);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s32 *)(p + 0xD0) != 0) {
        lim = 25.7142849f + *(f32 *)(q + 0x430);
    } else {
        lim = *(f32 *)(q + 0x430);
    }
    if (*(f32 *)(p + 0x38) <= lim) {
        u32 t = p[5];
        p[5] = t + 1;
        *(f32 *)(p + 0x38) = lim;
        func_001757E0(p, 0x17, (u8)(*(s32 *)(p + 0xD0) + 0x4D));
    }
}

void func_002309E0(u8 *p) {
    extern void func_00175700(u8 *);
    extern s32 func_001864a0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00183d50(u8 *);
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864a0(p) != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x169] = 0x16;
        p[0x168] = 1;
        func_001757E0(p, p[0x169], p[0x168]);
        func_00183d50(p);
    }
}

void func_003A9540(u8 *p) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_003A9730();
    s32 i, j;
    u8 *o;
    for (i = 0, j = 0; i < 2; i++, j += 2) {
        if ((o = func_003DA750(0, 1, 0)) != 0) {
            f32 x;
            *(u32 *)(o + 0x10) = (u32)func_003A9730;
            *(u8 **)(o + 0x18) = p;
            *(s16 *)(o + 0x26) = 0x2F04;
            o[0x20] = j;
            x = -13.333333f;
            if (*(s16 *)(p + 0x140) != 0) x = -x;
            *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34) + x;
            *(f32 *)(o + 0x38) = 102.85714f + *(f32 *)(p + 0x430);
        }
    }
}

void func_0034E1C0(u8 *p) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0034E290();
    s32 i;
    u8 *o;
    for (i = 0; i < 8; i++) {
        if ((o = func_003DA750(0, 1, 0)) == 0) break;
        *(u32 *)(o + 0x10) = (u32)func_0034E290;
        *(u8 **)(o + 0x18) = p;
        o[0x20] = 2;
        o[0x21] = i;
        *(s16 *)(o + 0x26) = 0x502;
    }
    for (i = 0; i < 8; i++) {
        if ((o = func_003DA750(0, 1, 0)) == 0) break;
        *(u32 *)(o + 0x10) = (u32)func_0034E290;
        *(u8 **)(o + 0x18) = p;
        o[0x20] = 1;
        o[0x21] = i;
        *(s16 *)(o + 0x26) = 0x502;
    }
}

void func_002139A0(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern s32 func_001E7FD0(u8 *);
    extern void func_00185640(u8 *, s32);
    s32 v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) == 0) {
        if ((v = func_001E7FD0(p)) != 0) {
            p[0x20B] = 0xC0;
            func_00185640(p, v);
        }
    }
}

void func_0030EE50(u8 *p) {
    extern void func_00185490(u8 *);
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001DD470(u8 *, s32);
    extern void func_0030F650(u8 *);
    extern s16 *D_004C2794[2];
    u32 t = p[6];
    if (t == 0) {
        s16 *g;
        p[6] = t + 1;
        func_00185490(p);
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        p[0x20D] = 1;
        p[0x1B5] = 0x48;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        g = (s16 *)((p[2] << 1) + (u32)D_004C2794[0]);
        g[0x3E] = g[0x3E] + 1;
        func_001757E0(p, 0x14, 5);
        func_001DD470(p, 2);
    } else {
        if (func_00175700(p) < 0) func_0030F650(p);
    }
}

void func_00194D50(u8 *p, u8 *q) {
    extern s32 func_00197560(u8 *);
    extern void func_00194C30(u8 *, u8 *);
    extern void func_00175670(u8 *);
    extern void func_001975C0(u8 *, u8 *);
    s16 h;
    if (func_00197560(p) == 0 && p[0x21] < 4) {
        h = *(s16 *)(p + 0x1C);
        if (h == 0) {
            s16 v = *(s16 *)(p + 0x1E) - 1;
            *(s16 *)(p + 0x1E) = v;
            if (v == 0) {
                func_00194C30(p, q);
                return;
            }
            func_00175670(p);
            *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            func_001975C0(p, q);
        } else {
            *(s16 *)(p + 0x1C) = h - 1;
        }
    }
}

void func_002B2130(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_00184540(u8 *);
    extern void func_001843A0(u8 *);
    if (p[0x20B] == 2) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
    if (func_00175700(p) < 0) {
        if (p[0x20B] == 2) func_00184540(p);
        else if (p[0x20D] == 2) func_00184540(p);
        else func_001843A0(p);
    }
}

void func_0014FCA0(u8 *p, s32 n) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0014FD80();
    extern void func_00150520(u8 *, f32, f32, f32);
    extern s32 D_004C27FC;
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(u32 *)(o + 0x10) = (u32)func_0014FD80;
        *(u32 *)(o + 0xD0) = 0x421;
        *(s16 *)(o + 0x1E) = n;
        *(u32 *)(o + 0x34) = 0x410547AE;
        *(u32 *)(o + 0x38) = 0xBF7D70A4;
        *(u32 *)(o + 0x3C) = 0x3DA3D70A;
        func_00150520(o, 1.0f, 0.620100021f, 0.807299972f);
        *(s16 *)(o + 0xCC) = 0x38;
        *(s32 *)(o + 0x84) = D_004C27FC;
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(u8 **)(o + 0x18) = p;
    }
}

void func_002F4E70(u8 *p, u8 *q) {
    extern s8 func_00175700(u8 *);
    extern void func_002F4F40(u8 *, u8 *);
    s32 t;
    p[0x209] = 2;
    t = *(s8 *)(p + 0x211);
    if (t != 0 && ((s8)t & 1) == p[0x1E6]) goto doit;
    if (func_00175700(p) < 0) goto doit;
    if (p[0x425] == 0 && (*(u16 *)(p + 0x362) & 0x60)) {
        u16 b = *(u16 *)(p + 0x35E);
        if (b & 0x1000) goto doit;
        if (b & 0x400) {
            p[6] = 5;
            goto out;
        }
    }
out:
    return;
doit:
    {
        u32 u = p[6];
        p[6] = u + 1;
        func_002F4F40(p, q);
    }
}

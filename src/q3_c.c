typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern int func_00175700(u8 *);
extern int func_00175670(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_002D7260(u8 *);

void func_002D7440(u8 *p) {
    if (p[7] == 0) {
        u32 t;
        *(s16 *)(p + 0x1C) = 0x3C;
        t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0x13, 6);
    } else {
        func_00175700(p);
    }
    func_002D7260(p);
}

extern void func_001266A0(u8 *, int, int);
extern void func_0015D010(u8 *, f32 *);
extern void func_0018C6E0(u8 *);

void func_001FB6A0(u8 *p) {
    f32 v[4];
    if ((p[0x22] & 2) == 0) {
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    func_001266A0(p, 5, 5);
    *(u32 *)&v[0] = 0x42055555;
    *(u32 *)&v[1] = 0x43430000;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 1);
}

extern void func_00184540(u8 *);
extern void func_001843A0(u8 *);
extern u8 *func_001B3E30(u8 *, int, int);
extern u8 *func_001B53E0(u8 *, s32, s32);

void func_00264D30(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        if (p[0x20D] == 2) {
            func_00184540(p);
        } else {
            func_001843A0(p);
        }
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_001B3E30(p, 0xC, 7);
        func_001B53E0(p, 0x22, 3);
    }
}

extern void func_00183d50(u8 *);
extern void func_00126400(void);

void func_002FFA30(u8 *p) {
    u32 *a = (u32 *)(p + 0x60); u32 *b = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *a = 0; *b = 0;
        func_00183d50(p);
        func_00126400();
        func_001843A0(p);
    }
}

void func_002588F0(u8 *p) {
    s16 t0;
    u32 t;
    *(f32 *)(p + 0x34) += (f32)(*(s16 *)(p + 0x140) != 0 ? 0x12 : -0x12);
    func_00175700(p);
    t0 = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = t0 - 1;
    if (t0 == 0) {
        t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x60) = 0x414DB6DB;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        *(s16 *)(p + 0x1C) = 8;
        func_001757E0(p, 0x12, 1);
    }
}

extern void func_00360080(u8 *, int, int);
extern void func_001E3710(u8 *, int);

void func_002472C0(u8 *p, u8 *q) {
    s32 f;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    f = *(s8 *)(p + 0x151);
    if (f & 2) {
        p[0x151] = f & 0x7D;
        func_00360080(p, 0, 0);
        func_001E3710(p, 0x4B);
    }
    if (q[6] != 0) {
        func_001757E0(p, 0x16, 6);
        t = p[6];
        p[6] = t + 1;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    }
}

void func_001F4EF0(u8 *p) {
    u8 *q;
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x422B6DB6;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        func_001757E0(p, 0xF, 0x2B);
    } else if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        p[0x1B5] = 0x53;
        q[0x1B5] = 0x53;
        q[0x20A] = 0x11;
    }
}

extern u8 D_00455CC0[];
extern void func_0028D810(u8 *, u8 *);
extern void func_001C09A0(u8 *, int);

void func_002881B0(u8 *p) {
    f32 *a = (f32 *)(p + 0x60);
    f32 *b = (f32 *)(p + 0x6C);
    u32 t;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(u32 *)a = 0;
        *(u32 *)b = 0;
        *(s16 *)(p + 0x1C) = 0x22;
        func_0028D810(p, D_00455CC0);
        func_001C09A0(p, 6);
        func_00175700(p);
    }
}

void func_002BF5B0(u8 *p) {
    u32 t;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_001757E0(p, 1, 5);
    }
}

extern int func_00174470(u8 *);
extern void func_003CAB00(u8 *, u8 *);
extern void func_003CAB20(u8 *, u8 *, int);

void func_003CC5A0(u8 *p, u8 *q) {
    if (func_00174470(p) == 0) {
        func_003CAB00(p, q);
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(q + 0x430)) {
        func_003CAB20(p, q, 0x10);
    }
}

extern void func_0036BFF0(u8 *, int, int, int);

void func_0025F260(u8 *p) {
    u32 t;
    if (*(s8 *)(p + 0x151) == 0x70) {
        p[0x151] = 0;
        func_0036BFF0(p, 6, 0x13, 6);
    }
    if (p[0x23] > 0) {
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x15, (u8)(p[0x23] + 0xF));
        return;
    }
    if (*(s8 *)(p + 0x153) < 0) {
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x15, 0xF);
    }
    func_00175700(p);
}

extern void func_001E7F60(u8 *);

void func_00351630(u8 *p) {
    s16 v;
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v != 0) {
        func_001E7F60(p);
    } else {
        t = p[5];
        p[5] = t + 1;
        func_001757E0(p, 0x15, (u8)(p[0x20] + 0x29));
        func_001E7F60(p);
    }
}

extern void (*D_0044EEF0[])(u8 *, u8 *);
extern void func_003DAA40();

void func_001DF5C0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    u8 st = p[4];
    if (st < 2) {
        D_0044EEF0[p[0x20]](p, q);
    } else if (st == 2) {
        p[4] = 3;
    } else {
        func_003DAA40();
    }
    p[0x24] = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7) {
        p[0x24] = 7;
    }
    if (*(s8 *)(p + 0x24) < 0) {
        p[0x24] = 0;
    }
}

extern void func_001A31D0(u8 *, int, int);

void func_0023EC30(u8 *p) {
    s32 f;
    u8 *q;
    if ((s8)func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
    f = *(s8 *)(p + 0x151);
    if (f & 1) {
        p[0x151] = f & ~1;
        func_001A31D0(p, 4, 0);
    }
    f = *(s8 *)(p + 0x151);
    if (f & 2) {
        p[0x151] = f & ~2;
        q = *(u8 **)(p + 0x1DC);
        q[0x20A] = 1;
        q[0x20D] = 2;
        q[0x1B5] = 0x21;
        p[0x1B5] = 0x21;
        q[0x1E6] = p[0x1E6];
    }
}

extern f32 D_004F1FC8[];
extern f32 D_004F1FCC[];
extern f32 D_004F1FD0[];
s32 func_0035AD40(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    s32 r = 0;
    if (D_004F1FC8[0] >= *(f32 *)(p + 0x34)) {
        *(f32 *)(p + 0x34) = D_004F1FC8[0];
        r += 1;
    } else if (D_004F1FCC[0] <= *(f32 *)(p + 0x34)) {
        *(f32 *)(p + 0x34) = D_004F1FCC[0];
        r += 1;
    }
    if (*(f32 *)(q + 0x430) >= *(f32 *)(p + 0x38)) {
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        r += 2;
    } else if (D_004F1FD0[0] <= *(f32 *)(p + 0x38)) {
        *(f32 *)(p + 0x38) = D_004F1FD0[0];
        r += 2;
    }
    return r;
}


extern void func_001975C0(u8 *, u8 *);

void func_00195E90(u8 *p, u8 *q) {
    s8 *a = (s8 *)(p + 0x88);
    u8 *r = q + 0x2B8;
    if (q[5] != 0 || *a != *(s8 *)(r + 0xC)) {
        *a = 0;
        p[5] = 0;
    } else if (p[0x21] < 4 && q[0x15B] != 0) {
        *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + *(f32 *)(p + 0x60);
        func_00175670(p);
        func_001975C0(p, q);
    }
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002DF060(u8 *p) {
    extern void func_00183D90(u8 *);
    extern s32 func_00175700();
    extern void func_001843A0();
    f32 *a, *b;
    f32 v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    a = (f32 *)(p + 0x5C);
    b = (f32 *)(p + 0x68);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(f32 *)(p + 0x5C) > 0.0f) func_00183D90(p);
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        *a = 0;
        *b = 0;
    }
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}

void func_00390EF0(u8 *p, u8 *q) {
    extern void func_00175700();
    s16 v;
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        t = p[5];
        p[5] = t + 1;
        t = p[0x21];
        *(u32 *)(q + 0x2F8) = t + 1;
        if (p[0x21] == 4) *(s32 *)(q + 0x2F8) = -1;
    }
}

void func_003BAE60(u8 *p) {
    extern void func_003BD0A0();
    extern s32 func_00175700();
    extern void func_003BD4A0();
    extern void func_001E7F60();
    u8 *q;
    f32 lim;
    q = *(u8 **)(p + 0x18);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_003BD0A0(p);
    lim = *(f32 *)(q + 0x430);
    if (!(lim <= *(f32 *)(p + 0x38))) {
        *(f32 *)(p + 0x38) = lim;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
    }
    if ((s8)func_00175700(p) < 0) {
        func_003BD4A0(p);
    } else {
        func_001E7F60(p);
    }
}

typedef struct { s32 w[3]; } S12;
extern S12 D_0045AB50[];

void func_002DBDB0(u8 *p) {
    extern void func_001D0D30();
    extern void func_0015D010();
    extern void func_001266A0();
    extern void func_001757E0();
    extern void func_0018C6E0(void *);
    s32 a;
    if (p[0x22] & 1) {
        *(s16 *)(p + 0x140) ^= 1;
        p[0x1E6] ^= 1;
    }
    if ((p[0x20B] & 0x3F) == 0) func_001D0D30(p, 1);
    a = 0;
    if ((p[0x20B] & 0x3F) != 0) {
        *(s16 *)(p + 0x1C) = 0x40;
        a = 1;
    }
    func_0015D010(p, &D_0045AB50[a]);
    p[0x1B4] = 10;
    func_001266A0(p, 0, 5);
    func_001757E0(p, 0xF, p[0x20B] & 0x3F);
    func_0018C6E0(p);
}

void func_0020FC30(u8 *p) {
    extern s32 func_00175700();
    extern void func_001757E0();
    f32 *a, *b, *c, *d;
    u32 t;
    d = (f32 *)(p + 0x6C);
    c = (f32 *)(p + 0x68);
    b = (f32 *)(p + 0x60);
    a = (f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) < 0) {
        t = p[6];
        p[6] = t + 1;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_001757E0(p, 2, 3);
    }
}

void func_002483F0(u8 *p) {
    extern s32 func_00188690();
    extern s32 func_00188ED0();
    extern s32 func_00188C70();
    extern s32 func_00189130();
    extern s32 func_00248680();
    extern s32 func_00248700();
    extern s32 func_00248600();
    extern s32 func_00248590();
    extern s32 func_002484E0();
    extern s32 func_00248780();
    extern s32 func_002487F0();
    extern void func_00187E00();
    extern void func_00187BB0();
    extern void func_00188330();
    if (func_00188690(p) != 0) return;
    if (func_00188ED0(p) != 0) return;
    if (func_00188C70(p) != 0) return;
    if (func_00189130(p) != 0) return;
    if (func_00248680(p) != 0) return;
    if (func_00248700(p) != 0) return;
    if (func_00248600(p) != 0) return;
    if (func_00248590(p) != 0) return;
    if (func_002484E0(p) != 0) return;
    if (func_00248780(p) != 0) return;
    if (func_002487F0(p) != 0) return;
    func_00187E00(p, p + 0x3E0);
    func_00187BB0(p);
    func_00188330(p);
}

void func_002E28E0(u8 *p) {
    extern s32 func_00175700();
    extern void func_001757E0();
    extern void func_001E3210();
    extern void func_001830D0();
    u32 v[3];
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if ((s8)func_00175700(p) < 0) {
        t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1E) = 0x60;
        *(s16 *)(p + 0x1C) = 2;
        func_001757E0(p, 0x16, 0x11);
        func_001E3210(p, 0x18);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        p[0x151] = 0;
        v[0] = 0xC0A00000;
        v[1] = 0x437CDB6D;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}

void func_0031DC40(u8 *p) {
    extern s32 func_00175700();
    extern void func_001757E0();
    f32 z = 0.0f;
    f32 *a, *b;
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    a = (f32 *)(p + 0x5C);
    b = (f32 *)(p + 0x68);
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < z)) {
        *a = z;
        *b = z;
    }
    func_00175700(p);
    if (*(f32 *)(p + 0x60) < z) {
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        p[0x1B2] = 1;
        *(u32 *)(p + 0x6C) = 0xBF9A4924;
        func_001757E0(p, 0x15, 4);
    }
}

void func_00229C20(u8 *p) {
    extern void func_0022C5C0();
    extern s32 func_00175700();
    extern void func_00126400();
    extern void func_0022C580();
    u8 *q;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_0022C5C0(p);
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x20D] = 2;
        q[0x1E6] = p[0x1E6];
        q[0x1B5] = 0x24;
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) ^= 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_00126400();
        func_0022C580(p);
    }
}

void func_0028D300(u8 *p) {
    extern void func_0015D010();
    extern void func_0018C6E0(void *);
    extern void func_001757E0();
    f32 v[3];
    *(u32 *)v = 0;
    if (*(s8 *)(p + 0x1E7) >= 0) {
        *(u32 *)v = 0xC0D55555;
        if (p[0x1E6] != 0) v[0] = -v[0];
        if (*(s8 *)(p + 0x1E7) != 0) v[0] = -v[0];
    }
    *(f32 *)(p + 0x5C) = v[0];
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    if (p[0x22] & 2) {
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    *(u32 *)v = 0xC292AAAA;
    *(u32 *)(v + 1) = 0x42D64924;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 1);
}

void func_002B2200(u8 *p) {
    extern s32 func_00175700();
    extern void func_001266A0();
    extern void func_0018FDB0();
    extern void func_001549B0();
    extern void func_001E3B70();
    f32 v[3];
    u8 *q;
    u32 t;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        func_001266A0(p, 0, 0);
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        *(u8 **)(*(u8 **)(p + 0x1DC) + 0x1C8) = p;
        (*(u8 **)(p + 0x1DC))[0x1B5] = 0x22;
        func_0018FDB0(p);
        (*(u8 **)(p + 0x1DC))[0x20A] = 1;
        q = *(u8 **)(p + 0x1DC);
        q[0x1B5] = 0x23;
        *(u32 *)v = 0xC2D55555;
        *(u32 *)(v + 1) = 0x43092492;
        func_001549B0(p, v, q, 0x23);
        func_001E3B70(*(u8 **)(p + 0x1DC), 1);
        *(u32 *)(p + 0x60) = 0x41092492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        *(u32 *)(p + 0x5C) = 0x40D55555;
        *(u32 *)(p + 0x68) = 0;
        if (*(s16 *)(p + 0x140) != 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
}

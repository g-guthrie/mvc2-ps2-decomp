typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;


extern void func_00175C00();
extern void func_003DAA40();
void func_00328E00(u8 *a, u8 *b) {
    if (b[0x23E] == 2) {
        s8 v = *(s8 *)(b + 0x23D) - 1;
        *(s8 *)(b + 0x23D) = v;
        if (v < 0) *(s8 *)(b + 0x23D) = 0;
    }
    func_00175C00(b, 1);
    func_003DAA40(a);
}

extern int func_00175700(u8 *);
extern void func_00175C00();
extern void func_001757E0();
void func_00234FB0(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        p[6] = 0;
        p[0x20] = 0;
        func_00175C00(p, 0);
        func_001757E0(p, 0, 0);
    }
}

extern f32 D_004F1F40[];
s32 func_00237CD0(u8 *a, u8 *b) {
    f32 *t = D_004F1F40;
    s8 m = *(s8 *)(a + 0x211);
    u32 bit = (u8)m;
    s32 r;
    f32 v;
    if (m == 0) {
        r = 0;
    } else if ((b[0x1D] & (u8)bit) == 0) {
        v = t[0x88 / 4];
        if (((u8)bit >> 1) == 0) v = t[0x8C / 4];
        *(f32 *)(a + 0x34) = v;
        b[0x1B] |= bit;
        r = (u8)bit;
    } else {
        r = 0;
    }
    return r;
}

extern void func_0015D010();
extern void func_00179160(void *, void *);
void func_0021C890(u8 *p, void *q) {
    u32 v[3];
    p[0x151] = 2;
    v[0] = 0xC1D55555;
    v[1] = 0x42892492;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_00179160(p, q);
}

extern int func_00175700(u8 *);
extern void func_001FA3B0();
extern void func_00183D10();
extern void func_00347F90();
void func_001FA090(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    func_001FA3B0(p);
    if ((*(s8 *)(p + 0x161) & 1) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x20D] = 2;
        func_00183D10(p);
        func_00347F90(p, 1);
    }
}

extern u32 *func_003DA750();
extern void func_001BC7A0(u8 *);
void *func_001BC720(void *a, void *b, u8 c, int d) {
    u32 *r = func_003DA750(0, 3, 0);
    if (r != 0) {
        r[4] = (u32)func_001BC7A0;
        r[6] = (u32)a;
        r[5] = (u32)b;
        *(u8 *)(r + 8) = c;
        *(u8 *)((u8 *)r + 0x23) = d;
    }
    return r;
}

extern int func_00175700(u8 *);
extern void func_00183D50(u8 *);
void func_002CF570(u8 *p) {
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183D50(p);
    } else if (*(s8 *)(p + 0x151) == 0) {
        func_00175700(p);
    }
}

extern void *func_003484A0(u8 *, s32, s32);
extern void func_001E3210();
extern int func_00175700(u8 *);
extern void func_001843A0();
void func_001FEE40(u8 *p) {
    u8 *q = p + 0x2B8;
    s8 r;
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        if (func_003484A0(p, 0, 0) != 0) {
            q[0x1A] = 1;
            func_001E3210(p, 0x1E);
        }
    }
    r = func_00175700(p);
    if (r < 0) {
        q[0xC] = 0;
        func_001843A0(p);
    }
}

extern u16 D_004D18DC[];
extern u8 D_004D18DB[];
extern int func_00175700(u8 *);
extern void func_001E7F60();
void func_003546D0(u8 *p) {
    if ((D_004D18DC[0] & (1 << D_004D18DB[0])) == 0) {
        s8 r = func_00175700(p);
        if (r < 0) {
            u32 t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
        } else if (p[0x20] == 0) {
            func_001E7F60(p);
        }
    }
}

extern int func_00175700(u8 *);
extern void func_001E3210();
extern void func_001757E0();
extern s32 func_00185980();
extern void func_00276230();
void func_002761A0(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        func_001E3210(p, 3);
        p[6] = 2;
        func_001757E0(p, 0x15, 0x16);
    } else if (*(s8 *)(p + 0x1B2) != 0) {
        if (func_00185980(p) != 0) {
            func_001E3210(p, 5);
            func_00276230(p);
        }
    }
}

extern s32 func_0016B250();
extern void func_0016B0C0();
extern s32 func_00169DD0();
extern s32 func_00165C90();
s32 func_00165C00(u8 *p, u8 *q) {
    s32 r;
    if (func_0016B250(p, 4) == 0) {
        r = 0;
    } else {
        u32 t;
        func_0016B0C0(p, q, 0);
        func_0016B0C0(p, q, 1);
        t = p[0x451];
        p[0x451] = t + 1;
        *(s32 *)(p + 0x460) = func_00169DD0(p, *(s32 *)(p + 0x4C8));
        r = func_00165C90(p, q);
    }
    return r;
}

extern void func_0015D010();
extern void func_001266A0();
extern void func_001757E0();
void func_002AB350(u8 *p) {
    u32 v[3];
    s16 t;
    t = p[0x1E6] ^ 1;
    *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = t;
    *(u8 *)(*(u8 **)(p + 0x1DC) + 0x1E6) = t;
    v[0] = 0xC1BAAAAA;
    v[1] = 0x43654924;
    v[2] = 0;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_001266A0(p, 5, 5);
    func_001757E0(p, 0xF, 2);
}

extern int func_00175700(u8 *);
extern s32 func_00185A90();
extern s32 func_001864a0();
extern void func_001865B0();
void func_0017B250(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00185A90(p) == 0) {
        if (func_001864a0(p) != 0) func_001865B0(p);
    }
}

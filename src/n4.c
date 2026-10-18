typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern V3 D_0043DF10[][3];
typedef struct { u8 pad[5]; u8 b; } E6;
extern E6 D_0044B470[];
extern void func_00175580();
extern void func_001757E0();
extern s32 func_00175700();
extern void func_00352670();

void func_00132FB0(u8 *p) {
    u8 *o;
    p[0x13C] = 0;
    o = *(u8 **)(p + 0x18);
    if (*(s16 *)(o + 0x2B4) != 0) {
        p[0x13C] = 1;
        *(V3 *)(p + 0x34) = D_0043DF10[o[2]][o[0x425]];
    }
}

void func_001A7D50(u8 *p, u8 *q) {
    if (*(s8 *)(q + 0x151) == 0 || q[0x1E4] != 0x22) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
func_00175580(p, 0x1B, ((u8*)(D_0044B470 + p[0x20]))[5], *(s8 *)(q + 0x150));
    }
}

extern void func_0034B040();
extern void func_0015E630();
extern void func_0034AFC0();
extern void func_00291DC0();

void func_0034A800(u8 *p, u8 *q) {
    *(u8 **)(q + 0x2BC) = p;
    *(u32 *)(p + 0x14C) = 0x80403030;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    *(s16 *)(p + 0x140) ^= 1;
    func_0034B040(p);
    func_001757E0(p, 0x16, 9);
    func_0015E630(p);
    p[0] = 1;
    func_0034AFC0(p, q);
}

void func_00253D40(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v != 0) {
            u32 t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0xF, 3);
        } else {
            p[6] = 6;
            func_001757E0(p, 0xF, 5);
        }
    }
}

void func_00291D30(u8 *p, u8 *q) {
    u32 t = q[0x18];
    q[0x18] = t + 1;
    *(s16 *)(p + 0x1C) = 6;
    q[0x19] = 0;
    if (p[0x1E6] == 0) {
        *(u32 *)(p + 0x5C) = 0x40855555;
    } else {
        *(u32 *)(p + 0x5C) = 0xC0855555;
    }
    *(u32 *)(p + 0x68) = 0;
    func_001757E0(p, 0x16, 8);
    func_00291DC0(p, q);
}


void func_002121B0(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u8 *q = p + 0x2B8;
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        q[1] = 0x40;
        *(s16 *)(q + 2) = 4;
        q[0] = 0;
        func_00352670(p, 1, 0, 0);
        q[4] = 0xFF;
    }
}

extern void func_001266A0();
extern void func_00361940();
extern void func_00186A60();

void func_002D89A0(u8 *p) {
    s16 v;
    func_001266A0(p, 5, 5);
    if ((*(u16 *)(p + 0x20E) & 0x800) == 0) {
        *(s16 *)(p + 0x140) ^= 1;
        p[0x1E6] ^= 1;
    }
    v = p[0x1E6] ^ 1;
    *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = v;
    *(u8 *)(*(u8 **)(p + 0x1DC) + 0x1E6) = v;
    p[6] = 0;
    *(s8 *)(p + 0x2BE) = -1;
    func_001757E0(p, 0xF, p[0x20B]);
}

void func_00246650(u8 *p, u8 *q) {
    s16 v;
    if ((*(s16 *)(p + 0x1C) & 3) == 0) {
        func_00361940(p, 0, p[0x1E]);
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
    }
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0x5A;
        q[9] = 1;
    }
}

extern void func_003BD7F0();
extern void func_003BD7A0();
extern void func_003BD810();

void func_003BAA80(u8 *p) {
    u32 t = p[6];
    u8 *q = p + 0xD0;
    if (t == 0) {
        p[6] = t + 1;
        if (*(s8 *)(q + 7) >= 0) {
            func_003BD7F0(p);
        }
        func_001757E0(p, 0x19, 2);
        func_003BD7A0(p);
    } else {
        if ((s8)func_00175700(p) < 0) {
            func_003BD810(p);
        } else {
            func_003BD7A0(p);
        }
    }
}

void func_001F4800(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x5C) = 0x41055555;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x41D64924;
        *(u32 *)(p + 0x6C) = 0xBFAB6DB6;
        if (p[0x1E6] == 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        func_001757E0(p, 0xF, 0x39);
    }
}

extern void func_0016B0C0();
extern s32 func_0016B240();
extern void func_00186CE0();
extern s32 func_00166710();
extern void func_003DAA40();
extern void (*D_00472B40[])();

void func_002E5710(u8 *p) {
    f32 *vx = (f32 *)(p + 0x60);
    f32 *vy = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)vx = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)vy = 0;
    }
}

s32 func_00166810(u8 *p, u8 *q) {
    u32 t;
    if (func_0016B240(p, 0) == 0) {
        return 0;
    }
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 1);
    t = p[0x451];
    p[0x451] = t + 1;
    *(u32 *)(p + 0x460) = *(u32 *)(p + 0x4C8);
    *(u32 *)(p + 0x468) = 10;
    *(u32 *)(p + 0x46C) = 0;
    *(s8 *)(p + 0x4B6) = -0x4C;
    func_00186CE0(p, 10);
    return func_00166710(p, q);
}

void func_003A2540(u8 *p) {
    u8 *o = *(u8 **)(p + 0x18);
    s32 base;
    if (p[4] < 2) {
        D_00472B40[p[0x20]](p, o);
    } else {
        func_003DAA40();
    }
    base = *(s8 *)(o + 0x24);
    p[0x24] = base + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7) {
        p[0x24] = 7;
    }
    if (*(s8 *)(p + 0x24) < 0) {
        p[0x24] = 0;
    }
}

extern void func_001830D0();

void func_00246F00(u8 *p) {
    u32 v[3];
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        t = p[6] + 1;
        p[6] = t;
        v[0] = 0xC2960000;
        v[1] = 0x43362492;
        v[2] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001830D0(p, v, 1, t);
    }
}

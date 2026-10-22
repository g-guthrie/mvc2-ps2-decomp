typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

void func_00132A50(u8 *d, u8 *s) {
    extern f32 D_0043E134, D_0043E138, D_0043E13C, D_0043E144, D_0043E148, D_0043E14C;
    extern void func_00132730();
    *(f32 *)(d + 0x78) = D_0043E134;
    *(f32 *)(d + 0x7C) = D_0043E138;
    *(f32 *)(d + 0x80) = D_0043E13C;
    if (*(s16 *)(s + 0x2B4) != 0) {
        *(f32 *)(d + 0x78) = D_0043E144;
        *(f32 *)(d + 0x7C) = D_0043E148;
        *(f32 *)(d + 0x80) = D_0043E14C;
    }
    if (*(s16 *)(d + 0x1C) != *(s16 *)(s + 0x2B4) && *(s16 *)(s + 0x2B4) == 0 && s[0x425] != 0) {
        func_00132730(s);
    }
    *(s16 *)(d + 0x1C) = *(s16 *)(s + 0x2B4);
}

void func_00141C90(s32 idx, s32 v) {
    extern void func_001415B0();
    extern u8 *D_004CACB0[];
    u8 *o = D_004CACB0[idx];
    if (o != 0) {
        *(u8 *)(o + 0x13C) = 1;
        *(s32 *)(o + 0x10) = v;
        *(s16 *)(o + 0x1C) = 1;
        *(f32 *)(o + 0x48) = 0;
        *(f32 *)(o + 0x44) = 0;
        *(f32 *)(o + 0x40) = 0;
        *(f32 *)(o + 0x58) = 1.0f;
        *(f32 *)(o + 0x54) = 1.0f;
        *(f32 *)(o + 0x50) = 1.0f;
        func_001415B0();
    }
}

void func_00183AD0(u8 *p) {
    extern u8 D_004D18B8[], D_004D18BC[], D_004D18C0[];
    extern void func_00175C00();
    u8 m; m = ~(1 << *(s8 *)(p + 2)); p[0x25C] &= m;
    func_00175C00(*(s32 *)(D_004D18B8 + (p[2] ^ 1) * 12), 10);
    func_00175C00(*(s32 *)(D_004D18BC + (p[2] ^ 1) * 12), 10);
    func_00175C00(*(s32 *)(D_004D18C0 + (p[2] ^ 1) * 12), 10);
}

void func_00229D10(u8 *p) {
    extern void func_0022C5C0();
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_0022C6B0();
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_0022C5C0(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) > *(f32 *)(p + 0x430)) {
        func_00175700(p);
        return;
    }
    p[6]++;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    func_001757E0(p, 0xF, 2);
    func_0022C6B0(p);
}

void func_002428E0(u8 *p) {
    extern void func_00175700();
    extern void func_001A6BE0();
    extern void func_001757E0();
    f32 *p5c, *p60, *p68, *p6c;
    func_00175700(p);
    p5c = (f32 *)(p + 0x5C); p68 = (f32 *)(p + 0x68); p60 = (f32 *)(p + 0x60); p6c = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[6]++;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *p5c = 0; *p60 = 0; *p68 = 0; *p6c = 0;
        func_001A6BE0(p, 2);
        func_001757E0(p, 0x14, 1);
    }
}

void func_00245530(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    f32 *a60, *a6c;
    func_00175700(p);
    a60 = (f32 *)(p + 0x60); a6c = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *a60 = 0; *a6c = 0;
        func_001757E0(p, 2, 3);
    }
}

void func_00253BC0(u8 *p) {
    extern u8 D_004D18A0;
    extern void func_00175700();
    extern void func_00254100();
    extern void func_00253FC0();
    extern void func_001757E0();
    u8 *q = *(u8 **)(p + 0x1DC);
    s16 h;
    func_00175700(p);
    if (*(s16 *)(q + 0x434) == 0 || D_004D18A0 >= 5) {
        func_00254100(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        func_00253FC0(p);
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h == 0) {
            p[6]++;
            *(s16 *)(p + 0x1C) = 7;
            *(s16 *)(p + 0x1E) = 0xC;
            func_001757E0(p, 0xF, 0xB);
        }
    }
}

void func_0028EED0(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    u8 m, q;
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    m = p[0x1FC];
    switch (m) {
    case 2:
        q = p[6];
        if (q == 0) {
            if (*(s8 *)(p + 0x151) != 0) {
                p[6] = q + 1;
                if (*(s16 *)(p + 0x140) == 0) {
                    *(u32 *)(p + 0x5C) = 0xBFD55555;
                    *(u32 *)(p + 0x68) = 0;
                } else {
                    *(u32 *)(p + 0x5C) = 0x3FD55555;
                    *(u32 *)(p + 0x68) = 0x80000000;
                }
            }
        } else {
            if (*(s8 *)(p + 0x151) == 0) {
                *(u32 *)(p + 0x68) = 0;
                *(u32 *)(p + 0x5C) = 0;
            }
        }
        break;
    case 0:
        break;
    case 1:
        break;
    }
}

void func_002B1130(u8 *p) {
    extern void func_00175700();
    extern void func_001830D0();
    f32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) & 1) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 0x3C;
        p[0x404] = 0;
        p[0x405] = 0;
        *(u32 *)&v[0] = 0xC23AAAAA;
        *(u32 *)&v[1] = 0x430B4924;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}

void func_002F7390(u8 *a, u8 *b) {
    extern u8 D_0045BE20[];
    extern void func_00175C00();
    extern void func_00176160();
    s16 t;
    u8 c;
    t = *(s16 *)(b + 0xE);
    if (t != 0) {
        if (*(s8 *)(a + 0x1B4) == 0) *(s16 *)(b + 0xE) = t - 1;
        c = b[0x14];
        b[0x14] = c - 1;
        if (c != 0) return;
        b[0x14] = 4;
        b[0x15]++;
        if (D_0045BE20[b[0x15]] == 0xFF) b[0x15] = 2;
        func_00176160(a, 0, D_0045BE20[b[0x15]] + 0x22 + a[0x25] * 28, 1);
    } else {
        func_00175C00(a, 0);
        b[0xD] = 0;
    }
}

void func_003479A0(u8 *p) {
    extern int func_00174470(const void *);
    extern void func_00175700();
    f32 z;
    u8 *s;
    z = 0.0f;
    s = *(u8 **)(p + 0x18) + 0x2B8;
    if (*(f32 *)(p + 0x118) <= z) p[4]++;
    if (func_00174470(p) == 0) {
        p[4]++;
        return;
    }
    if (*s == 0) p[4]++;
    *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 0x14) + 0x34);
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x14) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x14) + 0x54);
    *(f32 *)(p + 0x118) = *(f32 *)(*(u8 **)(p + 0x14) + 0x118);
    func_00175700(p);
}

void func_0034CE70(u8 *p) {
    extern void (*D_00462190[])();
    u8 *o;
    s16 h;
    s32 t;
    h = *(s16 *)(p + 0x1E);
    o = *(u8 **)(p + 0x18);
    if (h != 0) *(s16 *)(p + 0x1E) = h - 1;
    if (o[0x1E4] != 0x1D || o[0x1FD] != 6 || o[6] == 5) {
        p[4] = 2;
        p[0x13C] = 0;
    } else {
        t = *(s8 *)(p + 0x1B4);
        if (t != 0) {
            *(s8 *)(p + 0x1B4) = t - 1;
        } else {
            *(f32 *)(p + 0x118) = *(f32 *)(o + 0x118);
            *(f32 *)(p + 0x50) = *(f32 *)(o + 0x50);
            *(f32 *)(p + 0x54) = *(f32 *)(o + 0x54);
            p[0x21] = 0xFF;
            D_00462190[p[5]](p);
        }
    }
}

s32 func_003DCC70(s32 a, s32 b, s32 c) {
    extern u8 D_004BA508[], D_004BA510[];
    extern void func_0011FE88();
    extern s32 func_0011FFA0();
    extern void func_0011FC10();
    extern void func_00120868();
    extern s32 func_00107E90();
    extern void func_00108298();
    extern void func_00108730();
    extern void func_00108118();
    char buf[0x800];
    char *end;
    s32 fd;
    func_0011FE88(buf, D_004BA508);
    end = buf + func_0011FFA0(buf);
    func_0011FC10(buf, a);
    func_00120868(end);
    func_0011FC10(buf, D_004BA510);
    if ((fd = func_00107E90(buf, 0x100)) < 0) return 0;
    func_00108298(fd, 0, 2);
    func_00108730(fd, b, c);
    func_00108118(fd);
    return 1;
}

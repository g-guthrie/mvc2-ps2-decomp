typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_004F1F45, D_004F1F46;
void func_002B4710(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001E3710(u8 *, s32);
    extern void func_001CDE40(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    f32 c;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x430) <= *(f32 *)(p + 0x38))) {
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        if (*(s16 *)(p + 0x140) != 0) {
            c = -106.66666412353516f;
            *(f32 *)(p + 0x34) += c;
        } else {
            c = 106.66666412353516f;
            *(f32 *)(p + 0x34) += c;
        }
        D_004F1F45 = 1;
        D_004F1F46 = 1;
        func_001E3710(p, 0x49);
        func_001CDE40(p, 1, 0);
        func_001CDE40(p, 1, 1);
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        func_001757E0(p, 0xD, 0x22);
    }
}
void func_00236350(u8 *a, u8 *b) {
    extern void func_00175700(u8 *);
    extern void func_00238B70(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    if (b[5] == 1) {
        *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
        *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
        *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
        *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
        func_00175700(a);
        func_00238B70(a, b);
        if ((*(s8 *)(a + 0x211) & (1 << (a[0x1E6] ^ 1))) != 0 || ((1 << a[0x22]) & 0xFC00000F) == 0) {
            b[5] = 2;
        }
    } else {
        t = a[6];
        a[6] = t + 1;
        a[7] = 0;
        *(u32 *)(a + 0x5C) = 0xC0A00000;
        *(u32 *)(a + 0x68) = 0;
        *(u32 *)(a + 0x60) = 0x40AB6DB6;
        *(u32 *)(a + 0x6C) = 0xBF092492;
        if (*(s16 *)(a + 0x140) != 0) {
            *(f32 *)(a + 0x5C) = -*(f32 *)(a + 0x5C);
            *(f32 *)(a + 0x68) = -*(f32 *)(a + 0x68);
        }
        func_001757E0(a, 0x15, (u8)(a[0x20] * 3 + 0xD));
    }
}
extern u8 D_004F1F45, D_004F1F46;
void func_002B7580(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001CDE40(u8 *, s32, s32);
    extern void func_00175C00(u8 *, s32);
    extern void func_00126400(s32);
    extern void func_0018FDE0(u8 *);
    extern void func_0015B200(u8 *, u8 *, s32, s32);
    u32 t;
    s32 r;
    s8 f;
    u8 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    p[0x209] = 2;
    p[0x201] = 2;
    if (p[7] == 0) {
        t = p[7];
        p[7] = t + 1;
        func_00175700(p);
        f = p[0x151];
        if ((f & 1) != 0) {
            p[0x151] = f ^ 1;
            func_001CDE40(p, 2, 0);
        }
        f = p[0x151];
        if ((f & 2) != 0) {
            p[0x151] = f ^ 2;
            func_00175C00(p, 8);
            return;
        }
    } else {
        r = func_00175700(p);
        if ((s8)r < 0) {
            *(u8 **)(*(u8 **)(p + 0x220) + 0x1C8) = p;
            (*(u8 **)(p + 0x220))[0x20A] = 1;
            v = p[0x1E6];
            (*(u8 **)(p + 0x220))[0x1E6] = v;
            (*(u8 **)(p + 0x220))[0x1B5] = 0x23;
            func_00126400(v);
            (*(u8 **)(p + 0x220))[0x1E6] ^= 1;
            p[0x1B5] = 0x24;
            p[0x1FE] = 0;
            func_0018FDE0(p);
            func_00175C00(p, 0);
        } else {
            f = p[0x151];
            if ((f & 2) != 0) {
                p[0x151] = f ^ 2;
                func_0015B200(p, p + 0x34, 1, 0x108);
                D_004F1F45 = 3;
                D_004F1F46 = 1;
            }
        }
    }
}
void func_002CFDB0(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_002CFA20(u8 *);
    extern void func_001CFE00(u8 *, s32);
    extern void func_002D0130(u8 *);
    s16 h, g;
    u32 t;
    s32 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        h = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = h;
        if (h < 0) {
            g = *(s16 *)(p + 0x1C);
            *(s16 *)(p + 0x1E) = g;
            if (g != 0) {
                *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
                *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
                *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
                *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
                *(s16 *)(p + 0x1C) = 0;
                *(u32 *)(p + 0x60) = 0;
                *(u32 *)(p + 0x6C) = 0;
                *(u32 *)(p + 0x5C) = 0;
                *(u32 *)(p + 0x68) = 0;
                func_001757E0(p, 0x16, 0xC);
                return;
            }
            t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0x16, 8);
            func_002CFA20(p);
            return;
        }
    }
    v = *(s8 *)(p + 0x150);
    if (v != 0) {
        if (*(s16 *)(p + 0x1E) != 0) {
            func_001CFE00(p, (u8)((s8)v - 1));
            p[0x150] = 0;
        }
    }
    func_002D0130(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_002CFA20(p);
}
void func_00231680(u8 *p) {
    extern void func_00175700(u8 *);
    extern s32 func_001864A0(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001843A0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00185870(u8 *, u8 *);
    extern void func_00190D50(u8 *, u8 *);
    u8 *o;
    f32 z = 0.0f;
    f32 d, e;
    u32 t;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) >= 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (func_001864A0(p) != 0) {
            func_001266A0(p, 0, 0);
            func_001843A0(p);
            return;
        }
        o = *(u8 **)(p + 0x1DC);
        if (o[0x20D] == 2) {
            d = *(f32 *)(o + 0x34) - *(f32 *)(p + 0x34);
            if (d < z) d = -d;
            if (d <= 106.66666412353516f) {
                e = *(f32 *)(o + 0x38) - *(f32 *)(p + 0x38);
                e = 68.57142639160156f + e;
                if (e < z) {
                    func_001757E0(p, 0xF, 4);
                    p[0x20B] = 0xC4;
                    func_00185870(p, o);
                    func_00190D50(o, p);
                    func_001266A0(p, 5, 5);
                    o[0x24A] = 0;
                    t = p[7];
                    p[7] = t + 1;
                }
            }
        }
    }
}
extern f32 D_0045E86C[];
void func_00330CE0(u8 *p) {
    extern void func_00330EF0(u8 *);
    extern void func_00330EB0(u8 *);
    extern void func_00330E70(u8 *);
    extern s32 func_003D90A0(s32);
    s16 h;
    u32 t;
    f32 x, y, z;
    func_00330EF0(p);
    switch (p[4]) {
    case 0:
        h = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = h;
        if (h < 0) {
            *(s16 *)(p + 0x1E) = 0;
        } else {
            func_00330EB0(p);
        }
        if (func_003D90A0(0) != 0) {
            t = p[4];
            p[4] = t + 1;
            *(s16 *)(p + 0x1E) = 0;
        }
        break;
    case 1:
        x = 0.5f * (f32)*(s16 *)(p + 0x1E);
        *(f32 *)(p + 0x38) = D_0045E86C[0] + (10.0f - 0.5f * x) * x;
        h = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = h;
        if (h >= 0x14) {
            t = p[4];
            p[4] = t + 1;
            *(s16 *)(p + 0x1E) = 0;
        }
        break;
    case 2:
        func_00330E70(p);
        x = 0.5f * (f32)*(s16 *)(p + 0x1E);
        y = 50.0f + D_0045E86C[0];
        z = -0.5f * x;
        z = z * x;
        *(f32 *)(p + 0x38) = y + z;
        h = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = h;
        if (h >= 0x14) {
            p[4] = 0;
            *(f32 *)(p + 0x38) = D_0045E86C[0];
        }
        break;
    }
}

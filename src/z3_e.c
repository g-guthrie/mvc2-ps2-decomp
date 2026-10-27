typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
s32 func_00166200(u8 *a, u8 *b) {
    extern s32 func_0016B240();
    extern void func_0016B0C0();
    extern s32 func_0016AD50();
    extern s32 func_00166C80();
    if (func_0016B240(a, 4) == 0) return 0;
    func_0016B0C0(a, b, 0);
    func_0016B0C0(a, b, 2);
    *(s32 *)(a + 0x460) = *(s32 *)(a + 0x4C8);
    func_0016B0C0(a, b, 2);
    *(s32 *)(a + 0x464) = *(s32 *)(a + 0x4C8);
    func_0016B0C0(a, b, 2);
    *(s32 *)(a + 0x468) = *(s32 *)(a + 0x4C8);
    func_0016B0C0(a, b, 2);
    *(s32 *)(a + 0x46C) = *(s32 *)(a + 0x4C8);
    return func_00166C80(a, b, func_0016AD50(a, (u8 *)((s32)a + 0x460)));
}

extern s8 D_004F7FC8[];
u8 func_00189FB0(u8 *a, u16 *b, u8 *c) {
    extern void func_0018A920();
    s8 t = c[1] - 1;
    c[1] = t;
    if (t <= 0) {
        return c[0] = 0;
    }
    if ((*(u16 *)(a + 0x362) & 0x3F60) == b[4 + c[2]]) {
        u32 v;
        func_0018A920(a, c);
        v = c[2] + 1;
        c[2] = v;
        if ((v & 0xFF) == b[0]) {
            c[0] = 2;
            c[1] = D_004F7FC8[a[2]] * 10 + 15;
        }
    }
    return 0;
}

void func_00244E40(u8 *p) {
    extern int func_00175700(u8 *);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        { u32 t = p[7]; p[7] = t + 1; }
        if (p[6] == 1) {
            *(u32 *)(p + 0x5C) = 0xC0D55555;
            *(u32 *)(p + 0x68) = 0x3D555555;
            *(u32 *)(p + 0x60) = 0xC02B6DB6;
            *(u32 *)(p + 0x6C) = 0xBD092492;
        } else {
            *(u32 *)(p + 0x5C) = 0xC0855555;
            *(u32 *)(p + 0x68) = 0x3CD55555;
            *(u32 *)(p + 0x60) = 0xC09A4924;
            *(u32 *)(p + 0x6C) = 0xBD892492;
        }
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}

void func_002FBE30(u8 *p) {
    extern s32 func_00188690(u8 *);
    extern s32 func_00188ED0(u8 *);
    extern s32 func_00188C70(u8 *);
    extern s32 func_00189130(u8 *);
    extern s32 func_002FC150(u8 *);
    extern s32 func_002FC0B0(u8 *);
    extern s32 func_002FBF20(u8 *);
    extern s32 func_002FC000(u8 *);
    extern s32 func_002FC210(u8 *);
    extern s32 func_002FC270(u8 *);
    extern void func_00187BB0(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00188330(u8 *);
    if (func_00188690(p)) return;
    if (func_00188ED0(p)) return;
    if (func_00188C70(p)) return;
    if (func_00189130(p)) return;
    if (func_002FC150(p)) return;
    if (func_002FC0B0(p)) return;
    if (func_002FBF20(p)) return;
    if (func_002FC000(p)) return;
    if (func_002FC210(p)) return;
    if (func_002FC270(p)) return;
    func_00187BB0(p);
    if (*(s8 *)(p + 0x150) != 0) {
        func_00175C00(p, 0);
    }
    func_00188330(p);
}

s32 func_001C5110(u8 *a) {
    extern s32 func_001C5200(u8 *, u8 *);
    extern s32 func_001C50B0(u8 *, u8 *);
    u8 *s = *(u8 **)(a + 0x18);
    if (s[0x2C0] == 0) {
        if (s[0x1E4] != 0x15 || s[0x1FD] != 6) {
            if (func_001C5200(a, s) != 0) {
                return func_001C50B0(a, s);
            }
        }
    }
    s = *(u8 **)(s + 0x220);
    if (s[1] == 0x1C || s[1] == 0x1D) {
        if (s[0x2C0] == 0) {
            if (s[0x1E4] != 0x15 || s[0x1FD] != 6) {
                if (func_001C5200(a, s) != 0) {
                    return func_001C50B0(a, s);
                }
            }
        }
    }
}

void func_0019DD00(u8 *a, u8 *b) {
    extern int func_00175700(u8 *);
    extern void func_0019DE40(u8 *, u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s16 v;
    a[0x24] = *(s8 *)(b + 0x24);
    if (a[0x22] == 0) {
        if ((s8)func_00175700(a) < 0) {
            func_0019DE40(a, b);
            return;
        } else {
            func_001E7F60(a);
        }
    } else {
        func_00175700(a);
        v = *(s16 *)(a + 0x1E) - 1;
        *(s16 *)(a + 0x1E) = v;
        if (v <= 0) {
            if (a[0x21] < 2) {
                u32 t = a[4];
                a[4] = t + 1;
                func_001757E0(a, 0x17, (a[0x21] + 0xB) & 0xFF);
            } else {
                func_0019DE40(a, b);
            }
        } else {
            func_001E7F60(a);
        }
    }
}

void func_003BC9E0(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    extern void func_003BD830(u8 *);
    s16 v;
    if (p[6] == 0) {
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0 || *(s8 *)(p + 0x1B3) != 0 || *(s8 *)(p + 0x1B2) != 0) {
            u32 t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0x19, 2);
        }
        func_001E7F60(p);
        return;
    }
    if ((s8)func_00175700(p) < 0) func_003BD830(p);
}

void func_002DE820(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_001843A0();
    extern void func_001865B0();
    f32 *v1, *a1, *a2, *a3;
    f32 z;
    if (p[7] == 0) {
        s8 r = func_00175700(p);
        if (r >= 0) return;
        func_001843A0(p);
        return;
    }
    func_00175700(p);
    v1 = (f32 *)(p + 0x5C);
    a2 = (f32 *)(p + 0x68);
    a1 = (f32 *)(p + 0x60);
    a3 = (f32 *)(p + 0x6C);
    z = 0.0f;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60) < z) {
        if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
            p[0x20D] = 0;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            *v1 = z;
            *a1 = z;
            *a2 = z;
            *a3 = z;
            func_001865B0(p);
        }
    }
}

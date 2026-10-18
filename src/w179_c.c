typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FD8;
extern f32 D_004F1FDC;
extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_00316400(u8 *p) {
    extern void func_00175700();
    extern void func_001E3210();
    u8 *q = p + 0x2B8;
    u8 *o;
    u32 t;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(s16 *)(p + 0x140) == 0) {
        if (!(D_004F1FD8 < *(f32 *)(p + 0x34))) q[0x14] = 1;
    } else {
        if (D_004F1FDC <= *(f32 *)(p + 0x34)) q[0x14] = 1;
    }
    if (q[0x14] != 0) {
        o = *(u8 **)(p + 0x1DC);
        *(u8 **)(o + 0x1C8) = p;
        o[0x1B5] = 0x23;
        p[0x1B5] = 0x23;
        o[0x20A] = 1;
        o[0x1E6] = p[0x1E6];
        t = o[0x1E6];
        o[0x1E6] = t ^ 1;
        p[0x1B4] = 8;
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        func_001E3210(p, 0x1E);
        p[6]++;
    }
}

void func_002594F0(u8 *p) {
    extern void func_001AFCB0();
    extern s32 func_00175700();
    extern void func_001843A0();
    f32 *a, *b, *c, *d;
    f32 z;
    s16 n;
    a = (f32 *)(p + 0x5C);
    b = (f32 *)(p + 0x60);
    c = (f32 *)(p + 0x68);
    d = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (p[0x425] == 0 && *(s8 *)(p + 0x151) == 2) {
        func_001AFCB0(p, 1);
        n = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = n;
        p[0x151] = 0;
    }
    z = 0.0f;
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) <= z)) {
        *a = z;
        *b = z;
        *c = z;
        *d = z;
    }
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}

void func_001F2B40(u8 *p) {
    extern s32 func_00175700();
    extern void func_001757E0();
    extern void func_001266A0();
    u8 *o;
    u32 t;
    p[0x206] = 3;
    if ((s8)func_00175700(p) < 0) {
        t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x5C) = 0x40BAAAAA;
        *(u32 *)(p + 0x68) = 0xBDD55555;
        *(u32 *)(p + 0x60) = 0x414DB6DB;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        func_001757E0(p, 0xF, 0x21);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_001266A0(p, 0, 0);
        o = *(u8 **)(p + 0x1DC);
        *(u8 **)(o + 0x1C8) = p;
        o[0x20A] = 2;
        if (p[0x269] == 3) {
            o[0x1B5] = 0x44;
            p[0x1B5] = 0x44;
        } else {
            o[0x1B5] = *(s8 *)(p + 0x1B7) + 0x43;
            p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x43;
        }
    }
}

void func_00220540(u8 *p) {
    extern s32 func_00175700();
    extern s32 func_001864a0();
    extern void func_001E3710();
    extern void func_001757E0();
    extern void func_00183d50();
    u32 *a, *b, *c, *d;
    f32 z;
    f32 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    a = (u32 *)(p + 0x5C);
    c = (u32 *)(p + 0x68);
    b = (u32 *)(p + 0x60);
    d = (u32 *)(p + 0x6C);
    z = 0.0f;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60) < z) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        *(f32 *)(p + 0x5C) = z;
        if (func_001864a0(p) != 0) {
            u32 t;
            func_001E3710(p, 0x34);
            t = p[6];
            p[6] = t + 1;
            *a = 0;
            *b = 0;
            *c = 0;
            *d = 0;
            func_001757E0(p, 0x15, 0xE);
            func_00183d50(p);
        }
    }
}

extern u8 D_00452FA0[];
extern u8 D_004D18E6;

void func_0024AEE0(u8 *p) {
    extern s32 func_00174170();
    extern s32 func_001841C0();
    u32 r;
    u8 v;
    if ((*(u16 *)(p + 0x4F0) & 0x3F0) != 0) {
        p[0x20] = 5;
        if ((*(u16 *)(p + 0x4F0) & 0x100) != 0) p[0x20] = 6;
        if ((*(u16 *)(p + 0x4F0) & 0x80) != 0) p[0x20] = 7;
        if ((*(u16 *)(p + 0x4F0) & 0x40) != 0) p[0x20] = 8;
        if ((*(u16 *)(p + 0x4F0) & 0x20) != 0) p[0x20] = 9;
        if ((*(u16 *)(p + 0x4F0) & 0x10) != 0) p[0x20] = 10;
    } else {
        r = func_00174170();
        p[0x20] = D_00452FA0[(r & 0xF) * 2];
    }
    if (D_004D18E6 == 0) {
        v = p[0x20];
        if (v == 8 || v == 9 || v == 10) p[0x20] = 5;
    }
    if (func_001841C0(p) > 1) p[0x20] = 5;
}

void func_003BC480(u8 *p) {
    extern s32 func_00175700();
    extern void func_003BD800();
    extern void func_001E7F60();
    u8 *q = *(u8 **)(p + 0x18);
    if (p[0x21] == 0) {
        if (q[5] != 0 || q[0x169] != 9 || q[0x168] != 1) {
            func_003BD800(p);
            return;
        }
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        if ((s8)func_00175700(p) < 0) {
            func_003BD800(p);
        } else {
            func_001E7F60(p);
        }
    } else {
        if (q[5] != 0 || q[0x169] != 0x15 || q[0x168] != 0x1A) {
            func_003BD800(p);
        } else {
            *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
            if ((s8)func_00175700(p) < 0) {
                func_003BD800(p);
            } else {
                func_001E7F60(p);
            }
        }
    }
}

void func_002A0760(u8 *p) {
    extern s32 func_00175700();
    extern void func_001266A0();
    extern void func_001757E0();
    extern void func_001549B0();
    extern void func_001548D0();
    extern void func_001E3710();
    u32 v[4];
    u32 t;
    if ((s8)func_00175700(p) < 0) {
        func_001266A0(p, 0, 0);
        t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x5C) = 0x403AAAAA;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x412B6DB6;
        *(u32 *)(p + 0x6C) = 0xBF2B6DB6;
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
        *(u8 **)(*(u8 **)(p + 0x1DC) + 0x1C8) = p;
        (*(u8 **)(p + 0x1DC))[0x20A] = 1;
        (*(u8 **)(p + 0x1DC))[0x1B5] = 0x20;
        func_001757E0(p, 0xF);
    }
    if ((*(s8 *)(p + 0x151) & 1) != 0) {
        p[0x151] = 0;
        v[0] = 0x42340000;
        v[1] = 0x4311B6DB;
        func_001549B0(p, v);
    }
    if ((*(s8 *)(p + 0x151) & 2) != 0) {
        p[0x151] = 0;
        func_001E3710(p, 6);
        v[0] = 0x42340000;
        v[1] = 0x431A4924;
        func_001548D0(p, v, 9);
    }
}

void func_002131A0(u8 *p, u8 *q) {
    extern void func_00174170();
    extern void func_00175700();
    extern void func_00212DE0();
    extern s32 func_0018AB10();
    extern void func_001757E0();
    extern void func_00175C00();
    extern void func_001E3240();
    extern void func_001E2490();
    s16 v;
    u32 t;
    s32 w;
    p[0x40C] = 2;
    p[0x33C] = 5;
    q[4] = 0xFF;
    func_00174170();
    func_00175700(p);
    func_00212DE0(p, q);
    if (*(s8 *)(q + 5) != 0 && func_0018AB10(p) != 0) {
        w = *(s8 *)(q + 5);
        *(s8 *)(q + 5) = w - 1;
        v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[0x168] = 1;
        if (p[0x20D] == 2) p[0x168] = 10;
        func_001757E0(p, 0x16, p[0x168]);
        q[4] = 0;
        func_00175C00(p, 0);
        func_001E3240(p, 0x1F);
        func_001E3240(p, 0x20);
        func_001E2490(6, 0x48);
    }
}

void func_003159D0(u8 *p) {
    extern void func_00175700();
    extern void func_001E3210();
    u8 *q = p + 0x2B8;
    u8 *o;
    u32 t;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(s16 *)(p + 0x140) == 0) {
        if (!(D_004F1FD8 < *(f32 *)(p + 0x34))) q[0x14] = 1;
    } else {
        if (D_004F1FDC <= *(f32 *)(p + 0x34)) q[0x14] = 1;
    }
    if (q[0x14] != 0) {
        o = *(u8 **)(p + 0x1DC);
        *(u8 **)(o + 0x1C8) = p;
        o[0x1B5] = 0x21;
        p[0x1B5] = 0x21;
        o[0x20A] = 1;
        o[0x1E6] = p[0x1E6];
        t = o[0x1E6];
        o[0x1E6] = t ^ 1;
        p[0x1B4] = 8;
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        func_001E3210(p, 0x1E);
        p[6]++;
    }
}

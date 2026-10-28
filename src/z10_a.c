typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00228820(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_0022C6B0();
    extern void func_0022C5D0();
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) > *(f32 *)(p + 0x430)) {
        func_00175700(p);
    } else {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_0022C6B0();
        func_0022C5D0(p);
    }
}

extern u8 D_004F1F45;
extern u8 D_004F1F46;
void func_0023E310(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_001843A0();
    extern void func_0035D370();
    s8 r;
    s8 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    r = func_00175700(p);
    if (r < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_001843A0(p);
    } else {
        t = p[0x151];
        if (t & 2) {
            p[0x151] = t & ~2;
            func_0035D370(p, 2, 0);
            D_004F1F45 = 3;
            D_004F1F46 = 1;
        }
    }
}

void func_002293C0(u8 *p) {
    extern s32 func_001757E0();
    extern int func_00175700(u8 *);
    extern void func_003589A0(u8 *, s32, f32, f32);
    extern void func_0022C5D0();
    extern void func_0022C720();
    s32 b = p[6];
    if (b == 0) {
        p[6] = b + 1;
        p[0x20D] = 0;
        *(s16 *)(p + 0x1C) = 0x3C;
        func_001757E0(p, 0x14, 0x16);
    } else {
        s16 v;
        func_00175700(p);
        if (*(s8 *)(p + 0x151) != 0) {
            f32 x = -34.0f;
            f32 y = 95.0f;
            p[0x151] = 0;
            func_003589A0(p, 0, x, y);
        }
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) func_0022C5D0(p);
    }
    func_0022C720(p);
}

void func_0024CE20(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_00175C00();
    extern void func_001843A0();
    extern void func_00362000();
    extern void func_00176160();
    s8 r = func_00175700(p);
    s16 v;
    if (r < 0) {
        func_00175C00(p, 0);
        func_001843A0(p);
    }
    if (*(s8 *)(p + 0x151) != 0) {
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v <= 0) {
            func_00362000(p, 2);
            func_00362000(p, 3);
            *(s16 *)(p + 0x1C) = 10;
        }
        v = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = v;
        if (v & 2) {
            func_00175C00(p, 0);
        } else {
            func_00176160(p, 3, 3, 1);
        }
    }
}

void func_00397880(u8 *p) {
    extern void func_001757E0();
    extern int func_00175700(u8 *);
    extern void func_001E7F60();
    u32 t;
    if (*(u16 *)(p + 0xD0) != *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    p[0x24] = 0;
    if (*(s8 *)(p + 0x1B2) != 0 || *(s8 *)(p + 0x1B3) != 0) {
        t = p[5];
        p[5] = t + 1;
        (*(u8 **)(p + 0x18))[0x1B4] = *(s8 *)(p + 0x1B4);
        func_001757E0(p, 0x17, 5);
        return;
    }
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
    if (*(s16 *)(p + 0x1C) < 0) {
        t = p[5];
        p[5] = t + 1;
        func_001757E0(p, 0x17, 4);
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    func_001E7F60(p);
}

void func_0026DD40(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_00178F20();
    extern void func_0018FDB0();
    extern void func_00126400(void);
    u8 *s1;
    u8 *q;
    u32 t;
    s32 b;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    s1 = *(u8 **)(p + 0x1DC);
    if (*(s8 *)(p + 0x160) != 0) {
        func_00178F20(p, s1);
        s1[0x13C] = 1;
    } else {
        s1[0x13C] = 0;
    }
    b = p[0x15B];
    if (b != 0 && (u8)b < 0x80) {
        p[0x15B] = 0;
        (*(u8 ***)(p + 0x1DC))[0x1C8 / 4] = p;
        (*(u8 **)(p + 0x1DC))[0x1B5] = 0x22;
        func_0018FDB0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        q = *(u8 **)(p + 0x1DC);
        q[0x20A] = 1;
        q[0x1B5] = 0x3F;
        q[0x13C] = 1;
        func_00126400();
    }
}

void func_0027E720(u8 *p) {
    extern s32 func_00174170();
    extern void func_0027E5D0();
    extern void func_00381E40();
    s16 v;
    u8 f;
    s32 r;
    u32 t;
    s32 m;
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v <= 0) {
        *(s16 *)(p + 0x1E) = func_00174170() & 7;
        m = (p[0x22] + 1) % 3;
        p[0x22] = m;
        if ((u8)m != 0) {
            *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 8;
            f = 0;
            *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
        } else {
            f = 1;
            *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 4;
        }
        r = func_00174170() & 0xF;
        func_0027E5D0(p);
        func_00381E40(p, (u8)(f + 1), r);
    }
    if (*(s16 *)(p + 0x1C) <= 0) {
        t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0x14;
    }
}

void func_002E0840(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_001843A0();
    extern void func_00158C70();
    extern void func_001E3A40();
    extern void func_0018FDB0();
    extern void func_00126400(void);
    s8 r;
    s32 t;
    u8 *s1;
    u8 *q;
    f32 v[4];
    r = func_00175700(p);
    if (r < 0) {
        func_001843A0(p);
        return;
    }
    t = *(s8 *)(p + 0x150);
    if (t & 2) {
        p[0x150] = t ^ 2;
        s1 = *(u8 **)(p + 0x1DC);
        v[0] = *(f32 *)(s1 + 0x34);
        v[1] = *(f32 *)(s1 + 0x430);
        func_00158C70(v, s1[2]);
        func_001E3A40(p);
        D_004F1F45 = 2;
        D_004F1F46 = 1;
        *(u8 **)(s1 + 0x1C8) = p;
        s1[0x1B5] = 0x22;
        func_0018FDB0(p);
    }
    t = *(s8 *)(p + 0x150);
    if (t & 1) {
        p[0x150] = t ^ 1;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x1B5] = 0x20;
        *(s16 *)(q + 0x140) = *(s16 *)(p + 0x140) ^ 1;
        q[0x1E6] = *(s8 *)(q + 0x140);
        func_00126400();
    }
}

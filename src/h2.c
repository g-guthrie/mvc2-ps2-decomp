typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;

void func_003916B0(u8 *p, s32 v) {
    extern u8 *func_003DA750(u8 *, s32, s32);
    extern void func_00391710();
    u8 *o = func_003DA750(p, 1, 3);
    if (o != 0) {
        *(void **)(o + 0x10) = func_00391710;
        *(s32 *)(o + 0x18) = *(s32 *)(p + 0x18);
        o[0x20] = v;
        *(s16 *)(o + 0x26) = 0x2000;
    }
}

u8 func_001898E0(u8 *a, u8 *b, u8 *c) {
    extern u8 func_0018A460(u8 *, u8 *, u8 *, u32);
    s8 v = *(s8 *)(c + 1) - 1;
    *(s8 *)(c + 1) = v;
    if (v <= 0) {
        return c[0] = 0;
    }
    {
        u32 t = *(u16 *)(a + 0x35E) & *(u16 *)(b + 0xC);
        if (t != 0) return func_0018A460(a, b, c, t & 0xFFFF);
    }
    return 0;
}

void func_0031B060(u8 *p) {
    extern void func_00186A60(u8 *, s32);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0:
        p[0x1FD] = 1;
        p[0x1B7] = 1;
        break;
    case 1:
        p[0x1FD] = 2;
        p[0x1B7] = 1;
        break;
    case 2:
        p[0x1FD] = 0xC;
        p[0x1B7] = 1;
        break;
    }
    func_00186A60(p, 0x15);
}

void func_001548D0(u8 *p, f32 *q, s32 r) {
    extern void func_00154790(V3 *, s32, s32, s32);
    V3 v;
    if (*(s16 *)(p + 0x140) != 0) {
        v.x = *(f32 *)(p + 0x34) - q[0];
    } else {
        v.x = *(f32 *)(p + 0x34) + q[0];
    }
    v.y = *(f32 *)(p + 0x38) + q[1];
    v.z = *(f32 *)(p + 0x3C);
    func_00154790(&v, *(s16 *)(p + 0x140), r, 0);
}

void func_00187710(u8 *p) {
    extern void func_00180DD0(u8 *);
    extern s8 D_004D18DE;
    extern u8 D_004D18A3;
    u8 r;
    func_00180DD0(p);
    if (D_004D18DE < 0) {
        r = 4;
    } else {
        r = 0;
        if (D_004D18DE != p[2]) r += 1;
        if (D_004D18A3 != 0) r += 2;
    }
    p[0x20] = r;
    p[0x20D] = 0;
}

void func_001AA1C0(u8 *p, u8 *q) {
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    if (func_00175700(p) < 0 && *(s16 *)(q + 0x280) < 3) {
        u32 t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0x17, 0x46);
    }
}

void func_00291E40(u8 *p, u8 *q) {

    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60) <= 0.0f) {
        u32 t = q[0x18];
        q[0x18] = t + 1;
        *(u32 *)(p + 0x6C) = 0xBFCDB6DB;
    }
}

void func_003348C0(u8 *p) {

    s16 v = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = v + 1;
    if (v >= 300) {
        u32 a, b;
        *(s16 *)(p + 0x1C) = 0;
        p[6] = 0;
        a = p[4];
        p[4] = a + 1;
        p[4] = (u32)p[4] % 3u;
        b = p[7];
        p[7] = b + 1;
        p[7] = (u32)p[7] & 1u;
        if (*(s32 *)(*(u8 **)(p + 0x18) + 0xDC) != 0) p[7] = 0;
    }
}

void func_00211640(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_00352170(u8 *, s32);
    extern void func_0019A3D0(u8 *, s32);
    if (func_00175700(p) < 0) {
        func_001843A0(p);
    } else if (p[0x1FC] == 2 && *(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_00352170(p, 0);
        func_0019A3D0(p, 0);
    }
}

void func_00265D00(u8 *p) {
    extern void func_001820A0(u8 *);
    extern void (*D_004542D0[])(u8 *, u8 *);
    if (p[0x20D] == 2) {
        func_001820A0(p);
        if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        }
    }
    p[0x24] = 8;
    D_004542D0[p[6]](p, (u8 *)((u32)p + 0x2B8));
}

void func_002C4D80(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u8 *o;
        p[0x151] = 0;
        o = *(u8 **)(p + 0x1DC);
        *(u8 **)(o + 0x1C8) = p;
        o[0x20A] = 1;
        o[0x20D] = 0;
        func_001266A0(p, 0, 0);
        o[0x1B5] = 0x20;
        o[0x1E6] = p[0x1E6];
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
    }
}

void func_003C1830(u8 *p, u8 *q) {
    extern void func_003C1530(u8 *);
    extern void func_003C15F0(u8 *, u8 *);
    extern void func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    u8 *r = p + 0xD0;
    func_003C1530(p);
    func_003C15F0(p, q);
    func_00175700();
    if (*(s8 *)(q + 0x13C) == 0) {
        u32 t = p[5];
        p[5] = t + 1;
        func_001757E0(p, 0x16, 2);
        r[4] = 1;
    }
}

void func_00235020(u8 *p) {
    extern void func_00175C00(u8 *, s32);
    extern void func_00176160(u8 *, s32, s32, s32);
    s16 v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v == 0) {
        *(s16 *)(p + 0x1E) = 3;
        if (*(s16 *)(p + 0x1C) == 8) {
            func_00175C00(p, 1);
        } else {
            func_00176160(p, 0, (p[0x25] << 4) + *(s16 *)(p + 0x1C), 1);
            *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
        }
    }
}

void func_003A8D20(u8 *p, s16 a, s16 b) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_003A8ED0();
    u8 *o = func_003DA750(0, 1, 0);
    if (o != 0) {
        *(void **)(o + 0x10) = func_003A8ED0;
        *(u8 **)(o + 0x18) = p;
        *(s16 *)(o + 0x26) = 0x2F02;
        *(s32 *)(o + 0xD0) = *(u16 *)(p + 0x168);
        *(s32 *)(o + 0xD4) = a;
        *(s32 *)(o + 0xD8) = b;
    }
}

void func_00363B10(u8 *p) {
    extern s32 func_00174470(u8 *);
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    if (*(s16 *)(p + 0x1C) < 0xD3 && func_00174470(p) == 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        func_001E7F60(p);
    }
}

void func_0038DEC0(u8 *p) {
    extern void func_0038E1F0(u8 *);
    extern void func_0038E2D0(u8 *, u8 *, u8 *);
    extern u8 D_004B8630[][10];
    u8 *q;
    u32 t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    func_0038E1F0(p);
    if (*(u16 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        p[4] = 2;
    } else {
        func_0038E2D0(p, q, D_004B8630[p[0x1B7] + p[0x20] * 2]);
    }
}

void func_001DEC50(u8 *p, u8 *q) {
    extern s8 func_00175700(u8 *);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    if (*(u16 *)(q + 0x168) != *(u16 *)(p + 0xD0)) {
        u32 t = p[4];
        p[4] = t + 1;
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + *(f32 *)(p + 0x60);
        if (func_00175700(p) < 0) {
            u32 t;
            p[0x13C] = 0;
            t = p[4];
            p[4] = t + 1;
        }
    }
}

void func_00207850(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    extern s8 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_001E3710(u8 *, s32);
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        p[0x20D] = 0;
        func_001757E0(p, 0x14, 3);
    } else {
        if (*(s8 *)(p + 0x150) != 0) {
            p[0x150] = 0;
            func_001E3710(p, 0x30);
        }
        if (func_00175700(p) < 0) func_001843A0(p);
    }
}

void func_00384380(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_003859F0(u8 *);
    u8 *q = *(u8 **)(p + 0x18);
    if (q[5] != 0 || q[0x1E4] != 0x1D || q[0x1FD] != 3) {
        func_003859F0(p);
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        p[0x24] = 0;
        if (func_00175700(p) < 0) func_003859F0(p);
    }
}

void func_001A9530(u8 *p) {

    s16 v;
    *(s32 *)(p + 0x48) += *(s32 *)(p + 0xD0);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 0x14;
        *(s32 *)(p + 0x48) = 0;
    }
}

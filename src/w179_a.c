typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00373960(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        u32 t = p[5];
        f32 a, b;
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 30;
        a = 5.0f;
        b = 0.0f;
        if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) {
            b = -b;
            a = -a;
        }
        *(f32 *)(p + 0x34) += b;
        *(f32 *)(p + 0x5C) = a;
        *(f32 *)(p + 0x68) = b;
        *(u32 *)(p + 0x60) = 0x42092492;
        *(u32 *)(p + 0x6C) = 0;
    }
}

s32 func_00165250(u8 *p, s32 b) {
    extern s32 func_0016B240();
    extern void func_0016B0C0();
    extern void func_00186CE0();
    extern s32 func_00164480();
    f32 c;
    f32 base;
    u32 n, t;
    u8 *q;
    if (func_0016B240(p, 0) == 0) {
        return 0;
    } else {
        func_0016B0C0(p, b, 0);
        func_0016B0C0(p, b, 3);
        t = p[0x451];
        q = *(u8 **)(p + 0x220);
        p[0x451] = t + 1;
        n = *(u8 *)(q + 0x14E);
        base = *(f32 *)(p + 0x4C8);
        c = 1.6666666f;
        *(f32 *)(p + 0x460) = base + c * (f32)n;
        *(s32 *)(p + 0x468) = 10;
        *(s32 *)(p + 0x46C) = 0;
        *(s8 *)(p + 0x4B6) = -0x4C;
        func_00186CE0(p, 10);
        return func_00164480(p, b);
    }
}

void func_00335B10(u8 *p) {
    extern s32 func_003367F0();
    extern s32 func_00336690();
    extern s32 func_00336460();
    s32 v;
    s32 r;
    s16 t;
    t = *(s16 *)(p + 0x1E) + 1;
    *(s16 *)(p + 0x1E) = t;
    *(s32 *)(p + 0x44) = (*(s16 *)(p + 0x140) != 0) ? 0 : 0x8000;
    t = *(s16 *)(p + 0x1E) % 8;
    *(s16 *)(p + 0x1E) = t;
    if (t == 0) p[0x20] ^= 1;
    v = -0x5B0;
    if (p[0x20] != 0) v = 0x5B0;
    *(s32 *)(p + 0x44) = *(s32 *)(p + 0x44) + v;
    if (func_003367F0(p) != 0) {
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
    } else if (func_00336690(p) == 0 && func_00336460(p) == 0) {
        s16 q = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = q;
        if (q == 0) {
            p[7] = 0;
            p[5] = 0;
        }
    }
}

void func_002E74E0(u8 *p) {
    extern s32 func_00175700();
    extern void func_00185490();
    extern void func_001757E0();
    extern u8 *func_001D45D0(u8 *, u8);
    extern void func_001E32C0();
    u8 *q = p + 0x2B8;
    s16 v;
    u32 t;
    f32 x, c;
    if (p[0x20] == 0) {
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            c = 137.14285278320312f;
            t = p[0x20];
            p[0x20] = t + 1;
            p[0x13C] = 1;
            p[0x20D] = 2;
            x = *(f32 *)(p + 0x430);
            *(f32 *)(p + 0x38) = x;
            *(f32 *)(p + 0x38) = x + c;
            func_00185490(p);
            func_001757E0(p, 0x12, 0);
        }
    } else {
        if ((s8)func_00175700(p) < 0) {
            t = p[7];
            p[7] = t + 1;
            func_001D45D0(p, 1);
            *(u32 *)(p + 0x60) = 0xC12B6DB6;
            *(u32 *)(p + 0x6C) = 0xBF700000;
            q[9] = 0;
            func_001757E0(p, 1, 9);
            func_001E32C0(p, 0x21, 5);
            func_001E32C0(p, 0x22, 5);
        }
    }
}

void func_0024B3E0(u8 *p) {
    extern s32 func_00175700();
    extern void func_00175C00();
    extern void func_001E3210();
    extern void func_001843A0();
    f32 z = 0.0f;
    f32 v;
    u16 h;
    f32 c, n;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    v = *(f32 *)(p + 0x5C);
    if (z == v || !(v * *(f32 *)(p + 0x68) <= z)) {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
    }
    if ((s8)func_00175700(p) < 0) {
        func_00175C00(p, 0);
        func_001E3210(p, 0x2B);
        func_001843A0(p);
    }
    h = *(u16 *)(p + 0x160);
    if (h != 0) {
        c = 1.6666666f;
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x34) += c * (f32)(s16)h;
        } else {
            *(f32 *)(p + 0x34) -= c * (f32)(s16)h;
        }
        *(s16 *)(p + 0x160) = 0;
    }
}

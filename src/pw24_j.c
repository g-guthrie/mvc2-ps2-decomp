typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 func_00175700();
extern void func_001757E0();
extern s32 func_001864a0();

void func_002C3CA0(u8 *a) {
    a[0x40C] = 2;
    a[0x33C] = 5;
    a[0x1FE] = 1;
    a[0x201] = 2;
    a[0x209] = 2;
    func_00175700(a);
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    if (func_001864a0(a) != 0) {
        u32 n = a[6];
        a[6] = n + 1;
        func_001757E0(a, 0xF, 4);
    }
}

static void func_002555E0(u8 *a) {
    *(s32 *)(a + 0x10) = 0;
    *(s32 *)(a + 0x14) = 0;
}
extern void func_001266A0();
extern s32 D_004F1CB8;
extern f32 D_004F1FC8;
extern f32 D_004F1FCC;

void func_0025A820(u8 *a) {
    u32 n;
    func_002555E0(a);
    a[0x1FE] = 1;
    a[0x201] = 2;
    a[0x209] = 2;
    D_004F1CB8 = 2;
    n = a[6];
    a[6] = n + 1;
    func_001266A0(a, 1, 0xD);
    *(f32 *)(a + 0x34) = (D_004F1FC8 + D_004F1FCC) / 2.0f;
    {
        f32 d;
        if (a[0x1E6] != 0) {
            d = -133.3333282f;
        } else {
            d = 133.3333282f;
        }
        *(f32 *)(a + 0x34) += d;
    }
}

extern void func_001754A0();
extern s8 func_00175670();
extern void func_001D7510();

void func_001D7450(u8 *a, u8 *b) {
    u32 t = a[5];
    if (t == 0) {
        if (*(s32 *)(b + 0xD8) != 0) {
            a[5] = t + 1;
            func_001754A0(a, 0x1B, (u8)(a[0x21] + 10));
        }
    } else {
        if (func_00175670(a) < 0) {
            func_001D7510(a, b);
            return;
        }
        *(f32 *)(a + 0x38) -= 2.142857075f;
    }
    func_00175670(a);
}

extern void func_001B7C70();
extern void func_00183920();

void func_00272720(u8 *a) {
    f32 v[3];
    if (func_00175700(a) < 0) {
        u32 n = a[6];
        a[6] = n + 1;
        func_001757E0(a, 0x15, 0xB);
    }
    if (*(s8 *)(a + 0x151) > 0) {
        a[0x151] = 0;
        func_001B7C70(a, 0);
        if (*(s8 *)(a + 0x1B2) != 0) {
            func_001B7C70(a, 1);
        }
    }
    if (*(s8 *)(a + 0x151) < 0) {
        a[0x151] = 0;
        v[0] = -85.0f;
        v[1] = 160.7142792f;
        v[2] = 0.0f;
        func_00183920(a, v);
    }
}

extern void func_0018F320();
extern void func_001E3A10();
extern void func_00163D70();
extern void func_001E3B30();

void func_001783E0(u8 *a) {
    f32 v;
    func_0018F320(a);
    func_00175700(a);
    if (*(s8 *)(a + 0x211) != 0) {
        if (a[0x24C] == 0) {
            a[0x24C] = 1;
            func_001E3A10(a);
            func_00163D70(a);
        }
    }
    if (func_001864a0(a) != 0) {
        u32 n;
        func_001E3B30(a);
        n = a[6];
        a[6] = n + 1;
        v = -(*(f32 *)(a + 0x60) / 2.0f);
        *(f32 *)(a + 0x60) = v;
        if (v <= 4.285714149f) {
            *(f32 *)(a + 0x60) = 4.285714149f;
        }
    }
}

extern s32 func_003760D0();
extern void func_001E7F60();

void func_00376160(u8 *a) {
    if (func_003760D0(a) != 0) return;
    {
        s32 t = *(s16 *)(a + 0x1C);
        if (t != 0) {
            *(s16 *)(a + 0x1C) = t - 1;
        }
    }
    if (*(s8 *)(a + 0x1B2) != 0) {
        u32 n = a[5];
        a[5] = n + 1;
        return;
    }
    if (*(s8 *)(*(u8 **)(a + 0xC) + 0x1B3) != 0 || *(s16 *)(a + 0x1C) == 0) {
        a[5] = 4;
        func_001757E0(a, 0x17, 3);
    } else {
        func_001E7F60(a);
    }
}

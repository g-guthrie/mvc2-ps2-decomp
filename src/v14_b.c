typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00177820(u8 *p) {
    extern void func_0018F320();
    extern void func_00175700();
    extern s32 func_001864A0();
    extern void func_001E3B30();
    extern void func_00158C70();
    extern void func_001757E0();
    func_0018F320(p);
    func_00175700(p);
    if (*(f32 *)(p + 0x60) <= 0.0f) {
        if (func_001864A0(p) != 0) {
            u32 t = p[6];
            p[6] = t + 1;
            *(f32 *)(p + 0x60) = -(*(f32 *)(p + 0x60) / 2.0f);
            func_001E3B30(p);
            func_00158C70(p + 0x34, p[2]);
            p[0x20D] = 2;
            *(s16 *)(p + 0x1C) = 0;
            func_001757E0(p, 0xD, 0x1C);
        }
    }
}

static void func_001CB680(u8 *a, u8 *b) {
    s32 *d = (s32 *)(a + 0xEC);
    s32 *e = (s32 *)(b + 0xEC);
    s32 n = 0x31;
    a[4] = a[4] + 1;
    do {
        *d = *e;
        n--;
        e++;
        d++;
    } while (n > 0);
    a[0x13C] = 1;
    a[2] = b[2];
    a[1] = b[1];
    *(f32 *)(a + 0x50) = *(f32 *)(b + 0x50);
    *(f32 *)(a + 0x54) = *(f32 *)(b + 0x54);
    a[0x1B7] = b[0x1B7];
    a[0x1B8] = b[0x1B8];
    a[0x30] = b[0x30];
}

void func_001CBBC0(u8 *p, u8 *q) {
    extern void func_001754A0();
    extern void func_0015E630();
    extern void func_00175670();
    f32 f;
    s16 h;
    if (*(s32 *)(p + 0xD4) != *(u16 *)(q + 0x168)) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        p[0] = 0;
        return;
    }
    if (p[4] == 0) {
        p[0] = 1;
        func_001CB680(p, q);
        f = 106.666664f;
        h = *(s16 *)(q + 0x140);
        *(s16 *)(p + 0x140) = h;
        if (h != 0)
            f = -f;
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + f;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        func_001754A0(p, 0x1B, 0x35);
        p[0x159] = 0xE0;
        func_0015E630(p);
    }
    func_00175670(p);
    p[0x159] = 0xE0;
}

void func_00362E20(u8 *p, u8 *q) {
    extern void func_00175700();
    extern void func_001757E0();
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= 171.4285583f + *(f32 *)(q + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x17, 0x1E);
    }
}

void func_00362D50(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    s16 v;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x5C) /= 2.0f;
        *(f32 *)(p + 0x60) /= 2.0f;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x17, 0x1D);
    }
}

void func_00224120(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_00224200();
    s16 v;
    f32 f;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        if (p[0x1E6] != 0)
            f = 6.666666507720947f;
        else
            f = -6.666666507720947f;
        *(f32 *)(p + 0x5C) = f;
        func_001757E0(p, 2, 2);
        func_00224200(p);
        return;
        func_001757E0(p, 2, 2);
        func_00224200(p);
    }
}

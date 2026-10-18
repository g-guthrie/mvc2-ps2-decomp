typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00279950(u8 *p) {
    extern s8 func_00175700();
    extern void func_0037E4A0();
    s32 a;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        { u32 t = p[6]; p[6] = t + 1; }
        p[0x151] = 0;
        func_0037E4A0(p, 2);
    }
    a = *(u16 *)(p + 0x160);
    if (a != 0) {
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x34) += (f32)(s16)a * 1.666666626930237f;
        } else {
            *(f32 *)(p + 0x34) -= (f32)(s16)a * 1.666666626930237f;
        }
        *(u16 *)(p + 0x160) = 0;
    }
}

void func_00200880(u8 *p) {
    extern void func_00175700();
    extern s32 func_001864a0();
    extern void func_00183d50();
    extern void func_001757E0();
    f32 *a, *b, *c, *d;
    func_00175700();
    a = (f32 *)(p + 0x5C);
    c = (f32 *)(p + 0x68);
    b = (f32 *)(p + 0x60);
    d = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864a0(p) != 0) {
        p[6] = 3;
        p[7] = 0;
        *(u32 *)a = 0;
        *(u32 *)b = 0;
        *(u32 *)c = 0;
        *(u32 *)d = 0;
        func_00183d50(p);
        func_001757E0(p, 0x16, 0xC);
    }
}

void func_002FFCE0(u8 *p) {
    extern void func_00175700();
    extern void func_00183d50();
    extern void func_001757E0();
    extern void func_001E3A40();
    f32 *a, *b, *c, *d;
    u8 *q;
    f32 x;
    a = (f32 *)(p + 0x5C);
    c = (f32 *)(p + 0x68);
    b = (f32 *)(p + 0x60);
    d = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    x = *(f32 *)(p + 0x430);
    if (!(x < *(f32 *)(p + 0x38))) {
        u32 t;
        *(f32 *)(p + 0x38) = x;
        *(u32 *)a = 0;
        *(u32 *)b = 0;
        *(u32 *)c = 0;
        *(u32 *)d = 0;
        func_00183d50(p);
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0xF, 4);
        q = *(u8 **)(p + 0x1DC);
        q[0x20A] = 2;
        q[0x20D] = 2;
        q[0x1B5] = 0x21;
        p[0x1B5] = 0x21;
        q[0x1E6] = p[0x1E6];
        t = q[0x1E6];
        q[0x1E6] = t ^ 1;
        func_001E3A40(q);
    }
}

void func_002BB450(u8 *p) {
    extern void func_00175700();
    extern void func_00183d50();
    extern void func_001757E0();
    f32 *a, *b, *c, *d;
    u32 k;
    func_00175700(p);
    a = (f32 *)(p + 0x5C);
    c = (f32 *)(p + 0x68);
    b = (f32 *)(p + 0x60);
    d = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    k = p[0x1E6];
    if ((k == 0 && !(*(f32 *)(p + 0x5C) <= 0.0f)) || (k != 0 && *(f32 *)(p + 0x5C) < 0.0f)) {
        *(u32 *)a = 0;
        *(u32 *)c = 0;
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *(u32 *)a = 0;
        *(u32 *)b = 0;
        *(u32 *)c = 0;
        *(u32 *)d = 0;
        func_00183d50(p);
        func_001757E0(p, 0x15, 0x1E);
    }
}

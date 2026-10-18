typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;



void func_001DA0C0(u8 *p, u8 *q) {
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_001E3270(u8 *, s32, f32);
    u8 *s = (u8 *)((s32)q + 0x2B8);
    s16 h;
    u32 t;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) {
        t = p[5];
        p[5] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        *(s16 *)(p + 0x1C) = 0x1E;
        *(u32 *)(p + 0x60) = 0x40892492;
        *(u32 *)(p + 0x6C) = 0x3F092492;
        func_001757E0(p, 0x12, 8, 0x1E);
        s[1] = 1;
        func_001E3270(q, 0x22, 4.0f);
    }
}

void func_00267170(u8 *p) {
    extern s8 func_00175700();
    extern void func_00267E20();
    extern void func_001B3E30();
    f32 c;
    if (func_00175700(p) < 0) {
        func_00267E20(p);
        return;
    }
    if (*(s8 *)(p + 0x151) == 1) {
        p[0x151] = 0;
        func_001B3E30(p, 0x20, 0xD);
        func_001B3E30(p, 0x21, 0xD);
    } else if (*(s8 *)(p + 0x151) == 2) {
        p[0x151] = 0;
        if (*(s16 *)(p + 0x140) != 0) c = -66.66666412f;
        else c = 66.66666412f;
        *(f32 *)(p + 0x34) += c;
    }
}

void func_002AD110(u8 *p) {
    extern void func_00175700();
    extern void func_002AD1F0();
    f32 c;
    u32 t;
    s32 n;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        if (*(s32 *)(p + 0xD0) == 0) {
            if (p[0x1E6] != 0) c = -13.33333301544189f;
            else c = 13.33333301544189f;
            *(f32 *)(p + 0x5C) = c;
            if (p[0x1E6] != 0) c = 0.3645833134651184f;
            else c = -0.3645833134651184f;
            *(f32 *)(p + 0x68) = c;
            n = (p[0x1E6] != 0) ? -0x28 : 0x28;
            *(f32 *)(p + 0x34) += (f32)n;
        } else {
            func_002AD1F0(p);
        }
    }
}

void func_002E03F0(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    f32 *a3, *t0, *t1, *t2;
    u32 t;
    func_00175700(p);
    a3 = (f32 *)(p + 0x5C);
    t1 = (f32 *)(p + 0x68);
    t0 = (f32 *)(p + 0x60);
    t2 = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430) - 85.71427917f) {
        t = p[6];
        p[6] = t + 1;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(s16 *)(p + 0x1C) = 6;
        *(s32 *)a3 = 0;
        *(s32 *)t0 = 0;
        *(s32 *)t1 = 0;
        *(s32 *)t2 = 0;
        func_001757E0(p, 0x14, 1);
    }
}

void func_0030DA90(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    s16 h;
    u32 t;
    f32 c;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) < 0) return;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h < 0) {
        t = p[6];
        p[6] = t + 1;
        c = -1.666666627f;
        if (p[0x1E6] == 0) c = -c;
        *(f32 *)(p + 0x5C) = c;
        *(s32 *)(p + 0x68) = 0;
        func_001757E0(p, 2, 3);
    }
}

void func_0037CE30(u8 *p) {
    extern void func_00175700();
    extern void func_001E7F60();
    s16 h;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x50) += 0.07142857462f;
    *(f32 *)(p + 0x54) += 0.07142857462f;
    if (*(s8 *)(p + 0x1B3) != 0 || (h = *(s16 *)(p + 0x1C) - 1, *(s16 *)(p + 0x1C) = h, h < 0)) {
        *(s32 *)(p + 0x118) = 0;
        p[4] = 2;
        p[0x13C] = 0;
    } else {
        if (*(s16 *)(p + 0x1C) < 7) *(f32 *)(p + 0x118) -= 0.1428571492f;
        func_00175700(p);
        func_001E7F60(p);
    }
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00304810(u8 *p) {
    extern void func_00175700();
    extern void func_001843A0();
    extern void func_003B38F0();
    s16 v;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) & 1) {
        s8 t = *(s8 *)(p + 0x151);
        p[0x151] = t & ~1;
        func_003B38F0(p, 1, 9);
    }
    if (*(s8 *)(p + 0x151) & 2) {
        u8 *q;
        s8 t = *(s8 *)(p + 0x151);
        p[0x151] = t & ~2;
        q = *(u8 **)(p + 0x1DC);
        q[0x20A] = 1;
        q[0x20D] = 2;
        q[0x1B5] = 0x22;
        p[0x1B5] = 0x22;
        q[0x1E6] = p[0x1E6];
        { u32 t2 = q[0x1E6]; q[0x1E6] = t2 ^ 1; }
    }
}

extern f32 D_004F1F4C;
extern f32 D_0044DEB0[];

void func_001CF520(u8 *p) {
    extern f32 func_00117078(f32);
    extern void func_001CF6D0();
    extern void func_001757E0();
    f32 r;
    if (*(s8 *)(*(u8 *volatile *)(p + 0x18) + 0x13C) != 0) {
        u32 t = p[5];
        p[5] = t + 1;
        p[0x13C] = 1;
        r = func_00117078(D_004F1F4C - *(f32 *)(*(u8 *volatile *)(p + 0x18) + 0x34));
        r = (p[0x21] & 1) ? r : -r;
        *(f32 *)(p + 0x34) = D_004F1F4C + r;
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(*(u8 *volatile *)(p + 0x18) + 0x220) + 0x38) + D_0044DEB0[p[0x21]];
        func_001CF6D0(p);
        func_001757E0(p, 0x15, 0x2B);
    }
}

void func_001F3AE0(u8 *p) {
    extern void func_0015B660();
    extern void func_001E3710();
    extern void func_0015B200();
    extern s8 func_00175700();
    extern void func_001757E0();
    f32 v[4];
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        v[0] = *(f32 *)(*(u8 **)(p + 0x1DC) + 0x34);
        v[1] = *(f32 *)(p + 0x430);
        if (p[0x216] == 0) {
            func_0015B660(v, 1);
            func_001E3710(p, 0x49);
        } else {
            func_0015B660(v, 1);
            func_0015B200(p, v, 4, 0x7E);
            func_001E3710(p, 0x4A);
        }
    }
    if (func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0xF, 0xE);
    }
}

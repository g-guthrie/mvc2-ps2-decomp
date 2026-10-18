typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_002275E0(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    s16 h;
    f32 v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h < 0) {
        p[6]++;
        v = 0.52083331f;
        if (p[0x1E6] != 0) v = -v;
        *(f32 *)(p + 0x68) = v;
        func_001757E0(p, 2, 2);
    }
}

void func_00229B40(u8 *p) {
    extern void func_0022C5C0();
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_003589A0(u8 *, s32, f32, f32);
    extern void func_001E3210();
    s16 h;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_0022C5C0(p);
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    func_00175700(p);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) {
        p[6]++;
        func_001757E0(p, 0xF, 1);
        return;
    }
    if (*(s8 *)(p + 0x150) != 0) {
        p[0x150] = 0;
        func_003589A0(p, 2, 29.0f, 100.0f);
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_001E3210(p, 0x16);
    }
}

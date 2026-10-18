typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00355520(u8 *p) {
    extern void func_00175700();
    extern s32 func_00174470();
    extern s32 func_00417A40();
    extern void func_0019BA70();
    extern void func_001E7F60();
    func_00175700(p);
    if (*(s8 *)(p + 0x1B2) != 0) {
        u32 t = p[4];
        p[4] = t + 1;
        return;
    }
    if (func_00174470(p) == 0) {
        p[0x13C] = 0;
        p[4] = 3;
        return;
    }
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
    if (*(s16 *)(p + 0x1C) == 0) {
        *(s16 *)(p + 0x1C) = func_00417A40();
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) & 3;
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
        func_0019BA70(p, 0);
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001E7F60(p);
}

extern u8 *D_004C2794;

void func_002FD550(u8 *p) {
    extern void func_001861B0();
    extern void func_0018C4B0();
    extern void func_001757E0();
    extern void func_00183D90();
    extern void func_001863F0();
    extern s8 func_00175700();
    extern void func_001843A0();
    u8 *q;
    if (p[6] == 0) {
        u32 t;
        func_001861B0(p);
        t = p[6];
        p[6] = t + 1;
        func_0018C4B0(p, 5);
        p[0x20D] = 0;
        func_001757E0(p, 0x14, 3);
        p[0x1B5] = 0x19;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        q = (u8 *)((p[2] << 1) + (u32)D_004C2794);
        *(s16 *)(q + 0x7C) = *(s16 *)(q + 0x7C) + 1;
    }
    if (p[0x213] == 3) func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if (func_00175700(p) < 0) func_001843A0(p);
}

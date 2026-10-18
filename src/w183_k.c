typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00374830(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_00154470(u8 *, s32, s32, f32, f32);
    extern void func_00175C00(u32, s32);
    f32 z = 0.0f;
    f32 four = 4.0f;
    u32 t;
    u8 *v;
    u32 s;
    func_00175700(p);
    *(s32 *)(p + 0x48) += 0x1200;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60) < z) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        v = *(u8 **)(p + 0x1C4);
        v[0x13C] = 1;
        v[0x20A] = 0x10;
        v[0x1B5] = 0x41;
        *(f32 *)(v + 0x34) = *(f32 *)(p + 0x34);
        *(f32 *)(v + 0x38) = *(f32 *)(p + 0x38);
        v[0x20D] = 2;
        s = *(u32 *)(p + 0x18);
        *(u32 *)(v + 0x1C8) = s;
        func_00154470(p, 0, 0x90, four, four);
        func_00154470(p, 0x10, 0x90, four, four);
        func_00154470(p, 0xF0, 0x90, four, four);
        func_00175C00(s, 0);
    }
}

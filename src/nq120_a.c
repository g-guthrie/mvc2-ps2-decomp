typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003C2340(u8 *p, u8 *q)
{
    extern void func_00175700(u8 *);
    extern s32 func_003C2510(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0015B1F0(u8 *, s32);
    extern void func_001E7F60(u8 *);
    f32 v;

    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    switch (q[0x2C5]) { default: p[0x13C] = 0; break; case 0: break; }
    if (func_003C2510(p, q) != 0) {
        p[4]++;
        return;
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        p[5]++;
        p[0x13C] = 1;
        p[0x13C] = 0;
        func_001757E0(p, 0x16, 6);
        func_0015B1F0(p + 0x34, 1);
        return;
    }
    {
    func_001E7F60(p);
    if (*(s8 *)(p + 0x1B2) != 0) {
        p[5]++;
        p[0x13C] = 1;
        p[0x13C] = 0;
        func_001757E0(p, 0x16, 6);
        func_0015B1F0(p + 0x34, 1);
        return;
    }
    v = *(f32 *)(q + 0x430);
    if (!(v <= *(f32 *)(p + 0x38))) {
        *(f32 *)(p + 0x38) = v;
        p[5]++;
        p[0x13C] = 1;
        p[0x13C] = 0;
        func_001757E0(p, 0x16, 7);
        func_0015B1F0(p + 0x34, 1);
    }
}
}

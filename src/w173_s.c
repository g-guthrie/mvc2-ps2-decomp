typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#define Q (*(u8 **)(p + 0x1DC))

void func_002224B0(u8 *p)
{
    extern s32 func_001864A0();
    extern void func_001E3710(u8 *, s32);
    extern void func_00175700();
    extern void func_00184540();
    extern void func_001843A0();
    extern void func_00126400();
    u32 *x, *y;
    s8 h;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    x = (u32 *)(p + 0x60);
    y = (u32 *)(p + 0x6C);
    if (p[0x20D] == 2) {
        if (func_001864A0(p) != 0) {
            *x = 0;
            *y = 0;
            func_001E3710(p, 0x34);
        }
    }
    func_00175700(p);
    h = *(s8 *)(p + 0x151);
    if (h == 2) {
        if (p[0x20D] == 2) {
            func_00184540(p);
            return;
        }
        func_001843A0(p);
    } else if (h < 0) {
        p[0x151] = 0;
        *(u32 *)(Q + 0x1C8) = (u32)p;
        Q[0x20A] = 1;
        Q[0x1E6] = *(s8 *)(p + 0x1E6) ^ 1;
        Q[0x1B5] = 0x20;
        p[0x20D] = 2;
        *(u32 *)(p + 0x5C) = 0;
        func_00126400();
    }
}

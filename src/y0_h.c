typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00319F20(u8 *p)
{
    extern s32 func_001864a0();
    extern void func_00183d50();
    extern void func_001757E0();
    u32 *a, *b, *c, *d;
    u32 t;
    a = (u32 *)(p + 0x5C);
    c = (u32 *)(p + 0x68);
    b = (u32 *)(p + 0x60);
    d = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864a0(p) != 0) {
        t = p[6];
        p[6] = t + 1;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_00183d50(p);
        func_001757E0(p, 0x15, (u8)(p[0x1B7] * 2 + 0x23));
    }
}

extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_00315FF0(u8 *p)
{
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_001E3710();
    extern void func_001DD8A0();
    u32 t;
    f32 n;
    p[0x208] = 3;
    func_00175700(p);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_001757E0(p, 0xF, 7);
        *(u32 *)(p + 0x5C) = 0xC1D55555;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        func_001E3710(p, 0x2F);
        func_001DD8A0(p, 8, 0);
    }
}

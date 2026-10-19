typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_001865B0(u8 *);
extern void func_00184540(u8 *);

void func_00235F20(u8 *p)
{
    if (p[0x20D] != 2) {
        u8 *a0 = p;
        if (func_00175700(a0) < 0)
            func_001843A0(a0);
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_001865B0(p);
        return;
    }
    {
        u8 *a0 = p;
        if (func_00175700(a0) < 0)
            func_00184540(a0);
    }
    if ((s8)p[0x151] & 1) {
        p[0x151] = 0;
        *(f32 *)(p + 0x60) += 0.8035714030265808f;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
}

typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern void func_00175700(u8 *);
extern s32 func_00174470(u8 *);
extern void func_00394760(u8 *);
extern u8 *D_004C29D4 __attribute__((section(".sdata")));

void func_003932E0(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00174470(p) == 0)
        goto fail;
    if (*(f32 *)(p + 0x38) <= *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
fail:
        func_00394760(p);
        D_004C29D4[8] = (u8)-1;
    }
}

typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001E7F60(u8 *);

void func_0039B410(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        *(s8 *)(p + 0x151) = 0;
        p[0x1B5] = 0x3F;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = (u8)(0 & 0xFFFF);
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
        *(s16 *)(p + 0x1E) = 2;
    }
    {
        s16 t = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = t;
        if ((s32)t == 0 && *(s8 *)(p + 0x1B2)) {
            p[0x1B5] = 0x3F;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = (u8)(0 & 0xFFFF);
            *(u32 *)(p + 0x1D8) = 0;
            ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
        }
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
        p[5] += 1;
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
        func_001757E0(p, 0x15, 0x14);
    }
    func_001E7F60(p);
}

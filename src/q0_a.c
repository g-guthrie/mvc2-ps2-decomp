typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_001757E0(void *, s32, s32);
extern s32 func_00175700(void *);
extern s32 func_00174170(void *);
extern s32 func_00186A60(void *, s32);
extern s8 D_004F7FC8[];
extern s8 D_00448FE0[];

void func_0036ADC0(u8 *p)
{
    p[0x13C] = 1;
    p[0x24] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    *(f32 *)(p + 0x38) += 120.0f;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x118) = 1.0f;
    func_001757E0(p, 0x17, 1);
}

void func_001DE270(u8 *a, u8 *b)
{
    a[0x24] = *(s8 *)(b + 0x24);
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38);
    func_00175700(a);
    if (*(u16 *)(b + 0x168) != *(u16 *)(a + 0xD0)) a[4]++;
}



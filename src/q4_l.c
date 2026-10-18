typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FC8[];
extern f32 D_004F1FCC[];
extern u32 D_004C2838;
extern void func_00163AA0(void);

void func_001639A0(u8 *p)
{
    extern u8 *func_003DA750(s32, s32, s32);
    u8 *o;
    s32 n;
    if ((o = func_003DA750(0, 0x2F, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00163AA0;
        *(u32 *)(o + 0xD0) = 0x800411;
        *(f32 *)(o + 0x50) = 1.0f;
        *(f32 *)(o + 0x54) = 1.0f;
        *(f32 *)(o + 0x58) = 1.0f;
        *(s16 *)(o + 0xCC) = 0x55;
        *(u32 *)(o + 0x84) = D_004C2838;
        switch (*(s8 *)(p + 0x211)) {
        case 1:
            *(f32 *)(o + 0x34) = D_004F1FCC[0];
            break;
        case 2:
            *(f32 *)(o + 0x34) = D_004F1FC8[0];
            break;
        }
        n = p[0x14C];
        *(f32 *)(o + 0x38) = *(f32 *)(p + 0x38) + 2.142857074737549f * (f32)(n / 2) * *(f32 *)(p + 0x54);
        *(f32 *)(o + 0x78) = 1.0f;
        *(f32 *)(o + 0x7C) = 1.0f;
        *(f32 *)(o + 0x80) = 1.0f;
    }
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 *D_004C2708;
extern u8 *D_004C2840;
extern void func_003DAA40();

void func_001C88F0(u8 *p)
{
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s16 *)(p + 0x140))
        *(f32 *)(p + 0x34) += D_004C2708[0];
    else
        *(f32 *)(p + 0x34) -= D_004C2708[0];
    *(f32 *)(p + 0x38) += D_004C2708[1];
}

void func_00141040(u8 *p)
{
    p[0x13C] = 0;
    if (*(s16 *)(D_004C2840 + 0xA) >= 0x17C) {
        f32 c = 0.05000000075f;
        p[0x13C] = 1;
        *(f32 *)(p + 0x78) -= c;
        *(f32 *)(p + 0x7C) -= c;
        *(f32 *)(p + 0x80) -= c;
        if (*(f32 *)(p + 0x78) <= 0.0f)
            func_003DAA40();
    }
}

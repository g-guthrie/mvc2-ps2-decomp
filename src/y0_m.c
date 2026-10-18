typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F7F30[];
extern u8 *D_004C2840;

void func_003D5260(void)
{
    extern void func_003D51E0();
    u8 *s = D_004F7F30;
    D_004F7F30[0xE] = 0;
    D_004F7F30[0xF] = 0;
    D_004F7F30[0] = 0;
    D_004F7F30[1] = 0;
    D_004F7F30[2] = 0;
    D_004F7F30[3] = 0;
    D_004F7F30[4] = 0;
    D_004F7F30[5] = 0;
    D_004F7F30[6] = 0;
    D_004F7F30[7] = 0;
    D_004F7F30[8] = 0;
    D_004F7F30[9] = 0;
    D_004F7F30[0x19] = 0;
    D_004F7F30[0xA] = 1;
    D_004F7F30[0xB] = 1;
    D_004F7F30[0xC] = 1;
    D_004F7F30[0xD] = 0;
    func_003D51E0(s);
    D_004C2840[0xAA] = 0;
    if (*(s8 *)(D_004C2840 + 0x4C) == 2) {
        D_004C2840[0xAA] = 1;
        s[0xF] = *(s8 *)(D_004C2840 + 0x18);
    }
}

void func_003B67F0(u8 *p)
{
    extern void func_00175700();
    extern void func_001E7F60();
    u8 *q;
    u32 t;
    q = *(u8 **)(p + 0x18);
    if (*(s8 *)(p + 0x1B2) != 0) {
        t = p[4];
        p[4] = t + 1;
        p[5] = 0;
        p[0x13C] = 0;
    } else if (*(s8 *)(p + 0x1B3) != 0) {
        t = p[4];
        p[4] = t + 1;
        p[5] = 0;
        p[0x13C] = 0;
    } else if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        t = p[4];
        p[4] = t + 1;
        p[5] = 0;
        p[0x13C] = 0;
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175700(p);
        func_001E7F60(p);
    }
}

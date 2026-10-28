typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

void func_001587B0(u8 *p)
{
    extern void func_003DAA40();
    *(s16 *)(p + 0x1C) += 1;
    switch (p[4]) {
    case 0:
        *(f32 *)(p + 0x50) += 0.05f;
        *(f32 *)(p + 0x58) += 0.05f;
        if (*(s16 *)(p + 0x1C) >= 20) p[4]++;
        break;
    }
    switch (p[5]) {
    case 0:
        *(f32 *)(p + 0x54) += 0.1875f;
        if (*(s16 *)(p + 0x1C) >= 8) p[5]++;
        break;
    case 1:
        *(f32 *)(p + 0x54) += -0.125f;
        break;
    }
    switch (p[6]) {
    case 0:
        *(f32 *)(p + 0x74) += 0.142857149f;
        *(f32 *)(p + 0x78) += 0.142857149f;
        *(f32 *)(p + 0x7C) += 0.142857149f;
        *(f32 *)(p + 0x80) += 0.142857149f;
        if (*(s16 *)(p + 0x1C) >= 7) p[6]++;
        break;
    case 1:
        if (*(s16 *)(p + 0x1C) >= 17) p[6]++;
        break;
    case 2:
        *(f32 *)(p + 0x74) += -0.333333343f;
        *(f32 *)(p + 0x78) += -0.333333343f;
        *(f32 *)(p + 0x7C) += -0.333333343f;
        *(f32 *)(p + 0x80) += -0.333333343f;
        break;
    }
    if (*(s16 *)(p + 0x1C) > 20) { func_003DAA40(); return; }
}

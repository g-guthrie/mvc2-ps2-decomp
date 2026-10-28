typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00158A40(u8 *p)
{
    extern void func_003DAA40();
    *(s16 *)(p + 0x1C) += 1;
    switch (p[4]) {
    case 0:
        *(f32 *)(p + 0x50) += 0.05f;
        *(f32 *)(p + 0x58) += 0.05f;
        break;
    }
    switch (p[5]) {
    case 0:
        *(f32 *)(p + 0x54) += -0.025f;
        break;
    }
    switch (p[6]) {
    case 0:
        *(f32 *)(p + 0x74) += 0.1f;
        *(f32 *)(p + 0x78) += 0.1f;
        *(f32 *)(p + 0x7C) += 0.1f;
        *(f32 *)(p + 0x80) += 0.1f;
        if (*(s16 *)(p + 0x1C) >= 10) p[6]++;
        break;
    case 1:
        if (*(s16 *)(p + 0x1C) >= 13) p[6]++;
        break;
    case 2:
        *(f32 *)(p + 0x74) += -0.1428571492433548f;
        *(f32 *)(p + 0x78) += -0.1428571492433548f;
        *(f32 *)(p + 0x7C) += -0.1428571492433548f;
        *(f32 *)(p + 0x80) += -0.1428571492433548f;
        break;
    }
    if (*(s16 *)(p + 0x1C) > 20) { func_003DAA40(); return; }
}

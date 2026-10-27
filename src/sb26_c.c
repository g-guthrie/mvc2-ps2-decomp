struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00157A10(u8 *p)
{
    extern void func_003DAA40(struct Object *);
    s16 h;

    *(s32 *)(p + 0x48) += 0x333;
    *(s16 *)(p + 0x1C) += 1;
    switch (p[4]) {
    case 0:
        *(f32 *)(p + 0x50) += 0.5720000267028809f;
        *(f32 *)(p + 0x54) += 0.5720000267028809f;
        h = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = h;
        if (h >= 7) p[4]++;
        break;
    case 1:
        *(f32 *)(p + 0x50) -= 0.30799999833106995f;
        *(f32 *)(p + 0x54) -= 0.30799999833106995f;
        h = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = h;
        if (h >= 0x14) {
            func_003DAA40((struct Object *)p);
            return;
        }
        break;
    }
    switch (p[4]) {
    case 0:
        *(f32 *)(p + 0x78) += 0.5f;
        *(f32 *)(p + 0x7C) += 0.5f;
        *(f32 *)(p + 0x80) += 0.5f;
        if (*(s16 *)(p + 0x1C) >= 2) p[5]++;
        break;
    case 1:
        if (*(s16 *)(p + 0x1C) >= 0xC) p[5]++;
        break;
    case 2:
        *(f32 *)(p + 0x78) -= 0.125f;
        *(f32 *)(p + 0x7C) -= 0.125f;
        *(f32 *)(p + 0x80) -= 0.125f;
        if (*(s16 *)(p + 0x1C) >= 0x14) func_003DAA40((struct Object *)p);
        return;
    }
}

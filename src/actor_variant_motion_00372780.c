typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00372780(u8 *p)
{
    s16 direction;

    p[0x13C] = 1;
    p[6]++;
    direction = *(s16 *)(p + 0x140);
    if (direction != 0) {
        f32 speed;
        if (p[0x1B7] != 0)
            speed = 6.666666507720947f;
        else
            speed = 5.0f;
        *(f32 *)(p + 0x5C) = speed;
    } else {
        f32 speed;
        if (p[0x1B7] != 0)
            speed = -6.666666507720947f;
        else
            speed = -5.0f;
        *(f32 *)(p + 0x5C) = speed;
    }

    switch (p[0x20]) {
    case 0:
        *(s16 *)(p + 0x1C) = 0xC;
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1C) - 7;
        *(s32 *)(p + 0x48) = 0xE000;
        *(f32 *)(p + 0x38) += 120.0f;
        *(f32 *)(p + 0x60) = 2.142857074737549f;
        break;
    case 1:
        *(s16 *)(p + 0x1C) = 0xC;
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1C) - 5;
        *(s32 *)(p + 0x48) = 0x1000;
        *(f32 *)(p + 0x38) += 51.42856979370117f;
        *(f32 *)(p + 0x60) = -2.142857074737549f;
        break;
    case 2:
        *(s16 *)(p + 0x1C) = 0;
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1C) - 3;
        *(s32 *)(p + 0x48) = 0x2000;
        *(f32 *)(p + 0x38) += 85.71427917480469f;
        break;
    }

    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
}

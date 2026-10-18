typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00372910(u8 *p)
{
    extern void func_00372B60(u8 *);
    s16 h;
    u32 t;
    f32 f;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00372B60(p);
    h = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = h - 1;
    if (h > 0)
        return;
    t = p[6];
    p[6] = t + 1;
    if (*(s16 *)(p + 0x140) != 0) {
        if (p[0x1B7] != 0)
            f = 6.666666507720947f;
        else
            f = 5.0f;
        *(f32 *)(p + 0x5C) = f;
    } else {
        if (p[0x1B7] != 0)
            f = -6.666666507720947f;
        else
            f = -5.0f;
        *(f32 *)(p + 0x5C) = f;
    }
    switch (p[0x20]) {
    case 0:
        *(s32 *)(p + 0x48) = 0x2000;
        *(u32 *)(p + 0x60) = 0xC02B6DB6;
        break;
    case 1:
        *(s32 *)(p + 0x48) = 0xE000;
        *(u32 *)(p + 0x60) = 0x402B6DB6;
        break;
    case 2:
        *(s32 *)(p + 0x48) = 0;
        *(s32 *)(p + 0x60) = 0;
        break;
    }
}

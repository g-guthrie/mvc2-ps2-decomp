typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00370AB0(u8 *p)
{
    u8 *owner = *(u8 **)(p + 0x18);
    u8 *move = owner + 0x2B8;
    f32 rate;

    if (owner[0x1E4] != 0x1D || owner[0x1FD] != 5) {
        p[5] = 5;
        if (*(s16 *)(p + 0x140) != 0)
            rate = -15.833333015441895f;
        else
            rate = 15.833333015441895f;
        *(f32 *)(p + 0x5C) = rate;
        if (*(s16 *)(p + 0x140) != 0)
            rate = -0.3125f;
        else
            rate = 0.3125f;
        *(f32 *)(p + 0x68) = rate;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x6C) = 0;
        *(s16 *)(p + 0x1C) = 0x3C;
        owner[0x23] = 0;
        move[0x0E] = 0;
        return;
    }

    if (owner[0x23] != 0) {
        *(u16 *)(move + 0x10) += 1;
        return;
    }

    {
        s16 timer = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = timer - 1;
        if (timer == 0) {
            p[5]++;
            if (*(s16 *)(p + 0x140) != 0)
                rate = -20.0f;
            else
                rate = 20.0f;
            *(f32 *)(p + 0x5C) = rate;
            if (*(s16 *)(p + 0x140) != 0)
                rate = 0.3125f;
            else
                rate = -0.3125f;
            *(f32 *)(p + 0x68) = rate;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x6C) = 0;
            *(s16 *)(p + 0x1C) = 2;
        } else {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        }
    }
}

typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

void func_003CC420(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x1C4);
    f32 x = 1.66666662693023681640625f * (f32)((s32)q[0x14E] >> 2);
    if (*(s16 *)(q + 0x140) == 0)
        x = -x;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + x;
    {
        f32 h = (f32)q[0x14C];
        if (h < 137.142852783203125f)
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + 2.142857074737548828125f * (f32)((s32)q[0x14C] >> 2);
    }
}

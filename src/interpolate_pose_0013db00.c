typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern V3 D_004B1730[];

void func_0013DB00(u8 *owner, s32 duration, s32 segment)
{
    V3 *start, *end;
    s32 index = segment + (owner[0x20] + owner[0x23] * 6) * 3;
    start = &D_004B1730[index];
    end = &D_004B1730[index + 1];
    {
        f32 ratio = (end->x - start->x) / duration;
        *(f32 *)(owner + 0x34) = start->x + *(s16 *)(owner + 0x1C) * ratio;
    }
    {
        f32 ratio = (end->y - start->y) / duration;
        *(f32 *)(owner + 0x38) = start->y + *(s16 *)(owner + 0x1C) * ratio;
    }
    {
        f32 ratio = (end->z - start->z) / duration;
        *(f32 *)(owner + 0x3C) = start->z + *(s16 *)(owner + 0x1C) * ratio;
    }
}

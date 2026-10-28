/* Provisional: row, segment, duration and owner bounds need proof. */
typedef unsigned char u8;typedef short s16;typedef float f32;
typedef struct {f32 value[3];} V3;
typedef struct {V3 values[3];} Row;
extern Row data_f32v3x3_004B1730[12];
void func_0013DB00(u8 *owner, int duration, int segment)
{
    V3 *start, *end;
    int index = segment + (owner[0x20] + owner[0x23] * 6) * 3;
    start = (V3 *)((u8 *)&data_f32v3x3_004B1730 + index * sizeof(V3));
    end = (V3 *)((u8 *)&data_f32v3x3_004B1730 + (index + 1) * sizeof(V3));
    {
        f32 ratio = (end->value[0] - start->value[0]) / duration;
        *(f32 *)(owner + 0x34) = start->value[0] + *(s16 *)(owner + 0x1C) * ratio;
    }
    {
        f32 ratio = (end->value[1] - start->value[1]) / duration;
        *(f32 *)(owner + 0x38) = start->value[1] + *(s16 *)(owner + 0x1C) * ratio;
    }
    {
        f32 ratio = (end->value[2] - start->value[2]) / duration;
        *(f32 *)(owner + 0x3C) = start->value[2] + *(s16 *)(owner + 0x1C) * ratio;
    }
}

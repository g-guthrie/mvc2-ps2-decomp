typedef float f32;
typedef struct { f32 value[3]; } F32Vector3;
/* func_001801E0 and func_001802A0 initialize three actors per side with
 * field0x425 = 0..2 and field0x02 = 0 or 1. func_00180800 only swaps
 * field0x425 values. Thus func_00132730's 2*field0x425 + field0x02 is 0..5. */
F32Vector3 data_f32v3_0043E240[6] = {
    { { -95.0f, 89.5f, -169.0f } },
    { { 95.0f, 89.5f, -169.0f } },
    { { -95.0f, 89.5f, -169.0f } },
    { { 95.0f, 89.5f, -169.0f } },
    { { -95.0f, 78.0f, -169.0f } },
    { { 95.0f, 78.0f, -169.0f } },
};

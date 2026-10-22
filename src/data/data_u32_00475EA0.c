typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* Layout as read by func_003C4D30 (f32 scale table indexed by byte 0x1B7) and
 * func_003C5420 / w1910_v.c (T3_v table indexed by p[0x22], 12-byte stride from +0x10). */
typedef struct { f32 a, b; s32 c; } T3_v;
typedef struct {
    f32 scale[4];
    T3_v table[5];
    u32 pad_4C;
} data_u32_00475EA0_layout;
typedef char data_u32_00475EA0_layout_size_check[(sizeof(data_u32_00475EA0_layout) == 80) ? 1 : -1];
data_u32_00475EA0_layout data_u32_00475EA0 = {
    { -40.0f, -146.666656f, -40.0f, 0.0f },
    {
    {0.0f, 0.0f, 0},
    {48.3333321f, 111.428566f, 131071},
    {-68.3333282f, 0.0f, 196607},
    {35.0f, 250.714279f, 262143},
    {-35.0f, 154.285706f, 524287}
    },
    0u
};

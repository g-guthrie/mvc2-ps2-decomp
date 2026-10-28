/* Tail of the angle+scale track D_00441480 and the start of the track at 0x004414F0;
 * see data_u32_0044138C for the key layouts. */
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

/* Track key, event category 6 (angle + scale x/y). */
typedef struct { s16 time; s16 angle; f32 scale[2]; } RotScaleKey;
typedef char RotScaleKey_size_check[(sizeof(RotScaleKey) == 12) ? 1 : -1];
/* Track key, event category 2 (angle in degrees): frame time, angle. */
typedef struct { s16 time; s16 angle; } RotKey;
typedef char RotKey_size_check[(sizeof(RotKey) == 4) ? 1 : -1];

typedef struct {
    RotScaleKey track_00441480_keys4_8[5];  /* keys 4..8 of D_00441480; key 8 has time -1 */
    u32 pad_004414EC[1];
    RotScaleKey track_004414F0[2];  /* event 0x07 (category 6), keys 0..1 */
    RotKey track_004414F0_key2;  /* time/angle half of key 2; its scale is the 1.0/1.0 pair in data_f32_one_0044150C */
} data_u32_004414B0_t;
typedef char data_u32_004414B0_t_size_check[(sizeof(data_u32_004414B0_t) == 92) ? 1 : -1];

data_u32_004414B0_t data_u32_004414B0 = {
    {
        { 180, -450, { 3.0f, 3.0f } },
        { 260, -720, { 2.0f, 2.0f } },
        { 320, -855, { 3.0f, 1.0f } },
        { 380, -990, { 6.0f, 6.0f } },
        { -1, -630, { 3.0f, 3.0f } },
    },
    { 0u },
    {
        { 0, -45, { 3.0f, 1.0f } },
        { 60, -225, { 2.5f, 2.5f } },
    },
    { 120, -405 },
};

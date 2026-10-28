/* Angle+scale tracks D_00441550 and 0x004415A0; see data_u32_0044138C for the key layouts. */
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
    u32 pad_00441544[3];
    RotScaleKey track_00441550[6];  /* D_00441550 (channel 6); key 5 has time -1 */
    u32 pad_00441598[2];
    RotScaleKey track_004415A0[2];  /* event 0x08 (category 6), keys 0..1 */
    RotKey track_004415A0_key2;  /* time/angle half of key 2; its scale is the 1.0/1.0 pair in data_f32_one_004415BC */
} data_u32_00441544_t;
typedef char data_u32_00441544_t_size_check[(sizeof(data_u32_00441544_t) == 120) ? 1 : -1];

data_u32_00441544_t data_u32_00441544 = {
    { 0u, 0u, 0u },
    {
        { 0, -45, { 2.2f, 2.2f } },
        { 240, -765, { 2.2f, 2.2f } },
        { 260, -825, { 2.5f, 2.5f } },
        { 320, -1005, { 3.0f, 1.0f } },
        { 380, -1185, { 6.0f, 6.0f } },
        { -1, -630, { 3.0f, 3.0f } },
    },
    { 0u, 0u },
    {
        { 0, 90, { 3.0f, 1.0f } },
        { 60, 270, { 3.0f, 3.0f } },
    },
    { 120, 450 },
};

/* Keyframe tracks driven by func_001415B0. Key layout depends on the event category
 * (byte +3 of data_scene_event_schedule_00441E30 rows, stored at object +0x20): 1 pos, 2 angle,
 * 3 pos+angle, 4 scale, 5 pos+scale, 6 angle+scale. A key with time -1 ends its track. */
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

/* Track key, event category 1 (position): frame time, unread s16, x/y/z. */
typedef struct { s16 time; s16 pad; f32 pos[3]; } PosKey;
typedef char PosKey_size_check[(sizeof(PosKey) == 16) ? 1 : -1];
/* Track key, event category 2 (angle in degrees): frame time, angle. */
typedef struct { s16 time; s16 angle; } RotKey;
typedef char RotKey_size_check[(sizeof(RotKey) == 4) ? 1 : -1];
/* Track key, event category 6 (angle + scale x/y). */
typedef struct { s16 time; s16 angle; f32 scale[2]; } RotScaleKey;
typedef char RotScaleKey_size_check[(sizeof(RotScaleKey) == 12) ? 1 : -1];

typedef struct {
    u32 pad_0044138C[1];
    PosKey track_00441390[4];  /* event 0x01 (category 1) */
    PosKey track_004413D0[4];  /* D_004413D0, passed to func_001415B0 for the object in slot 1 */
    RotKey track_00441410[4];  /* event 0x04 (category 2) */
    RotKey track_00441420[4];  /* event 0x05 (category 2) */
    RotScaleKey track_00441430[6];  /* event 0x06 (category 6) */
    u32 pad_00441478[2];
    RotScaleKey track_00441480[3];  /* D_00441480 (channel 5); keys 3.. continue in data_u32_004414B0 */
    RotKey track_00441480_key3;  /* time/angle half of key 3; its scale is the 1.0/1.0 pair in data_f32_one_004414A8 */
} data_u32_0044138C_t;
typedef char data_u32_0044138C_t_size_check[(sizeof(data_u32_0044138C_t) == 284) ? 1 : -1];

data_u32_0044138C_t data_u32_0044138C = {
    { 0u },
    {
        { 0, 0, { 0.0f, 0.0f, -4.0f } },
        { 90, 0, { 0.0f, 0.0f, -15.0f } },
        { 270, 0, { 0.0f, 0.0f, -15.0f } },
        { -1, 0, { 0.0f, 0.0f, -15.0f } },
    },
    {
        { 0, 0, { 0.0f, 0.0f, -4.0f } },
        { 15, 0, { 0.0f, 0.0f, -15.0f } },
        { 240, 0, { 0.0f, 0.0f, -15.0f } },
        { -1, 0, { 0.0f, 0.0f, -15.0f } },
    },
    {
        { 0, 0 },
        { 150, 180 },
        { 270, 360 },
        { -1, 360 },
    },
    {
        { 0, 0 },
        { 150, -180 },
        { 270, -360 },
        { -1, -360 },
    },
    {
        { 0, 45, { 3.0f, 1.0f } },
        { 60, -135, { 2.0f, 2.0f } },
        { 120, -315, { 3.0f, 3.0f } },
        { 240, -630, { 3.0f, 3.0f } },
        { 360, -945, { 2.0f, 2.0f } },
        { -1, -630, { 3.0f, 3.0f } },
    },
    { 0u, 0u },
    {
        { 0, 45, { 1.8f, 1.8f } },
        { 30, -45, { 2.4f, 2.4f } },
        { 60, -135, { 3.0f, 3.0f } },
    },
    { 120, -315 },
};

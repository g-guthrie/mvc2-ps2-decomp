/* Angle+scale track D_00441700 (continued) and the pos/angle tracks of events 0x0A..0x23;
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
/* Track key, event category 3 (position + angle). */
typedef struct { s16 time; s16 angle; f32 pos[3]; } PosRotKey;
typedef char PosRotKey_size_check[(sizeof(PosRotKey) == 16) ? 1 : -1];
/* Track key, event category 1 (position): frame time, unread s16, x/y/z. */
typedef struct { s16 time; s16 pad; f32 pos[3]; } PosKey;
typedef char PosKey_size_check[(sizeof(PosKey) == 16) ? 1 : -1];
/* Track key, event category 5 (position + scale x/y). */
typedef struct { s16 time; s16 pad; f32 pos[3]; f32 scale[2]; } PosScaleKey;
typedef char PosScaleKey_size_check[(sizeof(PosScaleKey) == 24) ? 1 : -1];

typedef struct {
    RotScaleKey track_00441700_keys[6];  /* keys 3..8 of D_00441700 (channel 8) (keys 0..2 precede it); key 8 has time -1 */
    u32 pad_0044176C[1];
    RotKey track_00441770[3];  /* events 0x0A..0x0C (category 2) */
    u32 pad_0044177C[1];
    RotKey track_00441780[4];  /* event 0x0D (category 2) */
    PosRotKey track_00441790[4];  /* event 0x0E (category 3) */
    PosRotKey track_004417D0[4];  /* event 0x10 (category 3) */
    PosKey track_00441810[5];  /* event 0x21 (category 1) */
    PosKey track_00441860[3];  /* event 0x1F (category 1) */
    PosScaleKey track_00441890[2];  /* event 0x23 (category 5), keys 0..1 */
    PosKey track_00441890_key2;  /* time/pos half of key 2; its scale is the 1.0/1.0 pair in data_f32_one_004418D0 */
} data_u32_00441724_t;
typedef char data_u32_00441724_t_size_check[(sizeof(data_u32_00441724_t) == 428) ? 1 : -1];

data_u32_00441724_t data_u32_00441724 = {
    {
        { 120, 360, { 2.0f, 2.0f } },
        { 180, 540, { 3.0f, 3.0f } },
        { 260, 900, { 2.0f, 2.0f } },
        { 320, 990, { 3.0f, 1.0f } },
        { 380, 1080, { 6.0f, 6.0f } },
        { -1, -630, { 3.0f, 3.0f } },
    },
    { 0u },
    {
        { 0, -120 },
        { 95, 120 },
        { -1, 120 },
    },
    { 0u },
    {
        { 0, -60 },
        { 35, 0 },
        { 55, 0 },
        { -1, 0 },
    },
    {
        { 0, 90, { 7.0f, 0.5f, -14.0f } },
        { 10, 0, { 9.98f, 0.5f, -14.5f } },
        { 15, 0, { 9.98f, 0.5f, -14.5f } },
        { -1, 0, { 9.98f, 0.5f, -14.5f } },
    },
    {
        { 0, -90, { 1e+01f, -0.5f, -14.0f } },
        { 10, 0, { 7.1f, -0.5f, -14.5f } },
        { 15, 0, { 7.1f, -0.5f, -14.5f } },
        { -1, 0, { 7.1f, -0.5f, -14.5f } },
    },
    {
        { 0, 0, { 13.0f, 0.0f, -14.8f } },
        { 10, 0, { 0.58f, 0.0f, -14.0f } },
        { 20, 0, { 0.0f, 0.0f, -13.0f } },
        { 30, 0, { 8.0f, 0.0f, -13.0f } },
        { -1, 0, { 0.0f, 0.0f, -15.0f } },
    },
    {
        { 0, 0, { 9.0f, -2.0f, -12.01f } },
        { 20, 0, { 9.0f, 0.0f, -12.01f } },
        { -1, 0, { 0.0f, 0.0f, -15.0f } },
    },
    {
        { 0, 0, { 25.0f, -3.0f, -12.0f }, { 1.0f, 0.1f } },
        { 10, 0, { 0.0f, -3.0f, -12.0f }, { 1.0f, 0.1f } },
    },
    { 20, 0, { 0.0f, -3.0f, -12.0f } },
};

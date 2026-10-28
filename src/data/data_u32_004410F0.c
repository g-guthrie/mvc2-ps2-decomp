/* Camera key tracks for the intro sequence. D_00441370[] (selector 0..6) points at the
 * track starts; func_001434A0 steps keys of 28 bytes (idx * 0x1C + base), reading the time
 * at +0 (s16) and two vec3 at +4 and +0x10, and ends a track at a key whose time is -1. */
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

/* Last 12 bytes (the b vec3) of the CamKey that starts at 0x004410E0, in data_zero_004410E0. */
typedef struct { f32 b[3]; } CamTail;
typedef char CamTail_size_check[(sizeof(CamTail) == 12) ? 1 : -1];
/* Camera key: frame time (s16), unread s16, two vec3 blended by func_00141540 (a -> object +0x5C, b -> +0x50). */
typedef struct { s16 time; s16 pad; f32 a[3]; f32 b[3]; } CamKey;
typedef char CamKey_size_check[(sizeof(CamKey) == 28) ? 1 : -1];

typedef struct {
    CamTail track_004410E0_key0_b;  /* tail of key 0 of the track at 0x004410E0 */
    CamKey track_004410E0_keys[3];  /* selector 0 (0x004410E0), keys 1..3; key 3 has time -1 (end) */
    CamKey track_00441150[3];  /* selector 1; key 2 has time -1 */
    u32 pad_004411A4[3];
    CamKey track_004411B0[2];  /* selector 5; no -1 key, stream stops after its 300-frame move */
    u32 pad_004411E8[2];
    CamKey track_004411F0[3];  /* selector 2 */
    u32 pad_00441244[3];
    CamKey track_00441250[3];  /* selector 3 */
    u32 pad_004412A4[3];
    CamKey track_004412B0[3];  /* selector 4 */
    u32 pad_00441304[3];
    CamKey track_00441310[3];  /* selector 6 */
    u32 pad_00441364[3];
} data_u32_004410F0_t;
typedef char data_u32_004410F0_t_size_check[(sizeof(data_u32_004410F0_t) == 640) ? 1 : -1];

data_u32_004410F0_t data_u32_004410F0 = {
    { { 0.0f, 0.0f, -15.0f } },
    {
        { 235, 0, { 6.68f, 0.0f, -7.36f }, { 6.68f, 0.0f, -15.0f } },
        { 355, 0, { 8.54f, 0.0f, -13.3f }, { 8.54f, 0.0f, -15.0f } },
        { -1, 0, { 8.54f, 0.0f, -13.3f }, { 8.54f, 0.0f, -15.0f } },
    },
    {
        { 0, 0, { 8.54f, 0.0f, -13.3f }, { 8.54f, 0.0f, -15.0f } },
        { 30, 0, { 8.0f, 0.0f, -6.0f }, { 8.0f, 0.0f, -15.0f } },
        { -1, 0, { 8.0f, 0.0f, -6.0f }, { 8.0f, 0.0f, -15.0f } },
    },
    { 0u, 0u, 0u },
    {
        { 0, 0, { 2.42f, -0.54f, 22.29f }, { -1.09f, 0.18f, 18.14f } },
        { 300, 0, { 2.42f, -0.54f, -9.23f }, { -1.09f, 0.18f, -13.65f } },
    },
    { 0u, 0u },
    {
        { 0, 0, { -3.41f, -0.54f, 22.29f }, { 1.1f, 0.18f, 18.14f } },
        { 300, 0, { -3.41f, -0.54f, -11.18f }, { 1.1f, 0.18f, -15.0f } },
        { -1, 0, { 2.42f, -0.54f, -9.23f }, { -1.09f, 0.18f, -13.65f } },
    },
    { 0u, 0u, 0u },
    {
        { 0, 0, { 5.0f, 0.0f, 0.0f }, { 5.0f, 0.0f, -15.0f } },
        { 30, 0, { 5.0f, 0.0f, -8.0f }, { 5.0f, 0.0f, -15.0f } },
        { -1, 0, { -8.0f, 0.0f, -6.0f }, { -8.0f, 0.0f, -15.0f } },
    },
    { 0u, 0u, 0u },
    {
        { 0, 0, { 5.0f, 0.0f, -8.0f }, { 5.0f, 0.0f, -15.0f } },
        { 30, 0, { -9.14f, 0.0f, -7.28f }, { -9.14f, 0.0f, -15.0f } },
        { -1, 0, { -9.14f, 0.0f, -7.28f }, { -9.14f, 0.0f, -15.0f } },
    },
    { 0u, 0u, 0u },
    {
        { 0, 0, { 0.0f, -3.0f, -5.0f }, { 0.0f, -3.0f, -15.0f } },
        { 60, 0, { 0.0f, 0.0f, -5.0f }, { 0.0f, 0.0f, -15.0f } },
        { -1, 0, { -9.14f, 0.0f, -7.28f }, { -9.14f, 0.0f, -15.0f } },
    },
    { 0u, 0u, 0u },
};

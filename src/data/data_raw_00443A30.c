typedef unsigned int u32;
typedef float f32;
extern unsigned char D_004C2864[];
extern unsigned char D_004C285C[];
extern unsigned char D_004C286C[];
typedef struct {
    const void *pointers[3];
    u32 zero;
    f32 floats[12];
    u32 tail[8];
} data_raw_00443A30_layout;
typedef char data_raw_00443A30_size_check[(sizeof(data_raw_00443A30_layout) == 96) ? 1 : -1];
data_raw_00443A30_layout data_raw_00443A30 = {
    { D_004C2864, D_004C285C, D_004C286C },
    0u,
    {
        0.19999999f, 4.5f, -12.99f, -0.79999995f,
        1.5f, -12.99f, -0.79999995f, -3.0f,
        -12.99f, -0.29999995f, -4.5f, -12.99f,
    },
    { 0u, 0u, 1u, 0u, 0u, 2u, 3u, 0u },
};

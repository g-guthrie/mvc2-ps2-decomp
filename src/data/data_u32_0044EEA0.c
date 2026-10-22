typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef struct {
    u16 hw[16];
    f32 f8;
    f32 f9;
} RecA;
typedef struct {
    u32 w0;
    f32 f1;
    f32 f2;
    u32 w3;
    f32 f4;
    f32 f5;
    u32 w6;
    f32 f7;
    f32 f8;
    u32 w9;
} RecB;
typedef struct {
    RecA a;
    RecB b;
} Tab;
Tab data_u32_0044EEA0 = {
    {
        0x0005u, 0x0004u, 0x0100u, 0x0008u, 0x0101u, 0x0004u, 0x0102u, 0x0010u,
        0x0103u, 0x0014u, 0x0400u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
        55.0f, 132.85713f,
    },
    {
        0x00020202u, -73.33333f, 1.5e+02f, 0x00030404u, 8e+01f,
        3e+01f, 0x00020306u, -76.666664f, 27.857141f, 0x00030603u,
    },
};

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* No reader found. 25 records of three f32 each (25 * 12 = 300 bytes). */
typedef struct {
    f32 x, y, z;
} Vec3f;
typedef char Vec3f_size_check[(sizeof(Vec3f) == 12) ? 1 : -1];

Vec3f data_u8_0045FA34[25] = {
    {0.0f, 0.0f, 0.0f},
    {1299.0f, 1066.0f, -950.0f},
    {1305.0f, 1012.0f, -892.0f},
    {1332.0f, 955.0f, -839.0f},
    {1363.0f, 898.0f, -789.0f},
    {0.0f, -82.0999985f, 0.0f},
    {0.0f, -51.7000008f, 0.0f},
    {0.0f, -45.0f, 0.0f},
    {0.0f, -45.0f, 0.0f},
    {945.0f, 36.0f, -960.0f},
    {846.0f, 22.0f, -794.0f},
    {1084.0f, 36.0f, -730.0f},
    {1152.0f, 22.0f, -561.0f},
    {964.0f, -125.0f, -667.0f},
    {1524.0f, 318.0f, -951.0f},
    {1524.0f, 395.0f, -931.0f},
    {0.0f, 0.0f, 0.0f},
    {1405.0f, 498.0f, -897.0f},
    {0.0f, 181.160004f, -82.0999985f},
    {0.0f, 0.0f, -51.7000008f},
    {0.0f, 188.039993f, -45.0f},
    {0.0f, 99.7799988f, -44.1699982f},
    {-16.2299995f, -38.9000015f, -69.0f},
    {-54.9000015f, 0.0f, -45.0f},
    {0.0f, 11.4499998f, -45.0f}
};

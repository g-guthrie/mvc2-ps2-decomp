typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

typedef struct {
    f32 x, y, z;
} Vec3f;
typedef char Vec3f_size_check[(sizeof(Vec3f) == 12) ? 1 : -1];
/* No reader found. Six Vec3f records, then a 20-byte tail of small byte values. */
typedef struct {
    Vec3f v[6];
    u8 tail[20];
} Data004ACD48;
typedef char data_004ACD48_size_check[(sizeof(Data004ACD48) == 92) ? 1 : -1];

Data004ACD48 data_raw_004ACD48 = {
    {
        {200.0f, 38.0f, 4.0f},
        {440.0f, 38.0f, 6.0f},
        {160.0f, 48.0f, 8.0f},
        {480.0f, 48.0f, 10.0f},
        {300.0f, 28.0f, 100.0f},
        {460.0f, 28.0f, 102.0f}
    },
    {0x01u, 0x01u, 0x01u, 0x01u, 0x01u, 0x01u, 0x01u, 0x02u, 0x01u, 0x01u, 0x01u, 0x02u, 0x01u, 0x01u, 0x01u, 0x01u, 0x02u, 0x01u, 0x02u, 0x01u}
};

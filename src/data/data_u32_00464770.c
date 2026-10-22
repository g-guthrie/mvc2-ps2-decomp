typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* No reader found. First 16 bytes: eight u16 values; then twelve f32. */
typedef struct {
    u16 idx[8];
    f32 val[12];
} Data00464770;
typedef char data_00464770_size_check[(sizeof(Data00464770) == 64) ? 1 : -1];

Data00464770 data_u32_00464770 = {
    {9u, 10u, 11u, 12u, 13u, 0u, 0u, 0u},
    {640.0f, 171.428558f, 640.0f, 342.857117f, 213.333328f, 137.142853f, 213.333328f, 274.285706f, 213.333328f, 411.428558f, 0.0f, 0.0f}
};

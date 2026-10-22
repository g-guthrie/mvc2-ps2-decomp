typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* No reader found; layout inferred. s16 pts and s32 16.16 fixed-point fields. */
typedef struct {
    u32 zero0;
    s16 pts[6];
    u32 zero1;
    s32 fx[14]; /* 16.16 fixed-point values */
} Data00472A9C;
typedef char data_00472A9C_size_check[(sizeof(Data00472A9C) == 76) ? 1 : -1];

Data00472A9C data_u32_00472A9C = {
    0x00000000u,
    {-46, 74, -40, 86, -44, 61},
    0x00000000u,
    {
        -524288,
        0,
        -524288,
        114688,
        -524288,
        -114688,
        0,
        0,
        -1048576,
        0,
        -1048576,
        114688,
        -1048576,
        -114688
    }
};

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* No reader found: two {u16, u16} pairs. */
typedef struct {
    u16 a;
    u16 b;
} U16Pair;
typedef char U16Pair_size_check[(sizeof(U16Pair) == 4) ? 1 : -1];

U16Pair data_u32_004595C8[2] = {
    {13, 30},
    {13, 29}
};

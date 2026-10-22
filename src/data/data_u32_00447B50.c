typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* No reader found: four {lo, hi} signed 16-bit pairs. */
typedef struct {
    s16 lo;
    s16 hi;
} S16Range;
typedef char S16Range_size_check[(sizeof(S16Range) == 4) ? 1 : -1];

S16Range data_u32_00447B50[4] = {
    {-1024, 1024},
    {-896, 896},
    {-1280, 1280},
    {-1280, 1280}
};

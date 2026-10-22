typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* No reader found: a zero word, then two u16 values. */
typedef struct {
    u32 zero;
    u16 a;
    u16 b;
} Data004BFE18;
typedef char Data004BFE18_size_check[(sizeof(Data004BFE18) == 8) ? 1 : -1];

Data004BFE18 data_u32_004BFE18 = {
    0x00000000u, 1, 2
};

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* 12-byte entry: three rows of four signed bytes; -1 appears as a sentinel. */
typedef s8 Grp12[3][4];
/* No reader found. One entry. */

Grp12 data_u32_004BFD9C[1] = {
    {{1, 2, 1, 2}, {-1, 2, -1, 2}, {-1, -1, -1, -1}}
};

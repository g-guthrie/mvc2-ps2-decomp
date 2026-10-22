typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* 12-byte entry: three rows of four signed bytes; -1 appears as a sentinel. */
typedef s8 Grp12[3][4];
/* No reader found: five entries, then four trailing signed bytes. */
typedef struct {
    Grp12 e[5];
    s8 tail[4];
} Data004C0AF0;
typedef char data_004C0AF0_size_check[(sizeof(Data004C0AF0) == 64) ? 1 : -1];

Data004C0AF0 data_u32_004C0AF0 = {
    {
        {{1, 2, 0, 2}, {-1, 2, 1, 2}, {-1, -1, -1, -1}},
        {{1, 2, 1, 2}, {-1, 2, -1, 2}, {-1, -1, -1, -1}},
        {{1, 2, 1, 2}, {-1, 2, -1, 2}, {-1, -1, -1, -1}},
        {{1, 2, 1, 2}, {-1, 2, -1, 2}, {-1, -1, -1, -1}},
        {{1, 2, 0, 2}, {-1, 2, 1, 2}, {-1, -1, -1, 2}}
    },
    {1, 2, 1, 2}
};

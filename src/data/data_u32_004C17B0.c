typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* 12-byte entry: three rows of four signed bytes; -1 appears as a sentinel. */
typedef s8 Grp12[3][4];
/* No reader found: six entries, then a 40-byte unsigned tail. */
typedef struct {
    Grp12 e[6];
    u8 tail[40];
} Data_004C17B0;
typedef char data_004C17B0_size_check[(sizeof(Data_004C17B0) == 112) ? 1 : -1];

Data_004C17B0 data_u32_004C17B0 = {
    {
        {{1, 2, 1, 2}, {-1, 2, -1, 2}, {-1, -1, -1, -1}},
        {{1, 2, 1, 2}, {-1, 2, -1, 2}, {-1, -1, -1, -1}},
        {{1, 2, 1, 2}, {-1, 2, -1, 2}, {-1, -1, -1, -1}},
        {{1, 2, 1, 2}, {-1, 2, -1, 2}, {-1, -1, -1, -1}},
        {{1, 2, 0, 2}, {-1, 2, 1, 2}, {-1, -1, -1, 2}},
        {{1, 2, 1, 2}, {-1, 2, -1, 2}, {-1, -1, -1, -1}}
    },
    {0x00u, 0x01u, 0x02u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x0Cu, 0x0Du, 0x0Eu, 0x0Fu, 0x10u, 0x11u, 0x00u, 0x00u, 0x00u, 0x01u, 0x02u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x01u, 0x02u, 0x00u, 0x01u, 0x02u, 0x00u, 0x00u, 0x0Bu, 0x0Bu, 0x0Bu, 0x0Cu, 0x0Cu, 0x0Cu, 0x00u, 0x00u}
};

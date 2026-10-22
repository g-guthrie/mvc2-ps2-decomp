typedef int s32;
/* 16.16 fixed-point (x, y) pairs. */
typedef struct { s32 x; s32 y; } Fixed16Pair;
typedef char Fixed16Pair_size_check[(sizeof(Fixed16Pair) == 8) ? 1 : -1];
Fixed16Pair data_u32_0044F820[4] = {
    { 262144, 884736 },
    { -49152, 163840 },
    { 950272, -32768 },
    { 0, 0 },
};

typedef int s32;
/* 16.16 fixed-point / count word pairs; D_004BF630 (+0x40) is a pointer pair table indexed
   by u8 (+0x20) in func_001A0200, D_004BF658 (+0x68) likewise. */
extern char D_0044AF30[], D_0044AF50[], D_0044AFE0[];
typedef struct Mv_004BF5F0 {
    s32 a_00[16];
    void *p_40[2];
    s32 a_48[8];
    void *p_68[2];
    s32 a_70[4];
} Mv_004BF5F0;
typedef char Mv_004BF5F0_size_check[(sizeof(Mv_004BF5F0) == 128) ? 1 : -1];
Mv_004BF5F0 data_u32_004BF5F0 = {
    { 65536, 10, -65312, 5, 65776, 5, 65784, 6, 65536, 4, 65536, 8, 65576, 6, -65536, 6 },
    { D_0044AF30, D_0044AF50 },
    { 65536, 2, -65344, 6, 65536, 20, 65584, 6 },
    { D_0044AFE0, D_0044AFE0 },
    { 65536, 1, -65344, 6 },
};

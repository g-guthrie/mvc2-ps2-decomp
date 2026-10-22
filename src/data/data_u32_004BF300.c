typedef int s32;
/* Records read by func_001234D0: lw count at +0, then count 4-byte entries (here one each).
   Table of record pointers is D_0043CB10 (slots 2 and 4 point at these two records). */
typedef struct { s32 count; s32 value[1]; } CountedS32x1;
typedef char CountedS32x1_size_check[(sizeof(CountedS32x1) == 8) ? 1 : -1];
CountedS32x1 data_u32_004BF300[2] = {
    { 1, { 30 } },
    { 1, { 60 } },
};

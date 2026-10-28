typedef signed int s32;
/* D_00478E10[desc->idx_478E10] (index << 3): src/rb81_c.c reads .e0, func_003EEC30 reads
 * D_00478E14 (.e4); the microcode descriptors use indices 0..9. */
typedef struct { s32 e0; s32 e4; } S32Pair478E10;
S32Pair478E10 data_rec_00478E10[10] = {
    { 0x30, 11 },
    { 0x40, 15 },
    { 0x20, 3 },
    { 0x30, 7 },
    { 0x20, 9 },
    { 0x30, 13 },
    { 0x10, 1 },
    { 0x20, 5 },
    { 0x50, 59 },
    { 0x60, 63 },
};

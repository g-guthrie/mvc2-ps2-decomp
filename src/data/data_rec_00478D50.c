typedef unsigned int u32;
typedef signed int s32;
/* func_003EDA60 (src/xl15_b.c): for j = 0..15, q = D_00478D50 + j * 8; q[0] is tested against the
 * input bits (lw) and q[1] selects the analog source case (lw, switch 1/2/3). */
typedef struct { u32 mask; s32 kind; } InputMap478D50;
InputMap478D50 data_rec_00478D50[16] = {
    { 0x10u, 1 },
    { 0x40u, 1 },
    { 0x80u, 1 },
    { 0x20u, 1 },
    { 0x4000u, 2 },
    { 0x2000u, 2 },
    { 0x200u, 3 },
    { 0x100u, 3 },
    { 0x8000u, 2 },
    { 0x1000u, 2 },
    { 0x800u, 3 },
    { 0x400u, 3 },
    { 0x2u, 0 },
    { 0x4u, 0 },
    { 0x1u, 0 },
    { 0x8u, 0 },
};

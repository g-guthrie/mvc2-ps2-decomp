typedef short s16;
typedef int s32;
/* gp-relative scalars: D_004BF448 read with lh (func_0015B000), D_004BF44C read with lh and lw. */
typedef struct Mv_004BF448 {
    s16 h_00;
    s16 h_02;
    s32 w_04;
} Mv_004BF448;
typedef char Mv_004BF448_size_check[(sizeof(Mv_004BF448) == 8) ? 1 : -1];
Mv_004BF448 data_u32_004BF448 = { 85, 0, 167 };

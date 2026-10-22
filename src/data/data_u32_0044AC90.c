typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
/* Tail of the 6-byte record table based at D_0044AC20 (s16, s16, s8 read by func_0019E0xx),
   then the table at D_0044ACA0 read by func_0019E2E0 as lh [id*6], lh [id*6+2], lb [id*6+4]. */
typedef struct Mv_0044AC90_R {
    s16 h_00;
    s16 h_02;
    s8 b_04;
    s8 b_05;
} Mv_0044AC90_R;
typedef char Mv_0044AC90_R_size_check[(sizeof(Mv_0044AC90_R) == 6) ? 1 : -1];
typedef struct Mv_0044AC90 {
    s8 b_00[2];
    Mv_0044AC90_R r_02[2];
    u8 pad_0E[2];
    Mv_0044AC90_R r_10[5];
    u8 pad_2E[2];
} Mv_0044AC90;
typedef char Mv_0044AC90_size_check[(sizeof(Mv_0044AC90) == 48) ? 1 : -1];
Mv_0044AC90 data_u32_0044AC90 = {
    { 0, 2 },
    { { 80, 384, 96, 0 }, { 512, 96, 0, 1 } },
    { 96, 0 },
    { { 8192, 16384, 32, 0 }, { 11008, 21760, 33, 0 }, { -2048, 6656, 34, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
    { 0, 0 },
};

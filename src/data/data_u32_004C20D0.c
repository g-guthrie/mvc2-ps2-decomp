typedef short s16;
/* s16 pair read by func_003BFC90 (gp-relative D_004C20D0/D_004C20D2), then an s16
   table D_004C20D8 indexed by actor field (+0xD0)*2. */
typedef struct Mv_004C20D0 {
    s16 h_00;
    s16 h_02;
    s16 h_04;
    s16 h_06;
    s16 a_08[4];
} Mv_004C20D0;
typedef char Mv_004C20D0_size_check[(sizeof(Mv_004C20D0) == 16) ? 1 : -1];
Mv_004C20D0 data_u32_004C20D0 = { 0, 64, 0, 0, { -1, 0, 1, 0 } };

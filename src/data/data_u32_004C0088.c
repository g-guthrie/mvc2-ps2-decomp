typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
/* Seven 8-byte index tables read via gp-relative labels D_004C0088..D_004C00B8
   (func_00227B90, func_00227C00, func_00228A60, func_00229130, func_00229E90, func_00229FD0). */
typedef struct Mv_004C0088 {
    u8 a_00[8];      /* lbu [i] */
    u8 a_08[8];      /* lbu [i] */
    u8 a_10[4][2];   /* lbu [i*2] */
    s16 a_18[4];     /* lh [i*2] */
    u16 a_20[2][2];  /* lhu [i*4] */
    u16 a_28[2][2];  /* lhu [i*4] */
    s16 a_30[2][2];  /* lh [i*4] */
} Mv_004C0088;
typedef char Mv_004C0088_size_check[(sizeof(Mv_004C0088) == 56) ? 1 : -1];
Mv_004C0088 data_u32_004C0088 = {
    { 9, 9, 2, 9, 9, 0, 0, 0 },
    { 4, 5, 6, 7, 8, 5, 6, 7 },
    { { 1, 2 }, { 3, 3 }, { 0, 0 }, { 0, 0 } },
    { 2, 6, 4, 0 },
    { { 0x40, 0x20 }, { 0x20, 0 } },
    { { 0x30, 0x40 }, { 0x50, 0 } },
    { { 8, 10 }, { 12, 0 } },
};

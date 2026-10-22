typedef unsigned char u8;
typedef signed char s8;
/* Byte lookup tables read via gp-relative labels D_004C0280..D_004C029C
   (func_0023C9A0, func_0023CE50, func_0023CF30). */
typedef struct Mv_004C0280 {
    s8 a_00[4];     /* lb [i] */
    u8 pad_04[4];
    u8 a_08[4][2];  /* lbu [j*2 + i] */
    u8 a_10[4][2];  /* lbu */
    u8 a_18[4];     /* lbu [i] */
    u8 a_1C[4];     /* lbu [i] */
} Mv_004C0280;
typedef char Mv_004C0280_size_check[(sizeof(Mv_004C0280) == 32) ? 1 : -1];
Mv_004C0280 data_u32_004C0280 = {
    { 0x10, 0x20, 0, 0 },
    { 0, 0, 0, 0 },
    { { 0x46, 0x48 }, { 0x49, 0x4B }, { 0x4C, 0x4E }, { 0, 0 } },
    { { 0x10, 0x11 }, { 0x12, 0x13 }, { 0x14, 0x15 }, { 0, 0 } },
    { 0x10, 0x20, 0, 0 },
    { 0x00, 0x03, 0x01, 0x00 },
};

typedef unsigned char u8;
typedef signed char s8;
/* Byte tables read via gp-relative labels D_004C1450/1458/1460 (func_002FF950, func_002FFB30, func_002FFEF0),
   a one-entry jump table, and 4-byte script lists (D_004C1468..). */
extern char lbl_002FFE70[];
typedef struct Mv_004C1450 {
    u8 a_00[8];     /* lbu [i] */
    s8 a_08[8];     /* lb [i] */
    s8 a_10[4];     /* lb [i] */
    void *p_14;     /* jtbl_004C1464 */
    s8 a_18[3][4];  /* script lists D_004C1468 / 146C / 1470 */
} Mv_004C1450;
typedef char Mv_004C1450_size_check[(sizeof(Mv_004C1450) == 36) ? 1 : -1];
Mv_004C1450 data_u32_004C1450 = {
    { 0x20, 0x20, 0x20, 0x28, 0x28, 0x28, 0x30, 0x30 },
    { 8, 7, 6, 5, 4, 3, 2, 1 },
    { 8, 6, 4, 2 },
    lbl_002FFE70,
    { { 1, 2, 0, 2 }, { -1, 2, 1, 2 }, { -1, -1, -1, 2 } },
};

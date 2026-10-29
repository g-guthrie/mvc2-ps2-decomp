typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
/* func_0019E2E0 reads lh [id*6], lh [id*6+2] and lb [id*6+4] (D_0044ACA0/A2/A4) with id =
 * the u8 at actor +0x21. */
typedef struct { s16 h_00; s16 h_02; s8 b_04; s8 b_05; } Rec_0044ACA0;
typedef char Rec_0044ACA0_size_check[(sizeof(Rec_0044ACA0) == 6) ? 1 : -1];
typedef struct { Rec_0044ACA0 r[5]; u8 pad[2]; } Tbl_0044ACA0;
typedef char Tbl_0044ACA0_size_check[(sizeof(Tbl_0044ACA0) == 32) ? 1 : -1];
Tbl_0044ACA0 D_0044ACA0 = {
    { { 8192, 16384, 32, 0 }, { 11008, 21760, 33, 0 }, { -2048, 6656, 34, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
    { 0, 0 },
};

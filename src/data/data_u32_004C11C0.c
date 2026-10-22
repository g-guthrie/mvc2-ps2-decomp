typedef signed char s8;
typedef unsigned short u16;
/* u16 table read by func_002F1840 (lhu [i*2]) followed by a 4-byte script list. */
typedef struct Mv_004C11C0 {
    u16 a_00[4];
    s8 a_08[4];
} Mv_004C11C0;
typedef char Mv_004C11C0_size_check[(sizeof(Mv_004C11C0) == 12) ? 1 : -1];
Mv_004C11C0 data_u32_004C11C0 = { { 0, 3, 1, 2 }, { 1, 2, 1, 2 } };

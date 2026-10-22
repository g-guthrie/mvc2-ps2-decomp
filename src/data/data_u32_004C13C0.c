typedef signed char s8;
/* Single-entry jump table (code label inside func_002FB6C0's switch) followed by a 4-byte script list. */
extern char lbl_002FB6C0[];
typedef struct Mv_004C13C0 {
    void *p_00;
    s8 a_04[4];
} Mv_004C13C0;
typedef char Mv_004C13C0_size_check[(sizeof(Mv_004C13C0) == 8) ? 1 : -1];
Mv_004C13C0 data_u32_004C13C0 = { lbl_002FB6C0, { 1, 2, 1, 2 } };

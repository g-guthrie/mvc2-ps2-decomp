typedef signed char s8;
typedef unsigned int u32;
typedef struct Mv_S8PAIR {
    s8 c_00;
    s8 c_01;
} Mv_S8PAIR;
typedef char Mv_S8PAIR_size_check[(sizeof(Mv_S8PAIR) == 2) ? 1 : -1];
typedef struct Mv_004C1F7C {
    u32 w_00;
    Mv_S8PAIR a_04[4];
} Mv_004C1F7C;
typedef char Mv_004C1F7C_size_check[(sizeof(Mv_004C1F7C) == 12) ? 1 : -1];
Mv_004C1F7C data_raw_004C1F7C = { 0x00000000u, {
    { -2, 2 },
    { -2, 2 },
    { -1, 1 },
    { -1, 1 },
} };

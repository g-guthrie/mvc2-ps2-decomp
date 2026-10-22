typedef unsigned int u32;
typedef struct Mv_00454F24_H {
    u32 w_00;
    u32 w_04;
    u32 w_08;
    u32 w_0C;
} Mv_00454F24_H;
typedef char Mv_00454F24_H_size_check[(sizeof(Mv_00454F24_H) == 16) ? 1 : -1];
typedef struct Mv_00454F24_R {
    u32 w_00;
    u32 w_04;
    u32 w_08;
    u32 w_0C;
} Mv_00454F24_R;
typedef char Mv_00454F24_R_size_check[(sizeof(Mv_00454F24_R) == 16) ? 1 : -1];
typedef struct Mv_00454F24_T {
    u32 w_00;
    u32 w_04;
    u32 w_08;
} Mv_00454F24_T;
typedef char Mv_00454F24_T_size_check[(sizeof(Mv_00454F24_T) == 12) ? 1 : -1];
typedef struct Mv_00454F24 {
    Mv_00454F24_H r_00;
    Mv_00454F24_R a_10[3];
    Mv_00454F24_T r_40;
} Mv_00454F24;
typedef char Mv_00454F24_size_check[(sizeof(Mv_00454F24) == 76) ? 1 : -1];
Mv_00454F24 data_u32_00454F24 = { { 0x00000000u, 0x00000000u, 0x00000000u, 0x10000003u }, {
    { 0x00000000u, 0x14001000u, 0x00600400u, 0x11000003u },
    { 0x00000001u, 0x14001000u, 0x03000400u, 0x10000003u },
    { 0x00000002u, 0x18001000u, 0x03000800u, 0x10000003u },
}, { 0x00000003u, 0x18001000u, 0x00600800u } };

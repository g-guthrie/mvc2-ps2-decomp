typedef unsigned short u16;
typedef float f32;
typedef struct Mv_0044E10C_R {
    f32 f_00;
    f32 f_04;
    u16 h_08;
    u16 h_0A;
    f32 f_0C;
    f32 f_10;
} Mv_0044E10C_R;
typedef char Mv_0044E10C_R_size_check[(sizeof(Mv_0044E10C_R) == 20) ? 1 : -1];
typedef struct Mv_0044E10C_T {
    f32 f_00;
    f32 f_04;
    u16 h_08;
    u16 h_0A;
} Mv_0044E10C_T;
typedef char Mv_0044E10C_T_size_check[(sizeof(Mv_0044E10C_T) == 12) ? 1 : -1];
typedef struct Mv_0044E10C {
    Mv_0044E10C_R a_00[3];
    Mv_0044E10C_T r_3C;
} Mv_0044E10C;
typedef char Mv_0044E10C_size_check[(sizeof(Mv_0044E10C) == 72) ? 1 : -1];
Mv_0044E10C data_u32_0044E10C = { {
    { 480.0f, 175.714279f, 0x0001u, 0x0004u, 1.0f, 0.600000024f },
    { 480.0f, 175.714279f, 0x0001u, 0x0004u, 1.0f, 0.300000012f },
    { 480.0f, 175.714279f, 0x0001u, 0x0004u, 1.0f, 1.5f },
}, { 586.666626f, 175.714279f, 0x0001u, 0x0004u } };

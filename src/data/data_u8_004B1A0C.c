typedef unsigned char u8;
typedef struct Mv_U8PAIR {
    u8 b_00;
    u8 b_01;
} Mv_U8PAIR;
typedef char Mv_U8PAIR_size_check[(sizeof(Mv_U8PAIR) == 2) ? 1 : -1];
typedef struct Mv_004B1A0C {
    u8 a_00[4];
    Mv_U8PAIR a_04[4];
} Mv_004B1A0C;
typedef char Mv_004B1A0C_size_check[(sizeof(Mv_004B1A0C) == 12) ? 1 : -1];
Mv_004B1A0C data_u8_004B1A0C = { { 0x00u, 0x00u, 0x00u, 0x00u }, {
    { 0x04u, 0x02u },
    { 0x04u, 0x02u },
    { 0x04u, 0x02u },
    { 0x04u, 0x02u },
} };

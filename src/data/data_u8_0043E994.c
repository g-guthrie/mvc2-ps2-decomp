typedef unsigned int u32;
typedef float f32;
/* Three leading zero words, then f32 1.0 at +0x0C. */
typedef struct Mv_0043E994 {
    u32 w_00;
    u32 w_04;
    u32 w_08;
    f32 f_0C;
} Mv_0043E994;
typedef char Mv_0043E994_size_check[(sizeof(Mv_0043E994) == 16) ? 1 : -1];
Mv_0043E994 data_u8_0043E994 = { 0x00000000u, 0x00000000u, 0x00000000u, 1.0f };

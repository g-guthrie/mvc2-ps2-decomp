typedef unsigned int u32;
typedef float f32;
/* Leading word has no proven typed consumer; f32 at +0x04 is 0.875. */
typedef struct Mv_0043E238 {
    u32 w_00;
    f32 f_04;
} Mv_0043E238;
typedef char Mv_0043E238_size_check[(sizeof(Mv_0043E238) == 8) ? 1 : -1];
Mv_0043E238 data_raw_0043E238 = { 0x00000000u, 0.875f };

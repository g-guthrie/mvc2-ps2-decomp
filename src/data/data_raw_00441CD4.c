typedef unsigned int u32;
typedef float f32;
/* Retained former owner boundary aliases: data_u32_00441CD4, data_f32_one_004421EC, data_u32_004421FC, data_zero_00442500, data_u32_00442510. */
/* Ten {x, y, z, id} records, then a tail typed word by word. */
typedef struct Mv_00441CD4_R {
    f32 f_00;
    f32 f_04;
    f32 f_08;
    u32 w_0C;
} Mv_00441CD4_R;
typedef char Mv_00441CD4_R_size_check[(sizeof(Mv_00441CD4_R) == 16) ? 1 : -1];
typedef struct Mv_00441CD4 {
    Mv_00441CD4_R a_00[10];
    f32 f_A0;
    u32 w_A4;
    f32 f_A8;
    f32 f_AC;
    f32 f_B0;
    u32 w_B4;
    f32 f_B8;
    u32 w_BC;
    f32 f_C0;
    f32 f_C4;
    f32 f_C8;
    u32 w_CC;
    f32 f_D0;
    u32 w_D4;
    f32 f_D8;
    f32 f_DC;
    f32 f_E0;
    u32 w_E4;
    f32 f_E8;
    f32 f_EC;
    f32 f_F0;
    f32 f_F4;
    f32 f_F8;
    u32 w_FC;
    u32 w_100;
    f32 f_104;
    f32 f_108;
    u32 w_10C;
    u32 w_110;
    f32 f_114;
    f32 f_118;
    u32 w_11C;
    u32 w_120;
    u32 w_124;
    f32 f_128;
    u32 w_12C;
    u32 w_130;
    f32 f_134;
    f32 f_138;
    u32 w_13C;
    u32 w_140;
    f32 f_144;
    f32 f_148;
    u32 w_14C;
    u32 w_150;
    u32 w_154;
    f32 f_158;
} Mv_00441CD4;
typedef char Mv_00441CD4_size_check[(sizeof(Mv_00441CD4) == 348) ? 1 : -1];
Mv_00441CD4 data_raw_00441CD4 = { {
    { 10.0f, 0.0f, 0.0f, 0x00000000u },
    { -13.0f, 1.0f, 0.0f, 0x0000000Au },
    { -13.0f, 1.0f, 0.0f, 0x00000078u },
    { -13.0f, 7.5999999f, 0.0f, 0x00000082u },
    { -10.0932999f, 8.0f, 0.0f, 0x0000008Cu },
    { -4.76550007f, 8.39999962f, 0.0f, 0x00000096u },
    { 1.45519996f, 8.89999962f, 0.0f, 0x000000A0u },
    { 7.0f, 9.30000019f, 0.0f, 0x000000D2u },
    { 12.4657001f, 9.60000038f, 0.0f, 0x0000FFFFu },
    { 20.0f, 9.0f, 0.0f, 0x00000000u },
}, 5.0999999f, 0x00000000u, -13.0f, 3.0f, 3.0f, 0x0000000Au, 5.0999999f, 0x00000000u, -13.0f, 1.5f, 1.5f, 0x00000026u, 5.0999999f, 0x00000000u, -13.0f, 1.5f, 1.5f, 0x0000FFFFu, 25.0f, -3.0f, -12.0f, 1.0f, 0.100000001f, 0x00000000u, 0x00000000u, 0.5f, -10.0f, 0x00000078u, 0x00000000u, 0.5f, -1.0f, 0x0000FFFFu, 0x00000000u, 0x00000000u, -15.0f, 0x00000000u, 0x00000000u, -0.5f, -10.0f, 0x00000078u, 0x00000000u, -0.5f, -1.0f, 0x0000FFFFu, 0x00000000u, 0x00000000u, -15.0f };

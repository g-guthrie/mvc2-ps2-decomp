typedef float f32;
/* Records 28..30 of the Vec4 table at D_00440CF0 (x, y, z, scale); func_00142320 indexes it
 * with sll 4 (0x001423C0) and reads +0/+4/+8/+0xC (0x001423CC-0x0014252C). */
typedef struct { f32 v[4]; } Rec_00440EB0;
typedef char Rec_00440EB0_size_check[(sizeof(Rec_00440EB0) == 16) ? 1 : -1];
Rec_00440EB0 data_u32_00440EB0[3] = {
    { { -1.48f, -0.1f, -11.81f, 0.9f } },
    { { -1.5f, -0.1f, -10.89f, 0.9f } },
    { { -1.5f, 0.0f, 1.0f, 1.0f } },
};

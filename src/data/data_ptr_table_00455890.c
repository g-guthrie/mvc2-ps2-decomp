typedef unsigned char u8;
typedef unsigned int u32;

extern u32 data_u32_00455510[];
extern u8 data_rec_004555B0[][16];
extern u32 data_u32_00455640[];
extern u32 data_u32_00455700[];
extern u32 data_u32_004557D0[];

/* func_002810D0 selects with func_00280D80's six-value direction result. */
u8 (*const data_ptr_table_00455890[6])[16] = {
    (u8 (*)[16])data_u32_00455510,
    data_rec_004555B0,
    (u8 (*)[16])data_u32_00455640,
    (u8 (*)[16])data_u32_00455700,
    (u8 (*)[16])data_u32_004557D0,
    (u8 (*)[16])data_u32_004557D0
};

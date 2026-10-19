typedef unsigned int u32;
typedef unsigned char u8;

extern const u32 data_ptr_table_004555A0[];
extern const u32 data_ptr_table_00455630[];
extern const u32 data_ptr_table_004556F0[];
extern const u32 data_ptr_table_004557C0[];
extern const u8 data_raw_00455880[];

/* func_002810D0 uses its six-value direction selector to choose a result array. */
const u32 *const data_ptr_table_004558B0[6] = {
    data_ptr_table_004555A0,
    data_ptr_table_00455630,
    data_ptr_table_004556F0,
    data_ptr_table_004557C0,
    (const u32 *)data_raw_00455880,
    (const u32 *)data_raw_00455880,
};

typedef unsigned int u32;
extern u32 data_u32_004434B0[];
typedef struct {
    u32 field_00;
    u32 field_04;
    const void *field_08;
    const void *field_0C;
    const void *field_10;
    u32 field_14;
} data_u32_00443958_record;
typedef char data_u32_00443958_size_check[(sizeof(data_u32_00443958_record) == 24) ? 1 : -1];
data_u32_00443958_record data_u32_00443958 = {
    0x124u, 0u,
    &data_u32_004434B0[88], &data_u32_004434B0[88], &data_u32_004434B0[88],
    0u,
};

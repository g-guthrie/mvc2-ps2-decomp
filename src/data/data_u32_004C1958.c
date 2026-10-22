typedef unsigned int u32;
typedef float f32;
typedef struct {
    u32 field_00;
    u32 field_04;
    u32 field_08;
    u32 field_0C;
    f32 field_10;
    char field_14[4];
} data_u32_004C1958_record;
typedef char data_u32_004C1958_size_check[(sizeof(data_u32_004C1958_record) == 24) ? 1 : -1];
data_u32_004C1958_record data_u32_004C1958 = { 0x1Au, 0x22u, 0x800u, 0x200800u, 3.0f, { 'F', 'G', 'E', 'D' } };

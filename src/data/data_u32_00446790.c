typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* Ends at 0x00446800, where D_00446800 (a Vec3) begins. */
typedef struct {
    u32 field_00;
    u8 field_04;
    u8 field_05;
    u16 field_06;
    u32 field_08;
} data_u32_00446790_entry;
typedef struct {
    u32 header[3];
    data_u32_00446790_entry entries[8];
    u32 trailer[1];
} data_u32_00446790_layout;
typedef char data_u32_00446790_size_check[(sizeof(data_u32_00446790_layout) == 112) ? 1 : -1];
data_u32_00446790_layout data_u32_00446790 = {
    { 0u, 0u, 0u },
    {
        { 4u, 1u, 255u, 0u, 0u },
        { 5u, 1u, 255u, 0u, 0u },
        { 5u, 1u, 145u, 0u, 0u },
        { 5u, 1u, 255u, 0u, 0u },
        { 30u, 1u, 72u, 0u, 0u },
        { 80u, 1u, 145u, 0u, 0u },
        { 80u, 1u, 182u, 0u, 0u },
        { 30u, 1u, 255u, 0u, 0u },
    },
    { 0u },
};

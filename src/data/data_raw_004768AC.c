typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
#pragma pack(1)
typedef struct {
    u32 field_00;
    u16 field_04;
    u16 field_06;
    u32 field_08;
    u32 field_0C;
} data_raw_004768AC_entry;
typedef struct {
    f32 floats[3];
    u32 head_word;
    data_raw_004768AC_entry entries[8];
    u8 tail[5];
} data_raw_004768AC_layout;
#pragma pack()
typedef char data_raw_004768AC_size_check[(sizeof(data_raw_004768AC_layout) == 149) ? 1 : -1];
data_raw_004768AC_layout data_raw_004768AC = {
    { 0.026f, -0.952f, -12.99f },
    0u,
    {
        { 0u, 1u, 50u, 0u, 0u },
        { 0u, 1u, 20u, 0u, 2147483648u },
        { 0u, 255u, 15u, 0u, 0u },
        { 0u, 1u, 50u, 0u, 0u },
        { 0u, 1u, 47u, 0u, 2147483648u },
        { 0u, 255u, 0u, 0u, 0u },
        { 0u, 1u, 4u, 0u, 0u },
        { 0u, 255u, 0u, 0u, 0u },
    },
    { 0, 0, 0, 0, 1 },
};

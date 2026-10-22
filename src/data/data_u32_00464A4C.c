typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct data_u32_00464A4C_ent_t {
    u32 zero;
    s16 v0;
    s16 v1;
} data_u32_00464A4C_ent_t;
typedef struct data_u32_00464A4C_t {
    u32 field0;
    f32 values[8];
    data_u32_00464A4C_ent_t ents[5];
    s16 tail[2][2];
} data_u32_00464A4C_t;
typedef char data_u32_00464A4C_size_check[(sizeof(data_u32_00464A4C_t) == 84) ? 1 : -1];
data_u32_00464A4C_t data_u32_00464A4C = {
    0x00000000U,
    { 81.428566f, 60.0f, 115.714279f, 34.2857132f, 66.428566f, 47.1428566f, 77.1428528f, 34.2857132f },
    {
        { 0x00000000U, -512, 9 },
        { 0x00000000U, -1024, 11 },
        { 0x00000000U, -256, 12 },
        { 0x00000000U, 256, 14 },
        { 0x00000000U, -768, 13 }
    },
    { 7, 9, 256, 38 }
};

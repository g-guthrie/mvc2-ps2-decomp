typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef struct {
    u32 u32_00;
    f32 f32_04;
    f32 f32_08;
    u32 u32_0C;
    f32 f32_10;
    f32 f32_14;
    f32 f32_18;
    u8 u8_1C[4];
    u32 u32_20;
    u32 u32_24;
    u32 u32_28;
    f32 f32_2C;
    f32 f32_30;
    f32 f32_34;
} Rec56;
typedef char Rec56_size_check[(sizeof(Rec56) == 56) ? 1 : -1];
Rec56 data_u32_00443814 = {
    0x00000005, 11.0f, -1.60000002f, 0x00000000,
    1.0f, 0.200000003f, 0.200000003f, { 0x02, 0x00, 0x00, 0x02 },
    0x00000000, 0x00000000, 0x00000000,
    -9.0f, 6.51999998f, -13.1000004f
};

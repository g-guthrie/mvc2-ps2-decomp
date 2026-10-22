typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef struct {
    u16 u16_00;
    u16 u16_02;
    f32 f32_04;
    u32 u32_08;
    f32 f32_0C;
} Rec16;
typedef char Rec16_size_check[(sizeof(Rec16) == 16) ? 1 : -1];
Rec16 data_u32_0044308C = { 0x72, 0x01, 9.5f, 0x00000000, 0.0199999996f };

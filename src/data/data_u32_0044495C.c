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
    f32 f32_0C;
    u32 u32_10;
} Rec20;
typedef char Rec20_size_check[(sizeof(Rec20) == 20) ? 1 : -1];
Rec20 data_u32_0044495C = { 0x00000012, 15.0f, 30.0f, 15.0f, 0x00000000 };

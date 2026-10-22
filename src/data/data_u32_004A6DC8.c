typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u32 w0; f32 f1; u32 w2; u32 w3; s32 w4; u32 w5; } Rec24;
typedef char Rec24_size[(sizeof(Rec24)==24)?1:-1];
Rec24 data_u32_004A6DC8[1] = {
    { 0x00000000u, 1.0f, 0x00000002u, 0x00000405u, -1, 0x00000000u },
};

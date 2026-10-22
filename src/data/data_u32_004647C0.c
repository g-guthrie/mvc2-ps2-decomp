typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 b[16]; f32 v[16]; } Rec80a;
typedef char Rec80a_size[(sizeof(Rec80a)==80)?1:-1];
Rec80a data_u32_004647C0[1] = {
    {
        { 0x11, 0x10, 0x13, 0x10, 0x15, 0x10, 0x17, 0x0F, 0x16, 0x10, 0x14, 0x10, 0x12, 0x0F, 0x18, 0x0E },
        {
            640.0f, 68.5714264f, 693.333313f, 197.142853f, 566.666626f, 308.571411f, 466.666656f, 222.857132f,
            340.0f, 312.857147f, 260.0f, 351.428558f, 160.0f, 480.0f, 233.333328f, 338.571411f,
        },
    },
};

/* Four-word record: u32, f32, u32, f32. Field meanings not established by a reader yet. */
typedef unsigned int u32;
typedef struct Rec16 { u32 w0; float f1; u32 w2; float f3; } Rec16;
typedef char data_u32_004433C8_size_check[(sizeof(Rec16) == 16) ? 1 : -1];
Rec16 data_u32_004433C8[1] = {
    { 0x00000057u, 0.0f, 0x00000000u, 0.00999999978f },
};

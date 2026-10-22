/* Four-word record: u32, f32, u32, f32. Field meanings not established by a reader yet. */
typedef unsigned int u32;
typedef struct Rec16 { u32 w0; float f1; u32 w2; float f3; } Rec16;
typedef char data_u32_00442E6C_size_check[(sizeof(Rec16) == 16) ? 1 : -1];
Rec16 data_u32_00442E6C[1] = {
    { 0xFF040070u, 4.69999981f, 0x00000000u, 0.00999999978f },
};

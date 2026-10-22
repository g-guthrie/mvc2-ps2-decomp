/* Five-word record: u32, u32, f32, f32, f32. Field meanings not established by a reader yet. */
typedef unsigned int u32;
typedef struct Rec20 { u32 w0; u32 w1; float f2; float f3; float f4; } Rec20;
typedef char data_u32_00443768_size_check[(sizeof(Rec20) == 20) ? 1 : -1];
Rec20 data_u32_00443768[1] = {
    { 0x00000081u, 0x00000000u, -9.0f, 6.51999998f, -13.1000004f },
};

typedef unsigned int u32;
typedef float f32;
typedef struct {
    u32 a;
    f32 b;
    f32 c;
    u32 d;
    u32 e;
} Rec20;
typedef char Rec20_size_check[(sizeof(Rec20) == 20) ? 1 : -1];
Rec20 data_raw_004B27BC[1] = {
    { 0x00000000u, -6.8f, -4.0f, 0x00000000u, 0x00000000u }
};

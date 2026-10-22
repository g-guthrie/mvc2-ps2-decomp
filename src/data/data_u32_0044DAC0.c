typedef unsigned char u8;
typedef float f32;
typedef struct {
    u8 ids[14];
    u8 pad[2];
    f32 ratios[4];
} Palette32;
typedef char Palette32_size_check[(sizeof(Palette32) == 32) ? 1 : -1];
Palette32 data_u32_0044DAC0[1] = {
    { { 0x50u, 0x61u, 0x62u, 0x58u, 0x59u, 0x5Au, 0x5Bu, 0x5Cu, 0x5Du, 0x5Eu, 0x5Fu, 0x55u, 0x56u, 0x57u }, { 0x00u, 0x00u }, { 4.285714f, 3.2142856f, 2.6785712f, 2.142857f } }
};

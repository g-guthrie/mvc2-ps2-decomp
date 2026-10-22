typedef unsigned char u8;
typedef short s16;
typedef float f32;
/* lut_00 is read as s16 by index*2; rec_20 holds 8-byte entries read at +0x20 + index*8;
   flt_70 is the float tail. Layout inferred from its reader. */
typedef struct { s16 lut_00[16]; u8 rec_20[10][8]; f32 flt_70[56]; } Data0044E9D0;
typedef char Data0044E9D0_size_check[(sizeof(Data0044E9D0) == 336) ? 1 : -1];
Data0044E9D0 data_u32_0044E9D0 = {
    { 7, 7, 4, 3, 6, 6, 3, 3, 4, 0, 0, 0, 0, 0, 0, 0 },
    {
        { 0x16u, 0x16u, 0x16u, 0x16u, 0x16u, 0x16u, 0x16u, 0x16u },
        { 0x1Eu, 0x1Eu, 0x1Eu, 0x1Eu, 0x1Eu, 0x1Eu, 0x1Eu, 0x1Eu },
        { 0x35u, 0x35u, 0x35u, 0x35u, 0x35u, 0x35u, 0x35u, 0x35u },
        { 0x30u, 0x30u, 0x30u, 0x30u, 0x30u, 0x30u, 0x30u, 0x30u },
        { 0x25u, 0x25u, 0x25u, 0x25u, 0x25u, 0x25u, 0x25u, 0x25u },
        { 0x2Cu, 0x2Cu, 0x2Cu, 0x2Cu, 0x2Cu, 0x2Cu, 0x2Cu, 0x2Cu },
        { 0x42u, 0x42u, 0x42u, 0x42u, 0x42u, 0x42u, 0x42u, 0x42u },
        { 0x39u, 0x39u, 0x39u, 0x39u, 0x39u, 0x39u, 0x39u, 0x39u },
        { 0x3Eu, 0x3Eu, 0x3Eu, 0x3Eu, 0x3Eu, 0x3Eu, 0x3Eu, 0x3Eu },
        { 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u }
    },
    { -73.3333282f, -60.0f, -46.6666641f, 33.3333321f, 73.3333282f, 60.0f, 46.6666641f, -33.3333321f, 0.0f, -13.333333f, 0.0f, 13.333333f, 0.0f, 13.333333f, -13.333333f, 26.666666f, 80.0f, 66.6666641f, 53.3333321f, 40.0f, -80.0f, -66.6666641f, -53.3333321f, -40.0f, -13.333333f, 13.333333f, -66.6666641f, 33.3333321f, 26.666666f, 13.333333f, -13.333333f, -30.0f, 26.666666f, 13.333333f, -26.666666f, -40.0f, 68.5714264f, 68.5714264f, 85.7142792f, 68.5714264f, 102.85714f, 102.85714f, 85.7142792f, 51.4285698f, 120.0f, 0.0f, 0.0f, 0.0f, 6.42857122f, 0.133928567f, 6.42857122f, 0.401785702f, 10.7142849f, 0.267857134f, 12.8571424f, 0.401785702f }
};

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
/* Header (u16 pair, u8 index lists) followed by 60 f32 values. */
typedef struct {
    u16 dim[2];
    u32 pad0[3];
    u8 idx[40];
    u32 tail[2];
    f32 f[60];
} data_u32_0045E340_t;
typedef char data_u32_0045E340_size_check[(sizeof(data_u32_0045E340_t) == 304) ? 1 : -1];
data_u32_0045E340_t data_u32_0045E340 = {
    { 0x20, 0x10 },
    { 0u, 0u, 0u },
    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x08, 0x01, 0x03, 0x04, 0x06, 0x05, 0x02, 0x07, 0x08, 0x06, 0x05, 0x00, 0x07, 0x01, 0x03, 0x02, 0x08, 0x03, 0x06, 0x02, 0x04, 0x07, 0x01, 0x05, 0x08, 0x09, 0x0A, 0x02, 0x0C, 0x0D, 0x0E, 0x0F, 0x10 },
    { 8u, 0u },
    {
    -780.5f, 980.0f, -2200.0f, 1690.0f, 980.0f, -1580.5f,
    580.0f, 1800.0f, -7620.0f, 3020.0f, 1800.0f, -7000.0f,
    -1007.0f, 1020.0f, -2235.0f, 1596.0f, 1020.0f, -1820.0f,
    -88.0f, 1800.0f, -7742.0f, 2400.0f, 1800.0f, -7335.0f,
    -1000.0f, 500.0f, 200.0f, -200.0f, 500.0f, -3000.0f,
    900.0f, 600.0f, 200.0f, 1700.0f, 600.0f, -3000.0f,
    1000.0f, 700.0f, 200.0f, 1800.0f, 700.0f, -3000.0f,
    -1000.0f, 600.0f, 200.0f, -200.0f, 600.0f, -3000.0f,
    -550.0f, 750.0f, 200.0f, 350.0f, 750.0f, -3000.0f,
    1000.0f, 550.0f, 200.0f, 1800.0f, 550.0f, -3000.0f
    },
};

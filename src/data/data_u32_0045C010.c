typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
/* Four 16-byte records read at 0x0045C010, +0x10, +0x20, +0x30. Byte and halfword fields are not named by any reader. */
typedef struct { u8 b0, b1, b2, b3; u32 index; u16 h[4]; } Rec16;
typedef char Rec16_size_check[(sizeof(Rec16) == 16) ? 1 : -1];
Rec16 data_u32_0045C010[4] = {
    { 3, 0, 0, 0, 0, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 3, 0, 0, 0, 1, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 3, 0, 0, 145, 2, { 0x1000, 0x1400, 0x0400, 0x0300 } },
    { 3, 0, 0, 129, 3, { 0x1000, 0x1800, 0x0800, 0x0300 } },
};

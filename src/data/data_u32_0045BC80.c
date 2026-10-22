typedef unsigned char u8;
/* func_002F4CA0 indexes this table with a u16 index i as base + 3*i: byte +0 is passed on,
   byte +1 is stored to the state at 0x22, byte +2 is stored at 0x1B5 (or 0x46 if the
   state byte does not match). Records 3..4 are zero; one trailing byte closes the unit. */
typedef struct {
    u8 a;
    u8 b;
    u8 c;
} data_u32_0045BC80_rec;
typedef char data_u32_0045BC80_rec_size_check[(sizeof(data_u32_0045BC80_rec) == 3) ? 1 : -1];
typedef struct {
    data_u32_0045BC80_rec rec[5];
    u8 tail;
} data_u32_0045BC80_t;
typedef char data_u32_0045BC80_t_size_check[(sizeof(data_u32_0045BC80_t) == 16) ? 1 : -1];
data_u32_0045BC80_t data_u32_0045BC80 = {
    {
        { 0x2C, 0xC0, 0x39 },
        { 0x2B, 0xE0, 0x3A },
        { 0x2A, 0x00, 0x3B },
        { 0x00, 0x00, 0x00 },
        { 0x00, 0x00, 0x00 },
    },
    0x00,
};

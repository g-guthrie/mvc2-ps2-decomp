typedef unsigned char u8;
typedef unsigned short u16;
/* Triangle-wave byte selector (values 0..4). func_0019A880 indexes sel[] with 2 * tri[i]. */
typedef struct { u8 tri[16]; u16 sel[8]; } SelectorBlock32;
typedef char SelectorBlock32_size_check[(sizeof(SelectorBlock32) == 32) ? 1 : -1];
SelectorBlock32 data_u32_0044A7E0 = {
    { 0, 1, 1, 2, 2, 3, 3, 4, 4, 3, 3, 2, 2, 1, 1, 0 },
    { 0x4000u, 0x1F00u, 0x0000u, 0xE100u, 0xC000u, 0x0000u, 0x0000u, 0x0000u },
};

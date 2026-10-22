typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
/* Four leading zero bytes, then a u8 lookup indexed by (flags >> 10) & 0xF in func_00292D30. */
typedef struct Tab_0045796C {
    u32 pad;
    u8 tbl[16];
} Tab_0045796C;
typedef char Tab_0045796C_size_check[(sizeof(Tab_0045796C) == 20) ? 1 : -1];
Tab_0045796C data_u32_0045796C = { 0x00000000u, { 0xFF, 0x08, 0x18, 0x08, 0x10, 0x0C, 0x14, 0x0C, 0x00, 0x04, 0x1C, 0x04, 0x00, 0x04, 0x1C, 0x04 } };

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;
/* Input-pattern records handed to func_00189310(p, record, ...): kind byte (index
   into a handler table), u16 flag word, owner byte, then u16 button masks. */
typedef struct { u8 kind; u8 pad1; u16 flags; u8 owner; u8 pad5[3]; u16 mask[4]; } InputRec16;
typedef struct { u8 kind; u8 pad1; u16 flags; u8 owner; u8 pad5[3]; u16 mask[6]; u8 pad[12]; } InputRec32;
typedef char InputRec16_size_check[(sizeof(InputRec16) == 16) ? 1 : -1];
typedef char InputRec32_size_check[(sizeof(InputRec32) == 32) ? 1 : -1];
/* s8 move rows (4 bytes each, D_0045A620) read as signed char via p+0x408, then input-pattern records. */
struct {
    s8 pad0[8];
    s8 move[6][4];
    s8 pad1[8];
    InputRec16 r0;
    InputRec16 r1;
    InputRec16 r2;
    InputRec32 r3;
    InputRec32 r4;
} data_u32_0045A618 = {
    { 0 },
    {
        { 1, 2, 0, 2 },
        { -1, 2, 1, 2 },
        { -1, -1, -1, 2 },
        { 1, 2, 1, 2 },
        { -1, 2, -1, 2 },
        { -1, -1, -1, -1 }
    },
    { 0 },
    { 0x03, 0, 0x1000, 0, { 0, 0, 0 }, { 0x0800, 0x1800, 0x1000, 0x0300 } },
    { 0x03, 0, 0x9100, 1, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x03, 0, 0x9000, 2, { 0, 0, 0 }, { 0x0800, 0x1000, 0x1800, 0x0300 } },
    { 0x05, 0, 0x1000, 3, { 0, 0, 0 }, { 0x0400, 0x1400, 0x1000, 0x1800, 0x0800, 0x0300 }, { 0 } },
    { 0x05, 0, 0x0000, 7, { 0, 0, 0 }, { 0x0400, 0x1400, 0x1000, 0x1800, 0x0800, 0x0060 }, { 0 } },
};
typedef char data_u32_0045A618_size_check[(sizeof(data_u32_0045A618) == 152) ? 1 : -1];

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
/* First 192 bytes: six 32-byte s16 blocks (func_002BFA70 copies block [p[0x25]] as 16 halfwords);
   the rest are input-pattern records (D_00459840..D_00459900). */
struct {
    s16 block[6][16];
    InputRec16 r0;
    InputRec32 r1;
    InputRec32 r2;
    InputRec16 r3;
    InputRec16 r4;
    InputRec16 r5;
    InputRec16 r6;
    InputRec16 r7;
    InputRec16 r8;
    InputRec16 r9;
    InputRec32 r10;
} data_u32_00459780 = {
    {
        { 0, -3823, -38, -72, -362, -924, -1982, -2784, -160, -704, -992, -1776, -2304, -176, -5, -16 },
        { 0, -3823, -38, -72, -362, -924, -1982, -2784, -2353, -2388, -2935, -3482, -4028, -176, -5, -16 },
        { 0, -3823, -38, -89, -907, -2221, -3021, -3823, -160, -704, -992, -1776, -2304, -176, -5, -16 },
        { 0, -3823, -38, -89, -907, -2221, -3021, -3823, -2353, -2388, -2935, -3482, -4028, -2785, -5, -16 },
        { 0, -3823, -39, -107, -665, -1466, -2524, -2781, -160, -704, -992, -1776, -2304, -492, -5, -160 },
        { 0, -3823, -925, -1725, -2525, -3053, -3325, -3836, -2353, -2388, -2935, -3482, -4028, -208, -619, -246 }
    },
    { 0x03, 0, 0x0000, 0, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x05, 0, 0x1000, 1, { 0, 0, 0 }, { 0x0800, 0x1800, 0x1000, 0x1400, 0x0400, 0x0300 }, { 0 } },
    { 0x05, 0, 0x1000, 2, { 0, 0, 0 }, { 0x0800, 0x1800, 0x1000, 0x1400, 0x0400, 0x0060 }, { 0 } },
    { 0x03, 0, 0x8000, 3, { 0, 0, 0 }, { 0x0800, 0x1000, 0x1800, 0x0300 } },
    { 0x03, 0, 0x8000, 3, { 0, 0, 0 }, { 0x0400, 0x1000, 0x1400, 0x0300 } },
    { 0x03, 0, 0x8000, 3, { 0, 0, 0 }, { 0x0800, 0x1000, 0x1800, 0x0060 } },
    { 0x03, 0, 0x8000, 3, { 0, 0, 0 }, { 0x0400, 0x1000, 0x1400, 0x0060 } },
    { 0x03, 0, 0x8100, 5, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x03, 0, 0x9100, 6, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 0x03, 0, 0x8000, 4, { 0, 0, 0 }, { 0x1000, 0x1400, 0x0400, 0x0060 } },
    { 0x05, 0, 0x1000, 0, { 0, 0, 0 }, { 0x0800, 0x1800, 0x1000, 0x1400, 0x0400, 0x0100 }, { 0 } },
};
typedef char data_u32_00459780_size_check[(sizeof(data_u32_00459780) == 416) ? 1 : -1];

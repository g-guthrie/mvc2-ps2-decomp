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
struct {
    InputRec16 r0;
    InputRec32 r1;
    InputRec32 r2;
    InputRec16 r3;
    InputRec16 r4;
    InputRec16 r5;
} data_u32_0045A890 = {
    { 0x03, 0, 0x0000, 0, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 0x05, 0, 0x0000, 6, { 0, 0, 0 }, { 0x0800, 0x1800, 0x1000, 0x1400, 0x0400, 0x0060 }, { 0 } },
    { 0x05, 0, 0x8100, 1, { 0, 0, 0 }, { 0x0400, 0x1400, 0x1000, 0x1800, 0x0800, 0x0300 }, { 0 } },
    { 0x03, 0, 0x8000, 3, { 0, 0, 0 }, { 0x1000, 0x1400, 0x0400, 0x0060 } },
    { 0x03, 0, 0x9100, 5, { 0, 0, 0 }, { 0x1000, 0x1400, 0x0400, 0x0300 } },
    { 0x03, 0, 0x2000, 12, { 0, 0, 0 }, { 0x1000, 0x1400, 0x0400, 0x0300 } },
};
typedef char data_u32_0045A890_size_check[(sizeof(data_u32_0045A890) == 128) ? 1 : -1];

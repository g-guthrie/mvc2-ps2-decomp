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
/* sel: s32 pairs indexed [p[0x20D]][p[0x212]] (func_002DBD20); pos: f32 triples passed to func_0015D010 (func_002DBDB0). */
struct {
    u8 pad0[12];
    s32 sel[4][2];
    f32 pos[4][3];
    InputRec16 r0;
    InputRec32 r1;
    InputRec32 r2;
    InputRec32 r3;
    InputRec16 r4;
    InputRec16 r5;
} data_u32_0045AB24 = {
    { 0 },
    { { 2, 1 }, { 0, 0 }, { 2, 0 }, { 0, 0 } },
    { { -80.0f, 188.571426f, 0.0f }, { 0.0f, 188.571426f, 0.0f }, { 0.0f, 0.0f, -30.0f }, { 0.0f, -43.3333321f, 0.0f } },
    { 0x03, 0, 0x1000, 0, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x05, 0, 0x1000, 1, { 0, 0, 0 }, { 0x0800, 0x1800, 0x1000, 0x1400, 0x0400, 0x0060 }, { 0 } },
    { 0x05, 0, 0x1000, 2, { 0, 0, 0 }, { 0x0800, 0x1800, 0x1000, 0x1400, 0x0400, 0x0300 }, { 0 } },
    { 0x05, 0, 0x9100, 4, { 0, 0, 0 }, { 0x0800, 0x1800, 0x1000, 0x1400, 0x0400, 0x0060 }, { 0 } },
    { 0x03, 0, 0x9100, 3, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x03, 0, 0x9100, 5, { 0, 0, 0 }, { 0x0800, 0x1000, 0x1800, 0x0300 } },
};
typedef char data_u32_0045AB24_size_check[(sizeof(data_u32_0045AB24) == 236) ? 1 : -1];

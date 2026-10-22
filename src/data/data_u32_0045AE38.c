typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

/* Spans D_0045AE20 tail, D_0045AE40 (s8 pairs, meaning not seen in code) and the records D_0045AE60..D_0045AEF0 passed to func_00189310 (same record shape as D_00448EE0). Fields beyond flags/id are guesses. */
typedef struct InputRec16 {
    u8 b0;
    u8 b1;
    u16 flags;
    u8 id;
    u8 b5;
    u8 b6;
    u8 b7;
    u16 seq[4];
} InputRec16;
typedef char InputRec16_size_check[(sizeof(InputRec16) == 16) ? 1 : -1];
typedef struct InputRec32 {
    u8 b0;
    u8 b1;
    u16 flags;
    u8 id;
    u8 b5;
    u8 b6;
    u8 b7;
    u16 seq[12];
} InputRec32;
typedef char InputRec32_size_check[(sizeof(InputRec32) == 32) ? 1 : -1];

typedef struct Data0045AE38 {
    s8 sel[40];
    InputRec32 r0;
    InputRec32 r1;
    InputRec16 r2;
    InputRec16 r3;
    InputRec16 r4;
    InputRec32 r5;
    InputRec16 r6;
} Data0045AE38;
typedef char Data0045AE38_size_check[(sizeof(Data0045AE38) == 200) ? 1 : -1];

Data0045AE38 data_u32_0045AE38 = {
    {
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 2, 0, 2, -1, 2, 1, 2,
    -1, -1, -1, 2, 1, 2, 1, 2,
    -1, 2, -1, 2, -1, -1, -1, -1,
    0, 0, 0, 0, 0, 0, 0, 0
    },
    { 5, 0, 0x0000, 0, 0, 0, 0, { 0x0400, 0x1400, 0x1000, 0x1800, 0x0800, 0x0300, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 } },
    { 5, 0, 0x0000, 1, 0, 0, 0, { 0x0800, 0x1800, 0x1000, 0x1400, 0x0400, 0x0060, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 } },
    { 3, 0, 0x9100, 2, 0, 0, 0, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 3, 0, 0x8100, 3, 0, 0, 0, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 3, 0, 0x8000, 4, 0, 0, 0, { 0x1000, 0x1400, 0x0400, 0x0060 } },
    { 5, 0, 0x1000, 8, 0, 0, 0, { 0x0400, 0x1400, 0x1000, 0x1800, 0x0800, 0x0060, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 } },
    { 3, 0, 0x2000, 7, 0, 0, 0, { 0x2000, 0x2800, 0x0800, 0x0300 } }
};

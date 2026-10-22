typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

/* Input/move records passed as arg to func_00189310 from func_00188430: lbu rec+4 is compared with obj+0x45C, lhu rec+2 holds flag bits (0x4000/0x20/0x800/0x100/0x2000/0x1000 tested in func_0018A460); the u8 count/ b-bytes and seq[] are guesses. */
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

InputRec16 data_u32_00448EE0[3] = {
    { 3, 0, 0x4000, 0, 0, 0, 0, { 0x0400, 0x1400, 0x1000, 0x0360 } },
    { 3, 0, 0x1800, 125, 0, 0, 0, { 0x0400, 0x1400, 0x1000, 0x0090 } },
    { 3, 0, 0x1000, 124, 0, 0, 0, { 0x1000, 0x1800, 0x0800, 0x0090 } },
};

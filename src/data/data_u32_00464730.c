typedef unsigned char u8;
/* Byte values read with lbu at word stride indexed by the actor's byte at +0x21 (func_00384D60). */
typedef struct { u8 value; u8 pad[3]; } Byte4;
typedef char Byte4_size_check[(sizeof(Byte4) == 4) ? 1 : -1];
Byte4 data_u32_00464730[4] = { { 4 }, { 5 }, { 6 }, { 7 } };

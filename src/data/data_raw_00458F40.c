typedef unsigned int u32;
/* Third mask word and zero pad of the 32-byte (kind 4) transition record at 00458F30. */
typedef struct { u32 w2; u32 pad[3]; } TransRecTail;
typedef char TransRecTail_size_check[(sizeof(TransRecTail) == 16) ? 1 : -1];
TransRecTail data_raw_00458F40 = { 0x00000200u, {0,0,0} };

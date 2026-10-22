typedef unsigned char u8;
/* Descriptor +4..+7: func_00189310 compares the byte at +4 (lbu) with the owner at actor+0x45C; +5..+7 are never read. */
typedef struct { u8 ownerTag; u8 unused[3]; } InteractionOwnerTag;
typedef char InteractionOwnerTag_size_check[(sizeof(InteractionOwnerTag) == 4) ? 1 : -1];
InteractionOwnerTag data_raw_0044F284 = { 2, { 0, 0, 0 } };

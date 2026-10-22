typedef unsigned char u8;
/* State tag at +4 of a transition record (compared with the actor byte at
   +0x45C by func_00189310); bytes +5..+7 are zero. */
typedef struct { u8 tag; u8 pad[3]; } TransTag;
typedef char TransTag_size_check[(sizeof(TransTag) == 4) ? 1 : -1];
TransTag data_raw_00458E94 = { 0x02, {0,0,0} };

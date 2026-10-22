typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
/* Four small tables packed together (each has its own reader):
   slot_map     lb-indexed by the u8 at +0x20 of the actor (func_00147D20)
   seq_a/seq_b  5-byte arrays copied to the stack and read with lb (func_001489E0)
   word_id      lhu-indexed by 2*player (func_00149820 stores it into +0xCC) */
typedef struct {
    s8  slot_map[8];
    s8  seq_a[5];
    u8  pad_a[3];
    s8  seq_b[5];
    u8  pad_b[3];
    u16 word_id[4];
} ActorSmallTables;
typedef char ActorSmallTables_size_check[(sizeof(ActorSmallTables) == 32) ? 1 : -1];
ActorSmallTables data_u32_004BF3A0 = {
    { -1, 0, -1, 1, 2, -1, -1, 0 },
    { 0, 2, 3, 4, 1 }, { 0, 0, 0 },
    { 3, 2, 1, 0, 4 }, { 0, 0, 0 },
    { 0x0000, 0x013C, 0x013D, 0x0000 },
};

/* Per-index flag table read as u32 at stride 8 from D_004A6D54 (func at
   0x0041B42C / 0x0041B910: bits 0x1/0x2/0x4/0x8 select optional 0x10-byte
   blocks). The leading word and the second field of each record are not read
   by the visible readers; their meaning is a guess ("aux"). */
typedef unsigned int u32;
typedef struct { u32 flags; u32 aux; } FlagRec;
typedef struct { u32 lead; FlagRec rec[10]; } FlagTable;
typedef char FlagTable_size_check[(sizeof(FlagTable) == 84) ? 1 : -1];
FlagTable data_u8_004A6D50 = {
    0x30,
    {
        { 0x0B, 0x40 }, { 0x0F, 0x20 }, { 0x03, 0x30 }, { 0x07, 0x20 }, { 0x09, 0x30 },
        { 0x0D, 0x10 }, { 0x01, 0x20 }, { 0x05, 0x50 }, { 0x3B, 0x60 }, { 0x3F, 0x00 },
    }
};

typedef unsigned int u32;
typedef unsigned short u16;
/* Leading zero word, then twelve 16-byte records. The second word is the record index (0..11). */
typedef struct { u32 tag; u32 index; u16 a[2]; u16 b[2]; } D004551CC_Rec;
typedef char D004551CC_Rec_size_check[(sizeof(D004551CC_Rec) == 16) ? 1 : -1];
typedef struct { u32 lead; D004551CC_Rec rec[12]; } D004551CC_Table;
typedef char D004551CC_Table_size_check[(sizeof(D004551CC_Table) == 196) ? 1 : -1];
D004551CC_Table data_u32_004551CC = {
    0u,
    {
        { 0x11000003u, 0u, { 0x1000u, 0x1800u }, { 0x0800u, 0x0200u } },
        { 0x10000003u, 1u, { 0x1000u, 0x1800u }, { 0x0800u, 0x0100u } },
        { 0x10000003u, 2u, { 0x1000u, 0x1800u }, { 0x0800u, 0x0040u } },
        { 0x10000003u, 3u, { 0x1000u, 0x1800u }, { 0x0800u, 0x0020u } },
        { 0x10000003u, 4u, { 0x1000u, 0x1400u }, { 0x0400u, 0x0200u } },
        { 0x10000003u, 5u, { 0x1000u, 0x1400u }, { 0x0400u, 0x0100u } },
        { 0x10000003u, 6u, { 0x1000u, 0x1400u }, { 0x0400u, 0x0020u } },
        { 0x10000003u, 7u, { 0x0800u, 0x1800u }, { 0x1000u, 0x0200u } },
        { 0x10000003u, 8u, { 0x0800u, 0x1800u }, { 0x1000u, 0x0100u } },
        { 0x10000003u, 9u, { 0x0800u, 0x1800u }, { 0x1000u, 0x0040u } },
        { 0x10000003u, 10u, { 0x0800u, 0x1800u }, { 0x1000u, 0x0020u } },
        { 0x10000003u, 11u, { 0x0800u, 0x1000u }, { 0x1800u, 0x0200u } },
    }
};

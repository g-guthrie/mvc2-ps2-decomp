typedef unsigned int u32;

/* Four-word header, then eleven 16-byte records. Passed as D_00455C00 to func_0018A160. */
typedef struct {
    u32 word0;
    u32 word1;
    u32 word2;
    u32 word3;
} Data455C00Record;

typedef struct {
    u32 header[4];
    Data455C00Record records[11];
} Data455C00Table;

typedef char Data455C00Record_size_check[(sizeof(Data455C00Record) == 16) ? 1 : -1];
typedef char Data455C00Table_size_check[(sizeof(Data455C00Table) == 192) ? 1 : -1];

Data455C00Table data_raw_00455C00 = {
    { 0x00000058u, 0x00000000u, 0x00000100u, 0x00000000u },
    {
        { 0x00000003u, 0x00000002u, 0x10000800u, 0x03001800u },
        { 0x81000003u, 0x00000007u, 0x18001000u, 0x03000800u },
        { 0x91000003u, 0x00000004u, 0x18001000u, 0x00600800u },
        { 0x81000003u, 0x00000005u, 0x14001000u, 0x00600400u },
        { 0x00000003u, 0x00000006u, 0x18001000u, 0x03000800u },
        { 0x10000003u, 0x0000000Cu, 0x18001000u, 0x00600800u },
        { 0x10000003u, 0x0000000Cu, 0x10000800u, 0x00601800u },
        { 0x10000003u, 0x0000000Cu, 0x14001000u, 0x00600400u },
        { 0x01380201u, 0x00000001u, 0x01000201u, 0x00000001u },
        { 0x01070001u, 0x00000001u, 0x01460001u, 0x00000001u },
        { 0x013D0101u, 0x00000001u, 0x014C0201u, 0x00000001u },
    },
};

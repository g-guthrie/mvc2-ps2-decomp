typedef unsigned int u32;

/* Leading u32 word, then ten 16-byte records. Layout inferred from the bytes. */
typedef struct {
    u32 word0;
    u32 word1;
    u32 word2;
    u32 word3;
} Data45A2DCRecord;

typedef struct {
    u32 header;
    Data45A2DCRecord records[10];
} Data45A2DCTable;

typedef char Data45A2DCRecord_size_check[(sizeof(Data45A2DCRecord) == 16) ? 1 : -1];
typedef char Data45A2DCTable_size_check[(sizeof(Data45A2DCTable) == 164) ? 1 : -1];

Data45A2DCTable data_u32_0045A2DC = {
    0x00000000u,
    {
        { 0x10000003u, 0x00000001u, 0x18001000u, 0x03000800u },
        { 0x20000003u, 0x00000009u, 0x18001000u, 0x03000800u },
        { 0x10000003u, 0x00000002u, 0x14001000u, 0x03000400u },
        { 0x10000003u, 0x00000003u, 0x10000800u, 0x03001800u },
        { 0x90000003u, 0x00000008u, 0x10000800u, 0x01401800u },
        { 0x10000028u, 0x00000004u, 0x20001000u, 0x00000060u },
        { 0x10000028u, 0x00000007u, 0x20001000u, 0x00000300u },
        { 0x91000003u, 0x00000005u, 0x18001000u, 0x03000800u },
        { 0x91000003u, 0x0000000Au, 0x14001000u, 0x00600400u },
        { 0x91000003u, 0x0000000Eu, 0x18001000u, 0x00600800u },
    },
};

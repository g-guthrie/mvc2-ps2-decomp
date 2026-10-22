typedef unsigned int u32;
typedef struct { u32 key; u32 ram_addr; } RamAddrEntry;
typedef char RamAddrEntry_size_check[(sizeof(RamAddrEntry) == 8) ? 1 : -1];
/* Key / runtime (0x80...) address pairs; the addresses are not image symbols. */
RamAddrEntry data_u32_00438630[6] = {
    { 0x00000056u, 0x800750C8u },
    { 0x00000057u, 0x80075108u },
    { 0x00000058u, 0x80075158u },
    { 0x00000059u, 0x800751A8u },
    { 0x00000003u, 0x80075330u },
    { 0x00000000u, 0x00000000u },
};

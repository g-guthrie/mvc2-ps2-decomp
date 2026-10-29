typedef unsigned int u32;
typedef struct { u32 key; u32 ram_addr; } RamAddrEntry;
typedef char RamAddrEntry_size_check[(sizeof(RamAddrEntry) == 8) ? 1 : -1];
/* Lookup table of the TLB kernel-patch image: func_0010C2F8 copies 0x330 bytes from
 * D_00438328 to 0x80075000, so this is runtime 0x80075300..0x80075330. The patch routine at
 * 0x80075000 scans it (addiu 0x5300, stride 8, sltiu 6) and returns ram_addr for a
 * matching key. Key / runtime (0x80...) address pairs; the addresses are not image symbols. */
RamAddrEntry data_u32_00438628[6] = {
    { 0x00000055u, 0x80075038u },
    { 0x00000056u, 0x800750C8u },
    { 0x00000057u, 0x80075108u },
    { 0x00000058u, 0x80075158u },
    { 0x00000059u, 0x800751A8u },
    { 0x00000003u, 0x80075330u },
};

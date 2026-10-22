typedef unsigned int u32;
/* Name-format block: word 0 is 0x45, word 1 zero, then the 8-byte format string "PLAYER%d". */
typedef struct {
    u32 id_00;
    u32 zero_04;
    char fmt_08[8];
} data_u32_004B9360_t;
typedef char data_u32_004B9360_size_check[(sizeof(data_u32_004B9360_t) == 16) ? 1 : -1];

data_u32_004B9360_t data_u32_004B9360 = {
    0x45u, 0u, { 'P', 'L', 'A', 'Y', 'E', 'R', '%', 'd' },
};

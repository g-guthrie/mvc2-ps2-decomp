typedef unsigned int u32;
typedef struct {
    u32 zero_00[2];
    char tag[8];
} data_u32_00489800_t;
typedef char data_u32_00489800_size_check[(sizeof(data_u32_00489800_t) == 16) ? 1 : -1];

/* Two zero words, then the 8-byte tag "MARK:lsc". */
data_u32_00489800_t data_u32_00489800 = {
    { 0u, 0u },
    { 'M', 'A', 'R', 'K', ':', 'l', 's', 'c' },
};

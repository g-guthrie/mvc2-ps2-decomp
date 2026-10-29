typedef unsigned int u32;
typedef struct {
    u32 zero_00[2];
    char tag[12];
} data_u32_00489800_t;
typedef char data_u32_00489800_size_check[(sizeof(data_u32_00489800_t) == 20) ? 1 : -1];

/* Two zero words, then the tag "MARK:lsc_obj". The tag runs to its NUL, which is the first
 * byte of the zero region data_zero_00489814. */
data_u32_00489800_t data_u32_00489800 = {
    { 0u, 0u },
    { 'M', 'A', 'R', 'K', ':', 'l', 's', 'c', '_', 'o', 'b', 'j' },
};

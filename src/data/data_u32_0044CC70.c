typedef unsigned short u16;
typedef unsigned int u32;
/* Six 8-byte entries: a halfword pair, then a u32 that is 1 for the first five entries
 * and 0 for the last. */
typedef struct {
    u16 a;
    u16 b;
    u32 c;
} data_u32_0044CC70_ent_t;
typedef char data_u32_0044CC70_size_check[(sizeof(data_u32_0044CC70_ent_t) == 8) ? 1 : -1];

data_u32_0044CC70_ent_t data_u32_0044CC70[6] = {
    { 0x0104, 0x0113, 1 },
    { 0x0104, 0x0112, 1 },
    { 0x0104, 0x0111, 1 },
    { 0x0104, 0x0110, 1 },
    { 0x0104, 0x010F, 1 },
    { 0x0110, 0x010E, 0 },
};

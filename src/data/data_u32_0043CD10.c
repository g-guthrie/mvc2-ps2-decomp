typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern char lbl_0012D300[];

/* Tail of D_0043CD0C, then the float table D_0043CD18 (indexed by a halfword
   in the actor at 0xC, read via lwc1), the u32 table D_0043CD30 and the two
   byte tables D_0043CD60 / D_0043CD80. */
typedef struct {
    void *link;        /* 0x0043CD10 */
    u32 zero;
    f32 offset[6];     /* -7.5, 0, 7.5, 0, 0, 0 */
    u32 mode[12];
    u8 remap[32];
    u8 order[32];
} data_u32_0043CD10_t;
typedef char data_u32_0043CD10_size_check[(sizeof(data_u32_0043CD10_t) == 144) ? 1 : -1];

data_u32_0043CD10_t data_u32_0043CD10 = {
    (void *)lbl_0012D300, 0,
    { -7.5f, 0.0f, 7.5f, 0.0f, 0.0f, 0.0f },
    { 2, 0, 1, 0, 1, 2, 0, 1, 0, 1, 0, 0 },
    { 0x07, 0x2D, 0x30, 0x2A, 0x1C, 0x1D, 0x38, 0x1B, 0x1F, 0x1E, 0x37, 0x03, 0x28, 0x2F, 0x29, 0x2C,
      0x32, 0x35, 0x2B, 0x31, 0x27, 0x21, 0x25, 0x26, 0x2E, 0x33, 0x36, 0x34, 0x23, 0x24, 0x20, 0x3A },
    { 0, 1, 2, 3, 4, 5, 1, 3, 5, 0, 2, 4, 0, 2, 4, 1, 3, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
extern u32 lbl_00326690[];
typedef struct {
    const void *p;
    u32 pad0[3];
    u8 a[12];
    u32 z0;
    u8 b[12];
    u32 z1;
    u8 c[12];
    u32 z2;
    u32 pad1[2];
    u32 one;
    u32 z3;
} data_u32_0045DE60_t;
typedef char data_u32_0045DE60_size_check[(sizeof(data_u32_0045DE60_t) == 80) ? 1 : -1];
data_u32_0045DE60_t data_u32_0045DE60 = {
    lbl_00326690,
    { 0u, 0u, 0u },
    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B }, 0u,
    { 0x00, 0x01, 0x02, 0x00, 0x01, 0x02, 0x00, 0x01, 0x02, 0x00, 0x01, 0x02 }, 0u,
    { 0x07, 0x07, 0x07, 0x08, 0x08, 0x08, 0x09, 0x09, 0x09, 0x0A, 0x0A, 0x0A }, 0u,
    { 0u, 0u }, 1u, 0u,
};

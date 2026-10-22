typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct {
    u32 a;
    u32 b;
    u16 c[4];
} T004544F0;
typedef char T004544F0_size_check[(sizeof(T004544F0) == 16) ? 1 : -1];
T004544F0 data_u32_004544F0[6] = {
    { 0x10000003u, 0x00000000u, { 0x1000, 0x1400, 0x0400, 0x0060 } },
    { 0x10000003u, 0x00000008u, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 0x10000003u, 0x00000001u, { 0x1000, 0x1400, 0x0400, 0x0300 } },
    { 0x00000003u, 0x00000002u, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x91000003u, 0x00000003u, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 0x91000003u, 0x00000005u, { 0x1000, 0x1400, 0x0400, 0x0300 } },
};

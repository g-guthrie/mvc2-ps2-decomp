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
} T0045D020;
typedef char T0045D020_size_check[(sizeof(T0045D020) == 16) ? 1 : -1];
T0045D020 data_u32_0045D020[6] = {
    { 0x00000003u, 0x00000000u, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x10000003u, 0x00000001u, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 0x91000003u, 0x00000002u, { 0x1000, 0x1400, 0x0400, 0x0300 } },
    { 0x91000003u, 0x00000006u, { 0x1000, 0x1400, 0x0400, 0x0060 } },
    { 0x91000003u, 0x00000003u, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 0x91000003u, 0x00000004u, { 0x1000, 0x1800, 0x0800, 0x0300 } },
};

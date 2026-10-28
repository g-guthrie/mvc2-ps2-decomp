typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* No reader found for the block as a whole; layout derived from the bytes.
 * Trimmed from the former data_u32_00443E50: its first 0x14 bytes are
 * D_00443E40[1..2] and its last 0x18 bytes belong to D_00443FF0. */
typedef struct { f32 x, y, z; } Vec3f;
typedef struct { f32 x, y, z; u32 pad; } Vec3fPad;
typedef struct {
    u32 lead;
    Vec3fPad rec[2];
    u32 mid[2];
    u8 map[56];
    u32 gap[2];
    f32 wave[7];
    u32 wave_pad;
    u32 ids[8];
    Vec3f keys[13];
    u32 tail[5];
    Vec3f keys2[4];
} Data00443E64;
typedef char data_00443E64_size_check[(sizeof(Data00443E64) == 0x18C) ? 1 : -1];
Data00443E64 data_u32_00443E64 = {
    0x00000000u,
    {{0.5f, 0.649999976f, 1.0f, 0x00000000u}, {4.0f, 0.949999988f, -12.6899996f, 0x00000000u}},
    {0x00000000u, 0x00000000u},
    {0x17u, 0x16u, 0x06u, 0x0Bu, 0x08u, 0x0Au, 0x0Fu, 0x39u, 0x09u, 0x0Cu, 0x0Du, 0x0Eu, 0x11u, 0x10u, 0x13u, 0x14u, 0x15u, 0x12u, 0x22u, 0x05u, 0x02u, 0x00u, 0x01u, 0x04u, 0x2Fu, 0x28u, 0x29u, 0x2Cu, 0x2Du, 0x2Au, 0x07u, 0x30u, 0x1Fu, 0x1Eu, 0x37u, 0x03u, 0x1Cu, 0x1Du, 0x38u, 0x1Bu, 0x2Bu, 0x35u, 0x31u, 0x32u, 0x2Eu, 0x33u, 0x36u, 0x34u, 0x27u, 0x21u, 0x25u, 0x26u, 0x23u, 0x24u, 0x20u, 0x3Au},
    {0x00000000u, 0x00000000u},
    {-1.5f, -2.20000005f, -2.9000001f, -3.5999999f, -4.30000019f, -5.0f, -5.69999981f},
    0x00000000u,
    {0x000000A7u, 0x000000A8u, 0x0000003Au, 0x000000CBu, 0x00000025u, 0x00000025u, 0x00000000u, 0x00000000u},
    {{6.0f, 1.79999995f, -13.0f}, {0.0f, 0.0f, 0.0f}, {4.69999981f, 4.5f, -12.8800001f}, {6.0f, 3.29999995f, -12.8000002f}, {7.30000019f, 4.19999981f, -12.8000002f}, {6.5f, 4.19999981f, -12.8000002f}, {0.0f, 0.0f, 6.0f}, {-1.20000005f, -13.0f, 0.0f}, {-3.0f, 0.0f, 4.69999981f}, {1.5f, -12.8800001f, 6.0f}, {0.300000012f, -12.8000002f, 7.30000019f}, {1.29999995f, -12.8000002f, 6.5f}, {1.29999995f, -12.8000002f, 0.0f}},
    {0x00000000u, 0x00000003u, 0x00000004u, 0x000000A9u, 0x000000B4u},
    {{6.05000019f, -7.6500001f, -13.1000004f}, {6.0f, -7.5999999f, -13.0f}, {5.19999981f, -6.46000004f, -11.0f}, {0.0f, 0.0f, 0.0f}}
};

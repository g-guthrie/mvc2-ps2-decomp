typedef unsigned int u32;
typedef struct {
    u32 w0;
    u32 w1;
    u32 w2;
    u32 w3;
    u32 w4;
    float xy[4][2];
} data_u32_004B829C_rec;
typedef char data_u32_004B829C_size_check[(sizeof(data_u32_004B829C_rec) == 52) ? 1 : -1];
data_u32_004B829C_rec data_u32_004B829C = {
    0x00000000u, 0x00000190u, 0x00000258u, 0x00000000u, 0x00000000u,
    {
        {-165.3f, 836.0f},
        {-903.0f, -194.0f},
        {343.5f, -8.7e+02f},
        {-1354.9f, -2250.9f},
    },
};

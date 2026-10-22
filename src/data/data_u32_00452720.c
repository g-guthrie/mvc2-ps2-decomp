typedef unsigned int u32;
typedef signed int s32;
/* 16-byte records of 16.16 fixed-point motion components, read by func_0023CF30
 * (index = p[0x21]*2 + p[0x20]): vx, ax, vy, ay. */
typedef struct { s32 vx; s32 ax; s32 vy; s32 ay; } data_u32_00452720_rec;
typedef char data_u32_00452720_rec_size_check[(sizeof(data_u32_00452720_rec) == 16) ? 1 : -1];
data_u32_00452720_rec data_u32_00452720[6] = {
    {-393216, 8192, 0, 0},
    {-655360, 8192, 0, 0},
    {-393216, 8192, 524288, -18432},
    {-655360, 8192, 917504, -18432},
    {0, 0, 524288, -18432},
    {0, 0, 917504, -18432}
};

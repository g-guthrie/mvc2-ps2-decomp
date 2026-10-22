typedef int s32;
/* Values are 16.16 fixed point (0x00010000 = 1.0). */
typedef struct { s32 v_00; s32 v_04; s32 v_08; s32 v_0C; } Fixed16x4;
typedef char Fixed16x4_size_check[(sizeof(Fixed16x4) == 16) ? 1 : -1];
Fixed16x4 data_u32_0044F8A0[2] = {
    { 0x00038000, 0x00000000, 0x000C8000, 0xFFFF4000 },
    { 0x00050000, 0x00000000, 0x000D0000, 0xFFFF6000 }
};

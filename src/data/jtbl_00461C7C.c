typedef short s16;

/* One of the s16 offset tables (rows of 0x14 bytes) reached through the D_00461D10
   pointer table; read with lh at table + (index & 0x1F) * 2 by func_0015E6C0. */
const s16 jtbl_00461C7C[10] = {
    18, 21, 24, 27, 30, 33, 36, 39, 42, 45,
};
typedef char jtbl_00461C7C_size_check[(sizeof(jtbl_00461C7C) == 20) ? 1 : -1];

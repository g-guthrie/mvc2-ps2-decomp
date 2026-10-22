typedef signed char s8;
typedef signed short s16;
/* Two gp-relative tables. func_003B5B30 reads byteTable[p[0x21]] as a signed
 * byte, and func_003B60A0 (src/h5b.c) reads halfTable[p[0x21]] as s16. */
typedef struct {
    s8 byteTable[8];
    s16 halfTable[4];
} GpTables16;

typedef char GpTables16_size_check[(sizeof(GpTables16) == 16) ? 1 : -1];

GpTables16 data_u32_004C2000 = { { 0, 4, 8, 0, 0, 0, 0, 0 }, { 1, 2, 3, 0 } };

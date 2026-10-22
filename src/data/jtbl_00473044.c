typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

/* Middle of the 8-byte {s16 x, s16 y, s16 flag, s16 id} record table at D_00473040 (lh at +0/+2/+4/+6, index*8 in func_003A8ED0 family); this unit starts at the id field of one record. */
const s16 jtbl_00473044[12] = {
    0, 21, 48, 48, 0, 22, 0, 56,
    0, 23, 48, 40,
};

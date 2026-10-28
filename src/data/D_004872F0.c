/* 0x38-byte runtime state block: func_00407BC0 memsets 0x38 bytes from 0x004872F0.
 * func_00407BF8 sets active/flag3/flag2/word4; func_00408608 returns selector (lb);
 * func_00408790 stores 9 to mode; func_004087B8 tests mode == 2 and passes handle;
 * func_00408618 returns state. Bytes 0x08..0x2F have no reader and stay raw. */
typedef signed char s8;
typedef unsigned char u8;
typedef signed int s32;
typedef struct {
    s8 active;      /* 0x00 */
    s8 selector;    /* 0x01 */
    s8 mode;        /* 0x02 */
    s8 flag3;       /* 0x03 */
    s32 word4;      /* 0x04 */
    u8 pad08[0x28];
    s32 handle;     /* 0x30 */
    s32 state;      /* 0x34 */
} RuntimeStateBlock;
typedef char RuntimeStateBlock_size_check[sizeof(RuntimeStateBlock) == 0x38 ? 1 : -1];
RuntimeStateBlock D_004872F0 = { 0 };

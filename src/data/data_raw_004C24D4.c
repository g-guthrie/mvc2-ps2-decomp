typedef signed int s32;
typedef unsigned char u8;
extern u8 data_u8_004BE9E0[];
extern char data_cstr_004BEA60[];

/* Small gp-relative block. The counters at +0x04 and +0x08 are the use counts
 * of func_0040F550 (src/k2b.c) and the pw39/b10s_0 users. The words at +0x10,
 * +0x14 and +0x18 are plain s32 values read and written with lw/sw. The
 * pointer at +0x0C has no reader in the code. The word at +0x00 holds the address
 * of data_u8_004BE9E0; its reader in src/k2b.c loads it as volatile s32 and discards it. */
typedef struct {
    u8 *bannerPtr;
    s32 initCount;
    s32 useCountD8;
    char *versionPtr;
    s32 word10;
    s32 word14;
    s32 word18;
} GpDataBlock28;

typedef char GpDataBlock28_size_check[(sizeof(GpDataBlock28) == 28) ? 1 : -1];

GpDataBlock28 data_raw_004C24D4 = { data_u8_004BE9E0, 0, 0, data_cstr_004BEA60, 0, 0, 0 };

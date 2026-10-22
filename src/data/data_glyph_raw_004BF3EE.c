typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
/* Two leading bytes, then two small u8 lookups addressed gp-relative
   (D_004BF3F0 and D_004BF3F4) and indexed by a slot number. */
typedef struct Tab_004BF3EE {
    u8 pad[2];
    u8 a[4];
    u8 b[4];
} Tab_004BF3EE;
typedef char Tab_004BF3EE_size_check[(sizeof(Tab_004BF3EE) == 10) ? 1 : -1];
Tab_004BF3EE data_glyph_raw_004BF3EE = { { 0x00, 0x00 }, { 0x82, 0x08, 0x83, 0x86 }, { 0x02, 0x87, 0x89, 0x00 } };

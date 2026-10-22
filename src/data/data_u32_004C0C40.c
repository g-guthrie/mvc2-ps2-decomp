typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

/* Entries 0..1 and 4..7 are loaded as f32 indexed by byte at +0x1B7
 * (func_002AEA60); words 2..3 are not floats (0x00180010 is a denormal). */
typedef struct {
    f32 a[2];
    u32 raw[2];
    f32 b[4];
} Mvc2FloatRow;
typedef char Mvc2FloatRow_size_check[(sizeof(Mvc2FloatRow) == 32) ? 1 : -1];
Mvc2FloatRow data_u32_004C0C40 = {
    { 17.1428566f, 25.7142849f },
    { 0x00180010u, 0x00000000u },
    { 10.0f, 13.333333f, 17.1428566f, 21.4285698f },
};

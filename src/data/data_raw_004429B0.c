typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

/* Three 32-byte records (func_001472B0 stores &table[p[0x20]] at actor+0xD8),
 * each four {u16,u16,f32} entries; a flag of 0xFF ends a record. */
typedef struct {
    u16 flag;
    u16 code;
    f32 value;
} Mvc2PairEntry;
typedef char Mvc2PairEntry_size_check[(sizeof(Mvc2PairEntry) == 8) ? 1 : -1];
Mvc2PairEntry data_raw_004429B0[12] = {
    { 0x1, 0x41, 0.0f },
    { 0x1, 0x38, 0.5f },
    { 0x1, 0x37, 0.5f },
    { 0xFF, 0x0, 0.0f },
    { 0x1, 0x42, 0.0f },
    { 0x1, 0x38, 0.5f },
    { 0x1, 0x37, 0.5f },
    { 0xFF, 0x0, 0.0f },
    { 0x1, 0x38, 0.0f },
    { 0x1, 0x37, 0.5f },
    { 0x1, 0x37, 0.5f },
    { 0xFF, 0x0, 0.0f },
};

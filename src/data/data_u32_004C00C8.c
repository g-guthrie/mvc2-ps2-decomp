typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

/* func_0022C820: p[0x1FD] = table[(s8)p[0x4DD]].first; p[0x1B7] = .second */
typedef struct {
    u8 first;
    u8 second;
} Mvc2BytePair;
typedef char Mvc2BytePair_size_check[(sizeof(Mvc2BytePair) == 2) ? 1 : -1];
Mvc2BytePair data_u32_004C00C8[14] = {
    { 0x0D, 0x01 },
    { 0x03, 0x01 },
    { 0x0B, 0x01 },
    { 0x00, 0x00 },
    { 0x0D, 0x01 },
    { 0x03, 0x01 },
    { 0x0B, 0x01 },
    { 0x00, 0x00 },
    { 0x01, 0x02 },
    { 0x01, 0x02 },
    { 0xFF, 0x02 },
    { 0xFF, 0x02 },
    { 0xFF, 0xFF },
    { 0xFF, 0xFF },
};

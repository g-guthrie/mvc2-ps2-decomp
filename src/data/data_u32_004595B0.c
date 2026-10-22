typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef struct {
    u32 count;
    u16 v[6];
} Rec16b;
typedef char Rec16b_size_check[(sizeof(Rec16b) == 16) ? 1 : -1];
Rec16b data_u32_004595B0 = { 12, { 15, 31, 15, 31, 15, 31 } };

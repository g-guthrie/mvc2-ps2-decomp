typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct u32_004430E0_rec {
    u16 half0;
    u16 half1;
    f32 value2;
    u32 field3;
    f32 value4;
} u32_004430E0_rec;
typedef char u32_004430E0_rec_size_check[(sizeof(u32_004430E0_rec) == 16) ? 1 : -1];
u32_004430E0_rec data_u32_004430E0[1] = {
    { 0x0075, 0x0001, 9.5f, 0x00000000U, 0.00999999978f },
};

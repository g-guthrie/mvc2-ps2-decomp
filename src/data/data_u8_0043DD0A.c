typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* No reader found. Six zero bytes, then six f32 values 1.0 down to 0.95 that
 * start at offset 6 (not 4-byte aligned, hence packed). */
#pragma pack(1)
typedef struct {
    u8 pad[6];
    f32 mul[6];
} Data0043DD0A;
#pragma pack()
typedef char data_0043DD0A_size_check[(sizeof(Data0043DD0A) == 30) ? 1 : -1];

Data0043DD0A data_u8_0043DD0A = {
    {0, 0, 0, 0, 0, 0},
    {1.0f, 0.99000001f, 0.980000019f, 0.970000029f, 0.959999979f, 0.949999988f}
};

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* No reader found; layout inferred from the bytes: two zero words, four
 * f32 values (small magnitudes), four byte fields, seven words, then a
 * 12-character ASCII string. */
typedef struct {
    u32 zero[2];
    f32 coef[4];
    u8 flags[4];
    u32 words[7];
    char name[12];
} Data00438208;
typedef char data_00438208_size_check[(sizeof(Data00438208) == 68) ? 1 : -1];

Data00438208 data_raw_00438208 = {
    {0x00000000u, 0x00000000u},
    {2.60188699e-06f, -0.000198074136f, 0.0083330255f, -0.166666567f},
    {0x04u, 0x04u, 0x00u, 0x01u},
    {0x20000000u, 0x00000000u, 0x05000000u, 0x04000000u, 0x00000000u, 0x00000000u},
    "PsIIlibkernl"
};

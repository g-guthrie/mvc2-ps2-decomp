/* MWCCPS2 3.0.3: -O3 -sdatathreshold 0 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern int func_00174170(void);
extern f32 data_f32_0044EB30[64];

void func_001DBE70(u8 *p)
{
    u32 i;

    p[6]++;
    i = (u32)func_00174170() & 7;
    *(f32 *)(p + 0x5c) = data_f32_0044EB30[i * 2];
    *(f32 *)(p + 0x68) = data_f32_0044EB30[i * 2 + 1];
    i = (u32)func_00174170() & 7;
    *(f32 *)(p + 0x60) = data_f32_0044EB30[i * 2 + 16];
    *(f32 *)(p + 0x6c) = data_f32_0044EB30[i * 2 + 17];
}

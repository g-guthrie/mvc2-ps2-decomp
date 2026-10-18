typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_0044F860[];
extern u8 D_0044F864[];
extern u8 D_0044F868[];
extern u8 D_0044F86C[];

void func_001F23F0(u8 *p)
{
    extern void func_00175700(u8 *);
    u32 t;
    p[0x206] = 3;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 0x5C) = 1.6666666269302368f * (f32)*(s32 *)(D_0044F860 + (p[0x1B7] << 4)) / 65536.0f;
        *(f32 *)(p + 0x68) = 1.6666666269302368f * (f32)*(s32 *)(D_0044F864 + (p[0x1B7] << 4)) / 65536.0f;
        *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)*(s32 *)(D_0044F868 + (p[0x1B7] << 4)) / 65536.0f;
        *(f32 *)(p + 0x6C) = 2.142857074737549f * (f32)*(s32 *)(D_0044F86C + (p[0x1B7] << 4)) / 65536.0f;
        if (p[0x1E6] == 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}

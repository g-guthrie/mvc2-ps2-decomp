typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern s32 D_0044F820[][3], D_0044F824[][3], D_0044F828[][3];

void func_001F1870(u8 *s0)
{
    extern int func_00175700(u8 *);
    extern int func_001757E0(u8 *, s32, s32);
    u32 t;
    s0[0x1FE] = 1;
    s0[0x201] = 2;
    s0[0x209] = 2;
    s0[0x206] = 3;
    if ((s8)func_00175700(s0) >= 0)
        return;
    t = s0[7];
    s0[7] = t + 1;
    *(f32 *)(s0 + 0x5C) = 1.6666666f * (f32)D_0044F820[s0[0x1B7]][0] / 65536.0f;
    *(f32 *)(s0 + 0x68) = 0.0f;
    *(f32 *)(s0 + 0x60) = 2.1428571f * (f32)D_0044F824[s0[0x1B7]][0] / 65536.0f;
    *(f32 *)(s0 + 0x6C) = 2.1428571f * (f32)D_0044F828[s0[0x1B7]][0] / 65536.0f;
    if (*(f32 *)(s0 + 0x34) < 0.0f) {
    } else
        *(f32 *)(s0 + 0x5C) = -*(f32 *)(s0 + 0x5C);
    func_001757E0(s0, 0xF, 0xC);
}

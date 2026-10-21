typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
extern void func_001E3210(u8 *, s32);
extern void func_0031DEC0(u8 *);
extern void func_0031DF20(u8 *);
extern u8 *D_004C2794 __attribute__((section(".sdata")));

void func_0031DAC0(u8 *p)
{
    f32 *velocity = (f32 *)(p + 0x5C);
    f32 *acceleration = (f32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < 0.0f)) {
        *velocity = 0.0f;
        *acceleration = 0.0f;
    }

    if ((s8)func_00175700(p) >= 0)
        goto status_ok;

    func_001E3210(p, 0x1F);
    if (*(s16 *)(p + 0x1C) != 0) {
        *(s16 *)(p + 0x1C) = 0;
        {
            s16 countdown = *(s16 *)(p + 0x1E) - 1;
            *(s16 *)(p + 0x1E) = countdown;
            if (countdown > 0) {
                *(f32 *)(p + 0x60) += 10.714284896850586f;
                {
                    u32 phase = p[0x20];
                    phase ^= 1;
                    p[0x20] = (u8)phase;
                    phase &= 0xFF;
                    phase += 1;
                    func_001757E0(p, 0x15, phase & 0xFF);
                }
                return;
            }
        }
    }

    p[7] = 3;
    p[0x1B5] = 0x4B;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    func_001757E0(p, 0x15, 3);
    return;

status_ok:
    func_0031DEC0(p);
    func_0031DF20(p);
}

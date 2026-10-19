typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_0015BA00(u8 *);
extern s16 func_00118FA8(f32);

void func_0015BD40(u8 *p)
{
    p[0x13C] = 1;
    func_0015BA00(p);
    if (p[5] != 0) {
        *(s16 *)(p + 0x1C) = func_00118FA8((f32)*(s16 *)(p + 0x1C) + 10.0f);
        if (*(s16 *)(p + 0x1C) >= 0) {
            *(s16 *)(p + 0x1C) = 0;
            p[4] = 0;
        }
        *(u32 *)(p + 0x48) = (u16)(65536.0 * (double)*(s16 *)(p + 0x1C) / 360.0 + 0.5);
    } else {
        *(s16 *)(p + 0x1C) = func_00118FA8((f32)*(s16 *)(p + 0x1C) - 10.0f);
        if (*(s16 *)(p + 0x1C) < -0xB3) {
            *(s16 *)(p + 0x1C) = -0xB4;
            p[4] = 0;
        }
        *(u32 *)(p + 0x48) = (u16)(65536.0 * (double)*(s16 *)(p + 0x1C) / 360.0 + 0.5);
    }
}

typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern void func_001C57B0(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);

void residual_0028FAD0(u8 *p)
{
    p[7]++;
    *(s16 *)(p + 0x1C) = 0x26;
    *(f32 *)(p + 0x64) = *(f32 *)(p + 0x34);
    if (p[2] == 0) {
        p[0x1E6] = 1;
        *(f32 *)(p + 0x34) += -160.0f;
    } else {
        p[0x1E6] = 0;
        *(f32 *)(p + 0x34) -= -160.0f;
    }
    *(s16 *)(p + 0x140) = p[0x1E6];
    *(f32 *)(p + 0x38) = 274.28570556640625f + *(f32 *)(p + 0x430);
    func_001C57B0(p, 0xC);
    func_001757E0(p, 0x12, 4);
}

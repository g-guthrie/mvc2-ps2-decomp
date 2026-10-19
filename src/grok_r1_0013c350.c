typedef unsigned char u8;
typedef float f32;

extern void func_0013BF80(u8 *);

void residual_0013C350(u8 *p)
{
    *(f32 *)(p + 0x50) -= 0.02f;
    *(f32 *)(p + 0x54) -= 0.02f;
    *(f32 *)(p + 0x58) -= 0.02f;
    if (*(f32 *)(p + 0x50) <= 1.0f) {
        p[4]++;
        *(f32 *)(p + 0x50) = 1.0f;
        *(f32 *)(p + 0x54) = 1.0f;
        *(f32 *)(p + 0x58) = 1.0f;
        func_0013BF80(p);
    }
}

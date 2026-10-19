typedef unsigned char u8;
typedef float f32;

extern void func_00137CA0(u8 *);
extern void func_00137DF0(u8 *);

void residual_00137C10(u8 *p)
{
    *(f32 *)(p + 0x50) -= 0.04f;
    *(f32 *)(p + 0x54) -= 0.04f;
    *(f32 *)(p + 0x58) -= 0.04f;
    if (*(f32 *)(p + 0x50) <= 1.0f) {
        p[4]++;
        *(f32 *)(p + 0x50) = 1.0f;
        *(f32 *)(p + 0x54) = 1.0f;
        *(f32 *)(p + 0x58) = 1.0f;
    }
    func_00137CA0(p);
    func_00137DF0(p);
}

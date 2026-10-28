typedef unsigned char u8;
typedef float f32;
typedef int s32;
extern void (*D_004C0678[2])(u8 *, u8 *);

void residual_00264BA0(u8 *p)
{
    extern void func_001820A0();
    if (p[0x20D] == 2) {
        func_001820A0(p);
        if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        }
    }
    D_004C0678[p[6]](p, (u8 *)((s32)p + 0x2B8));
}

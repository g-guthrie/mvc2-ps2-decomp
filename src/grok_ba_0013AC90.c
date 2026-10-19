typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;

extern double func_00119058(float);
extern s32 func_00100260(double, s32);

void func_0013AC90(u8 *p)
{
    float f;
    u8 st;
    *(u32 *)(p + 0x48) = *(u32 *)(*(u8 **)(p + 0x18) + 0x48);
    st = p[6];
    if (st == 0x63)
        return;
    if (st == 2) {
        f = *(float *)(p + 0x54) - 0.1f;
        *(float *)(p + 0x54) = f;
        if (func_00100260(func_00119058(f), 0)) {
            p[6] = 0x63;
            *(u32 *)(p + 0x54) = 0x3C23D70A;
        }
        return;
    }
    if (st == 1) {
        f = *(float *)(p + 0x54) + 0.1f;
        *(float *)(p + 0x54) = f;
        if (!(f < 1.0f)) {
            p[6] = 0x63;
            *(float *)(p + 0x54) = 1.0f;
        }
        return;
    }
    if (st == 0) {
        if (*(s32 *)(*(u8 **)(*(u8 **)(p + 0x18) + 0x18) + 0x2C) == p[0x21])
            p[6] = 1;
        else
            p[6] = 2;
        return;
    }
}

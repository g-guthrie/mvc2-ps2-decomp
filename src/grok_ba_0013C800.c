typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

extern void func_0032D5F0(u8 *);
extern float D_004404A0[];
extern float D_004404A4[];

void residual_0013C800(u8 *p)
{
    s16 t;
    float f;
    f = *(float *)(p + 0x74) + (float)(1.0 / 20.0);
    if (!(f <= 1.0f))
        f = 1.0f;
    *(float *)(p + 0x74) = f;
    t = *(s16 *)(p + 0x1C);
    t = t - 1;
    *(s16 *)(p + 0x1C) = t;
    if (*(s16 *)(p + 0x1C) <= 0) {
        p[4] = p[4] + 1;
        *(float *)(p + 0x34) = *(float *)((u8 *)D_004404A0 + (p[0x20] << 3));
        *(float *)(p + 0x38) = *(float *)((u8 *)D_004404A4 + (p[0x20] << 3));
        *(u32 *)(p + 0x3C) = 0x43660000;
        *(u32 *)(p + 0x74) = 0x3F800000;
        if (p[0x20] == 0)
            (*(u8 **)(p + 0x14))[4] = 1;
        return;
    }
    *(float *)(p + 0x34) += *(float *)(p + 0x5C);
    *(float *)(p + 0x5C) += *(float *)(p + 0x68);
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    func_0032D5F0(p);
}

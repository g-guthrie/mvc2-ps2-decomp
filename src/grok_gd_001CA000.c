typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern void func_00175670(u8 *);

void func_001CA000(u8 *p)
{
    u8 *q;
    q = *(u8 **)(p + 0x18);
    if (q[0x1E4] != 0x1D || q[0x1FD] != 1) {
        p[4] = 2;
        return;
    }
    func_00175670(p);
    if (p[5] == 0) {
        u8 t = p[0x22];
        p[0x22] = t - 1;
        if (t != 0)
            return;
        p[5]++;
        *(signed char *)(p + 0x31) = -8;
        *(f32 *)(p + 0x34) = 140.0f;
        *(unsigned int *)(p + 0x38) = 0x44011B6D;
        if (*(s16 *)(q + 0x140) != 0)
            *(f32 *)(p + 0x34) = -*(f32 *)(p + 0x34);
        *(f32 *)(p + 0x34) += *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) += *(f32 *)(q + 0x38);
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    {
        s16 t = *(s16 *)(p + 0x1C);
        t--;
        *(s16 *)(p + 0x1C) = t;
        if (t < 0) {
            p[4] = 2;
            return;
        }
    }
    {
        s16 t = *(s16 *)(p + 0x1E);
        *(s16 *)(p + 0x1E) = t - 1;
        if (t == 0) {
            p[0x13C] = D_004C2840[0x1C] & 1;
            *(s16 *)(p + 0x1E) = 0;
        }
    }
}

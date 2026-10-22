typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0018ED20(u8 *p);
void func_0018F1A0(u8 a, s32 b, f32 *v);

void func_0018EB00(u8 *p, s32 a1)
{
    u8 *s0;
    f32 v[2];
    f32 x, lim, z;

    s0 = *(u8 **)(p + 0x1CC);
    if (s0 == 0) s0 = *(u8 **)(p + 0x220);
    if (s0[5] >= 2) {
        func_0018ED20(p);
        return;
    }
    func_0018F1A0(p[0x242], a1, v);
    if ((*(u16 *)(p + 0x1C2) & 0x20) != 0) {
        if (p[0x1E6] == 0) v[0] = -v[0];
    } else if (p[0x1BA] != 0) {
        v[0] = -v[0];
    }
    z = 0.0f;
    if (v[0] != z) {
        if ((v[0] < z && *(f32 *)(s0 + 0x5C) < 1.6666666269302368f) ||
            (v[0] > z && *(f32 *)(s0 + 0x5C) > -1.6666666269302368f)) {
            v[0] += *(f32 *)(s0 + 0x5C);
        }
        x = v[0];
        lim = (x > z) ? 31.66666603088379f : -31.66666603088379f;
        if (x > z) {
            if (x > lim) v[0] = lim;
        } else if (x < lim) {
            v[0] = lim;
        }
    }
    *(f32 *)(p + 0x22C) = v[0];
    *(s32 *)(p + 0x68) = 0;
    if (s0[0x210] != 0) {
        *(f32 *)(p + 0x230) = v[1] + *(f32 *)(s0 + 0x60) / 2.0f;
    } else {
        *(f32 *)(p + 0x230) = v[1] + *(f32 *)(s0 + 0x60);
    }
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
}

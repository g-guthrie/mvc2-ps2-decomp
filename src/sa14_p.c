typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00450170[], D_00450172[], D_00450174[], D_00450176[];

void func_00200990(u8 *p)
{
    extern void func_001549B0(u8 *, f32 *);
    extern void func_001E3B70(s32, s32);
    f32 v[4];
    u8 *q = p + 0x2B8;
    s32 x;
    u8 t;
    v[0] = 1.6666666269302368f * (f32)D_00450170[(s8)p[0x2CE] * 4] / 256.0f;
    v[1] = 2.142857074737549f * (f32)D_00450172[(s8)p[0x2CE] * 4] / 256.0f;
    func_001549B0(p, v);
    v[0] = 1.6666666269302368f * (f32)D_00450174[(s8)q[0x16] * 4] / 256.0f;
    v[1] = 2.142857074737549f * (f32)D_00450176[(s8)q[0x16] * 4] / 256.0f;
    func_001549B0(p, v);
    if ((t = p[0x15B]) != 0) {
        func_001E3B70(*(s32 *)(p + 0x1DC), (u8)((u8)t - 1));
        p[0x15B] = 0;
    }
    x = (s8)q[0x16];
    switch (x) {
    case 0:
        q[0x16] = 1;
        break;
    case 1:
        q[0x16] = 0;
        break;
    case 2:
    case 3:
    case 4:
        q[0x16] = x + 1;
        break;
    case 5:
        q[0x16] = 0;
        break;
    }
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern double func_001173D0(double);

void func_003F3FD0(f32 *d, f32 *s)
{
    extern void func_003F38A0(f32 *);
    f32 m[16];
    f32 l0, l1, l2;
    f32 tx, ty, tz;
    f32 x, y, z;

    x = s[0]; y = s[1]; z = s[2];
    l0 = (f32)func_001173D0((double)(x * x + y * y + z * z));
    x = s[4]; y = s[5]; z = s[6];
    l1 = (f32)func_001173D0((double)(x * x + y * y + z * z));
    x = s[8]; y = s[9]; z = s[10];
    l2 = (f32)func_001173D0((double)(x * x + y * y + z * z));
    func_003F38A0(m);
    m[0] = s[0] / l0;
    m[1] = s[4] / l1;
    m[2] = s[8] / l2;
    m[4] = s[1] / l0;
    m[5] = s[5] / l1;
    m[6] = s[9] / l2;
    m[8] = s[2] / l0;
    m[9] = s[6] / l1;
    m[10] = s[10] / l2;
    tx = -s[12];
    ty = -s[13];
    tz = -s[14];
    m[12] = m[0] * tx + m[4] * ty + m[8] * tz;
    m[13] = m[1] * tx + m[5] * ty + m[9] * tz;
    m[14] = m[2] * tx + m[6] * ty + m[10] * tz;
    d[0] = m[0] / l0;
    d[1] = m[1] / l1;
    d[2] = m[2] / l2;
    d[3] = m[3];
    d[4] = m[4] / l0;
    d[5] = m[5] / l1;
    d[6] = m[6] / l2;
    d[7] = m[7];
    d[8] = m[8] / l0;
    d[9] = m[9] / l1;
    d[10] = m[10] / l2;
    d[11] = m[11];
    d[12] = m[12] / l0;
    d[13] = m[13] / l1;
    d[14] = m[14] / l2;
    d[15] = m[15];
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003DDC30(f32 *m) {
    extern void func_003DE720();
    f32 sn, cs;
    f32 x, z;
    func_003DE720(&sn, &cs);
    x = m[0]; z = m[2];
    m[0] = cs * x + sn * z;
    m[2] = -sn * x + cs * z;
    x = m[4]; z = m[6];
    m[4] = cs * x + sn * z;
    m[6] = -sn * x + cs * z;
    x = m[8]; z = m[10];
    m[8] = cs * x + sn * z;
    m[10] = -sn * x + cs * z;
}

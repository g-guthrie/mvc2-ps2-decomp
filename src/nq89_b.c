typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
void residual_00253620(u8 *p)
{
    extern void func_00179160(u8 *, u8 *);
    V3 v[2]; V3 a; f32 z; u32 t;
    t = p[6]; p[6] = t + 1; v[0] = a = *(V3 *)(p + 0x34); v[1] = a;
    func_00179160(p, *(u8 **)(p + 0x1DC));
    v[0].x = *(f32 *)(p + 0x34) - v[0].x;
    v[0].y = *(f32 *)(p + 0x38) - v[0].y;
    *(V3 *)(p + 0x34) = v[1];
    v[0].y /= 8.0f;
    if ((p[0x20B] & 0x3F) != 1) {
        z = 0.0f;
        if (v[0].y < z) v[0].y = z;
    }
    *(f32 *)(p + 0x5C) = v[0].x / 8.0f;
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) = 2.142857074737549f + v[0].y;
    *(u32 *)(p + 0x6C) = 0xBF092492;
}

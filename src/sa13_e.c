typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern double func_00119B08(s32);
extern s32 dptoli(double);

void func_00155FA0(u8 *p)
{
    extern void func_00156480(u8 *);
    f32 f;
    u32 t;
    s16 h;
    p[0x13C] = 1;
    func_00156480(p);
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    *(u32 *)(p + 0x44) = (u32)dptoli(0.5 + 65536.0 * func_00119B08(*(s16 *)(p + 0x1C) * 2) / 360.0) & 0xFFFFu;
    *(u32 *)(p + 0x48) = (u32)dptoli(0.5 + 65536.0 * func_00119B08(*(s16 *)(p + 0x1C) * 3) / 360.0) & 0xFFFFu;
    if (p[5] == 0) {
        h = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = h;
        if (h <= 0) {
            t = p[5];
            p[5] = t + 1;
        }
    } else {
        f = *(f32 *)(p + 0x74) - 0.03333333507180214f;
        *(f32 *)(p + 0x74) = f;
        if (f < 0.0f) {
            t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
        }
    }
}

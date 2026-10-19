typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00156480(u8 *);

void func_00155FA0(u8 *p)
{
    s16 t;
    p[0x13C] = 1;
    func_00156480(p);
    *(s16 *)(p + 0x1C) = (s16)(*(s16 *)(p + 0x1C) + 1);
    t = *(s16 *)(p + 0x1C);
    *(u32 *)(p + 0x44) = (u16)(65536.0 * (double)(t + t) / 360.0 + 0.5);
    *(u32 *)(p + 0x48) = (u16)(65536.0 * (double)(t + t + t) / 360.0 + 0.5);
    if (p[5] == 0) {
        *(s16 *)(p + 0x1E) = (s16)(*(s16 *)(p + 0x1E) - 1);
        if (*(s16 *)(p + 0x1E) <= 0)
            p[5]++;
    } else {
        f32 a = *(f32 *)(p + 0x74) - (1.0f / 30.0f);
        *(f32 *)(p + 0x74) = a;
        if (a < 0.0f) {
            p[4]++;
            p[0x13C] = 0;
        }
    }
}

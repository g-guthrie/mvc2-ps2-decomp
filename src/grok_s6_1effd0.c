typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);

void func_001EFFD0(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        p[6]++;
        *(f32 *)(p + 0x5C) = 0;
        *(f32 *)(p + 0x60) = 0;
        *(f32 *)(p + 0x68) = 0;
        *(f32 *)(p + 0x6C) = 0;
        *(s16 *)(p + 0x1C) = 0x1E;
        if (p[0x216] == 0) {
            *(f32 *)(p + 0x5C) = p[0x1E6] ? (32.5f / 3.0f) : -(32.5f / 3.0f);
            *(f32 *)(p + 0x68) = p[0x1E6] ? -0.3125f : 0.3125f;
        } else {
            *(f32 *)(p + 0x5C) = p[0x1E6] ? 5.8333330154418945f : -5.8333330154418945f;
            *(f32 *)(p + 0x68) = p[0x1E6] ? -(5.0f / 48.0f) : (5.0f / 48.0f);
        }
    }
}

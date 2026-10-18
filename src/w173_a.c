typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001BCE00(u8 *p)
{
    extern void func_00175670();
    u8 *q;
    f32 v;
    func_00175670(p);
    *(f32 *)(p + 0x118) -= *(f32 *)(p + 0x64);
    v = *(f32 *)(p + 0x118);
    if (v <= 0.0f) {
        p[4]++;
        p[0x13C] = 0;
        q = *(u8 **)(p + 0x14);
        if (q[3] == 3 && *(u16 *)(q + 0x26) == 0x1802) {
            q[0x23] &= ~p[0x23];
            if (p[0x20] == 7) {
                (*(u8 **)(p + 0x14))[0x23] &= 0xFE;
            } else if (p[0x20] == 8) {
                (*(u8 **)(p + 0x14))[0x23] &= 0xFE;
            }
        }
    }
}

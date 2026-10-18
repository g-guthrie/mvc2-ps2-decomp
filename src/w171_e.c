typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;

s32 func_003D91E0(u8 *p)
{
    extern void func_001E3CE0(s32);
    extern void func_003D92D0(u8 *);
    s8 t;
    s8 v;
    u8 *q;
    if (p[6] != 0) {
        return 1;
    }
    {
        t = *(s8 *)(p + 0x41) - 1;
        *(s8 *)(p + 0x41) = t;
        if (t == 0) {
            if (*(s8 *)(p + 0x40) == 0) {
                return 0;
            }
    q = *(u8 **)(p + 0x18);
    q[0x4BD] = *(s8 *)(q + 0x4BD) + 1;
    q = *(u8 **)(p + 0x24);
    q[0x4BD] = *(s8 *)(q + 0x4BD) + 1;
    if (*(s8 *)(D_004C2840 + 0x4D) != 3) {
        v = *(s8 *)(p + 0x40);
        if (v > 0) {
            p[0x40] = v - 1;
            if (*(s8 *)(p + 0x40) == 10 || *(s8 *)(p + 0x40) == 0x14) {
                func_001E3CE0(0x18);
            }
        }
    }
    v = *(s8 *)(p + 0x86);
    if (v > 0) {
        p[0x86] = v - 1;
    }
    func_003D92D0(p);
        }
    }
    return 1;
}

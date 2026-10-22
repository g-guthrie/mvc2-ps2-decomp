typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_001DCC80(u8 *p, u8 *q)
{
    extern s8 func_00175700();
    extern void func_003BEF10(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_001DCDA0(u8 *, u8 *);
    u8 v;
    s16 h;
    u8 t;
    if (*(s16 *)(p + 0x1C) != 0) {
        func_00175700();
        v = 7;
        if (*(s8 *)(p + 0x151) != 0) v = 0;
        p[0x24] = v;
        if (q[0x1E4] == 0x1D && q[5] == 0) {
            {
                if (*(s16 *)(p + 0x1C) >  0x3C && *(s16 *)(p + 0x1C) < 0x78) {
                    t = p[0x22];
                    t += 0x20;
                    p[0x22] = t;
                    if (t & 0x80) {
                        *(s16 *)(p + 0x1E) ^= 1;
                        func_003BEF10(p, *(u16 *)(p + 0x1E));
                    }
                }
                h = *(s16 *)(p + 0x1C) - 1;
                *(s16 *)(p + 0x1C) = h;
                if (h > 0) return;
            }
        }
        *(s16 *)(p + 0x1C) = 0;
        func_001757E0(p, 0x16, 0x48);
        return;
    }
    if (func_00175700() < 0) return func_001DCDA0(p, q);
}

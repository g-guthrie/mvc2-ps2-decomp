typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_0018A380(u8 *, u8 *, u8 *, u32);
extern s32 func_0018A460(u8 *, u8 *, u8 *, u32);

s32 func_0018A080(u8 *a, u8 *b, u8 *c)
{
    s8 t;
    u16 mask;
    u16 val;
    u16 flags;
    t = (s8)c[1] - 1;
    c[1] = t;
    if (t <= 0)
        return c[0] = 0;
    mask = *(u16 *)((u8 *)(c[2] * 2) + (u32)b + 8);
    val = (u16)((*(u16 *)(a + 0x362) & 0x3F60) & mask);
    if (val) {
        flags = *(u16 *)(b + 2);
        {
            int hi = (u32)((flags & 0x8000) ^ 0x8000) < 1u;
            if (hi) {
                if (val == mask)
                    return func_0018A380(a, b, c, val);
                c[0]++;
            } else if ((flags & 0x40) == 0x40)
                return func_0018A460(a, b, c, val);
            else
                return func_0018A380(a, b, c, val);
        }
    }
    return 0;
}

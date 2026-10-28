typedef unsigned char u8;
typedef unsigned int u32;
extern u32 D_00478DF0[];

void func_003F0370(u8 *p)
{
    extern u8 *func_003DD030(u32);
    extern void func_003DBA90(u8 *, u32, u8 *, int, int);
    u8 *s0, *s1, *s2, *r;
    u32 w, k, v, t;
    if ((s1 = func_003DD030(*(u32 *)(p + 0x1C))) == 0) return;
    if ((s2 = func_003DD030(*(u32 *)(p + 0x24))) == 0) return;
    for (;;) {
        s0 = s1;
        s1 += 0x10;
        w = *(u32 *)s0;
        switch (w & 0x70000000) {
        case 0x30000000:
            v = *(u32 *)s2;
            s2 += 4;
            r = func_003DD030(*(u32 *)(p + 0x20));
            t = D_00478DF0[*(u32 *)(*(u8 **)(p + 0x40) + 0x14)];
            r += v * t;
            func_003DBA90(s0, t >> 4, r, 0, 0);
            break;
        case 0x70000000:
            return;
        default:
            s1 += (w & 0xFFFF) << 4;
            break;
        }
    }
}

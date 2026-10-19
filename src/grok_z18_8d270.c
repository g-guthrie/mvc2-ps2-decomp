typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

void residual_0028D270(u8 *p)
{
    extern void func_0015D010();
    extern void func_0018C6E0();
    extern void func_001757E0();
    f32 v[3];
    if (p[0x22] & 2) {
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    *(u32 *)v = 0xC292AAAA;
    *(u32 *)(v + 1) = 0x42D64924;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 0);
}

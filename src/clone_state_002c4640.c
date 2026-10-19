typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float PlanarOffset[2] __attribute__((aligned(16)));
extern void func_001266A0(u8 *, int, int);
extern void func_0015D010(u8 *, const float *);
extern void func_0018C6E0(u8 *);
extern int func_001757E0(u8 *, int, int);
void func_002C4640(u8 *p)
{
    PlanarOffset v;
    if ((p[0x22] & 1) == 0) {
        u32 t = p[0x1E6];
        p[0x1E6] = t ^ 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    func_001266A0(p, 5, 5);
    v[0] = -90.0f;
    v[1] = 162.857132f;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 1);
}

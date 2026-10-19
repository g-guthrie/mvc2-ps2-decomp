typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

typedef f32 PlanarOffset[2] __attribute__((aligned(16)));

extern void func_0015D010(u8 *, const f32 *);
extern void func_001266A0(u8 *, int, int);
extern void func_0018C6E0(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_00277A70(u8 *p)
{
    PlanarOffset v;
    if (*(u16 *)(p + 0x20E) & 0x800) {
        *(s16 *)(p + 0x140) ^= 1;
        p[0x1E6] ^= 1;
    }
    ((u32 *)v)[0] = 0xC2A6AAAA;
    ((u32 *)v)[1] = 0x4313DB6D;
    func_0015D010(p, v);
    func_001266A0(p, 5, 5);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x1B4] = 10;
    func_0018C6E0(p);
    if (p[0x20D] == 2)
        func_001757E0(p, 0xF, 3);
    else
        func_001757E0(p, 0xF, 0);
}

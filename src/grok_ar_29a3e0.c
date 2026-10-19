typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float PlanarOffset[2] __attribute__((aligned(16)));
typedef float PlanarTriplet[3] __attribute__((aligned(16)));
typedef char PlanarTripletSizeCheck[(sizeof(PlanarTriplet) == 12) ? 1 : -1];

extern void func_001266A0(u8 *, s32, s32);
extern void func_0015D010(u8 *, const float *);
extern void func_0018C6E0(u8 *);
extern int func_001757E0(u8 *, s32, s32);

void func_0029A3E0(u8 *p)
{
    PlanarOffset v;
    p[0x1E6] ^= 1;
    *(s16 *)(p + 0x140) = p[0x1E6];
    if ((p[0x22] & 2) == 0) {
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    func_001266A0(p, 5, 5);
    ((u32 *)v)[0] = 0xC2A6AAAA;
    ((u32 *)v)[1] = 0x431E9249;
    func_0015D010(p, v);
    p[0x1B4] = 0xA;
    func_0018C6E0(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001757E0(p, 0xF, 0);
}

void func_001ED180(u8 *p)
{
    PlanarOffset v;
    p[0x1E6] ^= 1;
    *(s16 *)(p + 0x140) = p[0x1E6];
    if ((p[0x22] & 2) == 0) {
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    func_001266A0(p, 5, 5);
    ((u32 *)v)[0] = 0xC2A6AAAA;
    ((u32 *)v)[1] = 0x431E9249;
    func_0015D010(p, v);
    p[0x1B4] = 0xA;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 0);
}

void func_001FB600(u8 *p)
{
    PlanarTriplet v;
    if ((p[0x22] & 1) == 0) {
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    func_001266A0(p, 5, 5);
    ((u32 *)v)[0] = 0xC2E2AAAA;
    ((u32 *)v)[1] = 0x43430000;
    ((u32 *)v)[2] = 0;
    func_0015D010(p, v);
    p[0x1B4] = 0xA;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 0);
}

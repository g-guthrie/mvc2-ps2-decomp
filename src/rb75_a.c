typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x34];
    f32 f34;
    f32 f38;
    u8 pad3C[0x20];
    f32 f5c;
    f32 f60;
    u8 pad64[4];
    f32 f68;
    f32 f6c;
} O2AE;

typedef struct {
    u8 pad0[0x428];
    u32 w428;
    u32 w42C;
    f32 f430;
} P2AE;

void func_002AE310(u8 *a)
{
    extern void func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern u8 *func_001E7FD0(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0015D010(u8 *, u32 *);
    extern void func_00185770(u8 *, u8 *);
    O2AE *o = (O2AE *)a;
    u8 *r;
    u32 v[4];
    s32 h;
    a[0x40C] = 2;
    a[0x33C] = 5;
    func_00175700(a);
    o->f34 += o->f5c;
    o->f5c += o->f68;
    o->f38 += o->f60;
    o->f60 += o->f6c;
    if ((s8)a[0x211] & (1 << (a[0x1E6] ^ 1)) || (h = *(s16 *)(a + 0x1C) - 1, *(s16 *)(a + 0x1C) = h, (s16)h <= 0)) {
        a[0x40D] = 0;
        a[0x40C] = 0;
        a[0x33B] = 0;
        a[0x33C] = 0;
        func_001843A0(a);
        return;
    }
    if ((r = func_001E7FD0(a)) != 0) {
        u32 t = a[6];
        a[6] = t + 1;
        func_001266A0(a, 6, 6);
        func_001757E0(a, 0xF, 6);
        v[0] = 0xC2A6AAAA;
        v[1] = 0x431E9249;
        func_0015D010(a, v);
        *(s16 *)(a + 0x1C) = 0x10;
        a[0x20B] = 0xC3;
        func_00185770(a, r);
        a[0x1B4] = 10;
        o->f38 = *(volatile f32 *)(a + 0x430);
        ((O2AE *)*(u8 **)(a + 0x1DC))->f38 = ((P2AE *)*(u8 **)(a + 0x1DC))->f430;
        if (((P2AE *)*(u8 **)(a + 0x1DC))->w42C & 0x4000000)
            ((O2AE *)*(u8 **)(a + 0x1DC))->f38 = 128.57142639160156f + *(volatile f32 *)(a + 0x430);
        if (((P2AE *)*(u8 **)(a + 0x1DC))->w428 & 0x20000000)
            ((O2AE *)*(u8 **)(a + 0x1DC))->f38 = 57.857139587402344f + *(volatile f32 *)(a + 0x430);
        if (((P2AE *)*(u8 **)(a + 0x1DC))->w428 & 0x10000000)
            ((O2AE *)*(u8 **)(a + 0x1DC))->f38 = 49.28571319580078f + *(volatile f32 *)(a + 0x430);
    }
}

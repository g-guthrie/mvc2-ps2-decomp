typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern u8 D_004B6FB0[];

typedef struct {
    s32 w0;
    s32 w4;
    u8 **p8;
    s32 wc, w10, w14;
    s32 pad[2];
} SA;

void func_001E6B80(u32 n, u8 *obj)
{
    extern void func_004161D0(SA *, s32);
    extern void func_001E6B00(u8 *, SA *);
    extern s32 func_001E6920(u8, s32);
    extern void func_004167D0(u8 *, s32, s32, u8 *, s32, s32, s32, s32);
    extern void func_003DCDC0(s32, s32, s32);
    s32 *pa, *pb, *pc;
    u8 c[0x50], d[0x50];
    SA a, b;
    u32 t;
    s32 r;
    s32 i;
    func_004161D0(&a, *(s32 *)(D_004C2840 + 0x98));
    func_004161D0(&b, *(s32 *)(obj + 0xA8));
    func_001E6B00(d, &a);
    func_001E6B00(c, &b);
    t = n / 10;
    if (t == 0) t = 10;
    r = func_001E6920(t, 3);
    func_004167D0(c, 0, 0, d, r & 0xFF, (u32)r >> 8, 0x20, 0x20);
    pa = (s32 *)&a.p8;
    pc = &b.w14;
    pb = &a.w14;
    func_003DCDC0(*pc, *pb, ((s32 *)*pa)[1]);
    func_004161D0(&b, *(s32 *)(obj + 0xC8));
    func_001E6B00(c, &b);
    r = func_001E6920(n % 10, 3);
    func_004167D0(c, 0, 0, d, r & 0xFF, (u32)r >> 8, 0x20, 0x20);
    func_003DCDC0(*pc, *pb, ((s32 *)*pa)[1]);
    func_004161D0(&b, *(s32 *)(obj + 0x98));
    func_001E6B00(c, &b);
    for (i = 0; i < 4; i++) {
        u8 q = D_004B6FB0[i];
        if (i == 3 && n < 2) q = 10;
        r = func_001E6920(q, 3);
        func_004167D0(c, (i & 1) << 5, (i >> 1) << 5, d, r & 0xFF, (u32)r >> 8, 0x20, 0x20);
    }
    func_003DCDC0(*pc, *pb, ((s32 *)*pa)[1]);
}

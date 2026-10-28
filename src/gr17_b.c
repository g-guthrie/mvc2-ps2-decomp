typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad[0x3C];
    s32 f3C;
} Sub_nq93c;

typedef struct {
    u8 b0;
    s8 b1;
    u8 pad2[6];
    s32 f8;
    s32 fC;
    s32 f10;
    Sub_nq93c *f14;
    s32 f18;
    s32 f1C;
    void (*f20)(s32, s32, s32);
    s32 f24;
    void (*f28)(s32, s32, s32);
    s32 f2C;
    u32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
} Obj_nq93c;

extern s32 D_004C2454;
extern s32 D_004C2448;

void func_00409470(Obj_nq93c *p)
{
    extern void func_00104818(s32, s32);
    extern void func_001046D8(s32, s32);
    extern s32 func_001041A0(u32 *, s32);
    s32 v;
    s32 n;
    s32 c;
    Sub_nq93c *s;

    D_004C2454++;
    if (p->b1 == 1 && p->f8 < p->f14->f3C) {
        func_00104818(p->fC, p->fC + p->f10 - 1);
        p->f20(p->f24, p->fC, p->f10);
        p->f8 = p->f14->f3C;
        p->b1 = 0;
    }
    if ((*(u32 *)p & 0xFFFF00) != 0x10000) return;
    v = D_004C2448;
    if (v != 1) return;
    p->f28(p->f2C, p->fC, p->f10);
    n = p->f8 + 1;
    s = p->f14;
    c = p->fC;
    p->f8 = n;
    s->f3C = n;
    func_001046D8(c, c + p->f10 - 1);
    func_00104818(p->fC, p->fC + p->f10 + 0x3F);
    p->f30 = p->fC & 0xFFFFFFF;
    p->f34 = p->f18;
    p->f38 = p->f1C;
    p->f3C = 0;
    p->f40 = func_001041A0(&p->f30, 1);
    p->b1 = v;
}

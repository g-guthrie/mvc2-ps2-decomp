/* Unit 0x0c112f24-0x0c11308c: 8 functions, all exact. func_0c112f4e
 * matches only when its post-guard body is written inline after a negated
 * `if` guard: an early `return` after the guard makes SHC resume the
 * fr1/fr2/fr3 rotation on a fresh fr3 for the a->f41c reload, while retail
 * keeps it in fr2. */
struct Obj_ud0_01 {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad1[0x38 - 7];
    float f38;
    unsigned char pad2[0x60 - 0x3c];
    float f60;
    unsigned char pad3[0x6c - 0x64];
    float f6c;
    unsigned char pad4[0x141 - 0x70];
    unsigned char b141;
    unsigned char pad5[0x1a1 - 0x142];
    unsigned char b1a1;
    unsigned char pad6[0x1b4 - 0x1a2];
    struct Obj_ud0_01 *p1b4;
    unsigned char pad7[0x1c8 - 0x1b8];
    struct Obj_ud0_01 *p1c8;
    unsigned char pad8[0x1d2 - 0x1cc];
    unsigned char b1d2;
    unsigned char pad9[0x1ea - 0x1d3];
    unsigned char b1ea;
    unsigned char pad10[0x1f6 - 0x1eb];
    unsigned char b1f6;
    unsigned char b1f7;
    unsigned char pad11[0x41c - 0x1f8];
    float f41c;
};

typedef void (*handler_ud0_01)(struct Obj_ud0_01 *);

extern handler_ud0_01 dat_0c24c0c8[];
extern handler_ud0_01 dat_0c24c0d4[];
extern handler_ud0_01 dat_0c24c0e4[];
extern char func_0c02a026(struct Obj_ud0_01 *);
extern void func_0c0438de(struct Obj_ud0_01 *);
extern void func_0c03489c(struct Obj_ud0_01 *);
extern void func_0c03f004(struct Obj_ud0_01 *, struct Obj_ud0_01 *);
extern void func_0c03edcc(struct Obj_ud0_01 *, struct Obj_ud0_01 *);

void func_0c112f24(struct Obj_ud0_01 *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b141 = 0;
        a->b6++;
        a->f6c = -0.80357140303f;
    }
}

void func_0c112f4e(struct Obj_ud0_01 *a)
{
    struct Obj_ud0_01 *p = a->p1c8;

    a->f38 += a->f60;
    a->f60 += a->f6c;
    if (!(a->f38 > a->f41c + -120.0f)) {
        a->f38 = a->f41c;
        a->f60 = 0;
        a->f6c = 0;
        p->p1b4 = a;
        p->b1a1 = 0x24;
        a->b1a1 = 0x24;
        p->b1f6 = 2;
        p->b1d2 = a->b1d2;
        p->b1d2 ^= 1;
        a->b6++;
        func_0c02a026(a);
        func_0c03489c(p);
    }
}

void func_0c112fd0(struct Obj_ud0_01 *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0438de(a);
}

void func_0c112ff2(struct Obj_ud0_01 *a)
{
    dat_0c24c0c8[a->b6](a);
}

void func_0c113004(struct Obj_ud0_01 *a)
{
    a->b1ea = 1;
    dat_0c24c0d4[a->b1f7 & 0x3f](a);
}

void func_0c113022(struct Obj_ud0_01 *a)
{
    dat_0c24c0e4[a->b1f7 & 0x3f](a);
}

void func_0c11303a(struct Obj_ud0_01 *a)
{
    struct Obj_ud0_01 *p = a->p1c8;
    func_0c03f004(p, a);
}

void func_0c113048(struct Obj_ud0_01 *a)
{
    func_0c03edcc(a->p1c8, a);
}

struct Obj_ud0_15 {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad1[28 - 7];
    short s28;
    unsigned char pad2[52 - 30];
    float f52;
    float f38;
    unsigned char pad4[0x5c - 60];
    float f92, f96;
    unsigned char pad5[0x68 - 0x64];
    float f104, f108;
    unsigned char pad6[0x130 - 0x70];
    short w130;
    unsigned char pad7[0x141 - 0x132];
    unsigned char b141;
    unsigned char pad8[0x1f9 - 0x142];
    unsigned char b1f9;
};

extern char func_0c02a026(struct Obj_ud0_15 *);
extern unsigned char func_0c044e52(struct Obj_ud0_15 *);
extern void func_0c0438de(struct Obj_ud0_15 *);
extern void func_0c0442fa(struct Obj_ud0_15 *);
extern void func_0c048bb0(struct Obj_ud0_15 *, int);
extern void func_0c02a0c4(struct Obj_ud0_15 *, int, int);

typedef void (*handler_ud0_15)(struct Obj_ud0_15 *);
extern handler_ud0_15 dat_0c24925c[];

void func_0c0e1ac0(struct Obj_ud0_15 *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f38 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    a->s28--;
    if (a->s28 <= 0 || func_0c044e52(a))
        func_0c0438de(a);
}

void func_0c0e1b2c(struct Obj_ud0_15 *a)
{
    dat_0c24925c[a->b6](a);
}

void func_0c0e1b3e(struct Obj_ud0_15 *a)
{
    a->b6++;
    func_0c0442fa(a);
    func_0c048bb0(a, 32);
    a->b1f9 = 0;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->f92 = a->w130 ? 3.3333333f : -3.3333333f;
    func_0c02a0c4(a, 21, 17);
}

void func_0c0e1b94(struct Obj_ud0_15 *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
    }
}

void func_0c0e1bb8(struct Obj_ud0_15 *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        a->s28 = 60;
    }
}

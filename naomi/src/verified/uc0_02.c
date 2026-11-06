struct Obj_uc0_02 {
    unsigned char pad0[2];
    unsigned char b2;
    unsigned char pad1[7 - 3];
    unsigned char b7;
    unsigned char pad2[28 - 8];
    short s28;
    short s30;
    unsigned char pad3[34 - 32];
    unsigned char b34;
    unsigned char pad4[52 - 35];
    float f52, f56, f60;
    unsigned char pad5[88 - 64];
    float f88, f92, f96, f100, f104, f108, f112, f116;
    unsigned char pad6[0x19e - 120];
    unsigned char b19e;
    unsigned char pad7[0x1a1 - 0x19f];
    unsigned char b1a1;
    unsigned char pad8[0x1ac - 0x1a2];
    short w1ac;
    unsigned char pad9[0x1c4 - 0x1ae];
    unsigned int u1c4;
    unsigned char pad10[0x1d2 - 0x1c8];
    unsigned char b1d2;
    unsigned char pad11[0x327 - 0x1d3];
    unsigned char b327, b328;
    unsigned char pad12[0x3f8 - 0x329];
    unsigned char b3f8, b3f9;
};

struct Table_uc0_02 {
    unsigned char pad[124];
    short counts[64];
};

extern struct Table_uc0_02 *dat_0c2f83f8;
extern void func_0c02a026(struct Obj_uc0_02 *);
extern void func_0c02a0c4(struct Obj_uc0_02 *, int, int);

void func_0c09b9ac(struct Obj_uc0_02 *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (--a->s28 == 0) {
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        a->b7++;
        a->f92 = a->b1d2 ? 5.0f : -5.0f;
        a->f104 = a->b1d2 ? -0.0520833321f : 0.0520833321f;
        a->f96 = -6.4285712242126465f;
        a->f108 = -0.80357140303f;
        a->b1a1 = 63;
        a->w1ac = 0;
        a->b19e = 0;
        a->u1c4 = 0;
        dat_0c2f83f8->counts[a->b2]++;
        func_0c02a0c4(a, 22, 3);
        return;
    }
    if (!a->b19e)
        return;
    if (--a->b34 != 0)
        return;
    a->b34 = 1;
    if (--a->s30 == 0) {
        a->s28 = 1;
    } else {
        a->b1a1 = 62;
        a->w1ac = 0;
        a->b19e = 0;
        a->u1c4 = 0;
        dat_0c2f83f8->counts[a->b2]++;
    }
}

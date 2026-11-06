/* Unit at 0x0c0be5f8. The assigned size of 284 stopped 4 bytes short of the
 * pool's last literal (the tail-call target func_0c02a0c4); the real extent
 * is 288 bytes, one function plus its pool. */

struct Global_ub9_08 {
    unsigned char pad[124];
    short arr[100];
};

struct Obj_ub9_08 {
    unsigned char pad0[0x2];
    unsigned char b2;
    unsigned char pad1[0x1];
    unsigned char b4;
    unsigned char pad2[0x1];
    unsigned char b6;
    unsigned char pad3[0x15];
    short s28;
    unsigned char pad4[0x16];
    float f52;
    float f56;
    unsigned char pad5[0x20];
    float f92;
    float f96;
    unsigned char pad6[0x4];
    float f104;
    float f108;
    unsigned char pad7[0xd1];
    unsigned char b141;
    unsigned char pad8[0x9];
    unsigned char b14b;
    unsigned char pad9[0x52];
    unsigned char b19e;
    unsigned char pad10[0x2];
    unsigned char b1a1;
    unsigned char pad11[0xa];
    unsigned short w1ac;
    unsigned char pad12[0x16];
    int l1c4;
    unsigned char pad13[0x160];
    unsigned char b328;
    unsigned char pad14[0xcf];
    unsigned char b3f8;
};

extern void func_0c02a026(struct Obj_ub9_08 *);
extern int func_0c047bbe(struct Obj_ub9_08 *);
extern void func_0c02a0c4(struct Obj_ub9_08 *, int, int);
extern struct Global_ub9_08 *dat_0c2f83f8;

void func_0c0be5f8(struct Obj_ub9_08 *a, struct Obj_ub9_08 *b)
{
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    if (!a->b141)
        a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->b14b) {
        a->b1a1 = a->b14b;
        a->w1ac = 0;
        a->b19e = 0;
        a->l1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->w1ac = 64;
        a->b14b = 0;
    }
    if (b->b4 && func_0c047bbe(a)) {
        b->b4--;
        return;
    }
    if (--a->s28)
        return;
    a->b6++;
    a->b1a1 = 70;
    a->w1ac = 0;
    a->b19e = 0;
    a->l1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 22, 7);
}

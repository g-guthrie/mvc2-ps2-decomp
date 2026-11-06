/* Unit at 0x0c0aeca0, size 292: a single function func_0c0aeca0 followed by
 * its literal pool (0x0c0aeda0..0x0c0aedc4), ending in a tail call to
 * func_0c02a0c4 emitted as jmp after the epilogue. */

struct Global_ub9_01 {
    unsigned char pad[124];
    short arr[100];
};

struct Obj_ub9_01 {
    unsigned char pad0[0x2];
    unsigned char b2;
    unsigned char pad1[0x3];
    unsigned char b6;
    unsigned char b7;
    unsigned char pad2[0x14];
    short s28;
    short s30;
    unsigned char pad3[0x30];
    float f80;
    float f84;
    unsigned char pad4[0x10];
    float f104;
    float f108;
    unsigned char pad5[0xdb];
    unsigned char b14b;
    unsigned char pad6[0x52];
    unsigned char b19e;
    unsigned char pad7[0x2];
    unsigned char b1a1;
    unsigned char pad8[0xa];
    unsigned short w1ac;
    unsigned char pad9[0x16];
    int l1c4;
    unsigned char pad10[0x2d];
    unsigned char b1f5;
    unsigned char pad11[0x8e];
    float f284;
    float f288;
    unsigned char pad12[0x9c];
    unsigned char b328;
    unsigned char pad13[0xcf];
    unsigned char b3f8;
};

extern void func_0c02a026(struct Obj_ub9_01 *);
extern int func_0c047bbe(struct Obj_ub9_01 *);
extern void func_0c02a0c4(struct Obj_ub9_01 *, int, int);
extern struct Global_ub9_01 *dat_0c2f83f8;

void func_0c0aeca0(struct Obj_ub9_01 *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b1f5 = 3;
    func_0c02a026(a);
    if (a->b14b && a->b14b < 0x80) {
        a->b1a1 = a->b14b + 56;
        a->w1ac = 0;
        a->b19e = 0;
        a->l1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->w1ac = 16;
        a->b14b = 0;
    }
    if (a->f108 < a->f104)
        a->f108 = a->f108 + 1.0f;
    a->f80 = a->f284 + 1.0f * (a->f108 / a->f104);
    a->f84 = a->f288 + 1.0f * (a->f108 / a->f104);
    if (a->s30 && func_0c047bbe(a)) {
        a->s30--;
        a->s28++;
    }
    if (--a->s28 < 0) {
        a->b1f5 = 0;
        a->b6++;
        a->b7 = 0;
        a->f104 = a->f108 = 34.0f;
        func_0c02a0c4(a, 22, 2);
    }
}

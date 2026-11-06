/* Five functions and both shared pools match retail across the 648-byte
 * section. The bit clear is a compound &= 0xfe: SHC reuses the 0x141 member
 * offset to make that mask, and the expanded assignment changes registers.
 * The -12.85714245f spelling lands on retail's 0xc14db6db pool word. */

struct Obj_ub8_04 {
    unsigned char pad0[2];
    unsigned char b2;
    unsigned char pad1[3];
    unsigned char b6;
    unsigned char b7;
    unsigned char pad2[28 - 8];
    short s28;
    short s30;
    unsigned char pad3[52 - 32];
    float f52, f56, f60;
    unsigned char pad4[88 - 64];
    float f88, f92, f96, f100, f104, f108, f112, f116;
    unsigned char pad5[0x130 - 120];
    short w130;
    unsigned char pad6[0x141 - 0x132];
    char b141;
    unsigned char pad7[0x19e - 0x142];
    unsigned char b19e;
    unsigned char pad8[0x1a1 - 0x19f];
    unsigned char b1a1;
    unsigned char pad9[0x1ac - 0x1a2];
    unsigned short w1ac;
    unsigned char pad10[0x1c4 - 0x1ae];
    int i1c4;
    unsigned char pad11[0x1f9 - 0x1c8];
    unsigned char b1f9;
    unsigned char pad12[0x1fe - 0x1fa];
    unsigned char b1fe;
    unsigned char b1ff;
};

struct Table_ub8_04 { unsigned char pad[124]; short arr[1]; };

extern struct Table_ub8_04 *dat_0c2f83f8;
extern char func_0c02a026(struct Obj_ub8_04 *);
extern void func_0c0437b8(struct Obj_ub8_04 *);
extern void func_0c02a0c4(struct Obj_ub8_04 *, int, int);
extern void func_0c044cbc(struct Obj_ub8_04 *);
extern void func_0c048bb0(struct Obj_ub8_04 *, int);
extern void func_0c0346da(struct Obj_ub8_04 *, int);
extern void func_0c043352(struct Obj_ub8_04 *);
extern void func_0c044df4(struct Obj_ub8_04 *);
extern void *dat_0c24d58c[];

void func_0c1221f8(struct Obj_ub8_04 *a)
{
    func_0c02a026(a);
    if (a->b141 & 1) {
        a->b141 &= 0xfe;
        a->f92 = -11.6666667f;
        a->f104 = 0.0f;
        a->f96 = -12.85714245f;
        a->f108 = 0.0f;
        if (a->w130 != 0) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
    }
    if (a->b19e) {
        if (a->s30-- == 0) {
            a->s30 = 2;
            if (a->s28) {
                a->s28 = a->s28 - 1;
                a->b1a1 = 18;
                a->w1ac = 0;
                a->b19e = 0;
                a->i1c4 = 0;
                dat_0c2f83f8->arr[a->b2]++;
            }
        }
    }
}

void func_0c12229a(struct Obj_ub8_04 *a)
{
    ((void (*)(struct Obj_ub8_04 *))dat_0c24d58c[a->b6])(a);
}

void func_0c1222ac(struct Obj_ub8_04 *a)
{
    func_0c044cbc(a);
    func_0c048bb0(a, 5);
    if (a->b1fe == 0) {
        a->b6 = 1;
        a->b1f9 = 0;
        func_0c02a0c4(a, 20, 9);
        a->b1a1 = 21;
        a->w1ac = 0;
        a->b19e = 0;
        a->i1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c0346da(a, 21);
    } else {
        a->b6 = 2;
        a->b7 = 0;
        a->b1f9 = 1;
        func_0c02a0c4(a, 20, 10);
        a->b1a1 = 22;
        a->w1ac = 0;
        a->b19e = 0;
        a->i1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
    }
}

void func_0c122388(struct Obj_ub8_04 *a)
{
    if (a->b1ff == 3)
        func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c1223f8(struct Obj_ub8_04 *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b7 = a->b7 + 1;
        a->f92 = -6.25f;
        a->f104 = 0.1041666642f;
        a->f96 = 16.07143f;
        a->f108 = -0.90401781f;
        if (a->w130 != 0) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
    }
}

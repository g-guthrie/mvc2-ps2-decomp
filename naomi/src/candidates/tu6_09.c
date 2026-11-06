/* Three functions sharing the literal pool at 0x0c19bf92.
 * func_0c19bf1c differs: retail calls func_0c19c91a with `bsr` (the real
 * translation unit extends at least to 0x0c19c91a and its return block sits
 * after the pool at 0x0c19bfbc); an extern call compiles to mov.l + jsr, two
 * bytes longer, which shifts the pool by two bytes so func_0c19be60 and
 * func_0c19beda differ only in pool displacements. */

struct Obj_0c19be60 {
    unsigned char pad0[7];
    unsigned char b7;
    unsigned char pad1[20];
    short s28;
    unsigned char pad2[52 - 30];
    float f52, f56, f60;
    unsigned char pad3[92 - 64];
    float f92, f96, f100, f104, f108, f112;
    unsigned char pad4[0x130 - 116];
    unsigned short w130;
    unsigned char pad5[0x41c - 0x132];
    float f41c;
};

struct Glob_0c2d9260 { unsigned char pad[0x88]; float f88, f8c; };

extern struct Glob_0c2d9260 dat_0c2d9260;
extern int func_0c028642(struct Obj_0c19be60 *a);
extern void func_0c02a0c4(struct Obj_0c19be60 *a, int b, int c);
extern void func_0c02a026(struct Obj_0c19be60 *a);
extern float func_0c19c91a(struct Obj_0c19be60 *b, int n);

void func_0c19beda(struct Obj_0c19be60 *a, struct Obj_0c19be60 *b);

void func_0c19be60(struct Obj_0c19be60 *a, struct Obj_0c19be60 *b)
{
    a->b7++;
    a->s28 = 30;
    a->w130 = b->w130;
    if (!func_0c028642(a)) {
        if (a->w130 == 0) {
            a->f52 = dat_0c2d9260.f8c + 80.0f;
            a->f92 = -7.9166665f;
        } else {
            a->f52 = dat_0c2d9260.f88 + -80.0f;
            a->f92 = 7.9166665f;
        }
    }
    a->f104 = 0.0f;
    a->f56 = b->f41c;
    func_0c02a0c4(a, 23, 13);
    func_0c19beda(a, b);
}

void func_0c19beda(struct Obj_0c19be60 *a, struct Obj_0c19be60 *b)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (--a->s28 == 0) {
        a->b7++;
        a->s28 = 300;
    }
}

void func_0c19bf1c(struct Obj_0c19be60 *a, struct Obj_0c19be60 *b)
{
    float f;

    func_0c02a026(a);
    a->f52 = a->f52 + a->f92;
    a->f92 += a->f104;
    f = func_0c19c91a(b, 56);
    if (--a->s28 == 0 || (a->w130 == 0 && a->f52 <= f) || (a->w130 != 0 && a->f52 >= f)) {
        a->b7++;
        func_0c02a0c4(a, 23, 26);
    }
}

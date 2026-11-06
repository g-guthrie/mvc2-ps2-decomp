/* Five functions sharing the literal pool at 0x0c19c44c. */
struct Obj_tu3_10 {
    unsigned char pad0[7];
    unsigned char b7;
    unsigned char pad1[28 - 8];
    short s28;
    unsigned char pad2[52 - 30];
    float f52;
    unsigned char pad3[92 - 56];
    float f92, f96;
    unsigned char pad4[104 - 100];
    float f104, f108;
    unsigned char pad5[0x130 - 112];
    short w130;
    unsigned char pad6[0x141 - 0x132];
    char b141;
};

typedef void (*handler_tu3_10)(struct Obj_tu3_10 *);

extern handler_tu3_10 dat_0c258844[];
extern float dat_0c2d92e8;
extern float dat_0c2d92ec;
extern void func_0c02a0c4(struct Obj_tu3_10 *, int, int);
extern void func_0c02a026(struct Obj_tu3_10 *);
extern int func_0c02849a(void);
extern void func_0c0344a0(struct Obj_tu3_10 *, int);

void func_0c19c37e(struct Obj_tu3_10 *a);
void func_0c19c414(struct Obj_tu3_10 *a, struct Obj_tu3_10 *b);

void func_0c19c30c(struct Obj_tu3_10 *a)
{
    func_0c19c37e(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    if ((a->w130 == 0 && a->f52 <= dat_0c2d92e8 + 46.666666f)
        || (a->w130 != 0 && a->f52 >= dat_0c2d92ec + -46.666666f)) {
        a->b7++;
        func_0c02a0c4(a, 23, 21);
    }
}

void func_0c19c37e(struct Obj_tu3_10 *a)
{
    func_0c02a026(a);
    if (--a->s28 == 0) {
        a->s28 = (func_0c02849a() & 31) + 60;
        func_0c0344a0(a, 26);
    }
}

void func_0c19c3b2(struct Obj_tu3_10 *a)
{
    dat_0c258844[a->b7](a);
}

void func_0c19c3c4(struct Obj_tu3_10 *a, struct Obj_tu3_10 *b)
{
    a->b7++;
    a->f92 = 0.0f;
    a->f104 = 0.0f;
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    if (a->f52 < b->f52)
        a->w130 = 1;
    else
        a->w130 = 0;
    func_0c02a0c4(a, 23, 0);
    func_0c19c414(a, b);
}

void func_0c19c414(struct Obj_tu3_10 *a, struct Obj_tu3_10 *b)
{
    func_0c02a026(a);
    if (!b->b141) {
        a->b7++;
        func_0c02a0c4(a, 23, 18);
    }
}

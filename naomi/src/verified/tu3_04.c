/* Four functions sharing the literal pool at 0x0c0c13c0. */
struct Obj_tu3_04 {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad1[20 - 7];
    int l20;
    unsigned char pad2[28 - 24];
    short s28;
    unsigned char pad3[56 - 30];
    float f56;
    unsigned char pad4[96 - 60];
    float f96;
    unsigned char pad5[108 - 100];
    float f108;
    unsigned char pad6[0x12c - 112];
    unsigned char b12c;
    unsigned char pad7[0x41c - 0x12d];
    float f41c;
};

typedef void (*handler_tu3_04)(struct Obj_tu3_04 *);

extern handler_tu3_04 dat_0c24685c[];
extern int dat_0c245e5c[];
extern void func_0c02a0c4(struct Obj_tu3_04 *, int, int);
extern void func_0c0c4fb4(struct Obj_tu3_04 *, int);
extern int func_0c1aa314(struct Obj_tu3_04 *, int);
extern void func_0c0344a0(struct Obj_tu3_04 *, int);
extern void func_0c0c4f04(struct Obj_tu3_04 *, int *);
extern void func_0c1a9cf0(struct Obj_tu3_04 *, int);
extern void func_0c02a026(struct Obj_tu3_04 *);

void func_0c0c1314(struct Obj_tu3_04 *a);

void func_0c0c1278(struct Obj_tu3_04 *a)
{
    dat_0c24685c[a->b6](a);
}

void func_0c0c128a(struct Obj_tu3_04 *a)
{
    a->b6 = a->b6 + 1;
    a->b12c = 1;
    a->s28 = 16;
    a->f56 = a->f41c + 426.66666f;
    a->f96 = -17.142857f;
    a->f108 = -0.80357143f;
    func_0c02a0c4(a, 18, 0);
    func_0c0c4fb4(a, 0);
    func_0c1aa314(a, 1);
    func_0c1aa314(a, 2);
    func_0c1aa314(a, 3);
    func_0c1aa314(a, 4);
    func_0c1aa314(a, 5);
    func_0c1aa314(a, 6);
    func_0c1aa314(a, 7);
    func_0c1aa314(a, 8);
    a->l20 = func_0c1aa314(a, 0);
    func_0c0c1314(a);
}

void func_0c0c1314(struct Obj_tu3_04 *a)
{
    if (--a->s28 == 0) {
        a->b6++;
        func_0c0344a0(a, 33);
    }
    a->f56 += a->f96;
    a->f96 += a->f108;
}

void func_0c0c1356(struct Obj_tu3_04 *a)
{
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f41c < a->f56)
        return;
    a->b6++;
    a->f56 = a->f41c;
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    a->s28 = 34;
    func_0c0c4f04(a, dat_0c245e5c);
    func_0c1a9cf0(a, 6);
    func_0c02a026(a);
}

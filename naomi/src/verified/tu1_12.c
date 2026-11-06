/* Three functions sharing the literal pool at 0x0c0aa25c. */

struct Sub2a4_tu1_12 { unsigned char pad[10]; short s10; };

struct Obj_tu1_12 {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char b7;
    unsigned char pad1[20 - 8];
    struct Obj_tu1_12 *p20;
    unsigned char pad2[28 - 24];
    short s28;
    unsigned char pad3[52 - 30];
    float f52, f56;
    unsigned char pad4[92 - 60];
    float f92, f96, f100, f104, f108;
    unsigned char pad5[0x130 - 112];
    short w130;
    unsigned char pad6[0x2a4 - 0x132];
    struct Sub2a4_tu1_12 sub2a4;
};

struct Glob_0c2f83f8 { unsigned char b0; };

typedef void (*fn_tu1_12)(struct Obj_tu1_12 *, struct Sub2a4_tu1_12 *);

extern struct Glob_0c2f83f8 *dat_0c2f83f8;
extern fn_tu1_12 dat_0c244544[];
extern fn_tu1_12 dat_0c244558[];
extern void func_0c02a0c4(struct Obj_tu1_12 *a, int b, int c);
extern int func_0c026a86(void);

void func_0c0aa170(struct Obj_tu1_12 *a)
{
    struct Obj_tu1_12 *b = a->p20;
    float x;

    a->b6++;
    func_0c02a0c4(a, 22, 7);
    a->f96 = 20.357141494750977f;
    a->f108 = -0.9040178298950196f;
    x = 53.33333206176758f;
    if (a->w130)
        x = -53.33333206176758f;
    a->f92 = (b->f52 + x - a->f52) / 46.0f;
    a->f96 += (b->f56 - a->f56 + 222.85713806152344f) / 46.0f;
    a->s28 = 46;
}

void func_0c0aa1ea(struct Obj_tu1_12 *a)
{
    struct Sub2a4_tu1_12 *s = &a->sub2a4;

    if (dat_0c2f83f8->b0 >= 5) {
        if (func_0c026a86() == 0)
            s->s10 = 0;
    }
    if (--s->s10 <= 0) {
        if (a->b6 != 4) {
            a->b6 = 4;
            a->b7 = 0;
        }
    }
    dat_0c244544[a->b6](a, &a->sub2a4);
}

void func_0c0aa246(struct Obj_tu1_12 *a)
{
    dat_0c244558[a->b7](a, &a->sub2a4);
}

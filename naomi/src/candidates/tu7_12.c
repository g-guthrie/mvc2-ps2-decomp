/* 286/288. func_0c16170c, func_0c161728, func_0c16178e and the pool match.
 * func_0c161782's tail loads func_0c037688 into r2; retail uses r3.
 * The goto keeps the zero store ahead of that load (a direct call sinks it).
 * Imports: __slow_mvn=0x0c1fb838, __quick_odd_mvn=0x0c1fb7a0. */
struct V3_tu7_12 { float x, y, z; };
struct Copy_c0_tu7_12 { unsigned char raw[0xc0]; };
struct Link_tu7_12 { unsigned char pad0[2]; unsigned char b2; };

struct Obj_tu7_12 {
    unsigned char pad0[1];
    unsigned char b1, b2;
    unsigned char pad1[1];
    unsigned char b4;
    unsigned char pad2[24 - 5];
    struct Obj_tu7_12 *p24;
    unsigned char pad3[36 - 28];
    unsigned char b36;
    unsigned char pad4[48 - 37];
    unsigned char b48;
    unsigned char pad5[52 - 49];
    float f52, f56, f60;
    unsigned char pad6[80 - 64];
    struct V3_tu7_12 v80;
    float f92, f96, f100, f104, f108, f112;
    unsigned char pad7[0xdc - 116];
    union {
        struct Copy_c0_tu7_12 s0dc;
        struct {
            unsigned char pad8[0x12c - 0xdc];
            unsigned char b12c;
            unsigned char pad9[0x13c - 0x12d];
            unsigned char b13c, b13d, b13e, b13f;
        } u;
    } v;
    unsigned char pad10[0x1a3 - 0x19c];
    unsigned char b1a3, b1a4;
    unsigned char pad11[0x2a4 - 0x1a5];
    struct Link_tu7_12 s2a4;
};

extern char func_0c02a026(struct Obj_tu7_12 *);
extern void func_0c037688(struct Obj_tu7_12 *);

void func_0c16170c(struct Obj_tu7_12 *a)
{
    struct Link_tu7_12 *s;
    a->b4 = 2;
    s = &a->p24->s2a4;
    if (a->b1 == a->p24->b1)
        s->b2 = 0;
}

void func_0c161728(struct Obj_tu7_12 *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0) {
        a->b4 = 2;
        a->v.u.b12c = 0;
    }
}

void func_0c161782(struct Obj_tu7_12 *a)
{
    a->v.u.b12c = 0;
    goto call;
call:
    func_0c037688(a + 0);
}

void func_0c16178e(struct Obj_tu7_12 *a)
{
    a->v.s0dc = a->p24->v.s0dc;
    a->v.u.b12c = 1;
    a->b2 = a->p24->b2;
    a->b1 = a->p24->b1;
    a->v80.x = a->p24->v80.x;
    a->v80.y = a->p24->v80.y;
    a->b1a3 = a->p24->b1a3;
    a->b1a4 = a->p24->b1a4;
    a->b48 = a->p24->b48;
    a->v80 = a->p24->v80;
    a->b36 = a->p24->b36;
    a->v.u.b13c = a->v.u.b13d = 32;
    a->v.u.b13e = a->v.u.b13f = 36;
    a->b36 = 11;
}

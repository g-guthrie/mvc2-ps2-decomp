/* Two functions sharing the literal pool at 0x0c172668. 315/412 bytes match.
 * func_0c172638 differs: retail tail-calls func_0c172d2e (outside this unit)
 * with a 2-byte `bra`, which SHC only emits for a callee in the same file;
 * ours is `mov.l`+`jmp`, 2 bytes longer with one more pool entry, so every
 * pool displacement in the unit shifts by one word. func_0c172508 is otherwise
 * instruction for instruction identical to retail.
 * Runtime imports: __slow_mvn=0x0c1fb838, __quick_odd_mvn=0x0c1fb7a0. */
struct Copy_c0 { unsigned char raw[0xc0]; };
struct Copy_0c { float f0, f4, f8; };
struct Sub_tu3_01 { short w0, w2, w4; };

struct Obj_tu3_01 {
    unsigned char pad0[1];
    unsigned char b1, b2;
    unsigned char pad1[1];
    unsigned char b4, b5;
    unsigned char pad2[0x21 - 6];
    char b33;
    unsigned char pad3[0x24 - 0x22];
    unsigned char b36;
    unsigned char pad4[0x30 - 0x25];
    unsigned char b48; char b49;
    unsigned char pad5[0x34 - 0x32];
    float f52, f56, f60;
    unsigned char pad6[0x50 - 0x40];
    struct Copy_0c s80;
    float f92, f96;
    unsigned char pad8[0x68 - 0x64];
    float f104, f108;
    unsigned char pad9[0xcc - 0x70];
    struct Sub_tu3_01 s0cc;
    unsigned char pad10[0xdc - 0xd2];
    union {
        struct Copy_c0 s0dc;
        struct {
            unsigned char pad11[0x12c - 0xdc];
            char b12c;
            unsigned char pad12[0x13c - 0x12d];
            char b13c, b13d;
            unsigned char pad13[0x159 - 0x13e];
            char b159;
        } u;
    } v;
    unsigned char b19c, b19d, b19e;
    unsigned char pad15[0x1a1 - 0x19f];
    unsigned char b1a1;
    unsigned char pad16[1];
    unsigned char b1a3, b1a4;
    unsigned char pad17[0x1ac - 0x1a5];
    short w1ac;
    unsigned char pad18[0x1c4 - 0x1ae];
    int l1c4;
    unsigned char pad19[0x20c - 0x1c8];
    struct Obj_tu3_01 *p20c;
    unsigned char pad20[0x41c - 0x210];
    float f41c;
};

struct Counters_tu3_01 { unsigned char pad[0x7c]; short w[1]; };

extern struct Counters_tu3_01 *dat_0c2f83f8;
extern short dat_0c252970[];
extern void (*dat_0c252990[])(struct Obj_tu3_01 *);
extern int func_0c02849a(void);
extern void func_0c02a0c4(struct Obj_tu3_01 *, int, int);
extern void func_0c172d2e(struct Obj_tu3_01 *);

void func_0c172638(struct Obj_tu3_01 *a, struct Obj_tu3_01 *b);

void func_0c172508(struct Obj_tu3_01 *a, struct Obj_tu3_01 *b)
{
    struct Obj_tu3_01 *t = b->p20c;
    struct Sub_tu3_01 *s = &a->s0cc;
    a->b4 = a->b4 + 1;
    a->v.s0dc = b->v.s0dc;
    a->v.u.b12c = 1;
    a->b2 = b->b2;
    a->b1 = b->b1;
    a->s80.f0 = b->s80.f0;
    a->s80.f4 = b->s80.f4;
    a->b1a3 = b->b1a3;
    a->b1a4 = b->b1a4;
    a->b48 = b->b48;
    a->s80 = b->s80;
    a->b36 = b->b36;
    a->v.u.b12c = 1;
    a->b49 = 1;
    a->b1a1 = 62;
    a->w1ac = 0;
    a->b19e = 0;
    a->l1c4 = 0;
    dat_0c2f83f8->w[a->b2]++;
    a->b19c = 66;
    a->b19d = 66;
    a->v.u.b13c = a->v.u.b13d = 68;
    a->f52 = b->f52;
    a->f56 = b->f56;
    a->f60 = b->f60;
    a->f52 += (float)dat_0c252970[func_0c02849a() & 15];
    a->f92 = 0.0f;
    a->f104 = 0.0f;
    a->f96 = 34.285714f;
    a->f108 = 0.26785714f;
    s->w2 = (short)t->f52;
    s->w4 = (short)(b->f41c + 960.0f);
    func_0c02a0c4(a, 23, a->b33 + 32);
    func_0c172638(a, b);
}

void func_0c172638(struct Obj_tu3_01 *a, struct Obj_tu3_01 *b)
{
    if (b->v.u.b159 != 22 || b->b5) {
        func_0c172d2e(a);
        return;
    }
    a->b36 = b->b36;
    dat_0c252990[a->b5](a);
}

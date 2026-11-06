struct Obj_0c177688 {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[16 - 5];
    void (*p16)(struct Obj_0c177688 *);
    unsigned char pad2[24 - 20];
    struct Obj_0c177688 *p24;
    short s28;
    unsigned char pad3[32 - 30];
    unsigned char b32;
    unsigned char pad4[34 - 33];
    unsigned char b34;
    unsigned char pad5[36 - 35];
    unsigned char b36;
    unsigned char pad6[38 - 37];
    short s38;
    unsigned char pad7[42 - 40];
    unsigned char b42;
    unsigned char pad8[0x88 - 43];
    unsigned char sub88;
    unsigned char pad9[0x12c - 0x89];
    unsigned char b12c;
    unsigned char pad10[0x1d3 - 0x12d];
    unsigned char b1d3;
};

typedef void (*handler2_0c177688)(struct Obj_0c177688 *, unsigned char *);
typedef void (*handler_0c177688)(struct Obj_0c177688 *);

extern struct Obj_0c177688 *func_0c0374da(int a, int b, int c);
extern handler2_0c177688 dat_0c2536dc[];
extern handler_0c177688 dat_0c2536ec[];

void func_0c1776ba(struct Obj_0c177688 *p);
void func_0c1776f2(struct Obj_0c177688 *p, struct Obj_0c177688 *r);

struct Obj_0c177688 *func_0c177688(struct Obj_0c177688 *p)
{
    struct Obj_0c177688 *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c1776ba;
        q->p24 = p;
        q->s38 = 0x3003;
        q->b32 = 0;
    }
    return q;
}

void func_0c1776ba(struct Obj_0c177688 *p)
{
    p->b36 = p->p24->b36;
    if (p->b32) {
        if (p->s28)
            return;
    }
    p->b12c = 0;
    dat_0c2536dc[p->b4](p, &p->sub88);
}

void func_0c1776f2(struct Obj_0c177688 *p, struct Obj_0c177688 *r)
{
    struct Obj_0c177688 *q;

    q = p->p24;
    r->b42 = q->b1d3;
    p->b34 = q->b34;
    dat_0c2536ec[p->b32](p);
}

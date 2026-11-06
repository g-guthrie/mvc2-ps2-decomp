struct Obj_0c17a03c {
    unsigned char pad0[1];
    unsigned char b1;
    unsigned char pad1[4 - 2];
    unsigned char b4;
    unsigned char pad2[16 - 5];
    void (*p16)(struct Obj_0c17a03c *);
    unsigned char pad3[24 - 20];
    struct Obj_0c17a03c *p24;
    unsigned char pad4[32 - 28];
    unsigned char b32;
    unsigned char b33;
    unsigned char pad5[38 - 34];
    short s38;
};

typedef void (*handler2_0c17a03c)(struct Obj_0c17a03c *, struct Obj_0c17a03c *);
typedef void (*handler_0c17a03c)(struct Obj_0c17a03c *);

extern struct Obj_0c17a03c *func_0c0374da(int a, int b, int c);
extern handler2_0c17a03c dat_0c2538a0[];
extern handler_0c17a03c dat_0c2538a8[];

void func_0c17a08a(struct Obj_0c17a03c *p);
void func_0c17a0a0(struct Obj_0c17a03c *p);

struct Obj_0c17a03c *func_0c17a03c(struct Obj_0c17a03c *p, unsigned char b, unsigned char c)
{
    struct Obj_0c17a03c *q;

    if ((q = func_0c0374da(0, 2, 0)) != 0) {
        q->p16 = func_0c17a08a;
        q->s38 = 0x3303;
        q->p24 = p;
        q->b1 = p->b1;
        *(&q->b32) = b;
        *(&q->b33) = c;
    }
    return q;
}

void func_0c17a08a(struct Obj_0c17a03c *p)
{
    dat_0c2538a0[p->b32](p, p->p24);
}

void func_0c17a0a0(struct Obj_0c17a03c *p)
{
    dat_0c2538a8[p->b4](p);
}

struct Obj_0c162d9c {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[16 - 5];
    void (*p16)(struct Obj_0c162d9c *);
    unsigned char pad2[24 - 20];
    struct Obj_0c162d9c *p24;
    unsigned char pad3[32 - 28];
    unsigned char b32;
    unsigned char pad4[38 - 33];
    short s38;
    unsigned char pad5[0xcc - 40];
    int lcc;
    unsigned char pad6[0x159 - 0xd0];
    unsigned char b159;
    unsigned char pad7[0x2f8 - 0x15a];
    int l2f8;
};

typedef void (*handler_0c162d9c)(struct Obj_0c162d9c *);

extern struct Obj_0c162d9c *func_0c0374da(int a, int b, int c);
extern handler_0c162d9c dat_0c251640[];

void func_0c162de4(struct Obj_0c162d9c *p);

struct Obj_0c162d9c *func_0c162d9c(struct Obj_0c162d9c *p, unsigned char b)
{
    struct Obj_0c162d9c *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c162de4;
        q->p24 = p;
        q->b32 = b;
        q->s38 = 0x1f01;
        q->lcc = p->b159;
        p->l2f8 = 1;
    }
    return q;
}

void func_0c162de4(struct Obj_0c162d9c *p)
{
    dat_0c251640[p->b4](p);
}

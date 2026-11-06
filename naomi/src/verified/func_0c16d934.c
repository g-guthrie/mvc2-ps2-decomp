struct Obj_0c16d934 {
    unsigned char pad0[1];
    unsigned char b1;
    unsigned char pad1[4 - 2];
    unsigned char b4;
    unsigned char pad2[16 - 5];
    void (*p16)(struct Obj_0c16d934 *);
    unsigned char pad3[24 - 20];
    struct Obj_0c16d934 *p24;
    unsigned char pad4[34 - 28];
    unsigned char b34;
    unsigned char pad5[38 - 35];
    short s38;
    unsigned char pad6[0xcc - 40];
    int lcc;
    unsigned char pad7[0x158 - 0xd0];
    unsigned short w158;
};

typedef void (*handler_0c16d934)(struct Obj_0c16d934 *, struct Obj_0c16d934 *);

extern struct Obj_0c16d934 *func_0c0374da(int a, int b, int c);
extern handler_0c16d934 dat_0c25252c[];

void func_0c16d97a(struct Obj_0c16d934 *p);

struct Obj_0c16d934 *func_0c16d934(struct Obj_0c16d934 *p, unsigned char b)
{
    struct Obj_0c16d934 *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c16d97a;
        q->p24 = p;
        q->b1 = p->b1;
        q->b34 = b;
        q->s38 = 0x2a04;
        q->lcc = p->w158;
    }
    return q;
}

void func_0c16d97a(struct Obj_0c16d934 *p)
{
    dat_0c25252c[p->b4](p, p->p24);
}

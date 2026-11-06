struct Obj_0c189224 {
    unsigned char pad0[1];
    unsigned char b1;
    unsigned char pad1[4 - 2];
    unsigned char b4;
    unsigned char pad2[16 - 5];
    void (*p16)(struct Obj_0c189224 *);
    unsigned char pad3[24 - 20];
    struct Obj_0c189224 *p24;
    short s28;
    unsigned char pad4[32 - 30];
    unsigned char b32;
    unsigned char pad5[38 - 33];
    short s38;
    unsigned char pad6[0xcc - 40];
    int lcc;
    unsigned char pad7[0x158 - 0xd0];
    unsigned short w158;
};

typedef void (*handler_0c189224)(struct Obj_0c189224 *, struct Obj_0c189224 *);

extern struct Obj_0c189224 *func_0c0374da(int a, int b, int c);
extern handler_0c189224 dat_0c2560a4[];

void func_0c189270(struct Obj_0c189224 *p);

struct Obj_0c189224 *func_0c189224(struct Obj_0c189224 *p, int b, int c)
{
    struct Obj_0c189224 *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c189270;
        q->p24 = p;
        q->b1 = p->b1;
        q->s28 = c;
        q->b32 = b;
        q->s38 = 0x3a00;
        q->lcc = p->w158;
    }
    return q;
}

void func_0c189270(struct Obj_0c189224 *p)
{
    dat_0c2560a4[p->b4](p, p->p24);
}

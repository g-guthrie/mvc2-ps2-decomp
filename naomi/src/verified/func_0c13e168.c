struct Obj_0c13e168 {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[16 - 5];
    void (*p16)(struct Obj_0c13e168 *);
    unsigned char pad2[24 - 20];
    struct Obj_0c13e168 *p24;
    short s28;
    unsigned char pad3[38 - 30];
    short s38;
    unsigned char pad4[0x158 - 40];
    short w158;
};

typedef void (*handler_0c13e168)(struct Obj_0c13e168 *);

extern struct Obj_0c13e168 *func_0c0374da(int a, int b, int c);
extern handler_0c13e168 dat_0c24f4b8[];

void func_0c13e198(struct Obj_0c13e168 *p);

struct Obj_0c13e168 *func_0c13e168(struct Obj_0c13e168 *p)
{
    struct Obj_0c13e168 *q;

    q = func_0c0374da(0, 1, 0);
    q->p16 = func_0c13e198;
    q->p24 = p;
    q->s38 = 0x0904;
    q->s28 = p->w158;
    return q;
}

void func_0c13e198(struct Obj_0c13e168 *p)
{
    dat_0c24f4b8[p->b4](p);
}

struct Obj_0c150268 {
    unsigned char pad0[1];
    unsigned char b1;
    unsigned char pad1[16 - 2];
    void (*p16)(struct Obj_0c150268 *);
    unsigned char pad2[24 - 20];
    struct Obj_0c150268 *p24;
    unsigned char pad3[30 - 28];
    short s30;
    unsigned char b32;
    unsigned char pad4[38 - 33];
    short s38;
    unsigned char pad5[0xcc - 40];
    short scc;
    unsigned char pad6[0xd0 - 0xce];
    float fd0;
    unsigned char pad7[0x158 - 0xd4];
    unsigned short w158;
    unsigned char pad8[0x41c - 0x15a];
    float f41c;
};

extern struct Obj_0c150268 *func_0c0374da(int a, int b, int c);
extern void func_0c150424(struct Obj_0c150268 *p);

struct Obj_0c150268 *func_0c150268(struct Obj_0c150268 *p, unsigned char b)
{
    struct Obj_0c150268 *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c150424;
        q->b1 = p->b1;
        q->s38 = 0x1401;
        q->b32 = b;
        q->p24 = p;
        q->scc = p->w158;
        q->fd0 = p->f41c;
        q->s30 = 0;
    }
    return q;
}

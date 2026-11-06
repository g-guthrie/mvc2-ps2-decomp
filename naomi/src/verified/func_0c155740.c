struct Obj_0c155740 {
    unsigned char pad0[1];
    unsigned char b1;
    unsigned char pad1[4 - 2];
    unsigned char b4;
    unsigned char pad2[16 - 5];
    void (*p16)(struct Obj_0c155740 *);
    unsigned char pad3[24 - 20];
    struct Obj_0c155740 *p24;
    unsigned char pad4[32 - 28];
    unsigned char b32;
    unsigned char pad5[38 - 33];
    short s38;
    unsigned char pad6[0x88 - 40];
    unsigned char sub88[1];
    unsigned char pad7[0x130 - 0x89];
    short w130;
};

typedef void (*handler_0c155740)(struct Obj_0c155740 *, struct Obj_0c155740 *, unsigned char *);

extern struct Obj_0c155740 *func_0c0374da(int a, int b, int c);
extern handler_0c155740 dat_0c2506b4[];

void func_0c155782(struct Obj_0c155740 *p);

struct Obj_0c155740 *func_0c155740(struct Obj_0c155740 *p, unsigned char b)
{
    struct Obj_0c155740 *q;

    if ((q = func_0c0374da(0, 1, 1)) != 0) {
        q->p16 = func_0c155782;
        q->p24 = p;
        q->b32 = b;
        q->s38 = 0x1701;
        q->w130 = p->w130;
    }
    return q;
}

void func_0c155782(struct Obj_0c155740 *p)
{
    dat_0c2506b4[p->b4](p, p->p24, p->sub88);
}

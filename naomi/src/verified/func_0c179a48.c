struct Obj_0c179a48 {
    unsigned char pad0[1];
    unsigned char b1;
    unsigned char pad1[4 - 2];
    unsigned char b4;
    unsigned char pad2[16 - 5];
    void (*p16)(struct Obj_0c179a48 *);
    struct Obj_0c179a48 *p20;
    struct Obj_0c179a48 *p24;
    unsigned char pad3[32 - 28];
    unsigned char b32;
    unsigned char b33;
    unsigned char pad4[38 - 34];
    short s38;
};

typedef void (*handler2_0c179a48)(struct Obj_0c179a48 *, struct Obj_0c179a48 *);
typedef void (*handler_0c179a48)(struct Obj_0c179a48 *);

extern struct Obj_0c179a48 *func_0c0374da(int a, int b, int c);
extern handler2_0c179a48 dat_0c25386c[];
extern handler_0c179a48 dat_0c253874[];

void func_0c179ae4(struct Obj_0c179a48 *p);
void func_0c179afa(struct Obj_0c179a48 *p);

struct Obj_0c179a48 *func_0c179a48(struct Obj_0c179a48 *p, unsigned char b, unsigned char c)
{
    struct Obj_0c179a48 *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c179ae4;
        q->s38 = 0x3302;
        q->p24 = p;
        q->b1 = p->b1;
        *(&q->b32) = b;
        *(&q->b33) = c;
    }
    return q;
}

struct Obj_0c179a48 *func_0c179a96(struct Obj_0c179a48 *p, unsigned char b, unsigned char c)
{
    struct Obj_0c179a48 *q;

    if ((q = func_0c0374da((int)p, 1, 2)) != 0) {
        q->p16 = func_0c179ae4;
        q->s38 = 0x3302;
        q->p20 = p;
        q->b1 = p->b1;
        q->p24 = p->p24;
        q->b32 = b;
        q->b33 = c;
    }
    return q;
}

void func_0c179ae4(struct Obj_0c179a48 *p)
{
    dat_0c25386c[p->b32](p, p->p24);
}

void func_0c179afa(struct Obj_0c179a48 *p)
{
    dat_0c253874[p->b4](p);
}

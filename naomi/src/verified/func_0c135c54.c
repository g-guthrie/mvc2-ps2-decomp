struct Obj_0c135c54 {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[16 - 5];
    void (*p16)(struct Obj_0c135c54 *);
    unsigned char pad2[24 - 20];
    struct Obj_0c135c54 *p24;
    unsigned char pad3[32 - 28];
    unsigned char b32;
    unsigned char pad4[38 - 33];
    short s38;
};

typedef void (*handler_0c135c54)(struct Obj_0c135c54 *);

extern struct Obj_0c135c54 *func_0c0374da(int a, int b, int c);
extern handler_0c135c54 dat_0c24e530[];

void func_0c135c88(struct Obj_0c135c54 *p);

struct Obj_0c135c54 *func_0c135c54(struct Obj_0c135c54 *p, unsigned char b)
{
    struct Obj_0c135c54 *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c135c88;
        q->p24 = p;
        q->b32 = b;
        q->s38 = 0x0402;
    }
    return q;
}

void func_0c135c88(struct Obj_0c135c54 *p)
{
    dat_0c24e530[p->b4](p);
}

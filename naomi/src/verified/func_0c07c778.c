struct Obj_0c07c778 {
    unsigned char pad0[34];
    unsigned char b34;
    unsigned char pad1[52 - 35];
    float f52, f56;
    unsigned char pad2[0x1a3 - 60];
    unsigned char b1a3;
    unsigned char pad3[0x1f7 - 0x1a4];
    unsigned char b1f7;
    unsigned char pad4[0x1fa - 0x1f8];
    unsigned short w1fa;
    unsigned char pad5[0x1fe - 0x1fc];
    char b1fe;
};

typedef void (*handler_0c07c778)(struct Obj_0c07c778 *);

extern struct Obj_0c07c778 *func_0c037d54(struct Obj_0c07c778 *);
extern handler_0c07c778 dat_0c241764[];

void func_0c07c7d8(struct Obj_0c07c778 *p);

struct Obj_0c07c778 *func_0c07c778(struct Obj_0c07c778 *p)
{
    int z;
    struct Obj_0c07c778 *q;

    z = 0;
    if (!(p->b34 = (p->w1fa & 0x0c00) >> 10))
        return (struct Obj_0c07c778 *)z;
    if (p->b1fe)
        return (struct Obj_0c07c778 *)z;
    if (p->b1a3 != 1)
        return (struct Obj_0c07c778 *)z;
    if (p->f56 > 137.142853f) {
        if ((q = func_0c037d54(p)) != 0) {
            p->b1f7 = 2;
            return q;
        }
    }
    return (struct Obj_0c07c778 *)z;
}

void func_0c07c7d8(struct Obj_0c07c778 *p)
{
    dat_0c241764[p->b1f7 & 63](p);
}

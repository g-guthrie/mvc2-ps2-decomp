/* Assembled by tools/clone.py from verified twins. */
struct Obj_0c07c778 {
    unsigned char pad0[34];
    unsigned char b34;
    unsigned char pad1[52 - 35];
    float f52, f56;
    unsigned char pad2[0x130 - 60];
    unsigned short w130;
    unsigned char pad2b[0x1a0 - 0x132];
    unsigned char b1a0;
    unsigned char pad2c[0x1a3 - 0x1a1];
    unsigned char b1a3;
    unsigned char pad3[0x1d2 - 0x1a4];
    unsigned char b1d2;
    unsigned char pad3b[0x1f7 - 0x1d3];
    unsigned char b1f7;
    unsigned char pad4[0x1fa - 0x1f8];
    unsigned short w1fa;
    unsigned char pad5[0x1fe - 0x1fc];
    char b1fe;
};
struct Vec3_me04 { float x, y, z; };
typedef void (*handler_0c07c778)(struct Obj_0c07c778 *);
extern void func_0c1d4610(struct Obj_0c07c778 *, struct Vec3_me04 *);
extern void func_0c048ce6(struct Obj_0c07c778 *);
extern void func_0c02a0c4(struct Obj_0c07c778 *, int, int);
extern struct Obj_0c07c778 *func_0c037d54(struct Obj_0c07c778 *);
extern handler_0c07c778 dat_0c241764[];
void func_0c07c7d8(struct Obj_0c07c778 *p);
extern handler_0c07c778 dat_0c2442ac[];

struct Obj_0c07c778 *func_0c0a6c8c(struct Obj_0c07c778 *p)
{
    int z;
    struct Obj_0c07c778 *q;

    z = 0;
    if (!(p->b34 = (p->w1fa & 0x1c00) >> 10))
        return (struct Obj_0c07c778 *)z;
    if (p->b1fe)
        return (struct Obj_0c07c778 *)z;
    if (p->b1a3 != 1)
        return (struct Obj_0c07c778 *)z;
    if (p->f56 > 137.142853f) {
        if ((q = func_0c037d54(p)) != 0) {
            p->b1f7 = 1;
            return q;
        }
    }
    return (struct Obj_0c07c778 *)z;
}

void func_0c0a6cec(struct Obj_0c07c778 *p)
{
    dat_0c2442ac[p->b1f7 & 63](p);
}

void func_0c0a6d04(struct Obj_0c07c778 *a)
{
    struct Vec3_me04 v;

    if (a->w1fa & 0x400) {
        a->b1d2 = a->b1d2 ^ 1;
        a->w130 = a->w130 ^ 1;
    }
    a->b1a0 = 10;
    v.x = -83.33333f;
    v.y = 158.57143f;
    func_0c1d4610(a, &v);
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 0);
}

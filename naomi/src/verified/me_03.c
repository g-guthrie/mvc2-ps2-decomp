/* Assembled by tools/clone.py from verified twins. */
struct Vec3_ud0_12 { float x, y, z; };

struct Obj_ud0_12 {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad0b[28 - 7];
    short s28;
    unsigned char pad1[0x22 - 30];
    unsigned char b34;
    unsigned char pad2[0x5c - 0x23];
    float f92, f96;
    unsigned char pad3[0x68 - 0x64];
    float f104, f108;
    unsigned char pad3b[0x130 - 0x70];
    unsigned short w130;
    unsigned char pad3c[0x141 - 0x132];
    unsigned char b141;
    unsigned char pad4[0x1a0 - 0x142];
    unsigned char b1a0;
    unsigned char b1a1;
    unsigned char pad5[0x1c8 - 0x1a2];
    struct Obj_ud0_12 *p1c8;
    unsigned char pad5b[0x1d2 - 0x1cc];
    unsigned char b1d2;
    unsigned char pad6[0x1f6 - 0x1d3];
    unsigned char b1f6;
    unsigned char b1f7;
    unsigned char pad7;
    unsigned char b1f9;
};
typedef void (*handler_ud0_12)(struct Obj_ud0_12 *);
extern handler_ud0_12 dat_0c24b69c[];
extern void func_0c02a0c4(struct Obj_ud0_12 *, int, int);
extern void func_0c1d4610(struct Obj_ud0_12 *, struct Vec3_ud0_12 *);
extern void func_0c048ce6(struct Obj_ud0_12 *);
extern void func_0c199414(struct Obj_ud0_12 *, int, int);
extern void func_0c0344a0(struct Obj_ud0_12 *, int);
struct Obj_0c03f15c {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad1[52 - 7];
    float f52, f56, f60;
    unsigned char pad2[92 - 64];
    float f92, f96, f100, f104, f108;
    unsigned char pad3[0x1dc - 112];
    char b1dc;
    unsigned char pad4[0x1ed - 0x1dd];
    unsigned char b1ed;
    unsigned char pad5[0x1f7 - 0x1ee];
    unsigned char b1f7;
    unsigned char pad6[0x238 - 0x1f8];
    char b238;
};
typedef void (*handler_0c03f15c)(struct Obj_0c03f15c *);
extern handler_0c03f15c dat_0c242f38[];
extern handler_0c03f15c dat_0c23bbe8[];
extern unsigned char dat_0c2f8338;
extern void func_0c0491a4(struct Obj_0c03f15c *);
extern char func_0c02a026(struct Obj_0c03f15c *);
extern void func_0c0437b8(struct Obj_0c03f15c *);
extern void func_0c042960(struct Obj_0c03f15c *);

void func_0c094e80(struct Obj_ud0_12 *a)
{
    struct Vec3_ud0_12 v;

    if (a->b34 & 1) {
        a->b1d2 ^= 1;
        a->w130 = a->b1d2;
    }
    a->b1a0 = 10;
    func_0c02a0c4(a, 15, 4);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    v.x = -238.33333f;
    v.y = 147.857132f;
    v.z = 0;
    func_0c1d4610(a, &v);
    func_0c048ce6(a);
}

void func_0c094eee(struct Obj_ud0_12 *a)
{
    struct Vec3_ud0_12 v;

    if (a->b34 & 1) {
        a->b1d2 ^= 1;
        a->w130 = a->b1d2;
    }
    a->b1a0 = 10;
    func_0c02a0c4(a, 15, 3);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    v.x = -238.33333f;
    v.y = 147.857132f;
    v.z = 0;
    func_0c1d4610(a, &v);
    func_0c048ce6(a);
}

void func_0c094f5c(struct Obj_0c03f15c *p)
{
    dat_0c242f38[p->b1f7](p);
}

void func_0c094f70(struct Obj_ud0_12 *a)
{
    struct Obj_ud0_12 *q;

    func_0c02a026(a);
    if (!a->b141)
        return;
    a->b141 = 0;
    a->b6++;
    a->s28 = 30;
    q = a->p1c8;
    q->b1f6 = 1;
    q->b1f9 = 2;
    q->b1a1 = 32;
    a->b1a1 = 32;
    q->b1d2 = a->b1d2;
    q->b1d2 ^= 1;
    func_0c199414(a, 1, 0);
    func_0c0344a0(a, 34);
}

struct Vec3_ud0_12 { float x, y, z; };

struct Obj_ud0_12 {
    unsigned char pad0[28];
    short s28;
    unsigned char pad1[0x22 - 30];
    unsigned char b34;
    unsigned char pad2[0x5c - 0x23];
    float f92, f96;
    unsigned char pad3[0x68 - 0x64];
    float f104, f108;
    unsigned char pad3b[0x130 - 0x70];
    unsigned short w130;
    unsigned char pad4[0x1a0 - 0x132];
    unsigned char b1a0;
    unsigned char pad5[0x1d2 - 0x1a1];
    unsigned char b1d2;
    unsigned char pad6[0x1f7 - 0x1d3];
    unsigned char b1f7;
};

typedef void (*handler_ud0_12)(struct Obj_ud0_12 *);

extern handler_ud0_12 dat_0c24b69c[];
extern void func_0c02a0c4(struct Obj_ud0_12 *, int, int);
extern void func_0c1d4610(struct Obj_ud0_12 *, struct Vec3_ud0_12 *);
extern void func_0c048ce6(struct Obj_ud0_12 *);

void func_0c10899c(struct Obj_ud0_12 *a)
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
    v.x = -58.3333321f;
    v.y = 135.0f;
    v.z = 0;
    func_0c1d4610(a, &v);
    func_0c048ce6(a);
}

void func_0c108a0a(struct Obj_ud0_12 *a)
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
    v.x = -58.3333321f;
    v.y = 135.0f;
    v.z = 0;
    func_0c1d4610(a, &v);
    func_0c048ce6(a);
    a->s28 = 60;
}

void func_0c108a7c(struct Obj_ud0_12 *a)
{
    dat_0c24b69c[a->b1f7](a);
}

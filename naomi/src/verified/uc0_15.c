struct Vec3_uc0_15 { float x, y, z; };

struct Obj_uc0_15 {
    unsigned char pad0[2];
    unsigned char b2;
    unsigned char pad1[7 - 3];
    unsigned char b7;
    unsigned char pad2[28 - 8];
    short s28, s30;
    unsigned char pad3[92 - 32];
    float f92, f96;
    unsigned char pad4[104 - 100];
    float f104, f108;
    unsigned char pad5[0x141 - 112];
    unsigned char b141;
    unsigned char pad6[0x19e - 0x142];
    unsigned char b19e;
    unsigned char pad7[0x1a1 - 0x19f];
    unsigned char b1a1;
    unsigned char pad8[0x1ac - 0x1a2];
    short w1ac;
    unsigned char pad9[0x1c4 - 0x1ae];
    unsigned int u1c4;
    unsigned char pad10[0x1f9 - 0x1c8];
    unsigned char b1f9;
    unsigned char pad11[0x255 - 0x1fa];
    unsigned char b255;
    unsigned char pad12[0x328 - 0x256];
    unsigned char b328;
    unsigned char pad13[0x3f0 - 0x329];
    unsigned char b3f0, b3f1;
    unsigned char pad14[0x3f8 - 0x3f2];
    unsigned char b3f8;
};

struct Table_uc0_15 {
    unsigned char pad[124];
    short counts[64];
};

typedef void (*handler_uc0_15)(struct Obj_uc0_15 *);

extern handler_uc0_15 dat_0c242ea0[];
extern struct Table_uc0_15 *dat_0c2f83f8;
extern char func_0c02a026(struct Obj_uc0_15 *);
extern void func_0c0437b8(struct Obj_uc0_15 *);
extern void func_0c0442fa(struct Obj_uc0_15 *);
extern void func_0c02a39a(struct Obj_uc0_15 *, int);
extern void func_0c02a0c4(struct Obj_uc0_15 *, int, int);
extern void func_0c095380(struct Obj_uc0_15 *, struct Obj_uc0_15 *);
extern void func_0c0429a4(struct Obj_uc0_15 *, struct Vec3_uc0_15 *, int);

void func_0c094252(struct Obj_uc0_15 *a, struct Obj_uc0_15 *b);

void func_0c094198(struct Obj_uc0_15 *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0941ba(struct Obj_uc0_15 *a)
{
    dat_0c242ea0[a->b7](a);
}

void func_0c0941cc(struct Obj_uc0_15 *a, struct Obj_uc0_15 *b)
{
    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b7++;
    func_0c0442fa(a);
    a->b1f9 = 2;
    func_0c02a39a(a, 0);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1a1 = 56;
    a->w1ac = 0;
    a->b19e = 0;
    a->u1c4 = 0;
    dat_0c2f83f8->counts[a->b2]++;
    func_0c02a0c4(a, 22, 1);
    func_0c094252(a, b);
}

void func_0c094252(struct Obj_uc0_15 *a, struct Obj_uc0_15 *b)
{
    struct Vec3_uc0_15 v;

    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    func_0c095380(a, b);
    func_0c02a026(a);
    if (a->b141 != 0) {
        a->b141 = 0;
        a->b7++;
        a->s28 = 90;
        a->s30 = 0;
        b->b7 = 5;
        v.x = -43.33333206176758f;
        v.y = 94.2857132f;
        v.z = 0.0f;
        a->b3f0 = 0;
        a->b3f1 = 0;
        func_0c0429a4(a, &v, 1);
    }
}

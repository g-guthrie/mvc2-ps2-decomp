struct Obj_uc0_13 {
    unsigned char pad0[2];
    unsigned char b2;
    unsigned char pad1[6 - 3];
    unsigned char b6;
    unsigned char pad2[28 - 7];
    short s28;
    unsigned char pad3[0x141 - 30];
    unsigned char b141;
    unsigned char pad4[0x19e - 0x142];
    unsigned char b19e;
    unsigned char pad5[0x1a1 - 0x19f];
    unsigned char b1a1;
    unsigned char pad6[0x1ac - 0x1a2];
    short w1ac;
    unsigned char pad7[0x1c4 - 0x1ae];
    unsigned int u1c4;
    unsigned char pad8[0x1f9 - 0x1c8];
    unsigned char b1f9;
    unsigned char pad9[0x255 - 0x1fa];
    unsigned char b255;
    unsigned char pad10[0x328 - 0x256];
    unsigned char b328;
    unsigned char pad11[0x3f0 - 0x329];
    unsigned char b3f0, b3f1;
    unsigned char pad12[0x3f8 - 0x3f2];
    unsigned char b3f8;
};

struct Table_uc0_13 {
    unsigned char pad[124];
    short counts[64];
};

struct Foo_uc0_13 { unsigned char pad0[34]; unsigned char b34; };

struct Vec3_uc0_13 { float x, y, z; };

extern struct Table_uc0_13 *dat_0c2f83f8;
extern void func_0c0442fa(struct Obj_uc0_13 *);
extern void func_0c0432ca(struct Obj_uc0_13 *);
extern void func_0c02a0c4(struct Obj_uc0_13 *, int, int);
extern struct Foo_uc0_13 *func_0c1bc460(struct Obj_uc0_13 *, int);
extern char func_0c02a026(struct Obj_uc0_13 *);
extern void func_0c0344a0(struct Obj_uc0_13 *, int);
extern void func_0c0429a4(struct Obj_uc0_13 *, struct Vec3_uc0_13 *, int);

void func_0c1203ec(struct Obj_uc0_13 *a)
{
    struct Foo_uc0_13 *p;

    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b6++;
    func_0c0442fa(a);
    a->b1f9 = 0;
    func_0c0432ca(a);
    a->b1a1 = 68;
    a->w1ac = 0;
    a->b19e = 0;
    a->u1c4 = 0;
    dat_0c2f83f8->counts[a->b2]++;
    func_0c02a0c4(a, 21, 13);
    if ((p = func_0c1bc460(a, 6)) != 0)
        p->b34 = 0;
    if ((p = func_0c1bc460(a, 6)) != 0)
        p->b34 = 16;
}

void func_0c12047e(struct Obj_uc0_13 *a)
{
    struct Vec3_uc0_13 v;

    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    func_0c02a026(a);
    if (a->b141 != 0) {
        a->b3f0 = 0;
        a->b3f1 = 0;
        a->b6++;
        a->b141 = 0;
        a->s28 = 420;
        func_0c0344a0(a, 22);
        v.x = 40.0f;
        v.y = 342.85711669921875f;
        func_0c0429a4(a, &v, 1);
    }
}

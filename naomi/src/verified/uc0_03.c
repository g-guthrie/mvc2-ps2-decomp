struct Obj_uc0_03 {
    unsigned char pad0[2];
    unsigned char b2;
    unsigned char pad1[6 - 3];
    unsigned char b6;
    unsigned char pad2[52 - 7];
    float f52, f56;
    unsigned char pad3[92 - 60];
    float f92, f96, f100, f104, f108;
    unsigned char pad4[0x19e - 112];
    unsigned char b19e;
    unsigned char pad5[0x1a1 - 0x19f];
    unsigned char b1a1;
    unsigned char pad6[0x1ac - 0x1a2];
    short w1ac;
    unsigned char pad7[0x1c4 - 0x1ae];
    unsigned int u1c4;
    unsigned char pad8[0x1d2 - 0x1c8];
    unsigned char b1d2;
    unsigned char pad9[0x1f9 - 0x1d3];
    unsigned char b1f9;
};

struct Table_uc0_03 {
    unsigned char pad[124];
    short counts[64];
};

typedef void (*handler_uc0_03)(struct Obj_uc0_03 *);

extern handler_uc0_03 dat_0c2483a8[];
extern struct Table_uc0_03 *dat_0c2f83f8;
extern void func_0c0344a0(struct Obj_uc0_03 *, int);
extern void func_0c048bb0(struct Obj_uc0_03 *, int);
extern void func_0c0442fa(struct Obj_uc0_03 *);
extern void func_0c02a0c4(struct Obj_uc0_03 *, int, int);
extern char func_0c02a026(struct Obj_uc0_03 *);
extern void func_0c0ce574(struct Obj_uc0_03 *);
extern void func_0c02a39a(struct Obj_uc0_03 *, int);

void func_0c0d20c0(struct Obj_uc0_03 *a)
{
    if (a->b6 == 0) {
        a->b6++;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c0344a0(a, 43);
        func_0c048bb0(a, 5);
        func_0c0442fa(a);
        func_0c02a0c4(a, 20, 3);
        return;
    }
    else if (func_0c02a026(a) < 0)
        func_0c0ce574(a);
}

void func_0c0d2124(struct Obj_uc0_03 *a)
{
    dat_0c2483a8[a->b6](a);
}

void func_0c0d2136(struct Obj_uc0_03 *a)
{
    func_0c02a39a(a, 0);
    a->b6++;
    a->b1f9 = 2;
    a->f92 = 30.0f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 4.285714149475098f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 67;
    a->w1ac = 0;
    a->b19e = 0;
    a->u1c4 = 0;
    dat_0c2f83f8->counts[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}

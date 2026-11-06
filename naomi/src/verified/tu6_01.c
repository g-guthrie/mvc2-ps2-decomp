/* Two functions sharing the literal pool at 0x0c06bf5a. */

struct Obj_0c06be0c {
    unsigned char pad0[4];
    unsigned char b4, b5, b6;
    unsigned char pad1[21];
    short s28;
    unsigned char pad2[52 - 30];
    float f52, f56, f60;
    unsigned char pad3[92 - 64];
    float f92, f96, f100, f104, f108, f112;
    unsigned char pad4[0x12c - 116];
    unsigned char b12c;
    unsigned char pad5[0x1a1 - 0x12d];
    unsigned char b1a1;
    unsigned char pad6[0x1b4 - 0x1a2];
    struct Obj_0c06be0c *p1b4;
    unsigned char pad7[0x1c8 - 0x1b8];
    struct Obj_0c06be0c *p1c8;
    unsigned char pad8[0x1ea - 0x1cc];
    unsigned char b1ea;
    unsigned char pad9[2];
    unsigned char b1ed;
    unsigned char pad10[0x1f5 - 0x1ee];
    unsigned char b1f5, b1f6;
    unsigned char pad11[2];
    unsigned char b1f9;
    unsigned char pad12[0x327 - 0x1fa];
    unsigned char b327, b328;
    unsigned char pad13[0x3f8 - 0x329];
    unsigned char b3f8, b3f9;
    unsigned char pad14[0x41c - 0x3fa];
    float f41c;
};

struct Glob_0c2d6f84 { unsigned char pad[69]; char b45; };

extern struct Glob_0c2d6f84 *dat_0c2d6f84;
extern void func_0c02a026(struct Obj_0c06be0c *a);
extern void func_0c025900(struct Obj_0c06be0c *a, int b, int c);
extern void func_0c13941c(struct Obj_0c06be0c *a);
extern void func_0c0344a0(struct Obj_0c06be0c *a, int b);
extern void func_0c02a0c4(struct Obj_0c06be0c *a, int b, int c);

void func_0c06be0c(struct Obj_0c06be0c *a)
{
    struct Obj_0c06be0c *p;

    a->b3f8 = 2;
    a->b328 = 5;
    a->b1ea = 1;
    a->b1ed = 2;
    a->b1f5 = 2;
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (--a->s28 == 0) {
        a->b6++;
        p = a->p1c8;
        p->p1b4 = a;
        p->b1f6 = 13;
        p->b1f9 = 2;
        p->b1a1 = 34;
        func_0c025900(a, 0, 0);
        func_0c13941c(a);
        a->b12c = 0;
        a->s28 = 192;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
    }
}

void func_0c06beca(struct Obj_0c06be0c *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b1ea = 1;
    a->b1ed = 2;
    a->b1f5 = 2;
    a->b12c = 0;
    if (--a->s28 == 0) {
        a->b6++;
        a->b12c = 1;
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        func_0c025900(a, 7, 7);
        a->f56 = a->f41c;
        a->b1f9 = 0;
        if (!dat_0c2d6f84->b45)
            func_0c0344a0(a, 15);
        func_0c02a0c4(a, 22, 32);
    }
}

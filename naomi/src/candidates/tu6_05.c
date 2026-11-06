/* Five reconstructed actor handlers. The first two functions and first
 * literal pool match exactly; the full unit remains a candidate while the
 * later handlers and shared pool placement are refined. */

struct Obj_0c0aa28c {
    unsigned char pad0[2];
    unsigned char b2;
    unsigned char pad1[3];
    unsigned char b6;
    unsigned char b7;
    unsigned char pad2[37 - 8];
    unsigned char b37;
    unsigned char pad2b[52 - 38];
    float f52, f56, f60;
    unsigned char pad3[80 - 64];
    float f80, f84;
    unsigned char pad4[0x19e - 88];
    unsigned char b19e;
    unsigned char pad5[0x1a1 - 0x19f];
    unsigned char b1a1;
    unsigned char pad6[0x1ac - 0x1a2];
    unsigned short w1ac;
    unsigned char pad7[0x1c4 - 0x1ae];
    int p1c4;
    unsigned char pad8[0x1eb - 0x1c8];
    unsigned char b1eb;
    unsigned char pad9[0x202 - 0x1ec];
    unsigned char b202;
    unsigned char pad10[0x255 - 0x203];
    unsigned char b255;
    unsigned char pad11[0x328 - 0x256];
    unsigned char b328;
    unsigned char pad12[0x3f0 - 0x329];
    unsigned char b3f0, b3f1;
    unsigned char pad13[0x3f8 - 0x3f2];
    unsigned char b3f8;
    unsigned char pad14[0x41c - 0x3f9];
    float f41c;
};

struct Rec_0c0aa28c {
    unsigned char pad0[8];
    short s8;
    unsigned short s10;
    float f12;
    unsigned char pad1[4];
    float f20;
};

struct Vec3 { float x, y, z; };
struct Glob_0c2f83f8 { unsigned char pad[0x7c]; short w7c[1]; };

extern struct Glob_0c2f83f8 *dat_0c2f83f8;
extern unsigned char dat_0c2f8370;
extern void func_0c025900(struct Obj_0c0aa28c *a, int b, int c);
extern void func_0c0442fa(struct Obj_0c0aa28c *a);
extern void func_0c02a0c4(struct Obj_0c0aa28c *a, int b, int c);
extern void func_0c0432ca(struct Obj_0c0aa28c *a);
extern void func_0c0344a0(struct Obj_0c0aa28c *a, int b);
extern void func_0c0346da(struct Obj_0c0aa28c *a, int b);
extern void func_0c0429a4(struct Obj_0c0aa28c *a, struct Vec3 *v, int n);
extern char func_0c02a026(struct Obj_0c0aa28c *a);
extern void func_0c1a286c(struct Obj_0c0aa28c *a, int b, int c);
extern void func_0c02a684(struct Obj_0c0aa28c *a, int b, int c, int d);
extern void func_0c04be40(struct Obj_0c0aa28c *a);

void func_0c0aa28c(struct Obj_0c0aa28c *a, struct Rec_0c0aa28c *b)
{
    struct Vec3 v;

    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    func_0c025900(a, 13, 6);
    a->b7++;
    b->s10 = 0xf0;
    func_0c0442fa(a);
    a->f56 = a->f41c;
    a->b1a1 = 66;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->w7c[a->b2]++;
    func_0c02a0c4(a, 22, 54);
    b->s8 = 15;
    func_0c0432ca(a);
    func_0c0344a0(a, 20);
    a->b3f0 = 0;
    a->b3f1 = 0;
    v.x = 0.0f;
    v.y = v.y + 137.14286f;
    func_0c0429a4(a, &v, 1);
}

void func_0c0aa348(struct Obj_0c0aa28c *a, struct Rec_0c0aa28c *b)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    if (func_0c02a026(a) < 0) {
        a->b7++;
        b->f12 = 0.5f;
        b->f20 = 0.5f;
        a->f80 = b->f12;
        a->f84 = b->f20;
        a->f56 = a->f41c;
        func_0c02a0c4(a, 22, 63);
        if (!(dat_0c2f8370 & (1 << a->b2)))
            func_0c1a286c(a, 0, 1);
        func_0c02a684(a, 0, a->b37 + 6, 1);
        func_0c02a684(a, 2, 12, 2);
        func_0c0344a0(a, 34);
        func_0c0346da(a, 53);
        a->b202 |= 0x80;
        a->b1eb = 2;
        func_0c04be40(a);
    }
}

struct SharedFlags_0c2d6f84 { unsigned char pad[0x1c]; unsigned int flags; };
extern struct SharedFlags_0c2d6f84 *dat_0c2d6f84;
extern unsigned char dat_0c2d9260[8];
extern void func_0c02a39a(struct Obj_0c0aa28c *a, int b);
extern void (*dat_0c244568[])(struct Obj_0c0aa28c *a, struct Rec_0c0aa28c *b);

void func_0c0aa450(struct Obj_0c0aa28c *a, struct Rec_0c0aa28c *b)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (!(dat_0c2d6f84->flags & 1))
        func_0c02a684(a, 0, a->b37 + 6, 1);
    else
        func_0c02a39a(a, 8);

    if (!(dat_0c2d6f84->flags & 7)) {
        dat_0c2d9260[5] = 2;
        dat_0c2d9260[6] = 1;
    }

    b->f12 += 0.02f;
    b->f20 += 0.02f;
    a->f80 = b->f12;
    a->f84 = b->f20;

    if (b->f20 > 1.0f) {
        b->f12 = 1.0f;
        a->f80 = b->f12;
        a->f84 = b->f20;
        a->b7++;
        b->s8 = 30;
        func_0c02a0c4(a, 22, 55);
        func_0c02a39a(a, 0);
        func_0c02a684(a, 0, a->b37 + 6, 1);
        func_0c02a684(a, 2, 12, 2);
        func_0c0344a0(a, 37);
    }

    a->b202 |= 0x80;
    a->b1eb = 2;
    func_0c04be40(a);
}

extern void func_0c1c1678(struct Obj_0c0aa28c *a, unsigned short *b, int n);
extern void func_0c0aafe6(struct Obj_0c0aa28c *a);

void func_0c0aa57a(struct Obj_0c0aa28c *a, struct Rec_0c0aa28c *b)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (--b->s8 <= 0) {
        a->b6++;
        a->b7 = 0;
        b->s10 = 0xf0;
        func_0c1c1678(a, &b->s10, 6);
        func_0c0aafe6(a);
    }
    a->b202 |= 0x80;
    a->b1eb = 2;
    func_0c04be40(a);
}

void func_0c0aa5d6(struct Obj_0c0aa28c *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    dat_0c244568[a->b7](a, (struct Rec_0c0aa28c *)((unsigned char *)a + 0x2a4));
    a->b202 |= 0x80;
    a->b1eb = 2;
    func_0c04be40(a);
}

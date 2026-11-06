/* 0x0c1b5c78 size 436: func_0c1b5c78, func_0c1b5d26 (pool in the
 * switch dispatch) and func_0c1b5e04. The last function's jmp pool word
 * sits at 0x0c1b5e28. */

struct Vec3_ub6_01 { float x, y, z; };

struct Big_ub6_01 {
    unsigned char pad0[0x12c - 0xdc];
    unsigned char b12c;
    unsigned char pad1[0x13e - 0x12d];
    unsigned char b13e, b13f;
    unsigned char pad2[0x141 - 0x140];
    unsigned char b141;
    unsigned char pad3[0x19c - 0x142];
};

struct Obj_ub6_01 {
    unsigned char pad0[1];
    unsigned char b1, b2;
    unsigned char pad1[1];
    unsigned char b4, b5;
    unsigned char pad2[36 - 6];
    unsigned char b36;
    unsigned char pad3[48 - 37];
    unsigned char b48;
    unsigned char pad4[52 - 49];
    struct Vec3_ub6_01 pos;
    unsigned char pad5[80 - 64];
    struct Vec3_ub6_01 vel;
    float f92, f96, f100, f104, f108;
    unsigned char pad6[0xdc - 112];
    struct Big_ub6_01 xdc;
    unsigned char pad7[0x1a3 - 0x19c];
    unsigned char b1a3, b1a4;
    unsigned char pad8[0x1d2 - 0x1a5];
    unsigned char b1d2;
    unsigned char pad9[0x41c - 0x1d3];
    float f41c;
};

extern void func_0c1d53e4(struct Obj_ub6_01 *);
extern void func_0c02a0c4(struct Obj_ub6_01 *, int, int);
extern void func_0c02a026(struct Obj_ub6_01 *);
extern int func_0c028642(struct Obj_ub6_01 *);
extern void func_0c037688(struct Obj_ub6_01 *);

void func_0c1b5c78(struct Obj_ub6_01 *a, struct Obj_ub6_01 *b)
{
    float d;

    a->xdc = b->xdc;
    a->xdc.b12c = 1;
    a->b2 = b->b2;
    a->b1 = b->b1;
    a->vel.x = b->vel.x;
    a->vel.y = b->vel.y;
    a->b1a3 = b->b1a3;
    a->b1a4 = b->b1a4;
    a->b48 = b->b48;
    a->vel = b->vel;
    a->b36 = b->b36;
    a->b4++;
    a->b36 = 12;
    a->xdc.b13e = 48;
    a->xdc.b13f = 48;
    d = -60.0f;
    a->f92 = 10.0f;
    if (b->b1d2 != 0) {
        d = 60.0f;
        a->f92 = -a->f92;
    }
    a->pos.x = b->pos.x + d;
    a->pos.y = b->f41c;
    func_0c1d53e4(a);
    func_0c02a0c4(a, 23, 30);
}

void func_0c1b5d26(struct Obj_ub6_01 *a, struct Obj_ub6_01 *b)
{
    unsigned char z = 0;

    switch (a->b5) {
    case 0:
        func_0c02a026(a);
        if (a->xdc.b141 == 0)
            return;
        a->b5 = a->b5 + 1;
        a->xdc.b141 = z;
    case 1:
        if (b->xdc.b141 == 0)
            return;
        a->b5 = a->b5 + 1;
    case 2:
        func_0c02a026(a);
        if (a->xdc.b141 == 0)
            return;
        a->pos.x += a->f92;
        a->f92 += a->f104;
        a->pos.y += a->f96;
        a->f96 += a->f108;
        if (func_0c028642(a) == 0) {
            a->b4 = 2;
            a->b5 = z;
            a->xdc.b12c = z;
        }
    }
}

void func_0c1b5e04(struct Obj_ub6_01 *a)
{
    if (a->b5 == 0)
        a->b5++;
    else
        func_0c037688(a);
}

/* Translation unit around the literal pools at 0x0c15b708 and 0x0c15b82c:
 * func_0c15b610, func_0c15b6ea (which retail splits around the first pool),
 * func_0c15b818 and func_0c15b826. Every byte the tool compares matches
 * (550/550), but the reviewed section stops at 0x0c15b836, two bytes of pool
 * padding short of the second pool's long entries, so the linked image is
 * reported as longer than the section. func_0c15b610 ends by calling
 * func_0c15b6ea, which the compiler emits as a fall-through into it.
 * Runtime helpers: __slow_mvn and __quick_odd_mvn come from
 * config/runtime.json; pass --import __modls=0x0c1fb5ac. */

struct Vec3_tu5_04 { float x, y, z; };
struct Big_tu5_04 {
    unsigned char pad0[0x12c - 0xdc];
    unsigned char b12c;
    unsigned char pad1[0x130 - 0x12d];
    short w130;
    unsigned char pad2[0x158 - 0x132];
    short w158;
    unsigned char pad3[0x19c - 0x15a];
};

struct Obj_tu5_04 {
    unsigned char pad0[1];
    unsigned char b1, b2;
    unsigned char pad1[1];
    unsigned char b4;
    char b5;
    unsigned char pad2[1];
    unsigned char b7;
    unsigned char pad3[24 - 8];
    struct Obj_tu5_04 *p24;
    short s28, s30;
    unsigned char pad4[36 - 32];
    unsigned char b36;
    unsigned char pad5[48 - 37];
    unsigned char b48;
    unsigned char pad6[52 - 49];
    struct Vec3_tu5_04 pos;
    unsigned char pad7[72 - 64];
    int l72;
    unsigned char pad8[80 - 76];
    struct Vec3_tu5_04 vel;
    unsigned char pad9[0xdc - 92];
    struct Big_tu5_04 xdc;
    unsigned char b19c, b19d, b19e;
    unsigned char pad14[0x1a1 - 0x19f];
    unsigned char b1a1;
    unsigned char pad15[1];
    unsigned char b1a3, b1a4;
    unsigned char pad16[0x1ac - 0x1a5];
    short w1ac;
    unsigned char pad17[0x1c4 - 0x1ae];
    int l1c4;
};

struct Stats_tu5_04 {
    unsigned char pad0[124];
    short w7c[256];
};

extern struct Stats_tu5_04 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Obj_tu5_04 *, int, int);
extern char func_0c02a026(struct Obj_tu5_04 *);
extern void func_0c037d0c(struct Obj_tu5_04 *);
extern void func_0c037688(struct Obj_tu5_04 *);

void func_0c15b6ea(struct Obj_tu5_04 *a);

void func_0c15b610(struct Obj_tu5_04 *a)
{
    a->b4++;
    a->xdc = a->p24->xdc;
    a->xdc.b12c = 1;
    a->b2 = a->p24->b2;
    a->b1 = a->p24->b1;
    a->vel.x = a->p24->vel.x;
    a->vel.y = a->p24->vel.y;
    a->b1a3 = a->p24->b1a3;
    a->b1a4 = a->p24->b1a4;
    a->b48 = a->p24->b48;
    a->vel = a->p24->vel;
    a->b36 = a->p24->b36;
    func_0c02a0c4(a, 23, 16);
    a->b19c = 66;
    a->b19d = 66;
    a->b36 = 0;
    a->l72 = 0x19a;
    a->vel.x *= 1.5f;
    a->vel.y *= 0.6666667f;
    a->s28 = 8;
    a->b1a1 = 59;
    a->w1ac = 0;
    a->b19e = 0;
    a->l1c4 = 0;
    dat_0c2f83f8->w7c[a->b2]++;
    a->b7 = 1;
    func_0c15b6ea(a);
}

void func_0c15b6ea(struct Obj_tu5_04 *a)
{
    float d;

    if (a->p24->b5 != 0) {
        a->xdc.b12c = 0;
        a->b4++;
        return;
    }
    a->pos = a->p24->pos;
    d = -(a->p24->vel.x * 176.66666f);
    if (a->xdc.w130 != 0)
        d = -d;
    a->pos.x += d;
    a->pos.y += a->p24->vel.y * 120.0f;
    if (!a->b5) {
        func_0c02a026(a);
        if (--a->s28 <= 0) {
            unsigned char v;

            a->s28 = 16;
            v = ((++a->b7) % 3 == 0) ? 59 : 60;
            a->b1a1 = v;
            a->w1ac = 0;
            a->b19e = 0;
            a->l1c4 = 0;
            dat_0c2f83f8->w7c[a->b2]++;
        }
        if (a->p24->xdc.w158 != a->s30) {
            a->b5++;
            a->b1a1 |= 0x80;
            func_0c02a0c4(a, 23, 17);
        }
        func_0c037d0c(a);
    } else {
        if (func_0c02a026(a) < 0) {
            a->b4++;
            a->xdc.b12c = 0;
        }
    }
}

void func_0c15b818(struct Obj_tu5_04 *a)
{
    a->b4++;
    a->xdc.b12c = 0;
}

void func_0c15b826(struct Obj_tu5_04 *a)
{
    func_0c037688(a);
}

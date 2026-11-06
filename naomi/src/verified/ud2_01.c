/* 0x0c1982f4-0x0c1984a4, 432 bytes. b49 is signed so -8 is mov #imm, not a
 * pool word; other = a->p20 is loaded before b4++ so the pos copy schedules
 * with the retail interleave. */

struct Vec3_ud2_01 { float x, y, z; };

struct Big_ud2_01 {
    unsigned char pad0[0x12c - 0xdc];
    unsigned char b12c;
    unsigned char pad1[0xc0 - (0x12c - 0xdc) - 1];
};

struct S_ud2_01 {
    unsigned char pad0[1];
    unsigned char b1, b2;
    unsigned char pad1[1];
    unsigned char b4;
    unsigned char b5;
    unsigned char pad2[0x10 - 6];
    void *p16;
    struct S_ud2_01 *p20;
    void *p24;
    short s28;
    unsigned char pad4[0x20 - 0x1e];
    unsigned char b32;
    unsigned char pad5[0x23 - 0x21];
    char b35;
    unsigned char b36;
    unsigned char pad6[0x26 - 0x25];
    unsigned short w38;
    unsigned char pad7[0x30 - 0x28];
    unsigned char b48;
    char b49;
    unsigned char pad8[0x34 - 0x32];
    struct Vec3_ud2_01 pos;
    unsigned char pad9[0x50 - 0x40];
    struct Vec3_ud2_01 vel;
    float f92, f96;
    unsigned char pad10[0x68 - 0x64];
    float f104, f108;
    unsigned char pad11[0xdc - 0x70];
    struct Big_ud2_01 xdc;
    unsigned char pad12[0x1a3 - 0x19c];
    unsigned char b1a3, b1a4;
    unsigned char pad13[0x1c8 - 0x1a5];
    struct S_ud2_01 *p1c8;
    unsigned char pad14[0x1eb - 0x1cc];
    unsigned char b1eb;
    unsigned char pad15[0x1f6 - 0x1ec];
    unsigned char b1f6;
};

typedef void (*handler1_ud2_01)(struct S_ud2_01 *);
typedef void (*handler2_ud2_01)(struct S_ud2_01 *, void *);

extern handler2_ud2_01 dat_0c2583d8[];
extern handler1_ud2_01 dat_0c2583e4[];
extern void (*dat_0c2583f0[])(struct S_ud2_01 *, struct S_ud2_01 *, struct S_ud2_01 *);
extern unsigned char dat_0c258350[];
extern struct S_ud2_01 *func_0c0374da(int, int, int);
extern void func_0c044788(struct S_ud2_01 *, struct S_ud2_01 *);
extern void func_0c0346da(struct S_ud2_01 *, int);
extern void func_0c02a0c4(struct S_ud2_01 *, int, int);
void func_0c19832e(struct S_ud2_01 *a);

struct S_ud2_01 *func_0c1982f4(void *p1, struct S_ud2_01 *p2, int p3)
{
    struct S_ud2_01 *obj;

    if ((obj = func_0c0374da(0, 3, 0)) != 0) {
        obj->w38 = 0x0e04;
        obj->b32 = p3;
        obj->p16 = (void *)func_0c19832e;
        obj->p24 = p1;
        obj->p20 = p2;
    }
    return obj;
}

void func_0c19832e(struct S_ud2_01 *a)
{
    dat_0c2583d8[a->b32](a, a->p24);
}

void func_0c198344(struct S_ud2_01 *a)
{
    dat_0c2583e4[a->b4](a);
}

void func_0c198356(struct S_ud2_01 *a, struct S_ud2_01 *b)
{
    struct S_ud2_01 *other;

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
    func_0c044788(b, a);
    other = a->p20;
    a->b4++;
    a->b36 = 11;
    a->s28 = 40;
    a->pos = other->pos;
    func_0c0346da(a, 13);
    other->b1f6 = 6;
    other->b1eb = 1;
    other->f92 = 0;
    other->f96 = 0;
    other->f104 = 0;
    other->f108 = 0;
    a->b36 = other->b36;
    a->b49 = -8;
    a->b35 = dat_0c258350[other->b1];
    func_0c02a0c4(a, 23, a->b35 + 29);
}

void func_0c198426(struct S_ud2_01 *a, struct S_ud2_01 *b)
{
    struct S_ud2_01 *other = b->p1c8;

    other->b1eb = 1;
    a->pos = other->pos;
    a->b36 = other->b36;
    a->b49 = -8;
    dat_0c2583f0[a->b5](a, b, other);
}

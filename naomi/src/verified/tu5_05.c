/* Translation unit around the literal pools at 0x0c1bce42 and 0x0c1bcfba:
 * nine functions from func_0c1bccdc to func_0c1bcfa8. Retail places the first
 * pool in the middle of func_0c1bcdb4 and the compiler reproduces that when
 * the functions after it are in the file. Every byte from 0x0c1bccdc to
 * 0x0c1bcfe4 matches (776/776, checked with an explicit span), but the
 * reviewed mapping has no range for the dead `rts; nop` epilogue the compiler
 * leaves at 0x0c1bcfa4 after func_0c1bcf72's tail jump, so the tool's derived
 * section stops there (712/712) and reports the rest as extra bytes.
 * func_0c1bccdc falls through into func_0c1bcd5c, func_0c1bcdb4 into
 * func_0c1bce92 and func_0c1bcee4 into func_0c1bcf72: each ends by calling
 * the next function, which the compiler emits as a fall-through.
 * Runtime helpers __slow_mvn/__quick_odd_mvn come from config/runtime.json. */

struct Vec3_tu5_05 { float x, y, z; };

struct Big_tu5_05 {
    unsigned char pad0[0x12c - 0xdc];
    unsigned char b12c;
    unsigned char pad1[0x130 - 0x12d];
    short w130;
    unsigned char pad2[0x158 - 0x132];
    union { short w; struct { unsigned char b158, b159; } b; } u158;
    unsigned char pad3[0x19c - 0x15a];
};

struct Obj_tu5_05 {
    unsigned char pad0[1];
    unsigned char b1, b2;
    unsigned char pad1[1];
    unsigned char b4;
    unsigned char pad2[36 - 5];
    unsigned char b36;
    unsigned char pad3[48 - 37];
    unsigned char b48;
    char b49;
    unsigned char pad4[52 - 50];
    struct Vec3_tu5_05 pos;
    unsigned char pad5[80 - 64];
    struct Vec3_tu5_05 vel;
    unsigned char pad6[0xcc - 92];
    short wcc;
    unsigned char pad7[0xdc - 0xce];
    struct Big_tu5_05 xdc;
    unsigned char pad8[0x1a3 - 0x19c];
    unsigned char b1a3, b1a4;
};

typedef void (*handler_tu5_05)(struct Obj_tu5_05 *);

extern handler_tu5_05 dat_0c25bdc8[];
extern handler_tu5_05 dat_0c25bdd8[];
extern handler_tu5_05 dat_0c25bde8[];
extern void func_0c02a0c4(struct Obj_tu5_05 *, int, int);
extern char func_0c02a026(struct Obj_tu5_05 *);

void func_0c1bcd5c(struct Obj_tu5_05 *a, struct Obj_tu5_05 *b);
void func_0c1bce92(struct Obj_tu5_05 *a, struct Obj_tu5_05 *b);
void func_0c1bcf72(struct Obj_tu5_05 *a, struct Obj_tu5_05 *b);

void func_0c1bccdc(struct Obj_tu5_05 *a, struct Obj_tu5_05 *b)
{
    a->b4++;
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
    a->xdc.b12c = 1;
    a->b49 = 1;
    a->pos.z = b->pos.z;
    func_0c02a0c4(a, 23, 8);
    func_0c1bcd5c(a, b);
}

void func_0c1bcd5c(struct Obj_tu5_05 *a, struct Obj_tu5_05 *b)
{
    short *q = &a->wcc;

    a->b36 = b->b36;
    a->pos.x = b->pos.x;
    a->pos.y = b->pos.y;
    func_0c02a026(a);
    if (b->xdc.u158.w != *q)
        a->b4++;
}

void func_0c1bcda2(struct Obj_tu5_05 *a)
{
    dat_0c25bdc8[a->b4](a);
}

void func_0c1bcdb4(struct Obj_tu5_05 *a, struct Obj_tu5_05 *b)
{
    float d;

    a->b4++;
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
    a->xdc.b12c = 1;
    a->b49 = -1;
    a->pos.x = b->pos.x;
    a->pos.y = b->pos.y;
    a->pos.z = b->pos.z;
    d = 16.666667f;
    if (a->xdc.w130 == 0)
        a->pos.x -= d;
    else
        a->pos.x += d;
    a->pos.y += 77.142857f;
    func_0c02a0c4(a, 23, 21);
    func_0c1bce92(a, b);
}

void func_0c1bce92(struct Obj_tu5_05 *a, struct Obj_tu5_05 *b)
{
    a->b36 = b->b36;
    if (b->xdc.u158.b.b159 != 21) {
        a->b4++;
        return;
    }
    if (func_0c02a026(a) < 0) {
        a->b4++;
        a->xdc.b12c = 0;
    }
}

void func_0c1bced2(struct Obj_tu5_05 *a)
{
    dat_0c25bdd8[a->b4](a);
}

void func_0c1bcee4(struct Obj_tu5_05 *a, struct Obj_tu5_05 *b)
{
    a->b4++;
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
    a->xdc.b12c = 1;
    a->b49 = -1;
    a->pos.x = b->pos.x;
    a->pos.y = b->pos.y;
    a->pos.z = b->pos.z;
    func_0c02a0c4(a, 23, 7);
    func_0c1bcf72(a, b);
}

void func_0c1bcf72(struct Obj_tu5_05 *a, struct Obj_tu5_05 *b)
{
    short *q = &a->wcc;

    if (b->xdc.u158.w != *q) {
        a->b4++;
        return;
    }
    a->b36 = b->b36;
    a->pos.x = b->pos.x;
    a->pos.y = b->pos.y;
    a->pos.z = b->pos.z;
    func_0c02a026(a);
}

void func_0c1bcfa8(struct Obj_tu5_05 *a)
{
    dat_0c25bde8[a->b4](a);
}

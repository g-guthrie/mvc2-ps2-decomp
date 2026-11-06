/* The full 440-byte section links at retail. Five of six functions and both
 * pools are exact. Retail places the first pool inside func_0c132d14 after
 * a `bra`; the loop continues at 0x0c132da8 and the second pool begins at
 * 0x0c132dd4. The whole section matches 429/440 bytes.
 * func_0c132d14 differs in the loop head: retail loads the constant 0x150
 * twice (mov.w into r2 for the p24 side, mov.w into r3 for the p side) and
 * keeps the pointers in r2/r3; SHC loads it once into r3 and uses r4/r5.
 * Imports: __slow_mvn=0x0c1fb838 and __quick_odd_mvn=0x0c1fb7a0 are the
 * compiler's struct-copy helpers (192-byte and 12-byte assignments). */

struct Pair_0c132c24 { char b0, b1; };

struct Inner_0c132c24 {
    unsigned char pad0[0x12c - 0xdc];
    unsigned char b12c;
    unsigned char pad1[0x130 - 0x12d];
    unsigned short w130;
    unsigned char pad2[0x150 - 0x132];
    struct Pair_0c132c24 s150;
    unsigned char pad3[0x19c - 0x152];
};

struct Vec3 { float x, y, z; };

struct Obj_0c132c24 {
    unsigned char pad0;
    unsigned char b1, b2;
    unsigned char pad1;
    unsigned char b4;
    unsigned char pad2[16 - 5];
    void (*fn16)(struct Obj_0c132c24 *);
    unsigned char pad3[4];
    struct Obj_0c132c24 *p24;
    unsigned char pad4[36 - 28];
    unsigned char b36;
    unsigned char pad5[48 - 37];
    unsigned char b48;
    unsigned char pad6[52 - 49];
    float f52, f56, f60;
    unsigned char pad7[80 - 64];
    struct Vec3 s80;
    unsigned char pad8[0xdc - 92];
    struct Inner_0c132c24 sdc;
    unsigned char pad9[0x1a3 - 0x19c];
    unsigned char b1a3, b1a4;
};

typedef void (*fn_t)(struct Obj_0c132c24 *);

extern fn_t dat_0c24e314[];
extern struct Obj_0c132c24 *func_0c0374da(int a, int b, int c);
extern void func_0c02a0c4(struct Obj_0c132c24 *p, int b, int c);
extern char func_0c02a026(struct Obj_0c132c24 *p);
extern void func_0c037688(struct Obj_0c132c24 *p);

void func_0c132c4a(struct Obj_0c132c24 *p);
void func_0c132d14(struct Obj_0c132c24 *p);
int func_0c132dc0(struct Obj_0c132c24 *p);

struct Obj_0c132c24 *func_0c132c24(struct Obj_0c132c24 *a)
{
    struct Obj_0c132c24 *p;

    if ((p = func_0c0374da(0, 1, 0)) != 0) {
        p->fn16 = func_0c132c4a;
        p->p24 = a;
    }
    return p;
}

void func_0c132c4a(struct Obj_0c132c24 *p)
{
    dat_0c24e314[p->b4](p);
}

void func_0c132c5c(struct Obj_0c132c24 *p)
{
    float c;

    p->b4++;
    p->sdc = p->p24->sdc;
    p->sdc.b12c = 1;
    p->b2 = p->p24->b2;
    p->b1 = p->p24->b1;
    p->s80.x = p->p24->s80.x;
    p->s80.y = p->p24->s80.y;
    p->b1a3 = p->p24->b1a3;
    p->b1a4 = p->p24->b1a4;
    p->b48 = p->p24->b48;
    p->s80 = p->p24->s80;
    p->b36 = p->p24->b36;
    p->f52 = p->p24->f52;
    p->f56 = p->p24->f56;
    p->f60 = p->p24->f60;
    c = 53.333334f;
    if (p->sdc.w130)
        p->f52 += c;
    else
        p->f52 -= c;
    p->s80.x += 0.03f;
    p->s80.y += 0.03f;
    p->b36 = 11;
    func_0c132d14(p);
}

void func_0c132d14(struct Obj_0c132c24 *p)
{
    p->f52 = p->p24->f52;
    p->f56 = p->p24->f56;
    p->f60 = p->p24->f60;
    if (p->sdc.w130)
        p->f52 += 53.333334f;
    else
        p->f52 -= 53.333334f;
    func_0c02a0c4(p, 23, 3);
    for (;;) {
        if (*((char *)&p->p24->sdc.s150 + 1) ==
            *((char *)&p->sdc.s150 + 1)) {
            p->sdc.b12c = 1;
            break;
        }
        if (func_0c02a026(p) < 0) {
            func_0c132dc0(p);
            break;
        }
    }
}

int func_0c132dc0(struct Obj_0c132c24 *p)
{
    p->b4++;
    p->sdc.b12c = 0;
}

void func_0c132dce(struct Obj_0c132c24 *p)
{
    func_0c037688(p);
}

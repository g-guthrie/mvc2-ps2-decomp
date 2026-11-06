/* Four functions sharing the literal pool at 0x0c12b1d0. */

struct Obj_0c12b0c4 {
    unsigned char pad0[2];
    unsigned char b2;
    unsigned char pad1[3];
    unsigned char b6;
    unsigned char pad2[21];
    short s28;
    unsigned char pad3[92 - 30];
    float f92, f96, f100, f104, f108, f112;
    unsigned char pad4[0x140 - 116];
    char b140;
    unsigned char pad5[0x14b - 0x141];
    char b14b;
    unsigned char pad6[0x19e - 0x14c];
    unsigned char b19e;
    unsigned char pad7[0x1a1 - 0x19f];
    unsigned char b1a1;
    unsigned char pad8;
    unsigned char b1a3;
    unsigned char pad9[0x1ac - 0x1a4];
    unsigned short w1ac;
    unsigned char pad10[0x1c4 - 0x1ae];
    int p1c4;
    unsigned char pad11[0x1d2 - 0x1c8];
    char b1d2;
    unsigned char pad12[0x348 - 0x1d3];
    unsigned short w348;
    unsigned char pad13[0x352 - 0x34a];
    unsigned short w352;
    unsigned char pad14[0x411 - 0x354];
    char b411;
    unsigned char pad15[0x525 - 0x412];
    char b525;
};

struct Vel4 { int x, ax, y, ay; };
struct Glob_0c2f83f8 { unsigned char pad[0x7c]; short w7c[1]; };

typedef void (*fn_t)(struct Obj_0c12b0c4 *);

extern int *dat_0c24dba8[];
extern fn_t dat_0c24dd4c[];
extern struct Glob_0c2f83f8 *dat_0c2f83f8;

void func_0c12b0c4(struct Obj_0c12b0c4 *a, int idx)
{
    int *v;

    v = dat_0c24dba8[idx];
    v += a->b1a3 * 4;

    a->f92 = (float)*v++ * 1.66666663f / 65536.0f;
    a->f104 = (float)*v++ * 1.66666663f / 65536.0f;
    a->f96 = (float)*v++ * 2.1428571f / 65536.0f;
    a->f108 = (float)*v * 2.1428571f / 65536.0f;
    if (a->b1d2) {
        a->f92 = -a->f92;
        a->f104 = -a->f104;
    }
}

void func_0c12b136(struct Obj_0c12b0c4 *a)
{
    if (a->b14b) {
        a->b1a1 = (a->b1a3 << 1) + a->b14b + 75;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->w7c[a->b2]++;
        a->b14b = 0;
    }
}

void func_0c12b17a(struct Obj_0c12b0c4 *a)
{
    if (a->b140) {
        if (!a->b525) {
            unsigned short t = a->w348 | a->w352;
            if (t & 0x300) {
                a->s28 = 1;
                a->w352 = 0;
            }
        } else {
            if (!a->b411)
                a->s28 = 1;
        }
    }
}

void func_0c12b1be(struct Obj_0c12b0c4 *a)
{
    dat_0c24dd4c[a->b6](a);
}

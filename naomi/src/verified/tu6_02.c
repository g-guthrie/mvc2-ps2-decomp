/* Five functions sharing the literal pool at 0x0c06c4c0. */

struct Obj_0c06c3d4 {
    unsigned char pad0[2];
    unsigned char b2;
    unsigned char pad1[3];
    unsigned char b6;
    unsigned char pad2[52 - 7];
    float f52, f56, f60;
    unsigned char pad3[92 - 64];
    float f92, f96, f100, f104, f108, f112;
    unsigned char pad4[0x141 - 116];
    char b141;
    unsigned char pad5[0x19e - 0x142];
    unsigned char b19e;
    unsigned char pad6[0x1a1 - 0x19f];
    unsigned char b1a1;
    unsigned char pad7[0x1ac - 0x1a2];
    unsigned short w1ac;
    unsigned char pad8[0x1c4 - 0x1ae];
    int p1c4;
    unsigned char pad9[0x1f9 - 0x1c8];
    unsigned char b1f9;
    unsigned char pad10[0x41c - 0x1fa];
    float f41c;
};

struct Glob_0c2f83f8 { unsigned char pad[0x7c]; short w7c[1]; };

typedef void (*fn_t)(struct Obj_0c06c3d4 *);

extern fn_t dat_0c240948[];
extern fn_t dat_0c240950[];
extern struct Glob_0c2f83f8 *dat_0c2f83f8;
extern char func_0c02a026(struct Obj_0c06c3d4 *a);
extern void func_0c0437b8(struct Obj_0c06c3d4 *a);
extern void func_0c048bb0(struct Obj_0c06c3d4 *a, int b);
extern void func_0c0442fa(struct Obj_0c06c3d4 *a);
extern void func_0c0432ca(struct Obj_0c06c3d4 *a);
extern void func_0c02a0c4(struct Obj_0c06c3d4 *a, int b, int c);
extern void func_0c1385f8(struct Obj_0c06c3d4 *a, int b);

void func_0c06c3d4(struct Obj_0c06c3d4 *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c06c3f6(struct Obj_0c06c3d4 *a)
{
    dat_0c240948[a->b6](a);
}

void func_0c06c408(struct Obj_0c06c3d4 *a)
{
    a->b6++;
    a->b1a1 = 82;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->w7c[a->b2]++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    a->b1f9 = 0;
    a->f56 = a->f41c;
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    func_0c0432ca(a);
    func_0c02a0c4(a, 21, 49);
}

void func_0c06c476(struct Obj_0c06c3d4 *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        func_0c1385f8(a, 0);
    }
}

void func_0c06c4ae(struct Obj_0c06c3d4 *a)
{
    dat_0c240950[a->b6](a);
}

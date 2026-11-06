/* Three functions sharing the literal pool at 0x0c1a415a. */
struct V3_tu7_09 { float x, y, z; };
struct Copy_c0_tu7_09 { unsigned char raw[0xc0]; };

struct Obj_tu7_09 {
    unsigned char pad0[1];
    unsigned char b1, b2;
    unsigned char pad1[1];
    unsigned char b4;
    char b5;
    unsigned char pad2[24 - 6];
    struct Obj_tu7_09 *p24;
    unsigned char pad3[36 - 28];
    unsigned char b36;
    unsigned char pad4[48 - 37];
    unsigned char b48, b49;
    unsigned char pad5[52 - 50];
    struct V3_tu7_09 v52;
    unsigned char pad6[80 - 64];
    struct V3_tu7_09 v80;
    unsigned char pad7[0xdc - 92];
    union {
        struct Copy_c0_tu7_09 s0dc;
        struct {
            unsigned char pad8[0x108 - 0xdc];
            float f108;
            unsigned char pad9[0x12c - 0x10c];
            unsigned char b12c;
        } u;
    } v;
    unsigned char pad10[0x1a3 - 0x19c];
    unsigned char b1a3, b1a4;
    unsigned char pad11[0x41c - 0x1a5];
    float f41c;
};

extern void func_0c029e70(struct Obj_tu7_09 *, int, int);
extern char func_0c029fc4(struct Obj_tu7_09 *);
extern void func_0c037688(struct Obj_tu7_09 *);

void func_0c1a4148(struct Obj_tu7_09 *a);

void func_0c1a4074(struct Obj_tu7_09 *a)
{
    a->b4 = a->b4 + 1;
    a->v.s0dc = a->p24->v.s0dc;
    a->v.u.b12c = 1;
    a->b2 = a->p24->b2;
    a->b1 = a->p24->b1;
    a->v80.x = a->p24->v80.x;
    a->v80.y = a->p24->v80.y;
    a->b1a3 = a->p24->b1a3;
    a->b1a4 = a->p24->b1a4;
    a->b48 = a->p24->b48;
    a->v80 = a->p24->v80;
    a->b36 = a->p24->b36;
    a->b36 = 7;
    a->b49 = 2;
    a->v52.x = a->p24->v52.x;
    a->v52.y = a->p24->f41c;
    func_0c029e70(a, 27, 19);
}

void func_0c1a4100(struct Obj_tu7_09 *a)
{
    if (!a->b5) {
        if (func_0c029fc4(a) < 0) {
            a->b5 = a->b5 + 1;
            a->v.u.f108 = 1.0f;
        }
    } else {
        if ((a->v.u.f108 -= 0.05000000074505806f) <= 0.0f)
            func_0c1a4148(a);
    }
}

void func_0c1a4148(struct Obj_tu7_09 *a)
{
    a->b4 = a->b4 + 1;
    a->v.u.b12c = 0;
    func_0c037688(a);
}

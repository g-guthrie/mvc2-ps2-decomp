/* One function with its literal pool at 0x0c0915d6. */

struct Obj_0c09149c {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char b7;
    unsigned char pad1[32 - 8];
    unsigned char b32;
    unsigned char pad2[1];
    unsigned char b34;
    unsigned char pad3[52 - 35];
    float f52, f56;
    unsigned char pad4[92 - 60];
    float f92, f96, f100, f104, f108;
    unsigned char pad5[0x140 - 112];
    unsigned char b140;
    unsigned char pad6[1];
    unsigned char b142;
    unsigned char pad7[0x1d2 - 0x143];
    unsigned char b1d2;
    unsigned char pad8[0x1f5 - 0x1d3];
    unsigned char b1f5;
    unsigned char pad9[0x1fd - 0x1f6];
    char b1fd;
};

struct Tgt_0c09149c { unsigned char pad[32]; char b32; };

extern void func_0c02a026(struct Obj_0c09149c *);
extern void func_0c0903b6(struct Obj_0c09149c *, struct Tgt_0c09149c *);
extern void func_0c02a18c(struct Obj_0c09149c *, int, int, int);

void func_0c09149c(struct Obj_0c09149c *a, struct Tgt_0c09149c *b)
{
    float g = -0.9375f;
    float v;

    if (a->b1fd) {
        if (!(a->b1fd & (1 << a->b1d2)))
            goto out;
    }
    {
        a->b1f5 = 0;
        func_0c02a026(a);
        func_0c0903b6(a, b);
        if (!a->b7) {
            if (a->b140)
                return;
            a->b7++;
            a->f92 = -5.4166667f;
            a->f104 = -1.25f;
            a->f96 = -6.4285712242126465f;
            a->f108 = g;
            if (a->b1d2) {
                a->f92 = -a->f92;
                a->f104 = -a->f104;
            }
        }
        v = a->f92 + a->f104;
        a->f92 = v;
        a->f52 += v;
        a->f56 += a->f96;
        if ((a->b1fd & (1 << (a->b1d2 ^ 1))) == 0) {
            if (0xff00000f & (1 << a->b34))
                return;
        }
    }
out:
    b->b32 = -1;
    a->b6++;
    a->b7 = 0;
    a->b142 = 1;
    a->f92 = -10.0f;
    a->f104 = 0.0f;
    a->f96 = 12.857142448425293f;
    a->f108 = g;
    if (a->b1d2) {
        a->f92 = -a->f92;
        a->f104 = -a->f104;
    }
    func_0c02a18c(a, 20, 3, 4);
}

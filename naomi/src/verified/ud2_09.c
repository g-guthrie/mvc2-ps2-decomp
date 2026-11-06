struct S_ud2_09 {
    unsigned char pad0[2];
    unsigned char b2;
    unsigned char pad1[3];
    unsigned char b6;
    unsigned char pad2[0x38 - 7];
    float f38;
    unsigned char pad3[0x5c - 0x3c];
    float f92, f96;
    unsigned char pad4[0x68 - 0x64];
    float f104, f108;
    unsigned char pad5[0x140 - 0x70];
    unsigned char b140;
    unsigned char pad6[0x19e - 0x141];
    unsigned char b19e;
    unsigned char pad7[0x1a1 - 0x19f];
    unsigned char b1a1;
    unsigned char pad8[0x1ac - 0x1a2];
    unsigned short w1ac;
    unsigned char pad9[0x1c4 - 0x1ae];
    int i1c4;
    unsigned char pad10[0x1d2 - 0x1c8];
    unsigned char b1d2;
    unsigned char pad11[0x255 - 0x1d3];
    unsigned char b255;
    unsigned char pad12[0x328 - 0x256];
    unsigned char b328;
    unsigned char pad13[0x3f0 - 0x329];
    unsigned char b3f0, b3f1;
    unsigned char pad14[0x3f8 - 0x3f2];
    unsigned char b3f8;
    unsigned char pad15[0x41c - 0x3f9];
    float f41c;
};

struct G2f83f8_ud2_09 { unsigned char pad0[0x7c]; short w7c[64]; };

extern struct G2f83f8_ud2_09 *dat_0c2f83f8;
extern void func_0c0442fa(struct S_ud2_09 *);
extern void func_0c0432ca(struct S_ud2_09 *);
extern void func_0c02a0c4(struct S_ud2_09 *, int, int);
extern signed char func_0c02a026(struct S_ud2_09 *);
extern void func_0c0429a4(struct S_ud2_09 *, void *, int);

void func_0c089b08(struct S_ud2_09 *a)
{
    if (a->b255 == 6) {
        a->b3f0 = 0xff;
        a->b3f1 = 0x10;
    }
    a->b6 = a->b6 + 1;
    a->f38 = a->f41c;
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->b1a1 = 94;
    a->w1ac = 0;
    a->b19e = 0;
    a->i1c4 = 0;
    dat_0c2f83f8->w7c[a->b2]++;
    a->f92 = -10.0f;
    if (a->b1d2 != 0)
        a->f92 = -a->f92;
    func_0c02a0c4(a, 22, 29);
}

void func_0c089b9c(struct S_ud2_09 *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    func_0c02a026(a);
    if (a->b140 != 0) {
        struct { float x, y, z; } v;

        a->b6 = a->b6 + 1;
        a->b140 = 0;
        a->b3f0 = 0;
        a->b3f1 = 0;
        v.x = 0;
        v.y = 111.42857f;
        func_0c0429a4(a, &v, 1);
    }
}

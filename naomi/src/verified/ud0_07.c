struct Vec3_ud0_07 { float x, y, z; };

struct Obj_ud0_07 {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad1[28 - 7];
    short s28;
    unsigned char pad2[0x38 - 30];
    float f38;
    unsigned char pad3[0x5c - 0x3c];
    float f92, f96;
    unsigned char pad4[0x68 - 0x64];
    float f104, f108;
    unsigned char pad5[0x141 - 0x70];
    unsigned char b141;
    unsigned char pad6[0x1d2 - 0x142];
    unsigned char b1d2;
    unsigned char pad7[0x1f9 - 0x1d3];
    unsigned char b1f9;
    unsigned char pad8[0x255 - 0x1fa];
    unsigned char b255;
    unsigned char pad9[0x328 - 0x256];
    unsigned char b328;
    unsigned char pad10[0x3f0 - 0x329];
    unsigned char b3f0, b3f1;
    unsigned char pad11[0x3f8 - 0x3f2];
    unsigned char b3f8;
    unsigned char pad12[0x41c - 0x3f9];
    float f41c;
};

typedef void (*handler_ud0_07)(struct Obj_ud0_07 *);

extern handler_ud0_07 dat_0c248004[];
extern void func_0c0432ca(struct Obj_ud0_07 *);
extern void func_0c0442fa(struct Obj_ud0_07 *);
extern void func_0c02a0c4(struct Obj_ud0_07 *, int, int);
extern char func_0c02a026(struct Obj_ud0_07 *);
extern void func_0c0429a4(struct Obj_ud0_07 *, struct Vec3_ud0_07 *, int);

void func_0c0cc8f8(struct Obj_ud0_07 *a)
{
    dat_0c248004[a->b6](a);
}

void func_0c0cc90a(struct Obj_ud0_07 *a)
{
    if (a->b255 == 6) {
        a->b3f0 = 0xff;
        a->b3f1 = 16;
    }
    a->b6++;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    func_0c0432ca(a);
    func_0c0442fa(a);
    a->f92 = a->b1d2 ? 5.83333302f : -5.83333302f;
    a->f38 = a->f41c;
    a->b1f9 = 0;
    a->s28 = 40;
    func_0c02a0c4(a, 22, 6);
}

void func_0c0cc980(struct Obj_ud0_07 *a)
{
    struct Vec3_ud0_07 v;

    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        a->b3f0 = 0;
        a->b3f1 = 0;
        v.x = -11.6666667f;
        v.y = 197.142853f;
        v.z = 0;
        func_0c0429a4(a, &v, 3);
    }
}

void func_0c0cc9f0(struct Obj_ud0_07 *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b6++;
    func_0c02a0c4(a, 22, 9);
}

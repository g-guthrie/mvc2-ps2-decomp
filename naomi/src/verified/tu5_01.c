/* Three functions sharing the literal pool at 0x0c0ddda6. */

struct Obj_tu5_01 {
    unsigned char pad0[2];
    unsigned char b2;
    unsigned char pad1[3];
    unsigned char b6;
    unsigned char pad2[28 - 7];
    short s28;
    unsigned char pad3[0x141 - 30];
    char b141;
    unsigned char pad4[0x19e - 0x142];
    unsigned char b19e;
    unsigned char pad5[0x1a1 - 0x19f];
    unsigned char b1a1;
    unsigned char pad6[0x1ac - 0x1a2];
    short w1ac;
    unsigned char pad7[0x1c4 - 0x1ae];
    unsigned int l1c4;
    unsigned char pad8[0x1f9 - 0x1c8];
    unsigned char b1f9;
    unsigned char pad9[0x255 - 0x1fa];
    unsigned char b255;
    unsigned char pad10[0x328 - 0x256];
    unsigned char b328;
    unsigned char pad11[0x3f0 - 0x329];
    unsigned char b3f0;
    unsigned char b3f1;
    unsigned char pad12[0x3f8 - 0x3f2];
    unsigned char b3f8;
};

struct Stats_tu5_01 {
    unsigned char pad0[124];
    short w7c[256];
};

struct Vec3_tu5_01 { float x, y, z; };

typedef void (*handler_tu5_01)(struct Obj_tu5_01 *);

extern handler_tu5_01 dat_0c248eb4[];
extern struct Stats_tu5_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Obj_tu5_01 *);
extern void func_0c02a39a(struct Obj_tu5_01 *, int);
extern void func_0c0432ca(struct Obj_tu5_01 *);
extern void func_0c02a0c4(struct Obj_tu5_01 *, int, int);
extern void func_0c02a026(struct Obj_tu5_01 *);
extern void func_0c16678c(struct Obj_tu5_01 *, int);
extern void func_0c0429a4(struct Obj_tu5_01 *, struct Vec3_tu5_01 *, int);

void func_0c0ddc88(struct Obj_tu5_01 *a)
{
    dat_0c248eb4[a->b6](a);
}

void func_0c0ddc9a(struct Obj_tu5_01 *a)
{
    if (a->b255 == 6) {
        a->b3f0 = 0xff;
        a->b3f1 = 16;
    }
    a->b1f9 = 0;
    a->b6++;
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    func_0c0432ca(a);
    a->s28 = 0;
    a->b1a1 = 81;
    a->w1ac = 0;
    a->b19e = 0;
    a->l1c4 = 0;
    dat_0c2f83f8->w7c[a->b2]++;
    func_0c02a0c4(a, 22, 9);
}

void func_0c0ddd12(struct Obj_tu5_01 *a)
{
    struct Vec3_tu5_01 v;

    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    func_0c02a026(a);
    if (a->b141 & 2) {
        a->b141 &= 0xfd;
        func_0c16678c(a, 4);
    }
    if (a->b141 & 1) {
        a->b141 &= 0xfe;
        a->b6++;
        a->b3f0 = 0;
        a->b3f1 = 0;
        v.x = 13.333333015441895f;
        v.y = 122.142857f;
        v.z = 0.0f;
        func_0c0429a4(a, &v, 1);
    }
}

/* Five functions sharing the literal pool at 0x0c0e1fea. */
struct Obj_tu4_01 {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad1[28 - 7];
    short s28;
    unsigned char pad2[92 - 30];
    float f92;
    float f96;
    unsigned char pad3[4];
    float f104;
    float f108;
    unsigned char pad4[0x130 - 112];
    short w130;
    unsigned char pad5[0x327 - 0x132];
    unsigned char b327;
    unsigned char b328;
    unsigned char pad6[0x3f8 - 0x329];
    unsigned char b3f8;
    unsigned char b3f9;
};

extern char func_0c02a026(struct Obj_tu4_01 *p);
extern void func_0c02a0c4(struct Obj_tu4_01 *p, int a, int b);

void func_0c0e1ec8(struct Obj_tu4_01 *p)
{
    p->b3f8 = 2;
    p->b328 = 5;
    if (func_0c02a026(p) < 0)
        p->b6++;
}

void func_0c0e1ef2(struct Obj_tu4_01 *p)
{
    p->b6++;
    p->b3f8 = 2;
    p->b328 = 5;
    func_0c02a0c4(p, 21, 34);
    p->s28 = 60;
}

void func_0c0e1f1e(struct Obj_tu4_01 *p)
{
    p->b3f8 = 2;
    p->b328 = 5;
    func_0c02a026(p);
    p->s28--;
    if (p->s28 > 0)
        return;
    p->b6++;
    if (p->w130)
        func_0c02a0c4(p, 21, 36);
    else
        func_0c02a0c4(p, 21, 35);
}

void func_0c0e1f68(struct Obj_tu4_01 *p)
{
    p->b3f8 = 2;
    p->b328 = 5;
    if (func_0c02a026(p) < 0)
        p->b6++;
}

void func_0c0e1f92(struct Obj_tu4_01 *p)
{
    p->b6++;
    p->b3f9 = 0;
    p->b3f8 = 0;
    p->b327 = 0;
    p->b328 = 0;
    p->f92 = -6.25f;
    p->f104 = 0.0390625f;
    p->f96 = 20.625f;
    p->f108 = -0.90401781f;
    if (p->w130) {
        p->f92 = -p->f92;
        p->f104 = -p->f104;
    }
    func_0c02a0c4(p, 21, 22);
}

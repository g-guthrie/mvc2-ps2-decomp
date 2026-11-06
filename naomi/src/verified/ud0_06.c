struct Obj_ud0_06 {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad1[28 - 7];
    short s28;
    unsigned char pad2[0x38 - 30];
    float f38;
    unsigned char pad3[0x60 - 0x3c];
    float f96;
    unsigned char pad4[0x6c - 0x64];
    float f108;
    unsigned char pad5[0x41c - 0x70];
    float f41c;
};

extern char func_0c02a026(struct Obj_ud0_06 *);
extern void func_0c02a0c4(struct Obj_ud0_06 *, int, int);
extern void func_0c1ba1a0(struct Obj_ud0_06 *, int, int);
extern void func_0c0344a0(struct Obj_ud0_06 *, int);

void func_0c117ac0(struct Obj_ud0_06 *a)
{
    func_0c02a026(a);
    a->f38 += a->f96;
    a->f96 += a->f108;
    if (--a->s28 == 0) {
        a->b6++;
        a->f38 = a->f41c;
        a->s28 = 8;
        func_0c02a0c4(a, 18, 1);
        func_0c1ba1a0(a, 1, 0);
    }
}

void func_0c117b22(struct Obj_ud0_06 *a)
{
    func_0c02a026(a);
    a->f38 += a->f96;
    a->f96 += a->f108;
    if (--a->s28 == 0) {
        a->b6++;
        a->f38 = a->f41c;
        a->s28 = 8;
        func_0c02a0c4(a, 18, 2);
    }
}

void func_0c117b7a(struct Obj_ud0_06 *a)
{
    func_0c02a026(a);
    a->f38 += a->f96;
    a->f96 += a->f108;
    if (--a->s28 == 0) {
        a->b6++;
        a->f38 = a->f41c;
        a->s28 = 10;
        func_0c02a0c4(a, 18, 3);
        func_0c0344a0(a, 10);
    }
}

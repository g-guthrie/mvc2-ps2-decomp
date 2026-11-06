struct S_ud2_11 {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad1[0x1c - 7];
    short w1c;
    unsigned char pad2[0x34 - 0x1e];
    float f34;
    float f38;
    unsigned char pad4[0x5c - 0x3c];
    float f5c, f60;
    unsigned char pad5[0x68 - 0x64];
    float f68, f6c;
    unsigned char pad6[0x130 - 0x70];
    short w130;
    unsigned char pad7[0x1ed - 0x132];
    unsigned char b1ed;
    unsigned char pad8[0x1f3 - 0x1ee];
    unsigned char b1f3;
    unsigned char b1f4;
};

extern signed char func_0c02a026(struct S_ud2_11 *);
extern void func_0c0437b8(struct S_ud2_11 *);
extern void func_0c02a0c4(struct S_ud2_11 *, int, int);
extern float dat_0c2d9260[];
extern void func_0c025762(void);

void func_0c065b8c(struct S_ud2_11 *a)
{
    a->f34 += a->f5c;
    a->f5c += a->f68;
    a->f38 += a->f60;
    a->f60 += a->f6c;
    if (func_0c02a026(a) >= 0)
        return;
    func_0c0437b8(a);
}

void func_0c065be6(struct S_ud2_11 *a)
{
    a->b1f4 = 3;
    a->b1ed = 3;
    a->b1f3 = 3;
    a->f34 += a->f5c;
    a->f5c += a->f68;
    a->f38 += a->f60;
    a->f60 += a->f6c;
    func_0c02a026(a);
    if (--a->w1c == 0) {
        a->b6 = a->b6 + 1;
        a->w1c = 4;
    }
}

void func_0c065c54(struct S_ud2_11 *a)
{
    a->b1f4 = 3;
    a->b1ed = 3;
    a->b1f3 = 3;
    if (--a->w1c == 0) {
        a->b6 = a->b6 + 1;
        a->w1c = 3;
        if ((a->w130 ^= 1))
            a->f34 = *(float *)((char *)dat_0c2d9260 + 0x88) - 133.33333f;
        else
            a->f34 = *(float *)((char *)dat_0c2d9260 + 0x8c) + 133.33333f;
        func_0c02a0c4(a, 20, 5);
    }
}

void func_0c065cb0(struct S_ud2_11 *a)
{
    a->b1f4 = 3;
    a->b1ed = 3;
    a->b1f3 = 3;
    if (--a->w1c == 0) {
        a->b6 = a->b6 + 1;
        a->w1c = 20;
        a->b1ed = 0;
        func_0c025762();
    }
}

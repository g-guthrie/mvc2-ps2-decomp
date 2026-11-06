/* func_0c1aac8c and func_0c1aac9e match exactly. func_0c1aad22 differs: retail
 * reaches its extern tail call to func_0c1aba44 with a plain `bra` (2 bytes,
 * the target is in range), while this source's identical tail statement
 * compiles to `mov.l addr,r3; jmp @r3` (SHC's normal far-call shape for an
 * extern symbol). No C spelling found in ten tries makes SHC choose `bra` for
 * a tail call to a symbol outside this translation unit, so the two bytes
 * saved shift every literal after it and func_0c1aad52/64/adb8/add2 no longer
 * link at their addresses even though their own bodies are otherwise right. */
struct Obj_uc0_05 {
    unsigned char pad0[6];
    unsigned char b6, b7;
    unsigned char pad1[30 - 8];
    short s30;
    unsigned char pad2[52 - 32];
    float f52;
    unsigned char pad3[92 - 56];
    float f92, f96;
    unsigned char pad4[104 - 100];
    float f104, f108;
    unsigned char pad5[0xd2 - 112];
    unsigned char bd2, bd3;
    short w130;
    unsigned char pad6[0x130 - 0xd4];
};

typedef void (*handler1_uc0_05)(struct Obj_uc0_05 *);
typedef void (*handler2_uc0_05)(struct Obj_uc0_05 *, struct Obj_uc0_05 *);

extern handler1_uc0_05 dat_0c259c64[];
extern handler2_uc0_05 dat_0c259c6c[];
extern handler1_uc0_05 dat_0c259c74[];
extern void func_0c02a0c4(struct Obj_uc0_05 *, int, int);
extern char func_0c02a026(struct Obj_uc0_05 *);
extern void func_0c1aba44(struct Obj_uc0_05 *, struct Obj_uc0_05 *);

void func_0c1aad22(struct Obj_uc0_05 *a, struct Obj_uc0_05 *b);
void func_0c1aad52(struct Obj_uc0_05 *a, struct Obj_uc0_05 *b);
void func_0c1aadb8(struct Obj_uc0_05 *a, struct Obj_uc0_05 *b);

void func_0c1aac8c(struct Obj_uc0_05 *a)
{
    dat_0c259c64[a->b7](a);
}

void func_0c1aac9e(struct Obj_uc0_05 *a, struct Obj_uc0_05 *b)
{
    unsigned char cond = 0;

    a->b7++;
    a->f92 = 0.0f;
    a->f104 = 0.0f;
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    if (a->f52 < b->f52)
        cond = 1;
    if (cond != a->w130) {
        a->bd2 = a->b6;
        a->bd3 = a->b7;
        a->b6 = 11;
        a->b7 = 0;
        func_0c1aad52(a, b);
    } else {
        if (a->b6 != a->bd2)
            func_0c02a0c4(a, 25, 0);
        func_0c1aad22(a, b);
    }
}

void func_0c1aad22(struct Obj_uc0_05 *a, struct Obj_uc0_05 *b)
{
    func_0c02a026(a);
    if (--a->s30 == 0)
        func_0c1aba44(a, b);
}

void func_0c1aad52(struct Obj_uc0_05 *a, struct Obj_uc0_05 *b)
{
    dat_0c259c6c[a->b7](a, b);
}

void func_0c1aad64(struct Obj_uc0_05 *a, struct Obj_uc0_05 *b)
{
    a->b7++;
    a->f92 = 0.0f;
    a->f104 = 0.0f;
    a->f96 = 0.0f;
    a->w130 ^= 1;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 25, 6);
    func_0c1aadb8(a, b);
}

void func_0c1aadb8(struct Obj_uc0_05 *a, struct Obj_uc0_05 *b)
{
    if (func_0c02a026(a) < 0) {
        a->bd2 = a->b6;
        a->bd3 = a->b7;
        a->b6 = 2;
        a->b7 = 0;
    }
}

void func_0c1aadd2(struct Obj_uc0_05 *a)
{
    dat_0c259c74[a->b7](a);
}

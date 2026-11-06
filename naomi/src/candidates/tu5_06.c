/* Three functions sharing the literal pool at 0x0c051a6e.
 * func_0c051954 and func_0c051994 match except for pool displacements:
 * retail places the pool in the middle of func_0c0519fc (after its case-8
 * tail call, at 0x0c051a6e), and that function does not match yet, so the
 * pool lands elsewhere. In func_0c0519fc retail keeps the two tail calls to
 * func_0c05081c/func_0c05083a as mov.l+jmp inside the loop while the compiler
 * hoists them (and the extra pool loads) into r8-r11 here; the case-22 and
 * case-67 tail calls are bra to func_0c050aaa/func_0c050afe, which are in the
 * same retail translation unit (before this pool), so they cannot be
 * reproduced from this file. */

struct Tgt_tu5_06 { unsigned char pad[0x1d3]; char b1d3; };
struct Str_tu5_06 { unsigned char *p0; unsigned short w4; unsigned char pad[1]; unsigned char b7; };
struct Flag_tu5_06 { char b0; };

struct Obj_tu5_06 {
    unsigned char pad0[0x20c];
    struct Tgt_tu5_06 *p20c;
    unsigned char pad1[0x40c - 0x210];
    struct Flag_tu5_06 *p40c;
    unsigned char pad2[0x43d - 0x410];
    unsigned char b43d;
    unsigned char pad3[0x442 - 0x43e];
    short w442, w444;
    unsigned char pad4[0x45e - 0x446];
    unsigned char b45e;
    unsigned char pad5[0x4b4 - 0x45f];
    union { int l; short w; char b; } u4b4;
};

extern void func_0c04e6b2(struct Obj_tu5_06 *, struct Str_tu5_06 *, int);
extern void func_0c050792(struct Obj_tu5_06 *, struct Str_tu5_06 *, int);
extern unsigned char dat_0c23e7b4[];
extern int func_0c05081c(struct Obj_tu5_06 *, struct Str_tu5_06 *);
extern int func_0c05083a(struct Obj_tu5_06 *, struct Str_tu5_06 *);
extern int func_0c050aaa(struct Obj_tu5_06 *, struct Str_tu5_06 *);
extern int func_0c050afe(struct Obj_tu5_06 *, struct Str_tu5_06 *);

void func_0c051954(struct Obj_tu5_06 *a, struct Str_tu5_06 *b)
{
    struct Tgt_tu5_06 *q;

    func_0c04e6b2(a, b, 0);
    func_0c04e6b2(a, b, 1);
    q = a->p20c;
    func_0c050792(a, b, q->b1d3 == a->u4b4.b);
}

int func_0c051994(struct Obj_tu5_06 *a, struct Str_tu5_06 *b)
{
    func_0c04e6b2(a, b, 0);
    a->w444 = b->w4;
    b->w4 += 5;
    func_0c04e6b2(a, b, 1);
    if (a->p40c->b0 < a->u4b4.l) {
        b->w4 += 2;
        a->w442 = 0;
    } else {
        func_0c04e6b2(a, b, 2);
        if (a->u4b4.l < 0)
            a->u4b4.l = 0;
        a->w442 = a->u4b4.w;
    }
    return 1;
}

int func_0c0519fc(struct Obj_tu5_06 *a, struct Str_tu5_06 *b)
{
    int n = 0;
    unsigned int i = b->w4;
    unsigned char *buf = b->p0;
    unsigned char c;

    do {
        b->b7++;
        c = buf[i];
        i += dat_0c23e7b4[c];
        if (c >= 96) {
            n++;
        } else {
            switch (c) {
            case 3:
                return func_0c05081c(a, b);
            case 8:
                return func_0c05083a(a, b);
            case 22:
                return func_0c050aaa(a, b);
            case 67:
                return func_0c050afe(a, b);
            case 23:
                if (n == 0)
                    n--;
                break;
            case 24:
            case 73:
                n--;
                break;
            }
        }
    } while (n >= 0);
    b->w4 = i;
    a->b45e = 0;
    return 1;
}

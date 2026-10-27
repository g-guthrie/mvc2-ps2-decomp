typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    s8 b0;
    s8 state;
    s8 b2;
    s8 n;
    u8 *f4;
    s32 f8;
    u8 *list[(0x90 - 0xC) / 4];
    void *list2[16];
    u8 pad[0x1A8 - 0xD0];
    s8 b1a8;
    s8 b1a9;
    u8 pad2[0x1B0 - 0x1AA];
    s32 f1b0;
    s32 f1b4;
} T404;

/* Provisional: the body forces a register and is not credited as reconstructed C. */
void func_00404E90(T404 *p) {
    extern s8 func_004052B8(void *);
    extern void func_00405350(u8 *, s32, s32 *, s32 *);
    extern void func_00400658(s32, s32);
    extern void func_004007A0(s32, s32);
    extern void func_00400790(s32, void (*)(), T404 *);
    extern void func_00404DA8();
    extern void func_004052E0(void *, s32);
    extern void func_004052E8(void *, s32);
    extern s8 func_004052F0(void *);
    extern void func_004028E0(void *, s32);
    extern void func_00401760(u8 *, void *);
    extern s32 func_00401920(s8 *);
    extern s32 func_00402550(s16 *);
    s32 x[2];
    s32 i, r, c;
    u8 *s;
    u8 **l, **a; void **b; s32 k5;
    register s32 n __asm__("$17");

    l = p->list;
    s = p->f4;
    if (p->state == 1) {
        if (func_004052B8(s) == 2) {
            p->f1b0 = p->f1b4;
            func_00405350(s, p->f1b4, &x[0], &x[1]);
            func_00400658(p->f8, x[0] / 2048);
            func_004007A0(p->f8, (x[0] + x[1]) / 2048);
            func_00400790(p->f8, func_00404DA8, p);
            func_004052E0(s, 0);
            if (p->b1a8 == 1 || p->b1a9 == 1) {
                func_004052E8(s, 1);
            }
            r = func_004052F0(s);
            if (r > 0) {
                n = r;
                b = p->list2;
                a = l;
                do {
                    func_004028E0(*a, 1);
                    func_00401760(*a, *b);
                    b++;
                    a++;
                } while (--n);
            }
            p->state = 2;
        }
    } else if (p->state == 2) {
        if (func_004052B8(s) == 3) {
            i = 0;
            k5 = 5;
            a = l;
            for (; i < p->n; i++) {
                c = func_00401920((s8 *)*a++);
                if (c != k5 && c != 0) break;
            }
            if (i == p->n) p->state = 3;
        }
    }
    a = l;
    for (i = 0; i < p->n; i++) {
        if (func_00402550((s16 *)*a++) == -1) {
            p->state = 4;
            break;
        }
    }
}

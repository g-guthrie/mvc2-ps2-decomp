/* Complete 312-byte unit: two handlers and the shared 18-byte pool.
 * The signed zero test preserves retail sign-extension at 0x0c1026d8. */
struct Obj_tu7_08 {
    unsigned char pad0[28];
    short s28;
    unsigned char pad1[37 - 30];
    unsigned char b37;
    unsigned char pad2[0x158 - 38];
    unsigned char b158, b159;
    unsigned char pad3[0x1d0 - 0x15a];
    unsigned char b1d0;
    unsigned char pad4[0x420 - 0x1d1];
    short w420;
};

struct Ctl_tu7_08 {
    unsigned char pad0[9];
    char b9;
    short s10;
    unsigned char pad1[1];
    char b13, b14, b15;
};

extern void func_0c02a39a(struct Obj_tu7_08 *, int);
extern void func_0c02a684(struct Obj_tu7_08 *, int, int, int);

void func_0c102648(struct Obj_tu7_08 *a, struct Ctl_tu7_08 *b)
{
    int s;
    if (b->b9 == 0)
        return;
    s = a->b1d0;
    if (s == 28 || s == 22 || !a->w420)
        b->s10 = 1;
    if (--b->s10 == 0) {
        b->b9 = 0;
        b->b13 = 0;
        b->b14 = 0;
        func_0c02a39a(a, 0);
        return;
    }
    if (--b->b14 == 0) {
        b->b14 = 8;
        func_0c02a684(a, 0, a->b37 * 48 + b->b15 + 37, 2);
        b->b15 += b->b9;
        if (!((signed char)b->b15) || (signed char)b->b15 == 4)
            b->b9 = -b->b9;
    }
}

void func_0c1026f2(struct Obj_tu7_08 *a, struct Ctl_tu7_08 *b)
{
    if (a->b159 == 15 && a->b158 == 2) {
        if (a->s28) {
            func_0c02a684(a, 0, a->b37 * 48 + b->b14 + 20, 1);
            if (--b->b13 == 0) {
                b->b13 = 9;
                b->b15 = -b->b15;
            }
            b->b14 += b->b15;
        } else {
            func_0c02a39a(a, 0);
        }
    }
}

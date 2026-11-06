/* Four functions sharing the literal pool at 0x0c080d80. */
struct V3_tu7_05 { float x, y, z; };
struct Sub_tu7_05 { unsigned char pad0[1]; unsigned char b1; unsigned char pad1[56 - 2]; float f56; };

struct Obj_tu7_05 {
    unsigned char pad0[28];
    short s28;
    unsigned char pad1[34 - 30];
    unsigned char b34;
    unsigned char pad2[0x1a0 - 35];
    unsigned char b1a0;
    unsigned char pad3[0x1a3 - 0x1a1];
    unsigned char b1a3;
    unsigned char pad4[0x1c8 - 0x1a4];
    struct Sub_tu7_05 *p1c8;
    unsigned char pad5[0x1f7 - 0x1cc];
    unsigned char b1f7;
    unsigned char pad6[1];
    unsigned char b1f9;
    unsigned short w1fa;
    unsigned char pad7[0x1fe - 0x1fc];
    char b1fe;
    unsigned char pad8[0x411 - 0x1ff];
    char b411;
};

typedef void (*fn_tu7_05)(struct Obj_tu7_05 *);

extern fn_tu7_05 dat_0c241c3c[];
extern fn_tu7_05 dat_0c241c4c[];
extern unsigned short dat_0c241c60[];
extern int func_0c037d54(struct Obj_tu7_05 *);
extern void func_0c1d4610(struct Obj_tu7_05 *, struct V3_tu7_05 *);
extern void func_0c025900(struct Obj_tu7_05 *, int, int);
extern void func_0c02a0c4(struct Obj_tu7_05 *, int, int);

int func_0c080c90(struct Obj_tu7_05 *a)
{
    int r = 0;
    unsigned int v;
    if (dat_0c241c3c[a->b1f9]) {
        if ((v = a->w1fa & 0xc00) != 0) {
            a->b34 = v >> 10;
            if (a->b1fe == 0 && a->b1a3 == 1) {
                if ((r = func_0c037d54(a)) != 0)
                    a->b1f7 = 2;
            }
        }
    }
    return r;
}

void func_0c080cec(struct Obj_tu7_05 *a)
{
    dat_0c241c4c[a->b1f7 & 63](a);
}

void func_0c080d04(struct Obj_tu7_05 *a)
{
    struct V3_tu7_05 loc;
    struct Sub_tu7_05 *q;
    loc.x = -110.0f;
    loc.y = 171.42855834960938f;
    func_0c1d4610(a, &loc);
    if (!a->b411)
        func_0c025900(a, 5, 5);
    a->b1a0 = 10;
    q = a->p1c8;
    q->f56 += 2.142857074737549f * (float)dat_0c241c60[q->b1];
    a->s28 = 64;
    func_0c02a0c4(a, 15, 0);
}

void func_0c080d78(struct Obj_tu7_05 *a)
{
    func_0c02a0c4(a, 15, 3);
}

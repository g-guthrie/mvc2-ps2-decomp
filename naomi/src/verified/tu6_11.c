/* Three functions sharing the literal pool at 0x0c0a5be0. */

struct Obj_0c0a5b18 {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad1[0x141 - 7];
    char b141;
    unsigned char pad2[0x1a3 - 0x142];
    unsigned char b1a3;
    unsigned char pad3[0x327 - 0x1a4];
    unsigned char b327, b328;
    unsigned char pad4[0x3f8 - 0x329];
    unsigned char b3f8, b3f9;
};

struct Vec3 { float x, y, z; };

typedef void (*fn_t)(struct Obj_0c0a5b18 *);

extern fn_t dat_0c24421c[];
extern char func_0c02a026(struct Obj_0c0a5b18 *a);
extern void func_0c0429a4(struct Obj_0c0a5b18 *a, struct Vec3 *v, int n);
extern void func_0c14b8d8(struct Obj_0c0a5b18 *a, int b, int c, int d);
extern void func_0c0437b8(struct Obj_0c0a5b18 *a);

void func_0c0a5b18(struct Obj_0c0a5b18 *a)
{
    struct Vec3 v;

    a->b3f8 = 2;
    a->b328 = 5;
    if (a->b141 == 1) {
        if (a->b141 == 1) {
            a->b141 = 0;
            v.x = 13.3333335f;
            v.y = 188.57143f;
            func_0c0429a4(a, &v, 1);
        }
    }
    if (a->b141 == 2) {
        a->b6++;
        a->b1a3 = 0;
        func_0c14b8d8(a, 22, 19, 0);
        a->b141 = 0;
    }
    func_0c02a026(a);
}

void func_0c0a5b8e(struct Obj_0c0a5b18 *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (func_0c02a026(a) < 0) {
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        func_0c0437b8(a);
    }
}

void func_0c0a5bce(struct Obj_0c0a5b18 *a)
{
    dat_0c24421c[a->b6](a);
}

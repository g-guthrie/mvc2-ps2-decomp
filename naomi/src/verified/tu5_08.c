/* Three functions sharing the literal pool at 0x0c0591ee. */

struct Obj_tu5_08 {
    unsigned char pad0[7];
    unsigned char b7;
    unsigned char pad1[52 - 8];
    float f52, f56;
    unsigned char pad2[92 - 60];
    float f92, f96, f100, f104, f108;
    unsigned char pad3[0x1c8 - 112];
    struct Obj_tu5_08 *p1c8;
    unsigned char pad4[0x1f7 - 0x1cc];
    unsigned char b1f7;
};

struct Vec3_tu5_08 { float x, y, z; };

extern char func_0c02a026(struct Obj_tu5_08 *);
extern void func_0c1d4610(struct Obj_tu5_08 *, struct Vec3_tu5_08 *);
extern void func_0c0344a0(struct Obj_tu5_08 *, int);
extern void func_0c02a0c4(struct Obj_tu5_08 *, int, int);
extern void func_0c044548(struct Obj_tu5_08 *, struct Obj_tu5_08 *);

void func_0c0590d8(struct Obj_tu5_08 *a)
{
    struct Vec3_tu5_08 v;
    struct Obj_tu5_08 *p;

    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    p = a->p1c8;
    if (p->f56 - a->f56 + -17.142857f < -68.57143f) {
        a->b7++;
        a->b1f7 = 202;
        v.x = -146.66666f;
        v.y = 171.42857f;
        func_0c1d4610(a, &v);
        func_0c0344a0(a, 5);
        func_0c02a0c4(a, 15, 17);
        func_0c044548(a, p);
    }
}

void func_0c059180(struct Obj_tu5_08 *a)
{
    if (func_0c02a026(a) < 0) {
        a->b7++;
        func_0c02a0c4(a, 15, 44);
    }
}

void func_0c0591aa(struct Obj_tu5_08 *a)
{
    if (func_0c02a026(a) < 0) {
        a->b7++;
        a->f92 = 0.0f;
        a->f104 = 0.0f;
        a->f96 = -6.4285713f;
        a->f108 = -1.2053571f;
        func_0c02a0c4(a, 15, 45);
    }
}

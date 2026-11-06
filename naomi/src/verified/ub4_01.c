/* Assigned span 0x0c08f908 size 312 stopped mid-pool at 0x0c08fa40, splitting
 * the literal pool (0x0c08fa3e-0x0c08fa58) shared by every function below.
 * Extended to 0x0c08fa58, the next code range (size 336), so the whole pool
 * is interior. */

struct Obj_ub4_01 {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad1[28 - 7];
    short s28;
    short s30;
    unsigned char pad2[52 - 32];
    float f52, f56;
    unsigned char pad3[92 - 60];
    float f92, f96;
    unsigned char pad4[104 - 100];
    float f104, f108;
    unsigned char pad5[0x1d2 - 112];
    unsigned char b1d2;
};

typedef void (*handler_ub4_01)(struct Obj_ub4_01 *);

extern handler_ub4_01 dat_0c242b38[];
extern char func_0c02a026(struct Obj_ub4_01 *);
extern void func_0c0437b8(struct Obj_ub4_01 *);
extern void func_0c02a0c4(struct Obj_ub4_01 *, int, int);

void func_0c08f9c6(struct Obj_ub4_01 *a);

void func_0c08f908(struct Obj_ub4_01 *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (--a->s30 != 0)
        return;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    func_0c0437b8(a);
}

void func_0c08f978(struct Obj_ub4_01 *a)
{
    dat_0c242b38[a->b6](a);
}

void func_0c08f98a(struct Obj_ub4_01 *a)
{
    a->b6++;
    a->s28 = 24;
    a->f92 = 15.83333302f;
    a->f104 = -0.401785702f;
    if (a->b1d2 != 0) {
        a->f92 = -a->f92;
        a->f104 = -a->f104;
    }
    a->f96 = 0;
    a->f108 = 0;
    func_0c08f9c6(a);
}

void func_0c08f9c6(struct Obj_ub4_01 *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    func_0c02a026(a);
    if (--a->s28 != 0)
        return;
    a->b6++;
    func_0c02a0c4(a, 2, 3);
}

void func_0c08fa14(struct Obj_ub4_01 *a)
{
    if (func_0c02a026(a) < 0) {
        a->f92 = 0;
        a->f104 = 0;
        func_0c0437b8(a);
    }
}

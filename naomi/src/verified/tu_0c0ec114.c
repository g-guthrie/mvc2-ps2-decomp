#include "objects.h"

struct Obj_0c0ec114 {
    unsigned char pad0[28];
    short s28;
    unsigned char pad1[37 - 30];
    unsigned char b37;
    unsigned char pad2[0x14b - 38];
    char b14b;
};

extern void func_0c02a684(struct Obj_0c0ec114 *, int, int, int);
extern void func_0c02a39a(struct Obj_0c0ec114 *, int);

void func_0c0ec114(struct Obj_0c0ec114 *a)
{
    func_0c02a684(a, 3, 4, 1);
    if (!a->b14b)
        return;
    if (a->b14b > 0) {
        a->s28 = (unsigned char)a->b14b;
        a->s28 = a->s28 - 2;
        a->s28 = a->s28 / 2;
        a->b14b = 0;
        func_0c02a684(a, 0, a->b37 * 5 + a->s28, 1);
        return;
    }
    a->b14b = 0;
    func_0c02a39a(a, 0);
}

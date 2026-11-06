#include "objects.h"



struct Obj_13bb5c {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[0x20 - 5];
    char b20;
    unsigned char pad2[0x12c - 0x21];
    unsigned char b12c;
};

extern struct Dat_13bb5c dat_0c2f8338;
extern char func_0c02a026(struct Obj_13bb5c *);
extern void func_0c037d0c(struct Obj_13bb5c *);
extern void func_0c037688(struct Obj_13bb5c *);

void func_0c13bb5c(struct Obj_13bb5c *a)
{
    if ((dat_0c2f8338.w3c & (1 << dat_0c2f8338.b3b)) == 0) {
        if (func_0c02a026(a) < 0) {
            a->b4 = a->b4 + 1;
            a->b12c = 0;
        } else if (!a->b20) {
            func_0c037d0c(a);
        }
    }
}

void func_0c13bbaa(struct Obj_13bb5c *a)
{
    func_0c037688(a);
}

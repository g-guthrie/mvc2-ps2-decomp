#include "objects.h"

struct Glob_0c032848 {
    unsigned char pad0[4];
    char b4;
    unsigned char pad1[0x41 - 5];
    unsigned char b41;
    unsigned char pad2[0x8c - 0x42];
    char b8c;
};

extern struct Glob_0c032848 *dat_0c2d6f84;
extern void (*table_0c23b2e4[])(void);
extern void func_0c033a50(void);
extern void func_0c0374b8(int);
extern void func_0c02606e(void);
extern void func_0c02c314(void (*)(void));

void func_0c032848(void)
{
    struct Glob_0c032848 *g = dat_0c2d6f84;

    if (g->b8c) {
        func_0c033a50();
    } else {
        g->b41 = 1;
        table_0c23b2e4[dat_0c2d6f84->b4]();
        func_0c0374b8(5);
        func_0c0374b8(11);
    }
    func_0c02c314(func_0c02606e);
}

#include "objects.h"

struct Glob_0c031140 {
    unsigned char pad0;
    char b1;
    unsigned char b2, b3, b4, b5, b6, b7;
    short s8;
    unsigned char pad9[0x2e - 10];
    unsigned char b2e;
};

extern struct Glob_0c031140 *dat_0c2d6f84;
extern void func_0c02a7ea(unsigned int, int, int);
extern void func_0c033ed6(int);
extern void func_0c037354(void);
extern void func_0c1fba00(void *, int, int);
extern char dat_0c2d7008[];
extern char dat_0c2f8338[];
extern void func_0c033cbe(void);
extern void func_0c033cd8(void);
extern void func_0c034358(void);

void func_0c031140(void)
{
    struct Glob_0c031140 *p;

    dat_0c2d6f84->s8 -= 1;
    if (dat_0c2d6f84->s8 == 60) {
        func_0c02a7ea(0xff000000, 60, 1);
        func_0c033ed6(60);
    }
    p = dat_0c2d6f84;
    if (p->s8 != 0)
        return;
    p->b1 = p->b1 + 1;
    dat_0c2d6f84->b2 = 0;
    dat_0c2d6f84->b3 = 0;
    dat_0c2d6f84->b4 = 0;
    dat_0c2d6f84->b5 = 0;
    dat_0c2d6f84->b6 = 0;
    dat_0c2d6f84->b7 = 0;
    dat_0c2d6f84->b2e = 3;
    func_0c037354();
    func_0c1fba00(dat_0c2d7008, 0, 128);
    func_0c1fba00(dat_0c2f8338, 0, 192);
    func_0c033cbe();
    func_0c033cd8();
    func_0c034358();
}

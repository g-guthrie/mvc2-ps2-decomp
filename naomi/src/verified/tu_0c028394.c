#include "objects.h"
int _builtin_get_fpscr(void);
void _builtin_set_fpscr(int);
extern struct ActorFlags *dat_0c2d6f84;
extern struct ActorFlags dat_0c2d6f88;
extern struct ActorInputRecord20 dat_0c2d6f24[];
extern int dat_0c28401c;
extern int dat_0c284018;
extern void func_0c0215f6(int);
extern void func_0c028154(void);
extern void func_0c0221d8(void);
extern void func_0c022354(void);
extern void func_0c02a894(void);
extern void func_0c1e9b20(void);
extern void func_0c1eae80(void);
extern void func_0c02156c(void *);
extern void func_0c02c3e2(void);
extern void func_0c022526(void);
extern void func_0c021c9c(void);
extern void func_0c0223d4(void);
extern void func_0c034288(void);
extern void func_0c02ab2c(void);
extern void func_0c1e68dc(void);
extern void func_0c02c39a(void);
extern void func_0c02c4a2(void);
extern void func_0c0271de(void);
extern void func_0c023060(void);

#pragma noregsave(func_0c028394)
void func_0c028394(void)
{
    int mode;
    mode = _builtin_get_fpscr();
    mode &= ~3;
    _builtin_set_fpscr(mode);
    dat_0c2d6f84 = &dat_0c2d6f88;
    func_0c0215f6(0);
    func_0c028154();
    func_0c0221d8();
    func_0c022354();
    func_0c02a894();
    for (;;) {
        func_0c1e9b20();
        func_0c1eae80();
        func_0c02156c(&dat_0c2d6f24[0]);
        func_0c02156c(&dat_0c2d6f24[1]);
        func_0c02c3e2();
        func_0c022526();
        func_0c021c9c();
        func_0c0223d4();
        func_0c034288();
        dat_0c28401c = 0;
        dat_0c284018 = 0;
        func_0c02ab2c();
        func_0c1e68dc();
        func_0c02c39a();
        func_0c02c4a2();
        func_0c0271de();
        func_0c023060();
    }
}

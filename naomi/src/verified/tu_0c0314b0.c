#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern struct FadeState dat_0c2d93d0;
extern void (*table_0c23b1c4[])(void);
extern void func_0c0374b8(int),func_0c026196(void),func_0c02c314(void (*)(void));
extern void func_0c0275a4(void),func_0c0268b8(void),func_0c033e6c(int,int);
extern void func_0c0343ac(int),func_0c034a1c(int),func_0c1cd3aa(void);
extern void func_0c1cd5e4(int),func_0c0267c4(void),func_0c0267ce(void);
void func_0c0314b0(void)
{
    table_0c23b1c4[dat_0c2d6f84->b3]();
    func_0c0374b8(5);func_0c0374b8(11);
    func_0c02c314(func_0c026196);
}
void func_0c0314d6(void)
{
    register int zero=0;
    ++dat_0c2d6f84->b3;
    dat_0c2d6f84->b25=1;
    ((signed char *)dat_0c2d6f84)[0xa4]=zero;
    dat_0c2d6f84->s8=330;dat_0c2d6f84->s14=60;
    func_0c0275a4();func_0c0268b8();
    func_0c033e6c(zero,1);func_0c033e6c(1,1);
    func_0c0343ac(5);func_0c034a1c(61);func_0c1cd3aa();
    func_0c1cd5e4(zero);func_0c1cd5e4(1);func_0c1cd5e4(2);func_0c1cd5e4(3);
    func_0c1cd5e4(4);func_0c1cd5e4(5);func_0c1cd5e4(6);func_0c1cd5e4(7);
    func_0c1cd5e4(8);func_0c1cd5e4(9);func_0c1cd5e4(10);func_0c1cd5e4(11);
    func_0c1cd5e4(12);func_0c1cd5e4(13);
    func_0c0267c4();
    dat_0c2d93d0.enabled=1;dat_0c2d93d0.count=42;dat_0c2d93d0.value=9000.0f;
    dat_0c2d93d0.red=zero;dat_0c2d93d0.green=zero;dat_0c2d93d0.blue=zero;
    func_0c0267ce();
}

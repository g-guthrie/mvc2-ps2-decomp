#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern unsigned short dat_0c2d6f24[],dat_0c2d6f38[];
extern void func_0c0374b8(int),func_0c037354(void),func_0c023658(unsigned int);
extern void func_0c033cbe(void),func_0c033cd8(void),func_0c034358(void);
void func_0c033b98(void)
{
    func_0c0374b8(11);
    --dat_0c2d6f84->s8;
    if (((dat_0c2d6f84->b84&1) && (dat_0c2d6f24[0]&0x360)) || ((dat_0c2d6f84->b84&2) && (dat_0c2d6f38[0]&0x360)) || !dat_0c2d6f84->s8)
        ++dat_0c2d6f84->b8e;
}
void func_0c033bec(void)
{
    int zero=0;
    dat_0c2d6f84->b2=zero;dat_0c2d6f84->b3=zero;dat_0c2d6f84->b4=zero;
    dat_0c2d6f84->b5=zero;dat_0c2d6f84->b6=zero;
    ((signed char *)dat_0c2d6f84)[7]=zero;
    ((signed char *)dat_0c2d6f84)[0x8d]=zero;
    dat_0c2d6f84->b8e=zero;dat_0c2d6f84->b25=1;
    func_0c037354();func_0c023658(0xff000000);
    func_0c033cbe();func_0c033cd8();func_0c034358();
}

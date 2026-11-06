#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern struct FadeState dat_0c2d93d0;
extern unsigned short dat_0c2d6f24[];
extern void func_0c0275dc(void), func_0c0267ce(void);
extern void func_0c033cbe(void), func_0c033cd8(void), func_0c034358(void);
void func_0c0315dc(void)
{
    struct ActorFlags *g;
    if (dat_0c2d6f84->s14) {
        --dat_0c2d6f84->s14;
        dat_0c2d93d0.count=((dat_0c2d6f84->s14 * 32)/60)+10;
        dat_0c2d93d0.value=8994.0f/(float)(2 << (60-dat_0c2d6f84->s14)) + 6.0f;
        dat_0c2d93d0.red-=4;dat_0c2d93d0.green-=4;dat_0c2d93d0.blue-=4;
        if (dat_0c2d93d0.value<6.0f) {
            dat_0c2d6f84->s14=0;
            dat_0c2d93d0.count=10;dat_0c2d93d0.value=6.0f;
            dat_0c2d93d0.red=0;dat_0c2d93d0.green=0;dat_0c2d93d0.blue=0;
        }
    }
    func_0c0275dc();func_0c0267ce();
    if (dat_0c2d6f84->s8) --dat_0c2d6f84->s8;
    g=dat_0c2d6f84;
    if (g->b42 || !g->b24) {
        if ((dat_0c2d6f24[0]&0x8000) || (dat_0c2d6f24[10]&0x8000) || g->s8==0) ++g->b3;
    }
}
void func_0c0316b2(void)
{
    dat_0c2d6f84->b2=6;dat_0c2d6f84->b3=0;
    func_0c033cbe();func_0c033cd8();func_0c034358();
}

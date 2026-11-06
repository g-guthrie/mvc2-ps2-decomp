#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern struct FadeState dat_0c2d93d0;
extern void (*table_0c23b214[])(void);
extern void func_0c0374b8(int),func_0c0260d8(void),func_0c02c314(void (*)(void));
extern char dat_0c22d1c0[],dat_0c23b1d0[],dat_0c23b220[];
extern char *dat_0c2fb1e4,*dat_0c2fb1e8;
extern char dat_0c2fb1ec,dat_0c2fb1ef,dat_0c2fb1ee,dat_0c2fb1ed;
extern void func_0c034258(void),func_0c037354(void),func_0c0275a4(void);
extern void func_0c0275bc(char *),func_0c0275d0(float);
extern void func_0c02aa78(void),func_0c02aaac(void),func_0c027ff0(int);
extern void func_0c023a50(void),func_0c023658(unsigned int),func_0c0268b8(void);
extern void func_0c02a7ea(unsigned int,int,int),func_0c0267c4(void),func_0c0267ce(void);
extern void func_0c0342a2(int),func_0c033ef8(int),func_0c034312(void);
void func_0c031704(void)
{
    table_0c23b214[dat_0c2d6f84->b4]();
    func_0c0374b8(11);func_0c0374b8(6);
    func_0c02c314(func_0c0260d8);
}
void func_0c03172a(void)
{
    register int zero=0;
    if (dat_0c2d6f84->b6==0) {
        dat_0c2d6f84->b5=zero;
        ++dat_0c2d6f84->b6;
        dat_0c2d6f84->b25=1;
        dat_0c2d6f84->s8=6000;
        dat_0c2d6f84->s10=zero;
        dat_0c2d6f84->s12=1;
        dat_0c2d6f84->s14=60;
        dat_0c2fb1e4=dat_0c22d1c0;dat_0c2fb1e8=dat_0c23b1d0;
        dat_0c2fb1ec=1;dat_0c2fb1ef=zero;dat_0c2fb1ee=zero;dat_0c2fb1ed=zero;
        func_0c034258();func_0c037354();func_0c0275a4();
        func_0c0275bc(dat_0c23b220);func_0c0275d0(1.0f);
        func_0c02aa78();func_0c02aaac();func_0c027ff0(9);
        func_0c023a50();func_0c023658(0xff000000);func_0c0268b8();
        func_0c02a7ea(-1,60,0);func_0c0267c4();
        dat_0c2d93d0.enabled=zero;dat_0c2d93d0.count=128;dat_0c2d93d0.value=9000.0f;
        dat_0c2d93d0.red=zero;dat_0c2d93d0.green=176;dat_0c2d93d0.blue=224;
        func_0c0267ce();
    } else {
        ++dat_0c2d6f84->b4;
        dat_0c2d6f84->b6=zero;
        func_0c0342a2(12);func_0c033ef8(1);func_0c034312();
    }
}

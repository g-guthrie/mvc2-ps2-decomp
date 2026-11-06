#include "objects.h"

extern unsigned char dat_0c2d95e4[];
extern struct F3_0c0268b8 dat_0c2d95ec;
extern char dat_0c2f833e;
extern void *func_0c1fba00(unsigned char *p, unsigned char v, unsigned int n);

void func_0c0268d8(float x);

void func_0c0268b8(void)
{
    func_0c1fba00(dat_0c2d95e4, 0, 24);
    dat_0c2d95ec.f4 = dat_0c2d95ec.f8 = dat_0c2d95ec.f12 = 1.0f;
}

void func_0c0268d8(float x)
{
    dat_0c2d95ec.f4 = dat_0c2d95ec.f8 = dat_0c2d95ec.f12 = x;
}

void func_0c0268e8(void)
{
    float x;
    if (!dat_0c2f833e)
        x = 1.0f;
    else
        x = 0.5f;
    func_0c0268d8(x);
}

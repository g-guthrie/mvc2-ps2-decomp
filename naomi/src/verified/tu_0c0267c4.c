#include "objects.h"
extern struct FadeState dat_0c2d93d0;
extern struct F3_0c0268b8 dat_0c2d95ec;
extern void func_0c1fba00(void *, int, int);
extern void func_0c1ecd40(float);
extern void func_0c1ecce0(unsigned int);
extern void func_0c1ecd30(float *);
extern void func_0c1eccb0(void);
void func_0c0267c4(void)
{ func_0c1fba00(&dat_0c2d93d0, 0, 0x214); }
void func_0c0267ce(void)
{
    int i = 0;
    float one = 1.0f;
    unsigned char green, red, blue;
    for (; i<dat_0c2d93d0.count; i++)
        dat_0c2d93d0.weights[i] = -((float)i / (float)dat_0c2d93d0.count) + one;
    i *= sizeof(float);
    for (; (unsigned int)i < sizeof(dat_0c2d93d0.weights); i += sizeof(float))
        *(float *)((char *)dat_0c2d93d0.weights + i)=0.0f;
    func_0c1ecd40(dat_0c2d93d0.value);
    red = (int)(dat_0c2d95ec.f4 * dat_0c2d93d0.red);
    green = (int)(dat_0c2d95ec.f8 * dat_0c2d93d0.green);
    blue = (int)(dat_0c2d95ec.f12 * dat_0c2d93d0.blue);
    func_0c1ecce0((red << 16) | (green << 8) | blue);
}
void func_0c02687c(void)
{
    if (dat_0c2d93d0.enabled) func_0c1ecd30(dat_0c2d93d0.weights);
    else func_0c1eccb0();
}

#include "objects.h"

struct S_0c02f164 {
    int a, b;
    float f8, f12;
    unsigned char pad[12];
    float f28, f32;
};

#pragma section n02f164
void func_0c02f164(struct S_0c02f164 *p)
{
    p->f28 = p->f12 / (float)p->a;
    p->f32 = 0.0f;
}

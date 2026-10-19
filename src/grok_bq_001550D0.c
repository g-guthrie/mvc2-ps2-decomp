typedef unsigned char u8;
typedef float f32;

extern void func_001551A0(u8 *, int, int, f32);

void func_001550D0(u8 *a0, int kind, int a2, int a3)
{
    f32 f;
    int i;

    if (kind == 3)
        f = 40.0f;
    else if (kind == 2)
        f = 30.0f;
    else if (kind == 1)
        f = 20.0f;
    else if (kind == 0)
        f = 10.0f;
    for (i = 0; i < 10; i++)
        func_001551A0(a0, a2, a3, f);
}

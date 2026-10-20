typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001830D0(u8 *, f32 *, int);

void func_002B7360(u8 *p)
{
    f32 v[3] __attribute__((aligned(16)));

    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = p[0x269] == 6 ? 2 : 0;
    func_00175700(p);
    if ((s8)p[0x151] < 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        p[6]++;
        p[7] = 0;
        p[0x151] = 0;
        v[0] = -5.0f;
        v[1] = 147.8571319580078f;
        v[2] = 0;
        func_001830D0(p, v, 3);
        *(int *)(p + 0x5C) = 0;
        *(int *)(p + 0x60) = 0;
        *(int *)(p + 0x68) = 0;
        *(int *)(p + 0x6C) = 0;
        if (*(short *)(p + 0x140)) {
            *(f32 *)(p + 0x5C) = 3.3333332538604736f;
        } else {
            *(f32 *)(p + 0x5C) = -3.3333332538604736f;
        }
    }
}

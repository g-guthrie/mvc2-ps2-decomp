typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001830D0(u8 *, f32 *, int);
extern u8 *func_003778A0(u8 *, int);
extern int func_001757E0(u8 *, int, int);

void func_0026D960(u8 *p)
{
    f32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        *(unsigned int *)(v + 0) = 0xC1D55555;
        *(unsigned int *)(v + 1) = 0x432B6DB6;
        v[2] = 0.0f;
        func_001830D0(p, v, 1);
    }
    if ((s8)p[0x150] != 0) {
        {
            u8 *r;
            p[7]++;
            *(s16 *)(p + 0x1C) = 0x78;
            r = func_003778A0(p, 0);
            *(u8 **)(p + 0x14) = r;
            if (r == 0) {
                p[6]++;
                p[7] = 0;
                func_001757E0(p, 0x16, 4);
            }
        }
    }
}

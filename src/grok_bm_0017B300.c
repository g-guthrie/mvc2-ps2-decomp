typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern void func_0017B3B0(u8 *);
extern void func_00185490(u8 *);
extern void func_0017B410(u8 *);

void residual_0017B300(u8 *p)
{
    f32 v;

    p[6]++;
    p[0x1FF] = 8;
    if (*(s8 *)(p + 0x1E7) < 0) {
        func_0017B3B0(p);
        return;
    }
    p[6]++;
    p[0x201] = 1;
    p[0x1B1] = 0;
    func_00185490(p);
    if (*(s8 *)(p + 0x1E7) == 0)
        v = -15.0f;
    else
        v = 10.0f;
    if (p[0x1E6])
        v = -v;
    *(f32 *)(p + 0x5C) = v;
    func_0017B410(p);
}

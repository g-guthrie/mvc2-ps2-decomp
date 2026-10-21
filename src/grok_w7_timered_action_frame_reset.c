typedef unsigned char u8;
typedef signed short s16;

extern int func_00175700(u8 *);
extern void func_003B10B0(u8 *, int, int);

void func_00302DE0(u8 *p, u8 *context)
{
    s16 timer;

    func_00175700(p);
    timer = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = timer;
    if (timer == 0) {
        p[7]++;
        func_003B10B0(p, 0, 0);
        p[0x28E] = 16;
        p[0x28F] = 0;
    }
}

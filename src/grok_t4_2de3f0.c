typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00186A20(u8 *);
extern f32 D_004C1090[] __attribute__((section(".sdata")));

void func_002DE3F0(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[7]++;
        p[0x151] = 0;
        func_00186A20(p);
        *(f32 *)(p + 0x5C) = D_004C1090[p[0x1B7]];
        *(int *)(p + 0x68) = 0;
        *(int *)(p + 0x60) = 0x41CDB6DB;
        *(int *)(p + 0x6C) = 0xBFAB6DB6;
        if (p[0x1E6])
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
}

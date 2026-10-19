typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern void func_0036C0B0(u8 *, int, int);
extern void func_00175700(u8 *);

void residual_00371970(u8 *p)
{
    if ((*(u8 **)(p + 0x18))[5]) {
        p[5] = 2;
        *(s16 *)(p + 0x1C) = 10;
        return;
    }
    if (*(s8 *)(p + 0x151) == 1) {
        *(s8 *)(p + 0x151) = 0;
        func_0036C0B0(p, 0x17, 0);
    }
    if (*(s8 *)(p + 0x151) == 2) {
        *(s8 *)(p + 0x151) = 0;
        func_0036C0B0(p, 0x17, 2);
    }
    if (*(s8 *)(p + 0x151) == 3) {
        *(s8 *)(p + 0x151) = 0;
        func_0036C0B0(p, 0x17, 1);
    }
    if (*(s8 *)(p + 0x151) == 4) {
        *(s8 *)(p + 0x151) = 0;
        func_0036C0B0(p, 0x17, 0);
    }
    if (*(s8 *)(p + 0x151) == 5) {
        *(s8 *)(p + 0x151) = 0;
        func_0036C0B0(p, 0x17, 2);
    }
    if (*(s8 *)(p + 0x151) == 6) {
        *(s8 *)(p + 0x151) = 0;
        func_0036C0B0(p, 0x17, 1);
        p[5]++;
    }
    func_00175700(p);
}

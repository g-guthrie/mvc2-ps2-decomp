typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);
extern int func_00175700(u8 *);
extern void func_001830D0(u8 *, void *, int);

void func_002DF140(u8 *p)
{
    /* The native passes this two-word buffer at the 16-byte-aligned $sp+0x20. */
    u32 v[2] __attribute__((aligned(16)));

    if (p[7] == 0) {
        if (p[0x269] == 6) {
            p[0x404] = 255;
            p[0x405] = 16;
        }
        p[7]++;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        p[0x1B5] = 0x39;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
        func_00185490(p);
        func_00183D10(p);
        func_001757E0(p, 0x16, 9);
        return;
    }
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[0x404] = 0;
        p[0x405] = 0;
        p[6]++;
        p[7] = 0;
        p[0x151] = 0;
        v[1] = 0x434DB6DB;
        v[0] = 0;
        func_001830D0(p, v, 1);
    }
}

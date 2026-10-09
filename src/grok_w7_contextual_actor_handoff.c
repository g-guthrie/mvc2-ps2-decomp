typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern void func_00176160(u8 *, int, int, int);
extern void func_001E3710(u8 *, int);
extern int func_00175700(u8 *);
extern void func_00126400(void);
extern void func_001E3A40(u8 *);
extern void func_0030F650(u8 *);

void func_0030F450(u8 *p)
{
    u8 *target;
    int animation = 11;

    if ((*(u32 *)(D_004C2840 + 0x1C) & 1) != 0)
        animation = 12;
    func_00176160(p, 1, animation, 1);

    if (p[6] == 0) {
        p[6]++;
        *(f32 *)(p + 0x5C) = 0.0f;
        *(f32 *)(p + 0x60) = 0.0f;
        *(f32 *)(p + 0x68) = 0.0f;
        *(f32 *)(p + 0x6C) = 0.0f;
        func_001E3710(p, 79);
        func_001E3710(p, 9);
    }

    if ((s8)func_00175700(p) < 0) {
        func_0030F650(p);
        return;
    }

    if (*(s8 *)(p + 0x151) == 0)
        return;
    *(s8 *)(p + 0x151) = 0;

    target = *(u8 **)(p + 0x1DC);
    *(u8 **)(target + 0x1C8) = p;
    target[0x20A] = 2;
    target[0x20D] = 2;
    target[0x1E6] = p[0x1E6] ^ 1;
    target[0x1B5] = 32;
    func_00126400();
    func_001E3A40(target);
    func_001E3710(p, 58);
}

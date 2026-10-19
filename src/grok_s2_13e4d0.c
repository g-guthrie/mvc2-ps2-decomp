typedef unsigned char u8;
typedef signed short s16;

extern u8 *D_004CB5B4;
extern void func_0013E0F0(u8 *);
extern void func_00170E60(int, int, int, int, void (*)(void), u8 **);

extern void func_0013E570(void);

void func_0013E4D0(u8 *p)
{
    u8 *g;
    u8 *tmp[2];
    if (*(s16 *)(p + 0x1C) != 60) {
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
        func_0013E0F0(p);
    }
    *(s16 *)(p + 0x1E) += 20;
    if (*(s16 *)(p + 0x1E) >= 360)
        *(s16 *)(p + 0x1E) = 0;
    g = *(u8 **)(p + 0x84);
    tmp[0] = p;
    tmp[1] = 0;
    func_00170E60(
        *(int *)(*(u8 **)(D_004CB5B4 + 0x14) /* wait */),
        0,0,0, func_0013E570, tmp);
}

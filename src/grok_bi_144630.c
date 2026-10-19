typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern u8 *D_004C2808 __attribute__((section(".sdata")));
extern void func_003DAA40(void);
extern void func_001444D0(u8 *);
extern void func_001446F0(void);
extern void func_00170E60(s32, s32, s32, s32, void (*)(void), u8 **);

void func_00144630(u8 *p)
{
    u8 *obj;
    u8 *tab;
    u8 *tmp[2];

    s16 t;
    if (D_004C2840[2] != 5) {
        func_003DAA40();
        return;
    }
    t = *(s16 *)(p + 0x1C);
    if (t != 0x3C) {
        *(s16 *)(p + 0x1C) = t + 1;
        func_001444D0(p);
        return;
    }
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 0x14;
    if (*(s16 *)(p + 0x1E) >= 0x168)
        *(s16 *)(p + 0x1E) = 0;
    obj = *(u8 **)(p + 0x84);
    tab = *(u8 **)(obj + 0x1C);
    tmp[0] = p;
    tmp[1] = 0;
    func_00170E60(
        *(s32 *)(D_004C2808 + 0x14),
        *(s32 *)(tab + 0x14),
        *(s32 *)(obj + 0x14),
        *(s32 *)(tab + *(s16 *)(p + 0xCC) * 4),
        func_001446F0,
        tmp);
}

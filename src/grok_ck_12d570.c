typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;

extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern s32 func_0012ABC0(s32, s32);
extern s32 func_003299D0(void);
extern s32 func_0012ABA0(s32, s32, s32);
extern s32 func_001315F0(void);
extern void func_003298B0(u32, s32, s32);
extern void func_00129060(s32, void *);
extern void func_0012D670(void);
extern void func_0012D6B0(void);
extern s32 func_001316D0(void);

void func_0012D570(void)
{
    s32 id = func_0012ABC0(3, 0) & 0xFFFF;
    if (func_003299D0())
        return;
    D_004C2840[4] = (u8)func_0012ABA0(id, *(s8 *)(D_004C2840 + 4), 3);
    if (func_001315F0()) {
        func_003298B0(0xFF000000, 10, 1);
        if (*(s8 *)(D_004C2840 + 4) == 3) {
            *(s8 *)(D_004C2840 + 3) = 4;
            func_00129060(8, func_0012D670);
        } else {
            *(s8 *)(D_004C2840 + 3) = 3;
            func_00129060(8, func_0012D6B0);
        }
        return;
    }
    if (func_001316D0()) {
        *(s8 *)(D_004C2840 + 3) = 4;
        func_003298B0(0xFF000000, 10, 1);
        func_00129060(8, func_0012D670);
    }
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_003DAA40(u8 *a0, s32 a1, u8 *a2);
extern u16 D_004C2A78;
extern u8 D_0062BFD4[];

void func_003A4230(u8 *a0, s32 a1, u8 *a2) {
    s32 b = *(s8 *)(a0 + 0x20);
    *(s8 *)(a2 + 2) &= ~(1 << b);
    func_003DAA40(a0, b, a2);
}

s32 func_003DF7B0(void) {
    D_004C2A78 = *(volatile u16 *)0x10000000;
    *(s32 *)D_0062BFD4 = 2;
    return 1;
}

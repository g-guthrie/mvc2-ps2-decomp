/* func_003ECD00: MW 3.0 (./try30.sh) "-O3,p -sdatathreshold 8". Busy-waits are nop-padded asm delays (as src/rt21_a.c). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;

extern s32 D_0062BC40[];
extern s32 D_0062BC38[];
extern s32 D_0062BC00[];
extern s32 D_0062BC44[];
extern s32 D_0062BF80[];
extern s32 D_0062BF84[];
extern s32 D_0062BF88[];
extern s32 D_004C2AE4;
extern s32 D_004C2AE0;
extern s32 D_004C2ADC;
extern s32 D_0062C000[];
extern s32 D_0062C004[];
extern s32 D_0062C008[];
extern s32 D_0062C00C[];
extern s32 D_0062C010[];
extern s32 D_0062C014[];
extern s32 D_0062C018[];
extern s32 D_0062C01C[];
extern u64 D_0062BFF0[];
extern u64 D_0062BFF8[];
extern s32 D_0062BFD8[];
extern s32 D_0062BFC8[];
extern s32 D_0062BFC4[];
extern u8 D_00478B60[];
extern u8 D_00478B70[];
extern u64 D_00478B80[];
extern u64 D_00478B90[];
extern u64 D_00478BA0[];
extern u64 D_00478BB0[];
extern u64 D_00478C30[];
extern u64 D_00478C60[];
extern u64 D_00478C70[];
extern u64 D_00478C80[];

s32 func_003ECD00(void)
{
    extern void func_00419FC0(s32);
    extern void func_003DC950(void);
    extern void func_003DBBF0(void *, s32);
    extern void func_003DC720(void);
    extern void func_003DD0D0(void);
    u32 v;
    volatile u64 *c0;
    volatile u64 *c1;
    volatile u64 *c2;
    s32 w, h, x, y;

    func_00419FC0(1);
    func_003DC950();
    if (D_0062BC40[0] == 0) {
        c0 = (volatile u64 *)0x12001000;
        D_0062BC38[0] = (s32)((*c0 >> 13) & 1);
    } else {
        while ((*(c1 = (volatile u64 *)0x12001000) & 8) == 0) {
            __asm__ volatile("nop;nop;nop;nop;nop;nop");
        }
        *c1 = 8;
    }
    if (D_0062BC00[0] == 1) {
        if (D_0062BC38[0] == 0) {
            func_003DBBF0(D_00478B60, 1);
        } else {
            func_003DBBF0(D_00478B70, 1);
        }
    }
    D_0062BC44[0] = 1;
    c2 = (volatile u64 *)0x12001000;
    while ((*c2 & 8) == 0) {
        __asm__ volatile("nop;nop;nop;nop;nop;nop");
    }
    *(volatile u32 *)0x10000010 = 0x83;
    *(volatile u32 *)0x10000000 = 0;
    D_0062BC40[0] = 0;
    *c2 = 8;
    if ((v = D_0062BF80[0]) != 0) {
        D_00478C30[0] = ((u64)(s64)(D_004C2AE4 - 1) << 16) | ((u64)(s64)(D_004C2AE0 - 1) << 48);
        D_00478C60[0] = ((u64)(v & 0xFF) << 16) | ((u64)((v >> 16) & 0xFF) | ((u64)((v >> 8) & 0xFF) << 8)) | ((u64)1 << 32);
        D_00478C70[0] = (u64)(s64)(D_0062BF84[0] << 4) | ((u64)(s64)(D_0062BF88[0] << 4) << 16);
        D_00478C80[0] = (u64)(s64)((D_0062BF84[0] + D_004C2AE4) << 4) | ((u64)(s64)((D_0062BF88[0] + D_004C2AE0) << 4) << 16);
        func_003DBBF0(D_00478C30, 6);
    }
    D_00478B80[0] = (u64)(s64)D_0062C000[0] | ((u64)(s64)D_0062C008[0] << 16) | ((u64)(s64)D_0062C004[0] << 32) | ((u64)(s64)D_0062C00C[0] << 48);
    D_00478B90[0] = (u64)(s64)D_0062C010[0] | ((u64)(s64)D_0062C018[0] << 16) | ((u64)(s64)D_0062C014[0] << 32) | ((u64)(s64)D_0062C01C[0] << 48);
    D_00478BA0[0] = D_0062BFF0[0];
    D_00478BB0[0] = D_0062BFF8[0];
    func_003DBBF0(D_00478B80, 0xB);
    D_004C2ADC++;
    D_0062BFD8[0] ^= 1;
    func_003DC720();
    func_003DD0D0();
    D_0062BFC8[0] = 0;
    D_0062BFC4[0] = -1;
    return 1;
}

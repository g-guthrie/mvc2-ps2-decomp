/* func_00105480: Sony EE GCC 2.9, ./trysony29.sh src/s6a_k.c 0 O2 (exact). f4/f8/fC are volatile (shared with the DECI2 handler), which fixes store order and temp naming. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*DeciHandler)(int, int, void *);
typedef struct { int f0; volatile int f4; volatile int f8; volatile int fC; u8 *f10, *f14; void *ring; } DebugState;
typedef struct { u16 f0, f2, f4; u8 f6, f7; int f8; } Hdr;
extern DebugState D_004C36D0;
extern u8 D_004C3700[];
extern u8 D_004C3840[];
extern void func_00104060(int);
extern int func_00104E40(unsigned short, void *, DeciHandler);
extern void func_001050C8(int, int, void *);
extern void *func_00105020(int);
int func_00105480(void)
{
    Hdr *h;
    func_00104060(0);
    D_004C36D0.f0 = func_00104E40(0x210, &D_004C36D0, func_001050C8);
    if (*(volatile int *)&D_004C36D0.f0 < 0) return 0;
    D_004C36D0.fC = 0;
    D_004C36D0.f4 = 0;
    D_004C36D0.f14 = (u8 *)((u32)D_004C3840 | 0x20000000);
    D_004C36D0.f10 = (u8 *)((u32)D_004C3700 | 0x20000000);
    D_004C36D0.f8 = 0;
    h = (Hdr *)D_004C36D0.f10;
    h->f4 = 0x210;
    h->f6 = 0x45;
    h->f7 = 0x48;
    h->f2 = 0;
    h->f8 = 0;
    D_004C36D0.ring = func_00105020(0x100);
    return 1;
}

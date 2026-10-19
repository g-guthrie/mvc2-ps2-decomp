typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef void (*StateCallback)(u8 *);

extern s32 func_00175670(u8 *);
extern s32 func_00175700(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
extern void func_0018C4B0(u8 *, s32);
extern void func_00183D10(u8 *);
extern void func_00199DC0(u8 *);
extern void func_0019B740(u8 *);
extern void func_001994B0(u8 *);
extern void func_001E3210(u8 *, s32);
extern void func_001FED30(u8 *);
extern StateCallback D_004BF860[] __attribute__((section(".sdata")));

void func_00198570(u8 *p)
{
    ((s8 *)p)[0x31] = -4;
    if ((s8)func_00175670(p) < 0) {
        p[0x13C] = 0;
        p[4]++;
    }
}

void func_0019B280(u8 *p)
{
    if ((s8)func_00175670(p) < 0)
        func_0019B740(p);
}

void func_00199CF0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_00199DC0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_001994B0(p);
        func_001E3210(p, 32);
    }
}

void func_001FF970(u8 *p)
{
    p[6]++;
    func_0018C4B0(p, 5);
    func_001FED30(p);
    func_00183D10(p);
    func_001757E0(p, 21, 15);
    p[0x2D4] = 1;
}

void func_001B26C0(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    D_004BF860[p[5]](p);
    if (*(s8 *)(q + 0x1B3) != 0) {
        p[4]++;
        p[0x13C] = 0;
    }
}

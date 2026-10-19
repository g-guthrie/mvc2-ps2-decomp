typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;

extern void func_00104060(s32);
extern s32 func_00102580(s32);
extern void func_001028B0(s32, u32);

void func_003DBBF0(u64 *src, s32 qwc)
{
    u64 *t = (u64 *)0x70000008;
    *(u64 *)0x70000000 = (u32)(qwc + 0x70000001);
    *(u64 *)0x70000008 = 0;
    t = (u64 *)0x70000010;
    *t++ = (u64)qwc | 0x10000000 | 0x8000;
    *t++ = 0xE;
    do {
        *t++ = *src++;
        *t++ = *src++;
        qwc--;
    } while (qwc);
    func_00104060(0);
    while (*(volatile u32 *)0x1000A000 & 0x100)
        ;
    func_001028B0(func_00102580(2), 0x70000008 | 0x80000000);
    while (*(volatile u32 *)0x1000A000 & 0x100)
        ;
}

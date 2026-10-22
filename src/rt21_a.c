typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

void func_003DBBF0(u64 *src, u32 n)
{
    extern void func_00104060(s32);
    extern u32 func_00102580(s32);
    extern void func_001028B0(u32, u32);
    u64 *d;
    u64 *q;
    u32 i;
    u32 cnt;
    volatile u32 *c;
    volatile u32 *c2;

    d = (u64 *)0x70000000;
    cnt = n;
    d[0] = (u32)(n + 0x70000001);
    d[1] = 0;
    q = d + 1;
    q++;
    *q = (u64)cnt | 0x8000 | ((u64)0x10000000 << 32);
    q++;
    *q = 0xE;
    q++;
    do {
        q[0] = src[0];
        src++;
        q++;
        q[0] = src[0];
        n--;
        src++;
        q++;
    } while (n != 0);
    func_00104060(0);
    c = (volatile u32 *)0x1000A000;
    while (*c & 0x100) {
        __asm__ volatile("nop;nop;nop;nop;nop;nop");
    }
    func_001028B0(func_00102580(2), (u32)d | 0x80000000);
    c2 = (volatile u32 *)0x1000A000;
    while (*c2 & 0x100) {
        __asm__ volatile("nop;nop;nop;nop;nop;nop");
    }
}

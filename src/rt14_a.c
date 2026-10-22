typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_0062BBA0[];

s32 func_003DECC0(u32 *p) {
    extern u32 *func_003DD160(s32, s32);
    extern void func_003DC2F0(u32, u8 *);
    u32 n;
    u32 *d;
    u32 i;
    n = (p[0] & 0x7FFF) + 1;
    d = func_003DD160(n << 4, 16);
    p[0] = p[0] | 0x80000000;
    p[2] = 0x13000000;
    p[3] = (n - 1) | 0x51000000;
    for (i = 0; i < n * 4; i++) {
        d[i] = *p++;
    }
    func_003DC2F0(((u32)d & 0xFFFFFFF) | 0x30000000, D_0062BBA0);
    return 1;
}

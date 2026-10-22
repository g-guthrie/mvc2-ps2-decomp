typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed long long s64;
typedef unsigned long long u64;

extern s32 D_004C2AE4;
extern s32 D_004C2AE0;
extern s32 D_0062C000[];
extern s32 D_0062C004[];
extern s32 D_0062C008[];
extern s32 D_0062C00C[];
extern s32 D_0062C010[];
extern s32 D_0062C014[];
extern s32 D_0062C018[];
extern s32 D_0062C01C[];
extern u8 D_0062BBA0[];

s32 func_003E00D0(s32 x, s32 y, s32 w, s32 h, s32 mode)
{
    extern u32 func_003DD160();
    extern void func_003DC2F0();
    u64 *q;
    u32 n;
    s32 r;
    s32 b;
    u64 pk;

    if (x < 0) {
        x = 0;
    }
    if (D_004C2AE4 < x + w) {
        w = D_004C2AE4 - x;
    }
    r = x + w - 1;
    if (y < 0) {
        y = 0;
    }
    if (D_004C2AE0 < y + h) {
        h = D_004C2AE0 - y;
    }
    b = y + h - 1;
    if (mode != 2) {
        q = (u64 *)func_003DD160(0x30, 0x10);
        n = 2;
    } else {
        q = (u64 *)func_003DD160(0x40, 0x10);
        n = 3;
    }
    q[0] = (u32)((n + 0x70000000) | 0x80000000);
    *(u32 *)((u8 *)q + 8) = 0x13000000;
    *(u32 *)((u8 *)q + 0xC) = n | 0x50000000;
    q[2] = (u32)(n - 1) | ((u64)0x10000000 << 32) | 0x8000;
    q[3] = 0xE;
    switch (mode) {
    case 0:
        D_0062C000[0] = x;
        D_0062C004[0] = y;
        D_0062C008[0] = r;
        D_0062C00C[0] = b;
        pk = (u64)(s64)x | ((u64)(s64)r << 16) | ((u64)(s64)y << 32) | ((u64)(s64)b << 48);
        q[4] = pk;
        q[5] = 0x40;
        break;
    case 1:
        D_0062C010[0] = x;
        D_0062C014[0] = y;
        D_0062C018[0] = r;
        D_0062C01C[0] = b;
        pk = (u64)(s64)x | ((u64)(s64)r << 16) | ((u64)(s64)y << 32) | ((u64)(s64)b << 48);
        q[4] = pk;
        q[5] = 0x41;
        break;
    case 2:
        D_0062C000[0] = x;
        D_0062C010[0] = x;
        D_0062C004[0] = y;
        D_0062C008[0] = r;
        D_0062C014[0] = y;
        D_0062C018[0] = r;
        D_0062C00C[0] = b;
        D_0062C01C[0] = b;
        pk = (u64)(s64)x | ((u64)(s64)r << 16) | ((u64)(s64)y << 32) | ((u64)(s64)b << 48);
        q[4] = pk;
        q[5] = 0x40;
        q[6] = pk;
        q[7] = 0x41;
        break;
    }
    func_003DC2F0((u32)q & 0xFFFFFFF, D_0062BBA0);
    return 1;
}

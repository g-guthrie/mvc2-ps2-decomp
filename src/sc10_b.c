typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

extern u64 D_004779D0[];
extern u64 D_004779D8[];
extern u64 D_004779E0[];
extern u64 D_004779E8[];
extern u64 D_0062BFF0[];
extern u64 D_0062BFF8[];
extern u8 D_0062BBA0[];

s32 func_003E0390(u32 sel, s32 mode) {
    extern u32 func_003DD160();
    extern void func_003DC2F0();
    u64 *q;
    u64 s0;
    u32 n;
    switch (sel) {
    case 1:
        s0 = D_004779D8[0];
        break;
    case 3:
        s0 = D_004779D0[0];
        break;
    case 0:
        s0 = D_004779E8[0];
        break;
    case 7:
        s0 = D_004779E0[0];
        break;
    case 2:
    case 4:
    case 5:
    case 6:
        return 0;
    }
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
        D_0062BFF0[0] = s0;
        q[4] = s0;
        q[5] = 0x47;
        break;
    case 1:
        D_0062BFF8[0] = s0;
        q[4] = s0;
        q[5] = 0x48;
        break;
    case 2:
        D_0062BFF0[0] = s0;
        D_0062BFF8[0] = s0;
        q[4] = s0;
        q[5] = 0x47;
        q[6] = s0;
        q[7] = 0x48;
        break;
    }
    func_003DC2F0((u32)q & 0xFFFFFFF, D_0062BBA0);
    return 1;
}

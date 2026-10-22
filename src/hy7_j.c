typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

extern u16 D_0062BCC0[];
extern u8 D_0062BCC3[];
extern u64 D_005BF2D0[];
extern u64 D_0062BFF0[];
extern u64 D_0062BFF8[];
extern u8 D_0062BBA0[];

s32 func_003E0530(s32 flag, s32 mode) {
    extern u32 func_003DD160();
    extern void func_003DC2F0();
    u64 *q;
    u64 s0;
    u32 n;
    if (flag != 0) {
        D_005BF2D0[0] = ((u64)D_0062BCC0[0] & 0x1FF) | (((u64)D_0062BCC3[0] & 0xF) << 24);
    } else {
        D_005BF2D0[0] = ((u64)D_0062BCC0[0] & 0x1FF) | (((u64)D_0062BCC3[0] & 0xF) << 24) | ((u64)1 << 32);
    }
    s0 = D_005BF2D0[0];
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
        q[4] = s0;
        q[5] = 0x4E;
        break;
    case 1:
        q[4] = s0;
        q[5] = 0x4F;
        break;
    case 2:
        D_0062BFF0[0] = s0;
        D_0062BFF8[0] = s0;
        q[4] = s0;
        q[5] = 0x4E;
        q[6] = s0;
        q[7] = 0x4F;
        break;
    }
    func_003DC2F0((u32)q & 0xFFFFFFF, D_0062BBA0);
    return 1;
}

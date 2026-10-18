typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
extern u64 *func_003DD160(s32, s32);
extern void func_003DC2F0(u32, void *);
extern char D_0062BBA0[];

s32 func_003E0A90(u32 c) {
    u64 *p = func_003DD160(0x30, 0x10);
    p[0] = 0xF0000002;
    ((u32 *)p)[2] = 0x13000000;
    ((u32 *)p)[3] = 0x51000002;
    p[2] = 0x1000000000008001ULL;
    p[3] = 0xE;
    p[4] = (u64)((c >> 16) & 0xFF) | ((u64)((c >> 8) & 0xFF) << 8) | ((u64)(c & 0xFF) << 16);
    p[5] = 0x3D;
    func_003DC2F0((u32)p & 0xFFFFFFF, D_0062BBA0);
    return 1;
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern s32 D_00633694;
extern s32 D_0063369C;
extern s32 D_006336A0;
extern s32 D_006336A4;
extern s32 D_006336B0;
extern s32 D_00633690;
extern s32 func_00110138();
s32 func_00419840(s32 a, s32 b, s32 c, s32 d) {
    s32 i;
    if (D_00633694 != 0) return -1;
    if (a >= 2) return -1;
    if (b > 0) return -1;
    i = 0;
    do {
        if (func_00110138(a, b, c, d) == 0) {
            D_0063369C = a;
            D_00633694 = 2;
            D_006336A0 = b;
            D_006336A4 = c;
            D_006336B0 = d;
            if (D_00633690 == 0) {
                D_00633690 = 5;
            }
            return 0;
        }
        i++;
    } while (i < 5);
    return -1;
}

typedef unsigned long long u64;
extern u8 *func_003DD160();
extern void func_003DC2F0();
extern u8 D_0062BBA0[];
s32 func_003E0B50(u32 flags, s32 b) {
    u64 *p = (u64 *)func_003DD160(0x30, 0x10);
    p[0] = 0xF0000002ULL;
    *(u32 *)((u8 *)p + 8) = 0x13000000;
    *(u32 *)((u8 *)p + 0xC) = 0x50000002;
    p[2] = 0x1000000000008001ULL;
    p[3] = 0xE;
    if ((flags & 0x10000) == 0x10000) {
        p[4] = 0;
    } else {
        p[4] = 0x60;
    }
    if (b == 0) {
        p[5] = 0x14;
    } else {
        p[5] = 0x15;
    }
    func_003DC2F0((u32)p & 0xFFFFFFF, D_0062BBA0);
    return 1;
}

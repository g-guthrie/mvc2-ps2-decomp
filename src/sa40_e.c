typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F20B0[];

s32 func_00167F50(u8 *p, s32 a1) {
    extern s32 func_0016B250(u8 *, s32);
    extern void func_0016B0C0(u8 *, s32, s32);
    u8 *e;
    u8 *q;
    s32 best;
    s32 cnt;
    s32 i;
    s16 v;
    if (func_0016B250(p, 3) == 0) {
        return 0;
    }
    func_0016B0C0(p, a1, 0);
    q = *(u8 **)(p + 0x220);
    e = D_004F20B0 + (1 >> (p[2] & 1)) * 0x5B8;
    best = 0x91;
    cnt = 0;
    i = 0;
    do {
        if (e[1] != q[1]) {
            if ((v = *(s16 *)(e + 0x434)) != 0) {
                if (v <= best) {
                    best = v;
                    cnt++;
                }
            }
        }
        i++;
        e += 0x5B8;
    } while (i < 3);
    p[0x471] = 1;
    p[0x45C] = 0x7C;
    p[0x4BF] = 0;
    p[0x4BE] = cnt;
    *(u16 *)(p + 0x4C0) = 0;
    return 0;
}

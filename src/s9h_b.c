/* MW 3.0.3 -O3 -sdatathreshold 0 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_004F1CB0[];
extern s16 D_004D1802[];

void func_00260B20(u8 *p) {
    extern u8 func_00174170();
    extern void func_0036BFF0(u8 *, s32, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    u16 h;
    s16 c;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (D_004F1CB0[0] != 0) return;
    if (*(s8 *)(p + 0x539) != 0 && *(s16 *)(p + 0x1C) != 0x1E) {
        {
            u8 r = func_00174170();
            r %= 2;
            if (r) {
                t = p[6]; p[6] = t + 1;
                *(s16 *)(p + 0x1C) = 0x10;
                func_0036BFF0(p, 0xC, 0x13, 0xC);
                if (D_004D1802[0] >= 0x18) p[7] = 1;
                return;
            }
        }
        t = p[6]; p[6] = t + 1;
        p[7] ^= 1;
        *(s16 *)(p + 0x1C) = 0x10;
        func_0036BFF0(p, 0xD, 0x13, 0xD);
        if (D_004D1802[0] >= 0x18) p[7] = 1;
        return;
    }
    h = *(u16 *)(p + 0x35C);
    if (h & 0x200) {
        t = p[6]; p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0x10;
        func_0036BFF0(p, 0xC, 0x13, 0xC);
        return;
    }
    {
    if (h & 0x40) {
        t = p[6]; p[6] = t + 1;
        p[7] ^= 1;
        *(s16 *)(p + 0x1C) = 0x10;
        func_0036BFF0(p, 0xD, 0x13, 0xD);
        return;
    }
    c = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = c - 1;
    if (c != 0) return;
    p[6] = 0xC;
    *(s16 *)(p + 0x1C) = 0xA;
    func_001757E0(p, 0x16, 0xD);
    }
}

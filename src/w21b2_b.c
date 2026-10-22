typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_002E7A10(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_001830D0(u8 *, u32 *, s32);
    extern void func_003A43F0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 v[4];
    u32 t;
    s32 r;
    if (p[7] == 0) {
        p[0x40C] = 2;
        p[0x33C] = 5;
        p[0x405] = (p[0x269] == 6) ? 2 : 0;
        func_00175700(p);
        if ((*(s8 *)(p + 0x151) & 1) != 0) {
            p[0x404] = 0;
            p[0x405] = 0;
            t = p[7];
            p[7] = t + 1;
            *(s8 *)((s32)p + 0x151) ^= 1;
            v[0] = 0x42855555;
            v[1] = 0xC304DB6D;
            func_001830D0(p, v, 1);
        }
    } else {
        p[0x40C] = 2;
        p[0x33C] = 5;
        if ((r = func_00175700(p)) >= 0) {
            if ((*(s8 *)(p + 0x151) & 2) != 0) {
                { s32 q = *(s8 *)(p + 0x151); p[0x151] = q ^ 2; }
                func_003A43F0(p);
            }
        } else {
            s16 h = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = h;
            if (h == 0) {
                p[0x40D] = 0;
                p[0x40C] = 0;
                p[6]++;
                p[7] = 0;
                func_001757E0(p, 22, 9);
            }
        }
    }
}

extern s32 D_00445A00[];

s32 func_001677E0(u8 *p, u8 *q)
{
    extern s32 func_0016B250(u8 *, s32);
    extern s32 func_0016B360(u8 *, u8 *);
    extern void func_0016B0C0(u8 *, u8 *, s32);
    extern void func_00168AE0();
    u16 x;
    s32 v;
    if (func_0016B250(p, 3) == 0) return 0;
    if (func_0016B360(p, q) == 0) return 0;
    func_0016B0C0(p, q, 0);
    p[0x451]++;
    p[0x452] = 0;
    p[0x453] = 0;
    p[0x471] = 1;
    func_0016B0C0(p, q, 1);
    p[0x45C] = *(s8 *)(p + 0x4C8);
    func_0016B0C0(p, q, 1);
    *(s32 *)(p + 0x460) = *(s32 *)(p + 0x4C8);
    func_0016B0C0(p, q, 1);
    p[0x4BF] = *(s8 *)(p + 0x4C8);
    func_0016B0C0(p, q, 1);
    p[0x4BE] = *(s8 *)(p + 0x4C8);
    func_0016B0C0(p, q, 1);
    v = *(s32 *)(p + 0x4C8) << 8;
    x = v;
    if ((x & 0xC00) != 0) {
        x = x ^ ((p[0x1E6] * 3) << 10);
    }
    *(s16 *)(p + 0x4C0) = v;
    *(s32 *)(p + 0x464) = x;
    *(s16 *)(p + 0x4F0) = x;
    switch (p[1]) {
    case 0x30:
        *(s32 *)(p + 0x4AC) = D_00445A00[*(s32 *)(p + 0x460)];
        break;
    default:
        *(s32 *)(p + 0x4AC) = (s32)func_00168AE0;
        break;
    }
    return 0;
}

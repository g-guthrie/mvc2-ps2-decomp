typedef struct SA37_J0 SA37_J0;
typedef struct SA37_R SA37_R;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;


extern s32 D_00445A00[];

s32 func_001677E0(u8 *p, u8 *q)
{
    extern s32 func_0016B250(u8 *, s32);
    extern s32 func_0016B360(u8 *, u8 *);
    extern void func_0016B0C0(SA37_J0 *, SA37_R *, s32);
    extern void func_00168AE0();
    u16 x;
    s32 v;
    if (func_0016B250(p, 3) == 0) return 0;
    if (func_0016B360(p, q) == 0) return 0;
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)q, 0);
    p[0x451]++;
    p[0x452] = 0;
    p[0x453] = 0;
    p[0x471] = 1;
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)q, 1);
    p[0x45C] = *(s8 *)(p + 0x4C8);
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)q, 1);
    *(s32 *)(p + 0x460) = *(s32 *)(p + 0x4C8);
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)q, 1);
    p[0x4BF] = *(s8 *)(p + 0x4C8);
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)q, 1);
    p[0x4BE] = *(s8 *)(p + 0x4C8);
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)q, 1);
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

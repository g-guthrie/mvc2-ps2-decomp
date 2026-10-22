typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C23C4, D_004C22C4, D_004C23FC;

s32 func_00402830(u8 *p)
{
    extern s32 func_003FF300(s32);
    extern void func_00402498(void);
    extern void func_00401B78(u8 *, s32 *, s32 *);
    s32 r;
    s32 sv;
    s32 v[2];

    if (*(s8 *)(p + 0x72) == 0) return 0;
    r = func_003FF300(*(s32 *)(p + 0xC));
    func_00402498();
    sv = D_004C23C4;
    D_004C23C4 = 0;
    func_00401B78(p, &v[0], &v[1]);
    D_004C23C4 = sv;
    {
        s32 g;
        f32 b = v[1];
        f32 a = v[0];
        f32 c;
        g = D_004C22C4;
        c = D_004C23FC;
        *(s32 *)(p + 0xA0) = g;
        *(s32 *)(p + 0x9C) = (s32)(a / b * c);
    }
    return r;
}

typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern s32 func_003FF300(s32 handle);
extern void func_00402498(void);
extern void func_00401B78(u8 *p, s32 *a, s32 *b);
extern s32 D_004C2274;
extern s32 D_004C2394;
extern s32 D_004C23CC;

s32 func_00402830(u8 *p)
{
    s32 r;
    s32 a, b;
    s32 saved;
    if ((s8)p[0x72] == 0)
        return 0;
    r = func_003FF300(*(s32 *)(p + 12));
    func_00402498();
    saved = D_004C2394;
    D_004C2394 = 0;
    func_00401B78(p, &a, &b);
    D_004C2394 = saved;
    *(s32 *)(p + 0xA0) = D_004C2274;
    *(s32 *)(p + 0x9C) = (s32)((float)a / (float)b * (float)D_004C23CC);
    return r;
}

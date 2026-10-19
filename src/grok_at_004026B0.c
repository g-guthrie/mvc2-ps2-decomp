typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern void func_003FB128(char *s);
extern void func_003F9630(void);
extern void func_003F9660(void);
extern void func_003FF160(s32 handle, s32 flag);
extern void func_00401B78(u8 *p, s32 *a, s32 *b);
extern char D_004BC560[];
extern s32 D_004C2274;
extern volatile s32 D_004C2394;
extern s32 D_004C23CC;

void func_004026B0(u8 *p, s32 mode)
{
    s8 st;
    s32 a, b, saved;
    if (p == 0) {
        func_003FB128(D_004BC560);
        return;
    }
    if (p[0x72] == (u8)mode)
        return;
    st = (s8)p[1];
    func_003F9630();
    p[0x72] = (u8)mode;
    if ((unsigned)(st - 3) < 2U) {
        if (mode == 1)
            func_003FF160(*(s32 *)(p + 12), 0);
        else
            func_003FF160(*(s32 *)(p + 12), 1);
        *(s32 *)(p + 0xA0) = D_004C2274;
        saved = D_004C2394;
        D_004C2394 = 0;
        func_00401B78(p, &a, &b);
        D_004C2394 = saved;
        *(s32 *)(p + 0x9C) = (s32)(((float)a / (float)b) * (float)D_004C23CC);
    }
    func_003F9660();
}

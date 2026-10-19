typedef unsigned char u8;
typedef signed int s32;

extern s32 func_00423990(void *, s32);
extern s32 func_001E5710(u8 *, s32);
extern void func_00418B10(void);
extern void func_0011D8F8(void *, s32, s32);
extern s32 func_001E5700(void);
extern u8 D_004CC150[];

s32 func_001E5870(u8 *p, s32 idx)
{
    s32 tok;
    s32 r;
    s32 n;
    tok = func_00423990((void *)0x8000000C, 1);
    r = func_001E5710(p, idx);
    n = 0xF0;
    if (r < 0)
        return r;
    goto check;
again:
    func_00418B10();
    n--;
    if (n < 0) {
        func_0011D8F8(&D_004CC150[idx << 9], 0, 0x200);
        return -1;
    }
check:
    if (func_00423990((void *)0x8000000C, 1) == tok)
        goto again;
    goto wait;
spin:
    func_00418B10();
wait:
    if (func_001E5700() > 0)
        goto spin;
    return 0;
}

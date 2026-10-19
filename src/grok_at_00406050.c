#pragma padloop on
typedef signed char s8;
typedef signed int s32;

extern void func_004061C0(s8 *s);
extern s32 func_00406128(s8 *s);
extern s32 func_0011FFA0(s8 *s);
extern void func_0011D740(s8 *dst, s8 *src, s32 n);

extern struct {
    s32 val;
    s8 name[12];
} D_0062FB48[32];

s32 func_00406050(s8 *s, s32 (*cb)(void))
{
    s32 r;
    s32 i;
    s8 *p;
    func_004061C0(s);
    r = cb();
    if (func_00406128(s) != 0)
        return r;
    i = 0;
    p = D_0062FB48[0].name;
    if (*p != 0) {
        do {
            i++;
            if (i >= 32)
                break;
            p += 16;
        } while (*p != 0);
    }
    if (i == 32)
        return 0;
    D_0062FB48[i].val = r;
    func_0011D740(D_0062FB48[i].name, s, func_0011FFA0(s) + 1);
    return r;
}

typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern s32 func_001688C0(u8 *, u8 *);
extern s32 func_001689F0(u8 *, u8 *);
extern s32 func_00163F40(u8 *, u8 *);

s32 func_00169AE0(u8 *p, s32 a1)
{
    u8 *slot;
    s8 a2;

    slot = p + 0x474;
    slot += a1 << 3;
    a2 = *(s8 *)(p + 0x4AA);
    if (a2 > 0) {
        if (p[0x1E4] != 2 && p[0x20D] != 2) {
            p[0x4AA] = 0;
            p[0x4A9] = 0;
            return func_001688C0(p, slot);
        }
    }
    if (a2 < 0) {
        if (p[0x1E4] != 0xD) {
            if (p[0x20D] != 2 || p[0x210] == 0) {
                p[0x4AA] = 0;
                p[0x4A9] = 0;
                return func_001688C0(p, slot);
            }
        }
    }
    if (p[0x4AB] != 0 && p[0x215] == 0) {
        p[0x4AB] = 0;
        p[0x4A9] = 0;
        return func_001689F0(p, slot);
    }
    return func_00163F40(p, slot);
}

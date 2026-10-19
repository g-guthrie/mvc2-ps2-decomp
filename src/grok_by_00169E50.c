#pragma padloop on
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern s32 func_00174170(void);
extern void func_00169C90(u8 *);

void func_00169E50(u8 *p, s32 a1, s32 a2)
{
    u8 *s0;
    u8 *s1;
    s32 v0;
    u8 *slot;
    u8 b;
    s32 r;

    s0 = *(u8 **)(p + 0x198 + a2 * 4);
    s1 = s0;
    if (a2 == 2) {
        s0 = s0 + (a1 - 2) * 12;
        v0 = *(s32 *)(s0 + 4);
    } else {
        v0 = *(s32 *)(s0 + *(s32 *)(s0 + 4) + p[0x470] * 4);
    }
    r = func_00174170() & 0x1F;
    slot = p + 0x474 + (a2 << 3);
    b = (s1 + v0)[r];
    *(s32 *)slot = (s32)(s1 + *(s32 *)(s1 + *(s32 *)(s0 + 8) + b * 4));
    *(s16 *)(slot + 4) = 0;
    slot[6] = b;
    slot[7] = 0;
    func_00169C90(p);
}

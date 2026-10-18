typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_0016AF10(u8 *, u8 *, s16 *, u8 *);
extern s32 func_0016AFE0(u8 *, u8 *, s16 *, u8 *);

s32 func_0016AC30(u8 *p, s32 *m) {
    s16 v[4];
    u8 *s0, *s1;
    u16 *s2;
    s32 i, t;
    v[0] = *(s16 *)m;
    v[1] = *(s16 *)((u8 *)m + 4);
    if (*(s16 *)(p + 0x140) & 1) t = m[2]; else t = -m[2];
    v[2] = t;
    if (*(s16 *)(p + 0x140) & 2) t = -m[3]; else t = m[3];
    v[3] = t;
    i = 0;
    s0 = *(u8 **)(p + 0x220);
    s2 = *(u16 **)(s0 + 0x1D4);
    s1 = *(u8 **)(s0 + 0x180);
    s2 += 2;
    do {
        u32 e = *s2 & 0xFFF;
        if (e != 0) {
            if (func_0016AF10(p, s0, v, s1 + (e << 3)) != 0) {
                if (func_0016AFE0(p, s0, v, s1 + ((*s2 & 0xFFF) << 3)) != 0) {
                    return 1;
                }
            }
        }
        i++;
        s2++;
    } while (i < 4);
    return 0;
}

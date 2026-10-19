/* ./try.sh src/grok_bg_00322960.c "-O4,p" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern s32 func_001E0CC0(u8 *, s32);

void func_00322960(u8 *p)
{
    s32 t;
    u8 *q;

    t = *(s32 *)(p + 0x2B8);
    if (t > 0)
        *(s32 *)(p + 0x2B8) = t - 1;
    if (*(s8 *)(p + 0x1B4) == 0) {
        t = *(s32 *)(p + 0xD0);
        if (t > 0) {
            t = t - 1;
            *(s32 *)(p + 0xD0) = t;
            if (t <= 0)
                p[0x216] = 0;
        }
    }
    if (*(s16 *)(p + 0x434) < 32) {
        if (*(s32 *)(p + 0xD4) == 0) {
            if (func_001E0CC0(p, 4))
                *(s32 *)(p + 0xD4) = 1;
        }
    }
    t = *(s32 *)(p + 0x2DC);
    if (t > 0)
        *(s32 *)(p + 0x2DC) = t - 1;
    q = *(u8 **)(p + 0x220);
    if (q[1] == 16 && q[0x25] == p[0x25] && p[5] == 0 && p[0x1E4] == 14 && p[0x1E5] == 31 && p[0x1B6] == 63)
        *(s32 *)(p + 0x2DC) = 120;
}

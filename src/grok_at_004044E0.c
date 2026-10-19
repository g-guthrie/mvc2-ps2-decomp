typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern s32 func_003FA728(s32, s32, s32, s32 *, s16, s16, s16 *, s16, s16);
extern s32 func_003FB040(s32, s32, s32, s32 *, s32, s32 *, s16, s16, s16 *, s16, s16);
extern s32 func_004044D0(void);

void func_004044E0(s32 *p)
{
    s32 st = p[3];
    if (st == 1) {
        p[3] = 2;
        st = 2;
    }
    if (st != 2)
        return;
    if (p[5] == 1) {
        p[4] = func_003FA728(p[6], p[7], p[8], p + 10,
                             *(s16 *)((u8 *)p + 48), *(s16 *)((u8 *)p + 50),
                             (s16 *)((u8 *)p + 52), *(s16 *)((u8 *)p + 54),
                             *(s16 *)((u8 *)p + 56));
    } else {
        s32 r = func_003FB040(p[6], p[7], p[8], p + 10, p[9],
                              (s32 *)((u8 *)p + 44),
                              *(s16 *)((u8 *)p + 48), *(s16 *)((u8 *)p + 50),
                              (s16 *)((u8 *)p + 52), *(s16 *)((u8 *)p + 54),
                              *(s16 *)((u8 *)p + 56));
        p[4] = r;
        if (r - ((r >> 31) + r >> 1 << 1) == 1)
            func_004044D0();
    }
    p[3] = 3;
}

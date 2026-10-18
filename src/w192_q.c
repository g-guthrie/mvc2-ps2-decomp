typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern u8 *func_0039C5B0(u8 *, s32);

void func_002D4470(u8 *p)
{
    u8 *o;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (func_00175700(p) < 0) {
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 1;
        if (*(s16 *)(p + 0x1E) > 0)
            goto L1;
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x16, 1);
        if (*(s8 *)(p + 0x2C0) != 0)
            p[0x152] = 8;
    } else {
L1:
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
    if (*(s16 *)(p + 0x1C) < 0) {
        *(s16 *)(p + 0x1C) = 1;
        t = p[7];
        if (t == 0) {
            p[7] = t + 1;
            if ((o = func_0039C5B0(p, 0)) != 0)
                o[0x95] = 0;
            if ((o = func_0039C5B0(p, 0)) != 0)
                o[0x95] = 1;
        }
        if ((o = func_0039C5B0(p, 8)) != 0) {
            o[0x22] = p[0x22];
            t = p[0x22];
            p[0x22] = t + 1;
            t = p[0x22];
            p[0x22] = t & 7;
            o[0x21] = p[0x21];
            t = p[0x21];
            p[0x21] = t + 1;
            t = p[0x21];
            p[0x21] = t & 7;
        }
    }
    }
}

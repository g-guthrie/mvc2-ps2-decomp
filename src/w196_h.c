typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_00324EA0(u8 *p)
{
    extern void func_00185490();
    extern void func_00183D10(u8 *);
    extern void func_0018C4B0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern u8 *func_003CA900(u8 *, unsigned int);
    extern s8 func_00175700(u8 *);
    extern void func_003266E0(u8 *);
    u32 t;
    s16 v;
    if (p[6] == 0) {
        t = p[6];
        p[6] = t + 1;
        func_00185490();
        func_00183D10(p);
        func_0018C4B0(p, 5);
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        p[0x20D] = 0;
        *(s16 *)(p + 0x1C) = 0x3C;
        func_001757E0(p, 0x15, 5);
        if (p[0x1FD] == 1) {
            if (p[0x1B7] == 0) {
                func_003CA900(p, 0);
            } else {
                func_003CA900(p, 7);
            }
        } else {
            if (p[0x1B7] == 0) {
                func_003CA900(p, 4);
            } else {
                func_003CA900(p, 3);
            }
        }
        p[0x28F] = 0;
        p[0x28E] = 0x10;
    }
    if (func_00175700(p) < 0) {
        if (*(s8 *)(p + 0x151) == 0) func_003266E0(p);
    } else {
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) func_001757E0(p, 0x15, 6);
    }
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_0017AAE0(u8 *p)
{
    extern s32 func_00187D70(u8 *);
    extern s32 func_001884C0(u8 *);
    extern s32 func_00184B30(u8 *);
    extern s32 func_00184720(u8 *);
    extern s32 func_00185A90(u8 *);
    extern s32 func_00184C60(u8 *);
    extern s32 func_00186080(u8 *);
    extern void func_00186CE0(u8 *, s32);
    extern void func_001E31D0(u8 *, s32);
    if (p[1] != 1) {
        p[0x24B] = 5;
    }
    if (p[1] == 0x35 && *(s8 *)(p + 0x150) == 0) goto fin;
    if (func_00187D70(p)) {
        func_001E31D0(p, 0x2B);
        return;
    }
    if (func_001884C0(p)) {
        func_001E31D0(p, 0x2B);
        return;
    }
    if (p[0x215] == 0) {
        if (func_00184B30(p)) {
            func_001E31D0(p, 0x2B);
            return;
        }
        if (func_00184720(p)) {
            func_001E31D0(p, 0x2B);
            return;
        }
        if (func_00185A90(p)) {
            func_001E31D0(p, 0x2B);
            return;
        }
        if (func_00184C60(p)) {
            func_001E31D0(p, 0x2B);
            return;
        }
        if (func_00186080(p)) {
            func_001E31D0(p, 0x2B);
            return;
        }
    } else {
        if (func_00184720(p)) {
            func_001E31D0(p, 0x2B);
            return;
        }
        if (func_00185A90(p)) {
            func_001E31D0(p, 0x2B);
            return;
        }
        if (*(u16 *)(p + 0x362) & 0x400) {
            func_00186CE0(p, 0);
            func_001E31D0(p, 0x2B);
            return;
        }
    }
fin:
    (*(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x10))(p);
}

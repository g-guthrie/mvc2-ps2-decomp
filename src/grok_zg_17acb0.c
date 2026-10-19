typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;

extern s32 func_00187D70(u8 *);
extern s32 func_001884C0(u8 *);
extern s32 func_00184B30(u8 *);
extern s32 func_00184720(u8 *);
extern s32 func_00185CA0(u8 *);
extern s32 func_00184C60(u8 *);
extern s32 func_00186080(u8 *);
extern void func_001E31D0(u8 *, s32);
extern void func_00186CE0(u8 *, s32);

void func_0017ACB0(u8 *p)
{
    if (p[1] != 0x2D && (p[1] != 0x35 || (s8)p[0x150] != 0)) {
        if (func_00187D70(p) != 0) {
            func_001E31D0(p, 0x2B);
            return;
        }
        if (func_001884C0(p) != 0) {
            func_001E31D0(p, 0x2B);
            return;
        }
        if (func_00184B30(p) != 0) {
            func_001E31D0(p, 0x2B);
            return;
        }
        if (func_00184720(p) != 0) {
            func_001E31D0(p, 0x2B);
            return;
        }
        if (func_00185CA0(p) != 0) {
            func_001E31D0(p, 0x2B);
            return;
        }
        if (p[0x215] == 0) {
            if (func_00184C60(p) != 0) {
                func_001E31D0(p, 0x2B);
                return;
            }
            if (func_00186080(p) != 0) {
                func_001E31D0(p, 0x2B);
                return;
            }
        } else if (*(u16 *)(p + 0x362) & 0x800) {
            func_00186CE0(p, 0);
        }
    }
    (*(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x14))(p);
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;

extern s32 func_00184B30(u8 *);
extern s32 func_00184720(u8 *);
extern s32 func_00185A90(u8 *);
extern s32 func_001884C0(u8 *);
extern s32 func_00187D70(u8 *);
extern s32 func_001846D0(u8 *, s32);
extern s32 func_00184C60(u8 *);
extern s32 func_00186120(u8 *);
extern void func_00186CE0(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);
extern s8 func_00175700(u8 *);

void func_0017A8A0(u8 *p)
{
    if (func_00184B30(p) != 0) {
        return;
    }
    if (func_00184720(p) != 0) {
        return;
    }
    if (func_00185A90(p) != 0) {
        return;
    }
    if (p[0x215] == 0) {
        if (func_001884C0(p) != 0) {
            return;
        }
        if (func_00187D70(p) != 0) {
            return;
        }
        if (func_001846D0(p, 0) != 0) {
            return;
        }
        if (func_00184C60(p) != 0) {
            return;
        }
    }
    if (func_00186120(p) != 0) {
        return;
    }
    if (*(u16 *)(p + 0x354) & 0x1000) {
        func_00186CE0(p, 5);
        func_001757E0(p, 3, 0);
        return;
    }
    if (func_00175700(p) < 0) {
        func_00186CE0(p, 0);
    }
}

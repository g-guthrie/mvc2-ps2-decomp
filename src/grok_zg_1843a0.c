typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern void func_00186CE0(u8 *, s32);
extern s32 func_001853E0(u8 *);
extern s32 func_00185A90(u8 *);
extern s32 func_00184B30(u8 *);
extern s32 func_00184720(u8 *);

void func_001843A0(u8 *p)
{
    p[0x13C] = 1;
    if (p[0x20D] != 2 && *(f32 *)(p + 0x38) > *(f32 *)(p + 0x430)) {
        p[0x20D] = 2;
        *(s32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
    if (p[0x215] != 0) {
        func_00186CE0(p, 0x18);
        return;
    }
    *(s16 *)(p + 0x140) = p[0x1E6];
    if (func_001853E0(p) != 0)
        return;
    if (func_00185A90(p) != 0)
        return;
    if (p[0x20D] != 2) {
        if (*(u16 *)(p + 0x35E) & 0x2000) {
            func_00186CE0(p, 2);
            return;
        }
    }
    if (p[0x20D] == 1) {
        if (*(u16 *)(p + 0x35E) & 0x1000)
            func_00186CE0(p, 6);
        else
            func_00186CE0(p, 7);
        return;
    }
    if (p[0x20D] == 0 && (*(u16 *)(p + 0x35E) & 0x1000)) {
        func_00186CE0(p, 5);
        return;
    }
    {
        u16 w = *(u16 *)(p + 0x35E);
        if (w & 0xC00) {
            func_00186CE0(p, 1);
            return;
        }
        if (w & 0x120) {
            if (func_00184B30(p) != 0)
                return;
        }
    }
    if (*(u16 *)(p + 0x35E) & 0x360) {
        if (func_00184720(p) != 0)
            return;
    }
    func_00186CE0(p, 0);
}

typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00184540(u8 *);
extern s32 func_001864a0(u8 *);
extern s32 func_00185A90(u8 *);
extern s32 func_00186030(u8 *);
extern void func_001865B0(u8 *);
extern int func_001757E0(u8 *, s32, s32);
extern void func_00183D90(u8 *);
extern void func_00186CE0(u8 *, s32);

void func_0017C1B0(u8 *p)
{
    p[0x201] = 2;
    {
    u8 st = p[0x20];
    if (st == 0) {
        if (((s8)func_00175700(p)) < 0) {
            func_00184540(p);
            return;
        }
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (func_001864a0(p) != 0) {
            if (func_00185A90(p) == 0) {
                if (func_00186030(p) == 0) {
                    func_001865B0(p);
                }
            }
        }
    } else if ((s8)st > 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        if (((s8)func_00175700(p)) < 0) {
            p[0x20] = 0x80;
            func_001757E0(p, 3, 1);
        }
    } else {
        ((s8)func_00175700(p));
        func_00183D90(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < 0.0f)) {
            func_00186CE0(p, 6);
        }
    }
    }
}

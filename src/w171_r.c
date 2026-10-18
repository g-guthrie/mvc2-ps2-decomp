typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00176E70(u8 *p)
{
    extern s32 func_001864A0(u8 *);
    extern void func_001E3B30(u8 *);
    extern void func_00158C70(u8 *, s32);
    extern s32 func_00169CE0(u8 *, s32, s32);
    extern void func_00186CE0(u8 *, s32);
    extern s32 func_00175700();
    f32 z = 0.0f;
    f32 *a, *b;
    a = (f32 *)(p + 0x60);
    b = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x6C) != z) {
        if (func_001864A0(p) != 0) {
            *(s32 *)a = 0;
            *(s32 *)b = 0;
            p[0x20D] = 3;
            func_001E3B30(p);
            func_00158C70(p + 0x34, p[2]);
        }
    } else {
        if (*(s16 *)(p + 0x434) != 0 && *(s8 *)(p + 0x24A) != 0) {
            if (*(s8 *)(p + 0x539) != 0) {
                if (func_00169CE0(p, 0x1D, 2) != 0) {
                    *(s8 *)(p + 0x24A) = -1;
                } else {
                    p[0x24A] = 0;
                }
            }
            if (*(s8 *)(p + 0x24A) < 0) {
                p[0x1E7] = 0;
                func_00186CE0(p, 0x11);
                return;
            }
        }
    }
    if ((s8)func_00175700(p) < 0) {
        func_00186CE0(p, 0x17);
    }
}

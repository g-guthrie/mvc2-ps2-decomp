typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FD8;
extern f32 D_004F1FDC;
extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_0017E880(u8 *p) {
    extern void func_001E3B30();
    extern void func_00158C70();
    extern s32 func_00169CE0();
    extern s32 func_00175700();
    extern void func_00186CE0();
    s16 v;
    s32 r;
    p[0x1FF] = 2;
    v = *(s16 *)(p + 0x28C);
    if (v >= 0) {
        if (*(s16 *)(p + 0x434) <= 0 || v <= 0) {
            *(s16 *)(p + 0x28C) = -1;
            func_001E3B30(p);
            func_00158C70(p + 0x34, p[2]);
            D_004F1F45 = (p[0x21B] < 5) ? 1 : 3;
            D_004F1F46 = 1;
            if (p[0x249] == 0 && *(s16 *)(p + 0x434) != 0 && *(s8 *)(p + 0x24A) != 0) {
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
    }
    if ((s8)func_00175700(p) < 0) func_00186CE0(p, 0x17);
}

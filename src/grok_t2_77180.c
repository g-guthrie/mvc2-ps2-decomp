typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern void func_0018F320(u8 *);
extern void func_00175700(u8 *);
extern void func_001E3A10(u8 *);
extern void func_00163D70(u8 *);
extern void func_00186CE0(u8 *, s32);
extern s32 func_001864a0(u8 *);
extern void func_001E3B30(u8 *);
extern void func_00158C70(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);

void func_00177180(u8 *p)
{
    func_0018F320(p);
    func_00175700(p);
    if (*(s8 *)(p + 0x211) != 0) {
        if (p[0x24C] == 0) {
            p[0x24C] = 1;
            func_001E3A10(p);
            func_00163D70(p);
        }
    }
    if (p[0x248] == 0 && *(s16 *)(p + 0x434) != 0) {
        s8 t = *(s8 *)(p + 0x24D) - 1;
        *(s8 *)(p + 0x24D) = t;
        if (t < 0) {
            *(s8 *)(p + 0x24D) = 0;
            if (*(f32 *)(p + 0x60) < -12.857142448425293f)
                goto L86;
        }
    }
    {
        s16 t = *(s16 *)(p + 0x1C);
        if (t != 0) {
            t = t - 1;
            *(s16 *)(p + 0x1C) = t;
            if (t <= 0) {
                func_001757E0(p, 13, 17);
            }
        }
    }
    if (*(f32 *)(p + 0x60) <= 0.0f) {
        if (func_001864a0(p) != 0) {
            func_001E3B30(p);
            func_00158C70(p + 0x34, p[2]);
            if (p[0x248] == 0 && *(s16 *)(p + 0x434) != 0) {
                *(f32 *)(p + 0x60) = -(*(f32 *)(p + 0x60) / 2.0f);
            L86:
                func_00186CE0(p, 15);
            } else {
                p[0x20D] = 3;
                p[6] = 3;
                func_001757E0(p, 13, 26);
            }
        }
    }
}

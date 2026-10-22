typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00454BA0[];

void func_00274730(u8 *p)
{
    s16 v;
    s32 r;
    u32 t;
    extern void func_00175700(u8 *);
    extern s32 func_00274910(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_0037D930(u8 *, s32);
    extern void func_001BBD80(u8 *, s32);
    extern void func_001E3710(u8 *, s32);
    extern s32 func_00174170(void);
    extern void func_001757E0(u8 *, s32, s32);

    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 5) {
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0) {
            func_001843A0(p);
        }
    } else {
        r = func_00274910(p);
        *(s32 *)(p + 0x2D0) = *(s32 *)(p + 0x2D0) + r;
        if (*(s8 *)(p + 0x151) == 2) {
            p[0x151] = 0;
            func_0037D930(p, 0);
            func_001BBD80(p, 0);
            func_001E3710(p, 0x24);
        }
        if (*(s8 *)(p + 0x151) == 3) {
            p[0x151] = 0;
            func_001BBD80(p, 3);
        }
        if (*(s8 *)(p + 0x151) == 4) {
            p[0x151] = 0;
            if (*(s32 *)(p + 0x2D4) < 3) {
                if (*(s8 *)(p + 0x539) != 0) {
                    if (func_00174170() & 1) {
                        *(s32 *)(p + 0x2D0) = 1;
                    } else {
                        *(s32 *)(p + 0x2D0) = 0;
                    }
                }
                if (*(s32 *)(p + 0x2D0) > 0) {
                    func_001757E0(p, 7, 3);
                    *(s32 *)(p + 0x2D4) = *(s32 *)(p + 0x2D4) + 1;
                }
                *(s32 *)(p + 0x2D0) = 0;
                *(s16 *)(p + 0x1C) = D_00454BA0[*(s32 *)(p + 0x2D4)];
            } else {
                t = p[7];
                p[7] = t + 1;
                *(s16 *)(p + 0x1C) = D_00454BA0[*(s32 *)(p + 0x2D4)];
            }
        }
    }
}

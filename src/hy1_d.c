typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00318320(u8 *p) {
    extern s32 func_00174170(void);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003C4910(u8 *, s32, s32);
    extern s32 func_003D92F0(void);
    extern void func_001843A0(u8 *);
    extern void func_00175700(u8 *);
    extern void func_003C80C0(u8 *, s32, s32);
    u32 x;
    u8 k;
    u32 t;
    if (p[6] == 0) {
        p[6]++;
        x = p[0x20];
        if (x == 0 || (x & 0xFF) == 2) {
            p[7] = 0;
            if (func_00174170() & 1) {
                t = p[0x1FD];
                if (t != 6 && t != 0) {
                    if (func_00174170() & 1) {
                        p[7] = 2;
                        k = 2;
                    } else {
                        k = 0;
                    }
                } else {
                    p[7] = 1;
                    k = 1;
                }
            } else {
                p[7] = 1;
                k = 1;
            }
            func_001757E0(p, 0x13, k);
            if (p[7] == 1) {
                func_003C4910(p, 3, 0);
                return;
            }
        } else {
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            func_001757E0(p, 0x13, 3);
        }
    } else {
        if (func_003D92F0() != 0) {
            func_001843A0(p);
        } else {
            x = p[0x20];
            if (x == 0 || (x & 0xFF) == 2) {
                func_00175700(p);
                t = p[7];
                if (t == 0) {
                    if (*(s8 *)(p + 0x151) != 0) {
                        p[0x151] = 0;
                        func_003C80C0(p, 0, 2);
                    }
                } else if ((t & 0xFF) == 2) {
                    if (*(s8 *)(p + 0x151) != 0) {
                        p[0x151] = 0;
                        func_003C80C0(p, 0, 4);
                    }
                }
            } else {
                func_00175700(p);
            }
        }
    }
}

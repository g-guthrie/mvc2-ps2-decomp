typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
extern G *D_004C2794;

void func_002495D0(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_001E3710(u8 *, s32);
    extern void func_003631F0(u8 *, s32);
    extern void func_001A78D0(u8 *, s32);
    s32 r;
    s32 t;
    switch (p[0x1FC]) {
    case 2:
        if ((*(u16 *)(p + 0x354) & 0x20) == 0) {
            p[7] = 1;
        }
        if (p[6] == 0) {
            func_00175700(p);
            if (*(s8 *)(p + 0x151) != 0) {
                if (p[7] != 0) {
                    t = p[6];
                    p[6] = t + 2;
                } else {
                    t = p[6];
                p[6] = t + 1;
                    *(s16 *)(p + 0x1C) = 0x5A;
                }
                return;
            }
        }
        if (p[6] == 1) {
            s16 h = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = h;
            if (h <= 0 || p[7] != 0) {
                t = p[6];
                p[6] = t + 1;
            }
        }
        if (p[6] == 2) {
            func_00175700(p);
            if (*(s8 *)(p + 0x151) != 0) {
                t = p[6];
                p[6] = t + 1;
                func_001E3710(p, 0x17);
                func_003631F0(p, 0);
            }
        } else if (p[6] == 3) {
            r = func_00175700(p);
            if ((s8)r < 0) {
                func_001843A0(p);
                return;
            }
        }
        break;
    case 1:
        r = func_00175700(p);
        if ((s8)r < 0) {
            func_001843A0(p);
            return;
        }
        if (p[6] == 0) {
            if (*(s8 *)(p + 0x151) != 0) {
                t = p[6];
                p[6] = t + 1;
                func_001A78D0(p, 0xD);
            }
        }
        if (*(s8 *)(p + 0x150) != 0) {
            p[0x150] = 0;
            p[0x1B5] = 4;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
        break;
    case 0:
        r = func_00175700(p);
        if ((s8)r < 0) {
            func_001843A0(p);
            return;
        }
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            p[0x1B5] = 0x19;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
        break;
    }
    if (*(u16 *)(p + 0x160) != 0) {
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x34) += 1.6666666269302368f * (s16) * (u16 *)(p + 0x160);
        } else {
            *(f32 *)(p + 0x34) -= 1.6666666269302368f * (s16) * (u16 *)(p + 0x160);
        }
        *(s16 *)(p + 0x160) = 0;
    }
}

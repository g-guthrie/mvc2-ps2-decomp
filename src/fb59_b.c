typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x7C];
    s16 f7c[1];
} G296500;

extern G296500 *D_004C2794;

void func_00296500(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_00183D50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00186530(u8 *, f32);
    switch (p[0x1FC]) {
    case 0:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        }
        return;
    case 1:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
            return;
        }
        if (*(s8 *)(p + 0x151) != 0) {
            *(s8 *)((s32)p + 0x151) = 0;
            p[0x1B5] = 0x19;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]] += 1;
        }
        break;
    case 2:
        if (p[6] == 0) {
            if (func_00175700(p) < 0) {
                func_001843A0(p);
            }
            return;
        }
        switch (p[7]) {
        case 0:
            func_00175700(p);
            if (*(s8 *)(p + 0x151) != 0) {
                f32 v;
                u32 t = p[7];
                p[7] = t + 1;
                p[0x20D] = 2;
                if (p[0x1E6] != 0) {
                    v = 6.666666507720947f;
                } else {
                    v = -6.666666507720947f;
                }
                *(f32 *)(p + 0x5C) = v;
                *(u32 *)(p + 0x68) = 0;
                *(u32 *)(p + 0x60) = 0x4111B6DB;
                *(u32 *)(p + 0x6C) = 0xBF40DB6D;
            }
            break;
        case 1:
            func_00175700(p);
            if (func_00186530(p, *(f32 *)(p + 0x38)) != 0) {
                u32 t = p[7];
                p[7] = t + 1;
                *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
                p[0x20D] = 0;
                *(u32 *)(p + 0x5C) = 0;
                *(u32 *)(p + 0x60) = 0;
                *(u32 *)(p + 0x68) = 0;
                *(u32 *)(p + 0x6C) = 0;
                func_00183D50(p);
                func_001757E0(p, 0x14, 0xA);
            }
            return;
        case 2:
            if (func_00175700(p) < 0) {
                *(u8 *)(*(u8 **)(p + 0x220) + 0x1FF) = 5;
                func_001843A0(p);
            }
            return;
        }
        return;
    }
}

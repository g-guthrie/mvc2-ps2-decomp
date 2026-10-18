typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G7D;
extern G7D *D_004C2794;

void func_0021E5E0(u8 *p) {
    extern s8 func_00175700();
    extern void func_00184540();
    if (p[0x1FC] != 2) {
        if (func_00175700(p) < 0) {
            func_00184540(p);
        }
    } else {
        s8 s = *(s8 *)(p + 0x151);
        if (func_00175700(p) < 0 && s < 0) {
            func_00184540(p);
        } else if (*(s8 *)(p + 0x151) == 1) {
            p[0x151] = 0;
            p[0x1B5] = 0x15;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
    }
}

void func_003BBE40(u8 *p) {
    extern s8 func_00175700();
    extern void func_001757E0();
    extern void func_003BD7F0();
    extern void func_003BD7A0();
    u8 *q = p + 0xD0;
    if (p[5] == 0) {
        u32 v = p[6];
        if (v == 0) {
            p[6] = v + 1;
            p[0x13C] = 1;
            if (*(s8 *)(q + 7) >= 0) {
                func_003BD7F0(p);
            }
            func_001757E0(p, 0x19, 0x11);
            func_003BD7A0(p);
        } else {
            if (func_00175700(p) < 0) {
                u32 t = p[4];
                p[4] = t + 1;
                p[0x13C] = 0;
            } else {
                func_003BD7A0(p);
            }
        }
    } else {
        u32 t;
        if (*(s8 *)(q + 7) >= 0) {
            func_003BD7F0(p);
        }
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}

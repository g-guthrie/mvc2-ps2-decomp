/* MW 3.0.3: ./try.sh src/rb92_c.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18A1;

void func_0017A0F0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    extern s32 func_00187D70(u8 *);
    extern s32 func_001884C0(u8 *);
    extern s32 func_00184B30(u8 *);
    extern s32 func_00184720(u8 *);
    extern s32 func_00185A90(u8 *);
    extern s32 func_001853E0(u8 *);
    extern s32 func_00184C60(u8 *);
    extern s32 func_00186030(u8 *);
    extern s32 func_00186170(u8 *);
    extern s32 func_001846D0(u8 *, s32);
    extern s32 func_00186120(u8 *);
    extern void func_00182050(u8 *);
    extern void func_00181F10(u8 *);
    extern void func_00186CE0(u8 *, s32);
    s8 s0;
    s32 v1;
    u8 t;

    if ((s8)((*(u16 *)(p + 0x35E) & 0x400) >> 10) != *(s8 *)(p + 0x1E7)) {
        p[6] = 0;
    }
    if (p[6] == 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x1E7] = (*(u16 *)(p + 0x35E) & 0x400) >> 10;
        if ((D_004D18A1 & 4) == 0) {
            p[7] = 0;
            p[0x168] = 2;
            if ((p[0x216] & 0x80) != 0) {
                u32 u = p[0x168];
                p[0x168] = u + 6;
            }
        } else {
            p[7] = 1;
            p[0x168] = 6;
        }
        {
            u32 a = p[0x1E7];
            p[0x168] += a;
        }
        func_001757E0(p, 0, p[0x168]);
    }
    if (func_00187D70(p) != 0) return;
    if (func_001884C0(p) != 0) return;
    if (func_00184B30(p) != 0) return;
    if (func_00184720(p) != 0) return;
    if (func_00185A90(p) != 0) return;
    if (func_001853E0(p) != 0) return;
    if (func_00184C60(p) != 0) return;
    if (func_00186030(p) != 0) return;
    if (func_00186170(p) != 0) return;
    if (func_001846D0(p, 1) != 0) return;
    if ((D_004D18A1 & 2) == 0 && (*(u16 *)(p + 0x354) & 0x3C00) != 0) {
        if (func_00186120(p) != 0) return;
        v1 = D_004D18A1 & 4;
        if (v1 == 0 && p[7] != 0) {
            p[6] = 0;
        } else {
            if (v1 != 0) {
                func_00182050(p);
            } else {
                func_00181F10(p);
            }
        }
        if (p[0x214] != 0) {
            func_00175700(p);
        }
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        return;
    }
    s0 = *(s8 *)(p + 0x1E7);
    func_00186CE0(p, 0);
    if ((D_004D18A1 & 4) != 0) return;
    switch (p[1]) {
    case 0x38:
        (**(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x64))(p);
        return;
    case 0x3A:
        (**(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x60))(p);
        break;
    default:
        s0 += 4;
        if ((p[0x216] & 0x80) != 0) {
            s0 = 1;
        }
        func_001757E0(p, 0, (u8)s0);
        break;
    }
}

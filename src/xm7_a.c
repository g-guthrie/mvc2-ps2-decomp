typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_a;
extern H_a *D_004C2794;
typedef struct { f32 x, y, z; } V3_a;
typedef struct { u8 pad[0x34]; f32 f34, f38; u8 pad2[0x1E6-0x3C]; u8 b1E6; } P_a;

void func_0038EF00(u8 *p)
{
    extern s32 func_00174170(void);
    extern void func_001757E0(u8 *, s32, s32);
    P_a *par;
    u8 *q;
    s32 i;
    s32 *d;
    s32 *s;
    f32 a, b, e, c, t2;
    u32 t;

    t = p[4]; p[4] = t + 1;
    par = *(P_a **)(p + 0x18);
    d = (s32 *)(p + 0xEC);
    s = (s32 *)((u8 *)par + 0xEC);
    i = 0x31;
    do {
        *d = *s;
        i--;
        s++;
        d++;
    } while (i > 0);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3_a *)(p + 0x50) = *(V3_a *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x13C] = 1;
    q = p + 2;
    if (p[0x20] == 0) {
        *(f32 *)(p + 0x34) = par->f34;
        *(f32 *)(p + 0x38) = 98.57142639160156f + par->f38;
        b = -98.33332824707031f;
        if (par->b1E6 != 0) b = -b;
        *(f32 *)(p + 0x34) += b;
        c = 1.6666666269302368f * (f32)(u32)(func_00174170() & 0x3F);
        e = 2.142857074737549f * (f32)(u32)(func_00174170() & 0x1F);
        if (func_00174170() & 1) c = -c;
        if (func_00174170() & 1) e = -e;
        *(f32 *)(p + 0x34) += c;
        *(f32 *)(p + 0x38) += e;
        if (func_00174170() & 1) {
            func_001757E0(p, 0x17, 8);
            *(s8 *)(p + 0x24) = 0xB;
            p[0x21] = 0;
        } else {
            func_001757E0(p, 0x17, 9);
            *(s8 *)(p + 0x24) = 0xD;
            p[0x21] = 1;
        }
    } else {
        f32 k;
        p[0x14D] = 0x30;
        p[0x14C] = 0x30;
        p[0x14F] = 0x30;
        p[0x14E] = 0x30;
        p[0x24] = (p[0x21] != 0) ? 0xC : 0xA;
        *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x14) + 0x38);
        p[0x1B5] = (func_00174170() & 1) + 0x57;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[*q] += 1;
        p[0x1B0] = 0x42;
        p[0x1B1] = 0x42;
        *(s16 *)(p + 0x1C) = 0;
        if (*(s16 *)(p + 0x140) != 0) k = 13.333333015441895f;
        else k = -13.333333015441895f;
        *(f32 *)(p + 0x5C) = k;
        *(f32 *)(p + 0x60) = -10.714284896850586f;
        *(s32 *)(p + 0x6C) = 0;
        *(s32 *)(p + 0x68) = 0;
        func_001757E0(p, 0x15, 0x10);
    }
}

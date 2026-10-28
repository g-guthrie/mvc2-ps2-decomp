/* s8f: MW 3.0, ./try30.sh src/s8f_c.c "-O3 -Op -sdatathreshold 0" (own file: opt_propagation off keeps the u8 constant for p[6] in a0) */
#pragma opt_propagation off
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x5C]; f32 f5c; f32 f60; f32 f64; f32 f68; } PF;
void func_0018C1A0(u8 *p, u8 *q)
{
    extern void func_001757E0(u8 *, s32, u8);
    extern void func_00186A60(u8 *, s32);
    extern void func_0018C970(u8 *, u8 *);
    extern void func_0018C8A0(u8 *, u8 *);
    u8 *c;
    u8 a;
    s32 m;
    u8 r;

    p[5] = 0;
    c = *(u8 **)(p + 0x1D0);
    p[0x242] = c[8];
    switch (p[0x1B6] & 0x80) {
    default: p[0x242] = q[0x22]; break;
    case 0: break;
    }
    p[0x243] = c[9];
    p[0x244] = c[2];
    a = c[0x14];
    if (a == 0) {
        a = 0x12;
        if ((c[2] & 0xF0) == 0) {
            u8 v = *(s8 *)(c + 3) & 0x70;
            if (v != 0) {
                if ((v & 0xFF) == 0x20) {
                    a = 0xE;
                } else if ((v & 0xFF) == 0x10) {
                    a = 0xB;
                }
            }
        }
    }
    p[0x1F2] = a;
    m = p[0x1E4];
    if ((m == 0x12 && p[6] == 3) || (m == 0x13 && p[6] == 2)) {
        if (p[0x20D] == 2) return;
        r = 3;
        if ((*(u8 **)(p + 0x1CC))[0x215] == 0) {
            m = p[0x244] & 0xF;
            if (m == 4) {
                r = 7;
            } else if (m != 2) {
                if (*(u16 *)(p + 0x354) & 0x1000) r = 7;
            }
        } else {
            if (*(u16 *)(p + 0x354) & 0x1000) r = 7;
        }
        func_001757E0(p, 5, r);
        return;
    }
    p[0x1F1] = 0x14;
    if (p[0x20D] == 2 || p[0x1E4] == 0x13) {
        PF *pf = (PF *)p;
        func_0018C970(p, q);
        *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x22C);
        func_00186A60(p, 0x13);
        p[6] = 1;
        pf->f68 /= 256.0f;
        if (pf->f60 > 0.0f) {
            pf->f60 = 0.0f;
        }
        pf->f60 /= 16.0f;
        if (p[0x215] == 0) {
            if (p[0x210] == 0) {
                *(s8 *)(p + 0x224) = *(s8 *)(p + 0x224) + 1;
            }
            if (pf->f60 < -0.066964283585548401f) {
                *(u32 *)&pf->f60 = 0xBF4DB6DB;
            }
        }
        func_001757E0(p, 6, 2);
        return;
    }
    func_0018C8A0(p, q);
    func_00186A60(p, 0x12);
    r = 3;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    a = 1;
    if ((*(u8 **)(p + 0x1CC))[0x215] == 0) {
        m = p[0x244] & 0xF;
        if (m == 4) {
            r = 7;
        } else if (m != 2) {
            if (*(u16 *)(p + 0x354) & 0x1000) r = 7;
        }
    } else {
        if (*(u16 *)(p + 0x354) & 0x1000) r = 7;
    }
    p[6] = a;
    func_001757E0(p, 5, r);
}

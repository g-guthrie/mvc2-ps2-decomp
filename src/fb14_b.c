typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* 0x00291800 static copy (real body, verified in src/n7e.c) */
static s32 func_00291800(u8 *p) {
    u8 f = p[0x1E6];
    u8 *q = *(u8 **)(p + 0x220);
    if ((f == 0 && *(f32 *)(p + 0x34) < *(f32 *)(q + 0x34)) || (f != 0 && !(*(f32 *)(p + 0x34) <= *(f32 *)(q + 0x34)))) return 1;
    return 0;
}

/* 0x00291860 */
extern void func_002918A0(u8 *, u8 *);
extern void func_00292420(u8 *);
void func_00291860(u8 *a, u8 *b) {
    if (func_00291800(a) != 0) {
        a[7] = 6;
        b[0x18] = 0;
        func_002918A0(a, b);
    } else {
        func_00292420(a);
    }
}

/* 0x0025C240 static copy (real body, verified in src/m8p.c) */
typedef struct { u8 pad[0x1E8]; s8 b1E8; u8 pad2[0x24]; u8 b20D; u8 pad3[2]; u8 b210; } S25C;
static s32 func_0025C240(S25C *p) {
    if (p->b20D != 2) {
        return 1;
    }
    if (p->b210 == 0) {
        if (p->b1E8 != 0) {
            return 0;
        }
        p->b1E8 += 1;
    }
    return 1;
}

/* 0x0025C6C0 */
extern u8 D_00453990[];
extern s32 func_00189310(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, int);
s32 func_0025C6C0(u8 *p) {
    if (func_00189310(p, D_00453990, p + 0x3A0) == 0) return 0;
    if (func_0025C240((S25C *)p) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    func_0018A990(p, p + 0x3A0);
    p[5] = 0; p[7] = 0; p[6] = 0; p[0x1FD] = 5;
    func_00186A60(p, 0x1D);
    return 1;
}

/* 0x002918A0 */
extern void func_001757E0(u8 *, s32, s32);
extern int func_00175700(u8 *);
void func_002918A0(u8 *a, u8 *b) {
    u32 t = b[0x18];
    if (t == 0) {
        b[0x18] = t + 1;
        a[0x1E6] ^= 1;
        *(s16 *)(a + 0x140) = a[0x1E6];
        b[0x19] = 1;
        func_001757E0(a, 0x16, 0xA);
    }
    if (func_00291800(a) != 0) {
        b[0x18] = 0;
        func_002918A0(a, b);
        return;
    }
    if ((s8)func_00175700(a) < 0) {
        a[7] = 0;
        b[0x18] = 0;
        b[0x19] = 0;
        func_001757E0(a, 0x16, 8);
    }
    func_00292420(a);
}

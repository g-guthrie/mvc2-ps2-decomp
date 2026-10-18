typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
#define F(p,o) (*(f32 *)((u8 *)(p)+(o)))
extern s32 func_00175700(u8 *);
extern s32 func_00174470(u8 *);
extern void func_00350FD0(u8 *);
extern void func_003C80A0(u8 *, u8 *);
extern void func_0018CDF0(u8 *);
extern void func_00175580(u8 *, s32, s32, s32);
extern u8 D_0044B470[];

void func_0036DD60(f32 *pf, u8 *q) {
    u8 *p = (u8 *)pf;
    u8 *s = q + 0x2B8;
    func_00175700(p);
    if ((pf[0x14] -= 0.05f) <= 0.0f) pf[0x14] = 0.0f;
    if ((s8)p[0x153] < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        *s = 0;
    }
}

void func_003C8020(u8 *p, u8 *q) {
    u8 *o = *(u8 **)(p + 0x14);
    if (*(u16 *)(o + 0x168) == 0x1414) {
        F(p, 0x34) = F(o, 0x34);
        F(p, 0x38) = F(o, 0x38);
        p[0x24] = 0;
        if ((s8)func_00175700(p) < 0) func_003C80A0(p, q);
    } else {
        func_003C80A0(p, q);
    }
}

void func_0018DC70(u8 *p) {
    u8 *o;
    p[0x248] = 1;
    if ((*(u8 **)(p + 0x1D0))[1] & 0x20) {
        o = *(u8 **)(p + 0x1CC);
        if (o == 0) o = *(u8 **)(p + 0x220);
        if (o[0x249] != 0) {
            p[0x249] = 0;
            o[0x249] = 0;
        } else {
            p[0x249] = 1;
        }
    }
    p[0x247] = 2;
    func_0018CDF0(p);
    p[0x24A] = 0;
}

void func_001A7CD0(u8 *p, u8 *q) {
    if (*(s8 *)(q + 0x151) == 0 || q[0x1E4] != 0x14 || q[0x1FC] != 2) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        u8 *e = D_0044B470 + p[0x20] * 6;
        func_00175580(p, 0x1B, e[5], *(s8 *)(q + 0x150));
    }
}

typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef float f32;

typedef struct { f32 x, y, z; } V_DED0;
extern V_DED0 D_004B8260[];
extern s32 D_004C283C;
void func_0033DED0(s32 n) {
    extern u8 *func_003DA750();
    extern void func_0033DF70();
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033DF70;
        *(s16 *)(o + 0xCC) = n + 0x25;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x801;
        *(V_DED0 *)(o + 0x34) = D_004B8260[n];
        o[0x20] = n;
    }
}

typedef struct { u8 pad[0x7C]; s16 t[8]; } G_F4A0;
extern G_F4A0 *D_004C2794;
typedef struct { u8 p0[2]; u8 b2; u8 p3[3]; u8 b6; u8 p7[0x15]; s16 h1c; u8 p1e[0x1A]; f32 f38; u8 p3c[0x20]; s32 w5c, w60; u8 p64[4]; s32 w68, w6c; u8 p70[0x142]; u8 b1b2; u8 p1b3[2]; u8 b1b5; u8 p1b6[0xA]; u16 h1c0; u8 p1c2[0x16]; s32 w1d8; u8 p1dc[0x31]; u8 b20d; u8 p20e[0x222]; f32 f430; } S_F4A0;
void func_0025F4A0(S_F4A0 *p) {
    extern void func_0018C4B0();
    extern void func_00185490();
    extern void func_00175C00();
    extern void func_00183D10();
    extern void func_001757E0();
    u32 t = p->b6;
    p->b6 = t + 1;
    p->b1b5 = 0x31;
    p->b1b2 = p->h1c0 = 0;
    p->w1d8 = 0;
    D_004C2794->t[p->b2] += 1;
    func_0018C4B0(p, 5);
    p->h1c = 0x18;
    p->w5c = 0;
    p->w60 = 0;
    p->w68 = 0;
    p->w6c = 0;
    p->b20d = 0;
    p->f38 = p->f430;
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    func_001757E0(p, 0x15, 0xC);
}

extern s32 D_004C27FC;
u8 *func_0014D570(void) {
    extern u8 *func_003DA750();
    extern void func_0014C710();
    u8 *s0;
    u8 *o;
    if ((s0 = func_003DA750(0, 0xD, 1)) != 0) {
        s0[0x13C] = 1;
        *(void **)(s0 + 0x10) = func_0014C710;
        *(s32 *)(s0 + 0xD0) = 0x800031;
        *(s32 *)(s0 + 0x74) = 0;
        *(s16 *)(s0 + 0x1C) = 0x1E;
        if ((o = func_003DA750(0, 0xD, 1)) != 0) {
            o[0x13C] = 1;
            *(s16 *)(o + 0xCC) = 0xB3;
            *(s32 *)(o + 0x84) = D_004C27FC;
            *(void **)(o + 0x10) = func_0014C710;
            *(s32 *)(o + 0xD0) = 0x800021;
            *(s32 *)(o + 0x74) = 0;
            *(s16 *)(o + 0x1C) = 0x14;
        }
        *(u8 **)(s0 + 0xD8) = o;
    }
    return s0;
}

void func_00202020(u8 *p) {
    extern void func_00175700();
    extern void func_001820A0();
    extern void func_00182300();
    extern s32 func_001864a0();
    extern void func_001865B0();
    u8 *q = p + 0x2B8;
    func_00175700(p);
    func_001820A0(p);
    func_00182300(p);
    if (func_001864a0(p) != 0) {
        func_001865B0(p);
        return;
    }
    if (*(s8 *)(q + 0xF) < 2) {
        if (*(s8 *)(p + 0x1B2) != 0) {
            if (*(s8 *)(p + 0x151) != 0) {
                p[0x151] = 0;
                *(s8 *)(q + 0xF) += 1;
                p[0x1B5] = *(s8 *)(q + 0xF) + 0x17;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                D_004C2794->t[p[2]] += 1;
            }
        }
    }
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x9C]; s8 f9c; } G_ra;
extern G_ra *D_004C2840;
extern u8 D_004D18A6[];

void func_001620F0(u8 *p)
{
    extern void func_00161630(u8 *);
    s32 v;
    p[0x13C] = v = D_004C2840->f9c;
    switch (v) { case 0: goto clr; } if (((s32)D_004C2840->f9c & 0xF) == 1 && D_004D18A6[0] != 0) { clr:
        p[0x13C] = 0;
        *(s16 *)(p + 0x1C) = 0;
    }
    p[0x13C] = D_004C2840->f9c;
    func_00161630(p);
    {
        s16 t = *(s16 *)(p + 0x1C);
        if (t != 0) {
            f32 a;
            *(s16 *)(p + 0x1C) = t - 1;
            *(f32 *)(p + 0x64) += *(f32 *)(p + 0x70);
            a = *(f32 *)(p + 0x64);
            *(f32 *)(p + 0x3C) += a;
        } else {
            u8 *q = *(u8 **)(p + 0x18);
            u32 x = q[5];
            q[5] = x - 1;
            x = p[4];
            p[4] = x + 1;
        }
    }
}
typedef struct { u8 pad0[4]; u8 b4; u8 b5; u8 pad6[0x34-6]; f32 f34; u8 pad38[0x5C-0x38]; f32 f5c; u8 pad60[0x68-0x60]; f32 f68; u8 pad6c[0x1B2-0x6C]; s8 b1b2; s8 b1b3; } CA;

void func_003A8180(CA *p, s32 a)
{
    extern s8 func_00175700(CA *);
    extern void func_001E7F60();
    extern s32 func_00174470(CA *);
    extern void func_003A82B0(CA *, s32);
    u32 t;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    func_00175700(p);
    switch (p->b1b3) {
    case 0: break;
    default: { t = p->b5; p->b5 = t + 1; return; }
    }
    {
        func_001E7F60(p);
    }
    switch (p->b1b2) {
    case 0: break;
    default: { t = p->b5; p->b5 = t + 1; return; }
    }
    {
        if (func_00174470(p) == 0) {
            t = p->b4;
            p->b4 = t + 1;
            func_003A82B0(p, a);
        }
    }
}
typedef struct { u8 pad[0x7C]; s16 f7c[4]; } G_nq;
extern G_nq *D_004C2794;

static void func_002F8DE0(u8 *p) {
    if (p[0x20D] == 2) {
        *(f32 *)(p + 0x5C) /= 8.0f;
        *(f32 *)(p + 0x68) /= 8.0f;
        *(f32 *)(p + 0x60) /= 8.0f;
        *(f32 *)(p + 0x6C) /= 8.0f;
    }
}

void func_002F90A0(u8 *p, s32 a)
{
    extern void func_0018C4B0(u8 *, s32);
    extern void func_00185490(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00183D10(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_002F9160(u8 *, s32);
    u32 t;
    t = p[6];
    p[6] = t + 1;
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_00175C00(p, 0);
    switch (p[0x20D]) { case 2: break; default: func_00183D10(p); break; }
    p[0x1B5] = 0x32;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0x15, 1);
    func_002F8DE0(p);
    func_002F9160(p, a);
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;

extern void func_001757E0(u8 *p, s32 a1, s32 a2);

void func_0036D130(u8 *p)
{
    f32 k = 34.28571319580078f;
    u8 *r;
    s32 v;
    s32 w;

    r = *(u8 **)(p + 0x18);
    r = *(u8 **)(r + 0x220);
    *(u8 *)(p + 0x13C) = 0;
    *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 0x14) + 0x140);
    *(f32 *)(p + 0x34) = *(f32 *)(r + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x14) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(r + 0x3C);
    *(f32 *)(p + 0x38) += k;
    *(u8 *)(p + 0x1B0) = 0x42;
    *(u8 *)(p + 0x1B1) = 0x42;

    if (*(u8 *)(p + 0x23) != 0) {
        v = 0x43;
        *(u8 *)(p + 0x1B5) = v;
        *(u8 *)(p + 0x1B2) = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        *(s16 *)((u8 *)((u32)(*(u8 *)(p + 2) << 1) + (u32)D_004C2794) + 0x7C) += 1;
    } else {
        v = 0x44;
        *(u8 *)(p + 0x1B5) = v;
        *(u8 *)(p + 0x1B2) = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        *(s16 *)((u8 *)((u32)(*(u8 *)(p + 2) << 1) + (u32)D_004C2794) + 0x7C) += 1;
    }
    *(s32 *)(p + 0x68) = 0;
    w = 0x1C;
    *(s32 *)(p + 0x6C) = 0;
    v = 0x17;
    *(s16 *)(p + 0x1C) = w;
    *(u8 *)(p + 0x169) = v;
    func_001757E0(p, *(u8 *)(p + 0x169), 4);
}

extern s16 D_0044EC60[];
extern s16 D_0044EC80[];
extern s16 D_004BFACC[2];

void func_001DCDE0(u8 *p, s32 a1)
{
    f32 kf1 = 1.6666666269302368f;
    f32 kf0 = 2.142857074737549f;
    u8 *o;
    u8 cnt;
    u8 i;
    s16 *s2;

    s2 = D_0044EC60;
    cnt = 8;
    if (a1 == 0) {
        cnt = 1;
        s2 = D_004BFACC;
    }
    i = 0;
    if ((u16)a1 == 2) {
        s2 = D_0044EC80;
        cnt = 9;
    }
    for (i = 0; (u8)i < cnt; i++) {
        extern u8 *func_003DA750(s32 a0, s32 a1, s32 a2);
        extern void func_001DCF20(void);
        o = func_003DA750(0, 3, 0);
        if (o != 0) {
            *(u32 *)(o + 0x10) = (u32)func_001DCF20;
            *(u8 **)(o + 0x18) = p;
            *(u8 *)(o + 0x1) = *(u8 *)(p + 1);
            *(u8 *)(o + 0x20) = a1;
            *(u16 *)(o + 0x26) = 0x3602;
            *(u32 *)(o + 0xD0) = *(u32 *)(p + 0x18);
            *(f32 *)(o + 0x5C) = *(f32 *)(p + 0x5C);
            *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34) + kf1 * (f32)s2[0];
            *(f32 *)(o + 0x38) = *(f32 *)(p + 0x38) + kf0 * (f32)s2[1];
            s2 += 2;
        }
    }
}

extern u8 D_004C0C0C[4];
extern u8 D_004C0BF4[4];
extern u8 D_004C0C10[4];
extern u8 D_004C0BF8[4];
extern u8 D_004C0C14[4];
extern u8 D_004C0BFC[4];

void func_002A7FD0(u8 *p)
{
    extern void func_001E3710(u8 *p, s32 a1);
    extern void func_001757E0(u8 *p, s32 a1, s32 a2);
    u8 k;

    k = p[0x1FC];
    switch (k) {
    case 0:
        if (*(u16 *)(p + 0x20E) & 0x1000) {
            *(u8 *)(p + 0x168) = 0;
            *(u8 *)(p + 0x1B5) = 0x15;
        } else {
            *(u8 *)(p + 0x168) = 3;
            *(u8 *)(p + 0x1B5) = 0xF;
        }
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) {
            *(u32 *)(p + 0x408) = (u32)D_004C0BF4;
        } else {
            *(u32 *)(p + 0x408) = (u32)D_004C0C0C;
        }
        *(u8 *)(p + 0x1BB) = 0;
        break;
    case 1:
        *(u8 *)(p + 0x168) = 4;
        *(u8 *)(p + 0x1B5) = 0x10;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) {
            *(u32 *)(p + 0x408) = (u32)D_004C0BF8;
        } else {
            *(u32 *)(p + 0x408) = (u32)D_004C0C10;
        }
        *(u8 *)(p + 0x1BB) = 1;
        break;
    case 2:
        *(u8 *)(p + 0x168) = 5;
        *(u8 *)(p + 0x1B5) = 0x11;
        func_001E3710(p, 0x16);
        if (p[0x210] == 0) {
            *(u32 *)(p + 0x408) = (u32)D_004C0BFC;
        } else {
            *(u32 *)(p + 0x408) = (u32)D_004C0C14;
        }
        *(u8 *)(p + 0x1BB) = 2;
        break;
    default:
        break;
    }
    {
        u8 t;
        t = *(volatile u8 *)(p + 0x1B5);
        *(u8 *)(p + 0x1B5) = t;
    }
    *(u8 *)(p + 0x1B2) = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    *(s16 *)((u8 *)((u32)(p[2] << 1) + (u32)D_004C2794) + 0x7C) += 1;
    func_001757E0(p, 0xC, p[0x168]);
    if ((s8)p[0x1EA] & 0xF0) {
        *(u8 *)(p + 0x1EA) = (s8)p[0x1EA] - 0x10;
    }
}

extern s16 D_0044C3C0[];

void func_001BF080(u8 *p, u8 *q)
{
    extern s32 func_00174170(void);
    extern s32 func_00175670(u8 *p);
    s16 *a2;
    s32 a0;
    f32 f;
    s16 h;
    f32 tq;
    f32 cv;
    f32 kk;
    f32 tq2;

    if (q[0x1E4] != 0x1D || q[0x1FD] != 1) {
        {
            u32 t4 = p[4];
            p[4] = t4 + 1;
        }
        p[0x13C] = 0;
    } else if (*(u16 *)(q + 0x168) != 0x1504) {
        {
            u32 t4 = p[4];
            p[4] = t4 + 1;
        }
        p[0x13C] = 0;
    } else {
        a2 = (s16 *)((u8 *)D_0044C3C0 + ((s32)p[0x20] * 6));
        h = *(s16 *)(q + 0x140);
        *(s16 *)(p + 0x140) = h;
        if (h == 0) {
            a0 = a2[0];
            kk = 1.6666666269302368f;
            cv = (f32)a0;
            tq2 = *(f32 *)(q + 0x34);
            *(f32 *)(p + 0x34) = tq2 + (kk * cv);

        } else {
            a0 = a2[0];
            kk = 1.6666666269302368f;
            cv = (f32)a0;
            tq2 = *(f32 *)(q + 0x34);
            *(f32 *)(p + 0x34) = tq2 - (kk * cv);

        }
        a0 = a2[1];
        kk = 2.142857074737549f;
        tq2 = *(f32 *)(q + 0x38);
        cv = (f32)a0;
        *(f32 *)(p + 0x38) = tq2 + (kk * cv);
        if (p[6] == 0) {
            if ((func_00174170() & 0x1F) == 0) {
                {
                    u32 t6 = p[6];
                    p[6] = t6 + 1;
                }
            }
        }
        if (p[6] != 0) {
            if ((s8)func_00175670(p) < 0) {
                p[6] = 0;
            }
        }
    }
}

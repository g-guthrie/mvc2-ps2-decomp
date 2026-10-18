typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002126B0(u8 *p, u8 *q)
{
    extern s32 func_00175700();
    extern void func_00175C00(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s16 v;
    q[4] = 0xFF;
    func_00175700();
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        q[4] = 0;
        p[0x168] = 7;
        if (p[0x20D] != 2) {
            p[0x168] = (p[0x1B7] != 0) ? 6 : 4;
        }
        func_00175C00(p, 0);
        func_001757E0(p, 0x15, p[0x168]);
    }
}

void func_002DF270(u8 *p, u8 *q)
{
    extern s32 func_00175700();
    extern void func_003A0890(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700();
    if (p[7] == 0) {
        if (*(s8 *)(p + 0x151) != 0) {
            p[7] = p[7] + 1;
            p[0x151] = 0;
            func_003A0890(p, 1);
        }
    } else if (q[0] == 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        func_001757E0(p, 0x16, 10);
    }
}

void func_0029E2A0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001C9420(u8 *, s32, s32);
    extern void func_00390810(u8 *, s32);
    extern void func_00175700(u8 *);
    s16 v;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x16, 9);
        func_001C9420(p, 7, 0);
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    } else {
        if (*(s8 *)(p + 0x151) == 1) {
            p[0x151] = 0;
            func_00390810(p, 0);
            func_00390810(p, 3);
        }
        if (*(s8 *)(p + 0x151) == 2) {
            p[0x151] = 0;
            func_00390810(p, 1);
            func_00390810(p, 2);
        }
    }
    func_00175700(p);
}

s32 func_00167960(u8 *p, u8 **q)
{
    s16 v;
    u8 *r;
    u32 k;
    s32 a;
    if (p[5] != 0 || ((k = p[0x1E4]) != 0x15 && k != 0x1D)) {
        k = p[0x451];
        p[0x451] = k - 1;
        *(s16 *)(p + 0x456) = 0;
        return 1;
    }
    if (*(s16 *)(p + 0x456) != 0) {
        v = *(s16 *)(p + 0x456) - 1;
        *(s16 *)(p + 0x456) = v;
        if (v == 0) {
            r = *q;
            k = *(u16 *)(p + 0x458);
            p[0x471] = 1;
            r = r + k;
            p[0x45C] = r[0];
            *(s32 *)(p + 0x460) = r[1];
            p[0x4BF] = r[2];
            p[0x4BE] = r[3];
            a = (r[4] << 8) & 0xFFFF;
            if ((a & 0xC00) != 0) {
                *(u16 *)(p + 0x4C0) = a ^ (p[0x1E6] * 3 << 10);
            }
        }
    }
    *(s16 *)(p + 0x4F0) = *(s16 *)(p + 0x464);
    return (*(s32 (**)(u8 *))(p + 0x4AC))(p);
}

typedef struct { f32 x, y, z; } V3_FA50;
extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_0020FA50(u8 *p)
{
    extern void func_00175700();
    extern void func_00158C70(V3_FA50 *, s32);
    extern void func_001E3A40(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    V3_FA50 v;
    u32 t;
    func_00175700(p);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        v = *(V3_FA50 *)(p + 0x34);
        v.x += (p[0x1E6] != 0) ? -8 : 8;
        func_00158C70(&v, -1);
        func_001E3A40(p);
        func_001757E0(p, 0xF, 4);
    }
}

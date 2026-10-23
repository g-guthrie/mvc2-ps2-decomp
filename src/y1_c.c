typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002DE770(u8 *p)
{
    extern s8 func_00175700();
    extern void func_00126400();
    extern void func_001757E0();
    u8 *o;
    p[0x206] = 3;
    p[0x1FE] = 1;
    if (func_00175700(p) >= 0) return;
    o = *(u8 **)(p + 0x1DC);
    *(u8 **)(o + 0x1C8) = p;
    o[0x20A] = 1;
    o[0x1B5] = 0x34;
    *(s8 *)(p + 0x22) = 0x19;
    if (p[0x1E6] != 0) *(s8 *)(p + 0x22) = 0x20 - *(s8 *)(p + 0x22);
    func_00126400();
    { u32 t = p[6]; p[6] = t + 1; }
    p[7] = 0;
    func_001757E0(p, 0x15, 9);
}

void func_002DFAE0(u8 *p, u8 *state_unused)
{
    extern void func_001757E0();
    p[0x209] = 2;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v != 0) return;
    }
    p[6]++;
    p[7] = 0;
    *(u32 *)(p + 0x5C) = 0xC0D55555;
    *(u32 *)(p + 0x68) = 0x3E555555;
    if (p[0x1E6] != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    func_001757E0(p, 0x16, 0xE);
}
void func_001788E0(u8 *p)
{
    extern void func_001820A0();
    extern s32 func_001864a0();
    extern void func_00178D80();
    extern void func_00185490();
    extern void func_00183d50();
    if (p[0x213] != 0) {
        func_001820A0();
        if (func_001864a0(p) == 0) return;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00178D80(p, 1);
        func_00185490(p);
        func_00183d50(p);
        return;
    }
    {
        s16 v = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v > 0) return;
    }
    if (*(u16 *)(p + 0x354) & 0x1000) {
        func_00178D80(p, 2);
        return;
    }
    func_00178D80(p, 1);
}
void func_002EF6A0(u8 *p)
{
    extern void func_00175700();
    extern void func_00175C00();
    extern void func_001830D0();
    u32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    {
        s32 t = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = t - 1;
    }
    if (*(s8 *)(p + 0x151) == 0) return;
    p[0x404] = 0;
    p[0x405] = 0;
    p[6]++;
    p[0x151] = 0;
    func_00175C00(p, 1);
    *(u32 *)(p + 0x2B8) = 0;
    v[0] = 0x4226AAAA;
    v[1] = 0x433A6DB6;
    func_001830D0(p, v, 1);
}
extern u8 D_004B71E0[];

void func_00220C00(u8 *p)
{
    extern u8 *func_0019B750();
    u8 *o;
    u8 *s;
    p[0x209] = 2;
    p[0x1FF] = 2;
    p[0x201] = 2;
    *(s16 *)(p + 0x1C) -= 1;
    if (*(s16 *)(p + 0x1C) > 0) return;
    { u32 t = p[6]; p[6] = t + 1; }
    if ((o = func_0019B750(p, 1)) == 0) return;
    o[0x1B7] = p[0x1B7];
    s = D_004B71E0 + p[0x1B7] * 3;
    if ((o = func_0019B750(p, 0)) != 0) {
        o[0x1B7] = *s;
        s++;
    }
    if ((o = func_0019B750(p, 0)) != 0) {
        o[0x1B7] = *s;
        s++;
    }
    if ((o = func_0019B750(p, 0)) != 0) {
        o[0x1B7] = *s;
    }
}
void func_003594D0(u8 *p, u8 *q)
{
    extern void func_0035ACA0();
    extern s32 func_0035A7B0();
    extern void func_0035AE70();
    u8 *o = *(u8 **)(p + 0x18);
    func_0035ACA0(p, q);
    if (func_0035A7B0(p, q) == 0) {
        if (o[0] == 0 && *(s16 *)(o + 0x434) == 0) p[4]++;
        {
            s16 v = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = v;
            if (v != 0) return;
        }
        p[0x21] = 9;
        func_0035AE70(p, q);
        func_0035ACA0(p, q);
        return;
    }
    *(s16 *)(p + 0x1C) = 0x1E0;
    if (*(s16 *)(o + 0x434) == 0 && o[0] == 0) p[4]++;
}
void func_002ADD30(u8 *p)
{
    extern void func_00175C00();
    extern void func_00185490();
    extern void func_00183D10();
    extern void func_001757E0();
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_001830D0();
    u32 v[4];
    if (p[6] == 0) {
        { u32 t = p[6]; p[6] = t + 1; }
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(s32 *)(p + 0xD0) = *(s32 *)(p + 0xD0) ^ 1;
        func_00175C00(p, 0);
        func_00185490(p);
        func_00183D10(p);
        func_001757E0(p, 0x16, 0x13);
        return;
    }
    if (func_00175700() < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        v[0] = 0xC1855555;
        v[1] = 0x431A4924;
        func_001830D0(p, v, 3);
    }
}
void func_002E2BD0(u8 *p)
{
    extern s8 func_00175700();
    extern void func_001757E0();
    extern void func_003A22C0();
    extern void func_001830D0();
    u32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if (func_00175700(p) < 0) {
        *(s16 *)(p + 0x1C) = 0x18;
        *(s16 *)(p + 0x1E) = 0;
        func_001757E0(p, 0x16, 1);
        { u32 t = p[6]; p[6] = t + 1; }
        func_003A22C0(p, 0);
        return;
    }
    if (*(s8 *)(p + 0x151) == 0) return;
    p[0x404] = 0;
    p[0x405] = 0;
    p[0x151] = 0;
    v[0] = 0xC226AAAA;
    v[1] = 0x43586DB6;
    v[2] = 0;
    func_001830D0(p, v, 1);
}

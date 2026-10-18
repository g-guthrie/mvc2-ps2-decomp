typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_001E1330(u8 *p, u8 *a)
{
    extern void func_00175670();
    extern void func_001E1570();
    f32 c = 1.6666666269302368f;
    f32 d;
    *(s8 *)(p + 0x24) = *(s8 *)(a + 0x24);
    d = c * (f32)*(s8 *)(a + 0x151);
    if (*(s16 *)(a + 0x140) != 0) d = -d;
    *(f32 *)(p + 0x34) = *(f32 *)(a + 0x34) + d;
    *(f32 *)(p + 0x38) = *(f32 *)(a + 0x38) + 2.142857074737549f * (f32)*(s8 *)(a + 0x150);
    func_00175670(p);
    if (*(u16 *)(a + 0x168) != *(s32 *)(p + 0xD0)) func_001E1570(p, a);
}
void func_002A6760(u8 *p)
{
    extern s32 func_00175700();
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) return;
    { u32 t = p[6]; p[6] = t + 1; }
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    { f32 w = (p[0x1E6] != 0) ? -3.3333332538604736f : 3.3333332538604736f;
    *(f32 *)(p + 0x5C) = w; }
    *(u32 *)(p + 0x6C) = 0xBF700000;
    if (p[0x1E6] != 0) {
        *(f32 *)(p + 0x34) -= 40.0f;
    } else {
        *(f32 *)(p + 0x34) += 40.0f;
    }
    *(f32 *)(p + 0x38) += 25.714284896850586f;
}
typedef struct { f32 x, y, z; } V3;

void func_0034F4B0(u8 *p)
{
    extern void func_00175700();
    extern s32 func_00174470();
    extern void func_0034FA60();
    extern void func_0015B200();
    extern void func_001E7F60();
    V3 v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (func_00174470(p) == 0) {
        func_0034FA60(p);
        return;
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        v = *(V3 *)(p + 0x34);
        v.y += 17.142856597900391f;
        func_0015B200(p, &v, 1, 0xC9);
        func_0034FA60(p);
    }
    func_001E7F60(p);
}
u8 func_00280D80(u8 *p)
{
    f32 d = *(f32 *)(*(u8 **)(p + 0x220) + 0x34) - *(f32 *)(p + 0x34);
    f32 f;
    u8 r;
    if (*(s16 *)(p + 0x140) != 0) d = -d;
    f = *(f32 *)(p + 0x50);
    if (d > -133.3333282470703f * f) {
        r = 4;
        if (d > 160.0f * f) r++;
    } else {
        r = 0;
        if (d < -226.66665649414062f * f) r++;
        if (d < -320.0f * f) r++;
        if (d < -400.0f * f) r++;
    }
    return r;
}
void func_002177F0(u8 *p)
{
    extern void func_00175700();
    extern void func_00184540();
    extern void func_00183d50();
    extern void func_001757E0();
    u8 s;
    func_00175700(p);
    if (*(s8 *)(p + 0x1B2) != 0) {
        *(u32 *)(p + 0x5C) = 0x40BAAAAA;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x41700000;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
        *(s8 *)(p + 0x1E7) = -1;
        s = p[0x1E6];
        func_00184540(p);
        p[0x1E6] = s;
        *(s16 *)(p + 0x140) = s;
        return;
    }
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        { u32 t = p[6]; p[6] = t + 1; }
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_00183d50(p);
        func_001757E0(p, 1, 3);
    }
}

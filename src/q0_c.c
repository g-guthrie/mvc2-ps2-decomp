typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_001757E0(void *, s32, s32);
extern void func_00175670(void *);
extern void func_00367EC0(void *);
extern s32 func_00367F60(void *);
extern void func_00126970(f32 *, f32 *);
extern void func_00126280(s32, s32);
extern void func_00126340(s32, s32);
extern void func_003DAA40(void *);
extern u8 *func_003DA750(s32, s32, s32);
extern void func_003421E0();

extern u16 D_004C1C88[2];
extern u8 *D_004C2978;
extern u8 *D_004C25D0;
extern s32 D_004C2838;
extern s32 D_004C283C;
extern u8 *D_004C2794;
typedef struct { s16 v; s16 w; } P;
extern P *D_00444940[];
extern s32 D_00444950[];
extern f32 D_004F1FEC[];
extern f32 D_004F1FF8[];

void func_00125C20(s32 x)
{
    D_004F1FEC[0] = *(f32 *)(D_004C25D0 + 0x34);
    func_00126970(D_004F1FEC, D_004F1FF8);
    D_004F1FF8[0] = D_004F1FEC[0];
    func_00126280(0, x);
    func_00126340(0, x);
}


void func_00154190(u8 *a)
{
    s16 v;
    *(s16 *)(a + 0xCC) = D_00444940[0][*(s16 *)(a + 0x1C)].v;
    *(s32 *)(a + 0x84) = D_004C2838;
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x3C) += *(f32 *)(a + 0x64);
    v = *(s16 *)(a + 0x1C) + 1;
    *(s16 *)(a + 0x1C) = v;
    if (v >= D_00444950[0]) func_003DAA40(a);
}

void func_002A3D70(u8 *a)
{
    s16 *q;
    a[6] = 6;
    a[0x1B5] = a[0x1B7] ? 0x3F : 0x3E;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    q = (s16 *)((a[2] << 1) + (u32)D_004C2794);
    q[0x3E]++;
    *(s32 *)(a + 0x5C) = 0;
    *(s32 *)(a + 0x60) = 0;
    *(s32 *)(a + 0x68) = 0;
    *(s32 *)(a + 0x6C) = 0;
    *(f32 *)(a + 0x5C) = a[0x1E6] ? 10.0f : -10.0f;
    *(f32 *)(a + 0x68) = a[0x1E6] ? -0.3125f : 0.3125f;
    func_001757E0(a, 0x15, 0x19);
}

s32 func_00367E10(u8 *a)
{
    u8 *s;
    func_00175670(a);
    func_00367EC0(a);
    s = D_004C2978;
    if (s[2] == 0) {
        return func_00367F60(a);
    }
    if (a[5] == 0) {
        if (*(s8 *)(s + 0xD)) {
            a[5]++;
            *(f32 *)(a + 0x118) = 1.0f;
        }
    } else {
        *(f32 *)(a + 0x118) -= 0.05000000075f;
        if (*(f32 *)(a + 0x118) <= 0.0f) return func_00367F60(a);
    }
}

typedef struct { f32 x, y, z; } V3;
extern V3 D_004605E0[];
void func_00342130(s32 n)
{
    u8 *p;
    V3 *s;
    if ((p = func_003DA750(0, 6, 1)) != 0) {
        p[0x13C] = 1;
        *(void **)(p + 0x10) = func_003421E0;
        *(s16 *)(p + 0xCC) = n + 0xF;
        *(s32 *)(p + 0x84) = D_004C283C;
        *(V3 *)(p + 0x34) = D_004605E0[n];
        *(s32 *)(p + 0xD0) = 0x801;
        p[0x20] = n;
        *(s16 *)(p + 0x1C) = n * 120;
    }
}

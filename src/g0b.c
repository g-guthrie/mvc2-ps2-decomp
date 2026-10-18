typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001E3A70();
extern f32 D_004F1FC8;
extern f32 D_004F1FD0;
extern s32 func_00118FA8(f32);
extern int func_00175700();
extern s32 func_003DAA40();
extern s32 func_00100290(s32, s32);
extern s32 func_00100240(s32, s32);
extern s32 fptodp(f32);

extern void func_00154390(f32 *, int);

extern f32 D_004CD168;
extern f32 D_004CD158;

void func_002D0CD0(u8 *p)
{
    f32 v[3];
    f32 x = *(f32 *)(p + 0x34), y = 1.6666666f;
    f32 c;
    v[0] = x;
    v[0] = x + y;
    if (*(s16 *)(p + 0x140))
        c = -120.0f;
    else
        c = 120.0f;
    v[0] += c;
    v[1] = *(f32 *)(p + 0x430);
    v[2] = *(f32 *)(p + 0x3C);
    func_001E3A70();
    func_00154390(v, 0);
}

void func_003C2C50(u8 *p)
{
    s16 *q = (s16 *)(p + 0xD0);
    *(f32 *)(p + 0x34) = 320.0f + D_004F1FC8;
    q[1] = func_00118FA8(68.57142639f + D_004F1FD0);
    *(f32 *)(p + 0x38) = (f32)(q[1] - q[0]);
}

void func_001EAFD0(u8 *p)
{
    f32 v = *(f32 *)(p + 0x60);
    f32 n;
    *(f32 *)(p + 0x38) += v;
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    n = *(f32 *)(p + 0x60);
    if (v > 0.0 && n < 0.0) *(f32 *)(p + 0x6C) = -1.607142806f;
}

void func_001E42D0(u32 n)
{
    f32 q = D_004CD168 / (f32)n;
    f32 r;
    if (q)
        r = -q;
    else
        r = -1.0f;
    D_004CD158 = r;
}

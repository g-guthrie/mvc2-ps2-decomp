typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_001757E0(void *, s32, s32);
extern s32 func_00175700(void *);
extern s32 func_0016A1F0(void *, s32);
extern s32 func_0016A130(void *, s32);
extern s32 func_0016B250(void *, s32);
extern s32 func_0016B0C0(void *, void *, s32);
extern s32 func_0016A8B0(void *, s32, s32);
extern s32 func_00166C80(void *, void *, s32);
extern void func_0018DB70(void *);
extern void func_0018DA70(void *);
extern void func_0018EA00(u8 *, u8 *);
extern void func_0018E810(void *, void *);
extern s32 func_00184B30(void *);
extern s32 func_00184720(void *);
extern s32 func_00185A90(void *);
extern s32 func_00184C60(void *);
extern s32 func_00186120(void *);
extern void func_00186CE0(void *, s32);
extern void func_001843A0(void *);
extern void func_002482C0(void *);
extern void func_00248310(void *);
extern void func_00360980(void *, s32, s32);
extern void func_00390CB0();
extern void func_003DAA40(void *);
extern void func_001E7F60(void *);
extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern void (*D_00471B58[])(void *);


s32 func_00166000(u8 *a, void *b)
{
    if (func_0016B250(a, 4) == 0) return 0;
    func_0016B0C0(a, b, 0);
    func_0016B0C0(a, b, 1);
    *(s32 *)(a + 0x460) = *(s32 *)(a + 0x4C8);
    return func_00166C80(a, b, func_0016A8B0(a, *(s32 *)(a + 0x220), *(s32 *)(a + 0x460)));
}

void func_0018E1C0(u8 *a, void *b)
{
    if (a[0x425]) {
        if (a[0x20D] == 2) {
            func_0018DB70(a);
        } else {
            func_0018DA70(a);
        }
    } else {
        a[0x247] = 0x17;
        func_0018EA00(a, b);
        func_0018E810(a, b);
        a[0x20D] = 2;
        func_001757E0(a, 0xD, 0);
    }
}

void func_0017AA40(u8 *a)
{
    if (func_00184B30(a) == 0 && func_00184720(a) == 0 && func_00185A90(a) == 0 && func_00184C60(a) == 0 && func_00186120(a) == 0) {
        s8 v = func_00175700(a);
        if (v < 0 || (*(u16 *)(a + 0x354) & 0xC00)) func_00186CE0(a, 6);
    }
}

void func_002A3EE0(u8 *a)
{
    s8 v = func_00175700(a);
    if (v < 0) {
        *(s32 *)(a + 0x5C) = 0;
        *(s32 *)(a + 0x60) = 0;
        *(s32 *)(a + 0x68) = 0;
        *(s32 *)(a + 0x6C) = 0;
        func_001843A0(a);
        return;
    }
    if (*(s8 *)(a + 0x151)) {
        *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
        *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
        *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
        *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    }
}

void func_00246030(u8 *a)
{
    s16 v;
    func_002482C0(a);
    func_00175700(a);
    func_00248310(a);
    if (*(s8 *)(a + 0x151)) {
        a[0x151] = 0;
        func_00360980(a, 0, 1);
        func_00360980(a, 1, 1);
        a[0x28E] = 0x10;
        a[0x28F] = 0;
    }
    v = *(s16 *)(a + 0x1C) - 1;
    *(s16 *)(a + 0x1C) = v;
    if (v == 0) {
        a[7]++;
        func_001757E0(a, 0x15, 2);
    }
}


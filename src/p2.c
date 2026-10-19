typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;

extern s32 func_003F6CC8();
extern s32 func_003F6B30();
s32 func_003F6E48(u8 *p)
{
    if (*(s16 *)(p + 0x9A) == 1) {
        return func_003F6CC8(p);
    }
    return func_003F6B30(p);
}

extern void func_003FF3B0();
void func_003FF628(u8 *p)
{
    func_003FF3B0(p);
    p[1] = 1;
}

extern void func_00118F48();
extern void func_00119C60(s32, s32, s32, u64);
void func_00119058(f32 x)
{
    s32 out[4];
    f32 in = x;
    func_00118F48(&in, out);
    func_00119C60(out[0], out[1], out[2], (u64)(u32)out[3] << 30);
}

extern void func_0040C808();


extern s32 D_0047C5B0, D_0047C5B4, D_0047C5AC, D_0047C5B8;
extern void func_003FCCF0();
void func_003FBFD8(void)
{
    func_003FCCF0(D_0047C5B0);
    D_0047C5B0 = 0;
    D_0047C5B4 = -1;
    D_0047C5AC = 0;
    D_0047C5B8 = 0;
}

extern s32 func_0040A4E8();
s32 func_0040A520(s8 a, s8 b)
{
    s32 x = func_0040A4E8(a);
    s32 y = func_0040A4E8(b);
    return (x ^ y) ? -1 : 0;
}

extern u8 D_004BCF60[], D_004BCF88[];
extern void func_00405DC8();
s32 func_00407298(s32 **p)
{
    s32 (*f)();
    if (p == 0) {
        func_00405DC8(D_004BCF60);
        __asm__ volatile("");
        return 0;
    }
    f = (s32 (*)())(*p)[0x13];
    if (f != 0) {
        return f((s32)p[1]);
    }
    func_00405DC8(D_004BCF88);
    __asm__ volatile("");
    return 0;
}

extern void func_0040A118();
extern void func_00409CC8();
void func_00409E60(u8 *p)
{
    if (p != 0) {
        if (p[2] >= 2) {
            func_0040A118();
        }
        p[0] = 0;
        func_00409CC8(p);
    }
}

extern void func_0040D5A0();
extern u8 D_004BE2F8[], D_004BE390[];
void func_0040D430(s32 *p, s32 n)
{
    if (p == 0) {
        func_0040D5A0(D_004BE2F8, n);
        return;
    }
    if (n < 0 || p[6] < n) {
        func_0040D5A0(D_004BE390, n);
        return;
    }
    p[5] = n;
}

extern u8 D_004BEB90[], D_004BEBB8[];
extern void func_00411380();
extern void func_00411288();
extern void func_004112B0();
typedef struct { s32 a; s32 b; } P8;
extern P8 D_00632360[];
void func_00411720(s32 a, s32 b, s32 c, s32 d)
{
    P8 *e;
    if ((u32)b >= 4) {
        func_00411380(D_004BEB90);
    }
    if (a < 0 || b >= 7) {
        func_00411380(D_004BEBB8);
    }
    func_00411288();
    e = &D_00632360[a * 4 + b];
    e->a = c;
    e->b = d;
    func_004112B0();
    __asm__ volatile("");
}

typedef struct { u8 pad[8]; u8 *x8; } C11;
extern C11 *D_0043B6F8;
extern void func_001209B8();
void func_0011EB60(const char *fmt, ...)
{
    __builtin_va_list ap;
    C11 *c;
    __builtin_stdarg_start(ap, fmt);
    c = D_0043B6F8;
    *(C11 **)(c->x8 + 0x54) = c;
    func_001209B8(c->x8, fmt, ap);
}

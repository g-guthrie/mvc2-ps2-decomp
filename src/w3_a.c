typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s32 a[6]; } S24;
typedef unsigned long long u64;
typedef struct { s32 cls; s32 sign; s32 exp; s32 pad; u64 frac; } FP;

extern s32 D_0043B6F8;

void func_0011C970(s32 a, s32 b)
{
    extern void func_0011C8D0(s32, s32, s32);
    func_0011C8D0(D_0043B6F8, a, b);
}

void func_0040E980(s8 *p, s32 flag)
{
    extern void func_00408ED8(s32);
    s32 i, n;
    p[0x48] = flag;
    n = p[0x26];
    if (flag != 1) {
        for (i = 0; i < n; i++) {
            func_00408ED8(((s32 *)(p + 0x10))[i]);
            p[0x49] = 1;
            p[0x48] = 0;
        }
    }
}

typedef struct S58 { s32 f0; s32 f4; s32 f8; s32 fC; } S58;

void *func_0011B670(u8 *s)
{
    extern void func_0011B7A8();
    extern u8 *func_0011B5F8();
    u8 *q;
    u8 *e;
    u8 *nx;
    s32 n;
    if (*(s32 *)(s + 0x38) == 0)
        func_0011B7A8(s);
    q = s + 0x1D8;
    for (;;) {
        n = *(s32 *)(q + 4);
        n--;
        e = *(u8 **)(q + 8);
        while (n >= 0) {
            if (*(s16 *)(e + 0xC) == 0)
                goto found;
            n--;
            e += 0x58;
        }
        e = *(u8 **)q;
        if (e == 0) {
            nx = func_0011B5F8(s, 4);
            *(u8 **)q = nx;
            if (nx == 0) {
                *(s32 *)s = 12;
                return nx;
            }
            e = nx;
        }
        q = e;
    }
found:
    *(s16 *)(e + 0xC) = 1;
    *(s16 *)(e + 0xE) = -1;
    *(u8 **)(e + 0x54) = s;
    *(s32 *)(e + 0x0) = 0;
    *(s32 *)(e + 0x8) = 0;
    *(s32 *)(e + 0x4) = 0;
    *(s32 *)(e + 0x10) = 0;
    *(s32 *)(e + 0x14) = 0;
    *(s32 *)(e + 0x18) = 0;
    *(s32 *)(e + 0x30) = 0;
    *(s32 *)(e + 0x34) = 0;
    *(s32 *)(e + 0x44) = 0;
    *(s32 *)(e + 0x48) = 0;
    return e;
}
void func_001191F0(u64 *src, FP *o)
{
    u64 v = *src;
    u64 frac = v & 0x000FFFFFFFFFFFFFULL;
    s32 e = ((s32)(v >> 52)) & 0x7FF;
    o->sign = v >> 63;
    if (e == 0) {
        o->cls = 2;
    } else if (e == 0x7FF) {
        o->exp = 0x3FF;
        if (frac == 0) {
            o->cls = 4;
            o->frac = 0x1000000000000000ULL;
        } else {
            if (frac & 0x0008000000000000ULL)
                o->cls = 1;
            else
                o->cls = 0;
            o->frac = frac;
        }
    } else {
        o->frac = (frac << 8) | 0x1000000000000000ULL;
        o->cls = 3;
        o->exp = e - 0x3FF;
    }
}

s32 func_003F99F0(u8 *p, s32 n, u16 *o0, u8 *o1, s8 *o3, s8 *o2, u8 *o4, u32 *o5, u32 *o6, s32 *o7)
{
    if (n < 0x10)
        return -1;
    if ((p[1] | (p[0] << 8)) != 0x8000)
        return -2;
    *o0 = ((p[2] << 8) | p[3]) + 4;
    *o1 = p[4];
    *o2 = p[5];
    *o3 = p[6];
    *o4 = p[7];
    *o5 = (p[8] << 24) | (p[9] << 16) | (p[10] << 8) | p[11];
    *o6 = (p[12] << 24) | (p[13] << 16) | (p[14] << 8) | p[15];
    if (*o3 == 0)
        *o7 = 0;
    else
        *o7 = (*o2 * 8 - 16) / *o3;
    return 0;
}

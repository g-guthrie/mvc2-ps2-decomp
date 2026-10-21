typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_004F7FC8[];
extern u8 D_0045DA40[];
typedef struct { f32 x, y, z; } V3;

s32 func_001673D0(u8 *p, s32 b)
{
    extern s32 func_0016B250(u8 *, s32);
    extern s32 func_0016B360(u8 *, s32);
    extern void func_0016B0C0(u8 *, s32, s32);
    u16 v;
    if (func_0016B250(p, 2) == 0) return 0;
    if (func_0016B360(p, b) == 0) return 0;
    func_0016B0C0(p, b, 0);
    func_0016B0C0(p, b, 1);
    v = (*(s32 *)(p + 0x4C8) != 0) ? 0x20 : 0x40;
    if (*(s16 *)(p + 0x4C2) & v) *(u16 *)(p + 0x4C2) = v;
    else *(u16 *)(p + 0x4F0) = v;
    return 0;
}

s32 func_0037B300(u8 *a, u8 *b, s32 *c)
{
    extern void func_00178F20(u8 *, u8 *);
    extern void func_0037B420(u8 *, s32);
    u8 *s0;
    s16 t;
    if (*c != 0) {
        b[0x1FE] = 1;
        s0 = *(u8 **)(a + 0x1DC);
        if (*(s16 *)(s0 + 0x434) == 0 || (*(s8 *)(s0 + 0x1B3) != 0 && s0[5] == 3)) {
            *c = 0;
            b[0x1FE] = 0;
        } else {
            func_00178F20(a, s0);
            *(f32 *)(s0 + 0x38) = ((f32 *)c)[1];
            func_0037B420(a, *(u8 *)c);
            t = *(s16 *)(a + 0x1C) - 1;
            *(s16 *)(a + 0x1C) = t;
            if (t < 0) {
                s0[0x20A] = 7;
                *c = 0;
                b[0x1FE] = 0;
            }
        }
    }
    return *c;
}

void func_001C5390(u8 *a)
{
    extern void func_001C54A0(u8 *, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_00176160(u8 *, s32, s32, s32);
    func_001C54A0(a, 3);
    func_001C54A0(a, 7);
    func_001C54A0(a, 11);
    func_001C54A0(a, 15);
    func_001C54A0(a, 1);
    func_001C54A0(a, 5);
    func_001C54A0(a, 9);
    func_001C54A0(a, 13);
    func_001C54A0(a, 2);
    func_001C54A0(a, 6);
    func_001C54A0(a, 10);
    func_001C54A0(a, 14);
    func_001C54A0(a, 0);
    func_001C54A0(a, 4);
    func_001C54A0(a, 8);
    func_001C54A0(a, 12);
    func_001E3210(a, 0x20);
    func_00176160(a, 2, a[0x25] * 0x57 + 1, 1);
}

u8 func_001893E0(u8 *a, u8 *b, u8 *c)
{
    extern void func_0018A920(u8 *, u8 *);
    extern u8 func_0018A460(u8 *, u8 *, u8 *, u16);
    extern u8 func_00189500(u8 *, u8 *, u8 *);
    s8 t;
    u32 n;
    t = *(s8 *)(c + 1) - 1;
    *(s8 *)(c + 1) = t;
    if (t <= 0) {
        return c[0] = 0;
    }
    if ((*(u16 *)(a + 0x35E) & 0x3C00) == *(u16 *)((c[2] << 1) + (u32)b + 8)) {
        func_0018A920(a, c);
        n = c[2] + 1;
        c[2] = n;
        if ((u8)n == *(u16 *)b) {
            if (*(u16 *)(b + 2) & 0x80) {
                return func_0018A460(a, b, c, *(u16 *)(a + 0x35E));
            }
            c[0] = 2;
            c[1] = D_004F7FC8[a[2]] * 10 + 15;
            return func_00189500(a, b, c);
        }
    }
    return 0;
}

void func_0031E3E0(u8 *a)
{
    extern s8 func_00175700(u8 *);
    extern void func_0031E710(u8 *);
    extern void func_0031E770(u8 *);
    extern void func_0031E950(u8 *);
    extern void func_00184540(u8 *);
    u8 *s0;
    u16 v, idx;
    u8 t;
    s0 = a + 0x2B8;
    if (func_00175700(a) < 0) {
        if (s0[1] != 0) {
            v = *(s16 *)(a + 0x354) & 0x3C00;
            if (v != 0) {
                idx = (u32)v >> 10;
                if (a[0x1E6] != 0) idx += 16;
                t = D_0045DA40[idx];
                if (t != 0) {
                    a[0x22] = t - 1;
                    a[0x20D] = 2;
                    a[7] = 0;
                    s0[0] = 1;
                    s0[1] = 0;
                    func_0031E710(a);
                    func_0031E770(a);
                    func_0031E950(a);
                    return;
                }
            }
        }
        *(s32 *)(a + 0x5C) = 0;
        *(s32 *)(a + 0x60) = 0;
        *(s32 *)(a + 0x68) = 0;
        *(s32 *)(a + 0x6C) = 0;
        a[0x1E9] = 1;
        *(s8 *)(a + 0x1E7) = -1;
        func_00184540(a);
    } else {
        v = *(s16 *)(a + 0x354) & 0x360;
        if (v != 0) s0[1] = 1;
    }
}

s32 func_00169470(u8 *a, s32 n)
{
    extern u8 *func_0016A3F0(u8 *);
    extern s32 func_0016A130(u8 *, s32, s32);
    extern s32 func_0016A1F0(u8 *, s32);
    u8 *o;
    u8 t, u;
    if (n > 3) return 0;
    if (a[0x215] == 0 && a[0x20D] != 2 && (o = func_0016A3F0(a)) != 0) {
        if (o == *(u8 **)(a + 0x4CC) && (o[0x1B5] & 0x7F) == a[0x4B4]) return 1;
        t = o[3];
        if (t == 1 || t == 3) {
            *(u8 **)(a + 0x4CC) = o;
            a[0x4B4] = *(s8 *)(o + 0x1B5) & 0x7F;
            return func_0016A130(a, 0xD, 3);
        }
        if (t == 0) {
            u = o[0x1E4];
            if (u == 0x14 || u == 0x15) {
                *(u8 **)(a + 0x4CC) = o;
                a[0x4B4] = *(s8 *)(o + 0x1B5) & 0x7F;
                return func_0016A130(a, 0xD, 3);
            }
        }
    }
    *(s32 *)(a + 0x4CC) = 0;
    a[0x4B4] = 0xFF;
    return func_0016A1F0(a, 0xD);
}

void func_0035BB00(u8 *a, u8 *b)
{
    extern void func_00182C30(u8 *, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_0019FC30(u8 *, s32);
    extern void func_00175700();
    u8 *s0;
    u8 *p;
    u32 i;
    b = (u8 *)((s32)b + 0x2B8);
    s0 = *(u8 **)(a + 0x14);
    s0[0x1FF] = 2;
    *(V3 *)(a + 0x34) = *(V3 *)(s0 + 0x34);
    if (*(u8 **)(*(u8 **)(a + 0x1E0) + 0x1E0) != a) {
        a[5]++;
        *(u16 *)(a + 0x1C) = 0;
        func_00182C30(s0, 8);
        return;
    }
    i = a[0x23];
    if (*(s8 *)(s0 + 0x1B3) != 0) {
        a[5] = 3;
        p = (u8 *)(i + (s32)b);
        *(u16 *)(a + 0x1C) = 0;
        p[1] &= 0xFD;
        p[1] |= 0x80;
        if (*(s16 *)(s0 + 0x434) == 0) s0[0x20A] = 7;
        else s0[0x20A] = 0;
        func_001E3210(a, 0x23);
        func_0019FC30(a, a[0x22]);
    } else {
        func_00175700();
        if (*(s8 *)(a + 0x151) != 0) {
            a[5]++;
            s0[0x13C] = 0;
            func_00182C30(s0, 8);
        }
    }
}

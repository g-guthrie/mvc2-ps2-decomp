typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003B0470(u8 *p, s32 a1)
{
    extern void func_00175910();
    extern void func_00174910();
    extern void func_003B07D0();
    u32 t = p[7];
    s32 q;
    if (t == 0) {
        p[7] = t + 1;
        if (*(s16 *)(p + 0x140) != 0) {
            q = 0x10 - p[0x22] / 2;
        } else {
            q = p[0x22] / 2;
        }
        func_00175910(p, 0x17, 3, q & 0xF);
    } else {
        func_00174910(p, 0x2BC);
    }
    func_003B07D0(p, a1);
}

void func_001E8A50(void)
{
    extern void func_003DA650();
    func_003DA650(0x22);
    func_003DA650(0x24);
    func_003DA650(0x26);
    func_003DA650(0x28);
    func_003DA650(0x2B);
    func_003DA650(0x34);
    func_003DA650(0x13);
    func_003DA650(0x1B);
    func_003DA650(0x20);
    func_003DA650(0x21);
    func_003DA650(0x2A);
    func_003DA650(0x2C);
    func_003DA650(0x2D);
    func_003DA650(0x2E);
    func_003DA650(0x2F);
    func_003DA650(0x30);
    func_003DA650(0x31);
    func_003DA650(0x32);
    func_003DA650(0x33);
    func_003DA650(0x36);
}

void func_003A9430(u8 *p)
{
    extern void func_003A9280();
    extern void func_001757E0();
    extern void func_00175700();
    s16 v;
    u8 *q = *(u8 **)(p + 0x18);
    p[0x24] = *(s8 *)(q + 0x24);
    v = *(s16 *)(p + 0x1E);
    if (v != 0) {
        v = v - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v == 0) {
            if (p[0x20] < 4) func_003A9280(p, q);
        }
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[4];
        p[4] = t + 1;
        func_001757E0(p, 0x14, 3);
    } else {
        func_00175700(p);
    }
}

typedef struct { u8 p0[5]; u8 c5; u8 p6[0x2E]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; f32 p64; f32 f68; f32 f6c; } S396;
typedef struct { u8 p0[0x430]; f32 f430; } Q396;
void func_00396710(S396 *p, Q396 *q)
{
    extern void func_00175700();
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (!(q->f430 <= p->f38)) {
        u32 t = p->c5;
        p->c5 = t + 1;
        p->f38 = q->f430;
        p->f5c /= 2.0f;
        *(u32 *)((u8 *)p + 0x60) = 0x40092492;
    }
}

void func_00230DA0(u8 *p, u8 *q)
{
    extern s32 func_00185980();
    extern void func_00230D30();
    extern void func_00185770();
    u8 *s;
    u32 t;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    s = *(u8 **)(p + 0x1C4);
    if (func_00185980(p) == 0) {
        func_00230D30(p, q);
        return;
    }
    if (s[0x247] != 2) {
        func_00230D30(p, q);
        return;
    }
    *(u8 **)(q + 4) = s;
    t = p[6];
    p[6] = t + 1;
    p[7] = 0;
    p[0x20B] = 0xC5;
    func_00185770(p, s);
    p[0x201] = 2;
    p[0x209] = 2;
    *(u8 **)(s + 0x1C8) = p;
    *(s16 *)(s + 0x140) = *(s16 *)(p + 0x140);
    s[0x20A] = 0x11;
    s[0x20D] = 2;
    s[0x1B5] = 0x4C;
}

typedef struct { u8 p0[0x34]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; f32 p64; f32 f68; f32 f6c; } S1190;
typedef struct { u8 p0[4]; u8 c4; u8 p5[0x17]; s16 s1c; u8 p1e[0x16]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; f32 p64; f32 f68; f32 f6c; u8 p70[0x142]; s8 c192; s8 c193; } S1190X;
void func_003A1190(S1190X *p)
{
    extern s32 func_00175700();
    extern s32 func_00174240();
    extern void func_001E7F60();
    u32 t;
    s16 v;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    if (p->c192 != 0 || p->c193 != 0) {
        t = p->c4;
        p->c4 = t + 1;
        *((u8 *)p + 0x13C) = 0;
        return;
    }
    v = p->s1c;
    if (v != 0) {
        p->s1c = v - 1;
    } else if (func_00174240(p) == 0) {
        t = p->c4;
        p->c4 = t + 1;
        *((u8 *)p + 0x13C) = 0;
    }
    func_001E7F60(p);
}

void func_00205580(S1190 *p)
{
    extern void func_00175700();
    extern void func_001843A0();
    f32 *s0, *s1, *s2, *s3;
    s16 v;
    s3 = &p->f6c;
    s2 = &p->f68;
    s1 = &p->f60;
    s0 = &p->f5c;
    *((u8 *)p + 0x207) = 3;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    v = *(s16 *)((u8 *)p + 0x1C) - 1;
    *(s16 *)((u8 *)p + 0x1C) = v;
    if (v == 0) {
        *(u8 *)((s32)p + 0x207) = 0;
        *(u32 *)s0 = 0;
        *(u32 *)s1 = 0;
        *(u32 *)s2 = 0;
        *(u32 *)s3 = 0;
        func_001843A0(p);
    }
}

void func_00215920(u8 *p)
{
    extern void func_00212DE0();
    extern s8 func_00175700();
    extern void func_00175C00();
    extern void func_001E3240();
    extern void func_001843A0();
    u8 *s1;
    u8 *a;
    u32 t;
    p[0x2BC] = 0xFF;
    s1 = p + 0x2B8;
    if (p[7] == 0) func_00212DE0(p, s1);
    if (func_00175700(p) >= 0) {
        if (*(s8 *)(p + 0x151) != 2) {
            p[0x151] = 0;
            s1[4] = 0;
            t = p[7];
            p[7] = t + 1;
            func_00175C00(p, 0);
            a = *(u8 **)(p + 0x1DC);
            *(u8 **)(a + 0x1C8) = p;
            a[0x20A] = 1;
            a[0x1E6] = *(s8 *)(p + 0x1E6) ^ 1;
            a[0x1B5] = 0x25;
        }
    } else {
        func_00175C00(p, 0);
        func_001E3240(p, 0x1F);
        func_001E3240(p, 0x20);
        func_001843A0(p);
    }
}

void func_0026E4E0(S1190 *p)
{
    extern void func_00175700();
    extern void func_00175910();
    extern void func_00183d50();
    s16 v;
    u32 t;
    *((u8 *)p + 0x200) = 3;
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    v = *(s16 *)((u8 *)p + 0x1C) - 1;
    *(s16 *)((u8 *)p + 0x1C) = v;
    if (v < 0) {
        t = *((u8 *)p + 6);
        *((u8 *)p + 6) = t + 1;
        *(u32 *)((u8 *)p + 0x48) = 0;
        *((u8 *)p + 7) = 0;
        *((u8 *)p + 0x2B9) = 1;
        *(f32 *)((u8 *)p + 0x38) = *(f32 *)((u8 *)p + 0x430);
        *((u8 *)p + 0x20D) = 0;
        *(u32 *)((u8 *)p + 0x48) = 0;
        *(u32 *)((u8 *)p + 0x50) = 0x3F800000;
        *(u32 *)((u8 *)p + 0x54) = 0x3F800000;
        func_00175910(p, 0x15, 0xB, 5);
        func_00183d50(p);
    }
}

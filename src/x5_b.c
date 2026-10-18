typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void (*D_004C1BF8[2])();

void func_00360BD0(u8 *a, u8 *b) {
    if (*(u16 *)(b + 0x168) != *(u16 *)(a + 0xD0)) {
        u32 t = a[4];
        a[4] = t + 1;
        return;
    }
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24) + *(s8 *)(a + 0x31);
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + *(f32 *)(a + 0x60);
    D_004C1BF8[a[5]](a);
}

extern u8 *func_003DA750();
extern void func_0013B120();
extern u32 D_004402A0[];
extern s32 D_004C2830;
void func_0013B060(void) {
    s32 i = 0;
    s32 off = 0;
    s32 k;
    u32 t;
    while ((k = (u8)i) < 0x11) {
        u8 *o = func_003DA750(0, 6, 0);
        if (o == 0) break;
o[0x13C] = 1;
*(void **)(o + 0x10) = func_0013B120;
o[0x20] = i;
*(s32 *)(o + 0x34) = 0;
*(u32 *)(o + 0x38) = 0x43C80000;
*(s32 *)(o + 0x3C) = 0;
*(s32 *)(o + 0x40) = 0;
t = *(u32 *)((u32)D_004402A0 + off);
off += 4;
*(u32 *)(o + 0x44) = t;
*(s32 *)(o + 0x48) = 0;
*(s16 *)(o + 0xCC) = k + 0x86;
*(s32 *)(o + 0x84) = D_004C2830;
*(s32 *)(o + 0xD0) = 0x805;
i = (u8)(i + 1);
    }
}

typedef struct { u8 pad[0x18]; s8 f18; u8 pad2[0xB6 - 0x19]; u8 fb6; } G7;
typedef struct { u16 flags; u8 pad[18]; } T7;
extern G7 *D_004C2840;
extern u8 D_004B5670[];
extern T7 D_004F4480[];
extern void func_003D7350();
extern void func_00173F90();
void func_00173EC0(u8 *p) {
    s32 v;
    G7 *g;
    if (*(s8 *)(p + 0x538) == 1) v = 0x78; else v = 0xC;
    func_003D7350((u8)v, D_004C2840->fb6, 0xB, D_004B5670);
    *(s16 *)(p + 0x4D4) = *(s16 *)(p + 0x4D4) - 1;
    if (*(s16 *)(p + 0x4D4) == 0 || (D_004F4480[*(s8 *)(p + 0x538) & 1].flags & 0x8000) != 0) {
        p[0x4D0] = 0;
        p[0x4D1] = 0;
        *(s16 *)(p + 0x4D4) = 0;
        *(s16 *)(p + 0x4D6) = 0;
        func_00173F90(p);
        g = D_004C2840;
        g->f18 -= *(s8 *)(p + 0x4DC);
    }
}

extern s16 D_004C27A4;
extern u8 *func_003DA750();
extern void func_001A26E0();
s32 func_001A2610(u32 a, s32 n, u32 c) {
    u8 *first;
    s32 i;
    u8 *o;
    if (D_004C27A4 <= n) return 0;
    if (n > 12) n = 12;
    i = 0;
    if (i < n)
    do {
            o = func_003DA750(0, 3, 1);
            if (o != 0) {
                *(s16 *)(o + 0x26) = 0xC06;
                o[0x23] = i;
                o[0x20] = c;
                *(s16 *)(o + 0x1E) = n;
                *(void **)(o + 0x10) = func_001A26E0;
                *(u32 *)(o + 0x18) = a;
                if (i == 0) first = o;
            }
            i++;
    } while (i < n);
    *(u8 **)(first + 0x14) = o;
    return i;
}

extern u16 *D_004C29DC;
extern void func_00395890();
extern s8 func_00175700();
void func_00394CD0(u8 *p) {
    s32 t;
    s8 v;
    s8 w;
    u16 a = *D_004C29DC;
    if (a != *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
        func_00395890(p);
        return;
    }
    p[0x24] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    p[0x13C] = 0;
    t = (s8)(*(s8 *)(*(u8 **)(p + 0x18) + 0x161) & ~1);
    v = t;
    if (t != 0) {
        if (v < 0) {
            func_00395890(p);
            return;
        }
        p[0x13C] = 1;
        goto test;
        do {
            func_00175700(p);
test:
            asm { nop }
            w = *(volatile s8 *)(p + 0x161);
            asm { nop; nop; nop }
        } while (v != w);
    }
}

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } GE;
extern GE *D_004C2794;
extern s8 func_00175700();
extern s32 func_001843A0();
s32 func_001FD430(u8 *p) {
    s8 r;
    switch (p[0x1FC]) {
    case 0:
        r = func_00175700(p);
        if (r < 0) {
            return func_001843A0(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            p[0x1B5] = 0x1B;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
        break;
    case 1:
    case 2:
        r = func_00175700(p);
        if (r < 0) return func_001843A0(p);
        break;
    }
}

extern u16 *D_004C26E8;
extern void func_001B93D0();
extern s8 func_00175670();
extern void func_001754A0();
void func_001B9290(u8 *p) {
    u16 a = *D_004C26E8;
    u32 t;
    if (a != *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
        func_001B93D0(p);
        return;
    }
    if (func_00175670(p) < 0) p[0x13C] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s8 *)(*(u8 **)(p + 0x18) + 0x150) == 1) {
        t = p[4];
        p[4] = t + 1;
        *(s8 *)(*(u8 **)(p + 0x18) + 0x150) = 0;
        func_001754A0(p, 0x1B, 0xF);
        p[0x13C] = 1;
    }
}

extern f32 D_004B4290[];
extern s32 D_004C2838;
void func_00163CD0(u8 *p) {
    f32 *t;
    u32 i;
    t = D_004B4290;
    i = p[5];
    t += i;
    *(s16 *)(p + 0xCC) = i + 0x58;
    *(s32 *)(p + 0x84) = D_004C2838;
    *(f32 *)(p + 0x78) = *t;
    *(f32 *)(p + 0x7C) = *t;
    *(f32 *)(p + 0x80) = *t;
    {
        u32 u = p[5];
        p[5] = u + 1;
        if ((u8)(u + 1) > 6) {
            u32 w = p[4];
            p[4] = w + 1;
        }
    }
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u32 w; u8 pad[20]; } E24;
typedef struct { u8 pad[4]; s8 f4; u8 pad1; s8 f6; } G40;
extern G40 *D_004C2840;
extern s32 D_004C27FC[1];
extern E24 D_004F7D44[];
extern E24 D_004D1584[];
extern E24 D_004F7D40[];
extern E24 D_004D1580[];

void func_00150210(u8 *p) {
    extern void func_0014E770(u8 *);
    extern s32 func_001503E0(u8 *, s32);
    u32 sh;
    u32 w;
    s32 n;
    s32 nib;
    func_0014E770(p);
    n = p[0x23];
    if (n >= 8) {
        sh = ((n - 8) * 4) & 0xFF;
        if (D_004C2840->f4 == 0) w = D_004F7D44[D_004C2840->f6 + *(s16 *)(p + 0x1E)].w;
        else w = D_004D1584[D_004C2840->f6 + *(s16 *)(p + 0x1E)].w;
            w >>= (sh & 0xFF); nib = w & 0xF;
        p[0x13C] = 1;
        p[0x13C] = *(s8 *)(*(u8 **)(p + 0x18) + 0x13C);
        if (nib == 0) {
            if (func_001503E0(p, p[0x23]) == 0) p[0x13C] = 0;
        }
        *(s16 *)(p + 0xCC) = nib + 0x25;
        *(s32 *)(p + 0x84) = *D_004C27FC;

    } else {
        sh = (n * 4) & 0xFF;
        if (D_004C2840->f4 == 0) w = D_004F7D40[D_004C2840->f6 + *(s16 *)(p + 0x1E)].w;
        else w = D_004D1580[D_004C2840->f6 + *(s16 *)(p + 0x1E)].w;
            w >>= (sh & 0xFF); nib = w & 0xF;
        p[0x13C] = 1;
        p[0x13C] = *(s8 *)(*(u8 **)(p + 0x18) + 0x13C);
        if (nib == 0) {
            if (func_001503E0(p, p[0x23]) == 0) p[0x13C] = 0;
        }
        *(s16 *)(p + 0xCC) = nib + 0x25;
        *(s32 *)(p + 0x84) = *D_004C27FC;

    }
    *(f32 *)(p + 0x74) = *(f32 *)(*(u8 **)(p + 0x18) + 0x74);
}

typedef struct { s32 x[16]; } S64;
extern s32 D_004C2B38;
extern s32 D_004C2B40;
extern S64 *D_004C2B48;
extern f32 D_006327B0[];
extern f32 D_006327B4[];
extern f32 D_006327B8[];
extern f32 D_006327BC[];
extern f32 D_006327C0[];
extern f32 D_006327C4[];
extern f32 D_006327C8[];
extern f32 D_006327CC[];
extern f32 D_006327D0[];
extern f32 D_006327D4[];
extern f32 D_006327D8[];
extern f32 D_006327DC[];
extern f32 D_006327E0[];
extern f32 D_006327E4[];
extern f32 D_006327E8[];
extern f32 D_006327EC[];
void func_00416F80(f32 *s) {
    if (s != 0) {
        D_006327B0[D_004C2B40 * 16] = s[0];
        D_006327B4[D_004C2B40 * 16] = s[1];
        D_006327B8[D_004C2B40 * 16] = s[2];
        D_006327BC[D_004C2B40 * 16] = s[3];
        D_006327C0[D_004C2B40 * 16] = s[4];
        D_006327C4[D_004C2B40 * 16] = s[5];
        D_006327C8[D_004C2B40 * 16] = s[6];
        D_006327CC[D_004C2B40 * 16] = s[7];
        D_006327D0[D_004C2B40 * 16] = s[8];
        D_006327D4[D_004C2B40 * 16] = s[9];
        D_006327D8[D_004C2B40 * 16] = s[10];
        D_006327DC[D_004C2B40 * 16] = s[11];
        D_006327E0[D_004C2B40 * 16] = s[12];
        D_006327E4[D_004C2B40 * 16] = s[13];
        D_006327E8[D_004C2B40 * 16] = s[14];
        D_006327EC[D_004C2B40 * 16] = s[15];
        D_004C2B48[D_004C2B38] = *(S64 *)&D_006327B0[D_004C2B40 * 16];
    }
    *(S64 *)&D_006327B0[D_004C2B40 * 16] = D_004C2B48[D_004C2B38];
}

typedef struct { u8 pad0[0x34]; f32 f34, f38; u8 pad1[0x20]; f32 f5c, f60; u8 pad2[4]; f32 f68, f6c; } F3b;
extern u8 D_004BFC28[8];
extern u8 D_004BFC29[8];

void func_001F3BB0(u8 *p) {
    extern s32 func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001266A0(u8 *, s32, s32);
    u8 *s0;
    u8 *q;
    s0 = p + 0x2B8;
    ((F3b *)p)->f34 += ((F3b *)p)->f5c;
    ((F3b *)p)->f5c += ((F3b *)p)->f68;
    ((F3b *)p)->f38 += ((F3b *)p)->f60;
    ((F3b *)p)->f60 += ((F3b *)p)->f6c;
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        *(u32 *)((s32)p + 0x5C) = 0x40D55555;
        *(u32 *)((s32)p + 0x68) = 0xBDD55555;
        *(u32 *)((s32)p + 0x60) = 0x419A4924;
        *(u32 *)((s32)p + 0x6C) = 0xBF2B6DB6;
        if (p[0x1E6] != 0) {
            *(volatile f32 *)(p + 0x5C) = -*(volatile f32 *)(p + 0x5C);
            *(volatile f32 *)(p + 0x68) = -*(volatile f32 *)(p + 0x68);
        }
        func_001757E0(p, 0xF, 0x21);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_001266A0(p, 0, 0);
        q = *(u8 **)(p + 0x1DC);
        q[0x20A] = D_004BFC28[(*(s8 *)(s0 + 2) / 4) * 2];
        q[0x1B5] = D_004BFC29[(*(s8 *)(s0 + 2) / 4) * 2];
        p[0x1B5] = D_004BFC29[(*(s8 *)(s0 + 2) / 4) * 2];
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[0x219] = *(s8 *)(s0 + 2) / 2 + 0x20;
    }
}

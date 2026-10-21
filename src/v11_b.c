typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C2818;
extern s32 D_004C27D8;
extern s16 D_004B1D00[];
extern f32 D_00440910[];
extern f32 D_00440914[];
extern f32 D_00440918[];

void func_0013FCE0(s32 n) {
    extern u8 *func_003DA750();
    extern void func_0013FDA0();
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(u32 *)(o + 0x10) = (u32)func_0013FDA0;
        if (n != 0) {
            *(s16 *)(o + 0xCC) = *(s16 *)((u32)D_004B1D00 + (n << 2));
            *(s32 *)(o + 0x84) = D_004C2818;
            *(u32 *)(o + 0xD0) = 0x800820;
        } else {
            *(s16 *)(o + 0xCC) = 0;
            *(s32 *)(o + 0x84) = D_004C27D8;
            *(u32 *)(o + 0xD0) = 0x821;
            *(f32 *)(o + 0x34) = D_00440910[0];
            *(f32 *)(o + 0x38) = D_00440914[0];
            *(f32 *)(o + 0x3C) = D_00440918[0];
        }
        o[0x20] = n;
        *(u32 *)(o + 0x74) = 0;
    }
}


extern s32 D_004C283C;
extern s32 D_0045ED80[];
extern s32 D_0045ED20[8][3];


typedef struct { u8 *a, *b, *c; } E3;
typedef struct { u8 pad[0x18]; E3 t[2]; u8 pad2[0x7C - 0x30]; s16 h[8]; } G;
extern G *D_004C2794;
extern s16 D_004C278C;

void func_001332D0(u8 *p) {
    extern void func_003DAA40();
    u8 *q;
    u32 t;
    s16 v;
    q = *(u8 **)(p + 0x18);
    if (p[7] == (t = q[0x425])) {
        p[7] = t;
        if (t != 0 && q[0] == 0) {
            p[0x13C] = 0;
            if (*(u8 *)(D_004C2794->t[q[2] ^ 1].a + 0x28B) != 0) return;
            if (*(u8 *)(D_004C2794->t[q[2] ^ 1].b + 0x28B) != 0) return;
            if (*(u8 *)(D_004C2794->t[q[2] ^ 1].c + 0x28B) != 0) return;
            if (D_004C278C >= 0) p[0x13C] = 1;
            v = *(s16 *)(p + 0x1E) - 1;
            *(s16 *)(p + 0x1E) = v;
            if (v > 0) return;
        }
    }
    p[0x13C] = 0;
    func_003DAA40(p);
}

void func_0022F1E0(u8 *p) {
    if (p[0x269] == 3) {
        p[0x1B5] = 0x44;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->h[p[2]] += 1;
    } else {
        p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x44;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->h[p[2]] += 1;
    }
    if (p[0x20D] == 2) {
        p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x48;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->h[p[2]] += 1;
    }
}

extern s16 *D_004C298C;


extern s16 D_004C27A4;

s32 func_001A5D80(u8 *a, s32 n, s32 c) {
    extern u8 *func_003DA750();
    extern void func_001A5E50();
    u8 *o;
    u8 *s0;
    s32 i;
    if (D_004C27A4 <= n) return 0;
    if (n > 12) n = 12;
    i = 0;
    if (i < n) do {
        if ((o = func_003DA750(0, 3, 1)) != 0) {
            *(s16 *)(o + 0x26) = 0xE05;
            o[0x23] = i;
            o[0x20] = c;
            *(s16 *)(o + 0x1E) = n;
            *(u32 *)(o + 0x10) = (u32)func_001A5E50;
            *(u8 **)(o + 0x18) = a;
            if (i == 0) s0 = o;
        }
        i++;
    } while (i < n);
    *(u8 **)(s0 + 0x14) = o;
    return i;
}

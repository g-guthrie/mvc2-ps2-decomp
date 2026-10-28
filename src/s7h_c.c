typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x1C]; u32 f1C; } G_f;
typedef struct { u8 pad[0x2B8]; s16 m[8]; } M_f;
extern u8 D_004D18E6[];
extern f32 D_004F1FC8[];
extern u8 D_00458C70[];
extern u8 D_004C0C80[8];
extern G_f *D_004C2840;

static void func_002AD770(u8 *p) {
    u8 *q = p + 0x2B8;
    u16 *r = (u16 *)(q + 4);
    u16 st = *(u16 *)(p + 0x2BC);
    switch (st) {
    case 0:
        if (*(u16 *)(p + 0x4F4) & 0x2000) *r = st + 1;
        break;
    case 1:
        if (*(u16 *)(p + 0x4F0) & 0x3C00) *r = st + 1;
        break;
    case 2:
        if (*(u16 *)(p + 0x4F4) & 0x1000) *r = st + 1;
        break;
    case 3:
        if (*(u16 *)(p + 0x4F0) & 0x3C00) {
            *r = 0;
            *(u16 *)(q + 8) = 1;
        }
        break;
    }
}

void func_002AD820(u8 *p)
{
    extern s32 func_003D92F0();
    extern void func_001843A0(u8 *);
    extern s32 func_00174170();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_001CCB70(u8 *, s32);
    extern void func_003958B0(u8 *, s32);
    s32 st;
    u32 t;
    u32 h;
    u32 k;
    s16 w;
    f32 f0, f1;
    s16 *m;
    s16 *q;

    if (func_003D92F0() != 0) {
        func_001843A0(p);
        return;
    }
    if (p[6] == 0) {
        t = p[6];
        p[6] = t + 1;
        if (p[0x20] == 0) {
            if (D_004D18E6[0] != 0) {
                h = (u16)(*(s16 *)(p + 0x4F0) & 0x360);
                if (h != 0) {
                    k = h & 0xFFFF;
                    if (k & 0x200) st = 0;
                    if (k & 0x100) st = 1;
                    if ((k & 0x300) == 0x300) st = 2;
                    if (k & 0x40) st = 3;
                    if (k & 0x20) st = 4;
                    if ((k & 0x60) == 0x60) st = 5;
                    p[7] = st;
                } else {
                    p[7] = D_00458C70[func_00174170() & 0xF];
                }
                if (p[7] == 5 && D_004D18E6[0] != 0) {
                    f1 = 320.0f;
                    f0 = D_004F1FC8[0];
                    f0 = f1 + f0;
                    if (!(*(f32 *)(p + 0x34) < f0)) {
                        p[0x1E6] = *(s16 *)(p + 0x140) = 0;
                    } else {
                        p[0x1E6] = *(s16 *)(p + 0x140) = 1;
                    }
                    if ((D_004C2840->f1C & 1) != 0) {
                        p[7] = 6;
                        w = *(s16 *)(p + 0x140) ^ 1;
                        *(s16 *)(p + 0x140) = w;
                        p[0x1E6] = w;
                    }
                }
            } else {
                p[7] = 3;
            }
            switch (p[7]) {
            case 0:
                *(s16 *)(p + 0x1C) = 0;
                func_00176160(p, 1, 2, 1);
                func_001757E0(p, 0x13, p[7]);
                func_001CCB70(p, 0);
                break;
            case 1:
            case 2:
            case 3:
            case 4:
                *(s16 *)(p + 0x1C) = 0;
                *(s16 *)(p + 0x2C0) = 0;
                *(s16 *)(p + 0x2BE) = 0;
                *(s16 *)(p + 0x2BC) = 0;
                func_001757E0(p, 0x13, p[7]);
                break;
            case 5:
                *(s16 *)(p + 0x2C2) = 0;
                func_001CCB70(p, 4);
                func_00176160(p, 1, (p[0x25] << 1) + 8, 2);
                break;
            case 6:
                func_001CCB70(p, 5);
                *(s16 *)(p + 0x2C4) = 0;
                func_00176160(p, 1, (p[0x25] << 1) + 8, 2);
                func_001757E0(p, 0x13, 0xC);
                break;
            }
        } else {
            func_001757E0(p, 0x13, D_004C0C80[p[0x20]]);
        }
    } else {
        if (p[0x20] == 0) {
            if (p[7] == 5) {
                p[0x33A] = 0xFF;
                q = (s16 *)((u8 *)((M_f *)p)->m + 5 * 2);
                if (*(u16 *)(p + 0x2C2) != 0) {
                    *q = 0;
                    func_001757E0(p, 0x13, 3);
                }
                func_00175700(p);
            } else if (p[7] == 6) {
                p[0x33A] = 0xFF;
                q = (s16 *)((u8 *)((M_f *)p)->m + 6 * 2);
                if (*(u16 *)(p + 0x2C4) != 0) {
                    *q = 0;
                    func_001757E0(p, 0x13, 0xD);
                }
                func_00175700(p);
            } else {
                func_00175700(p);
                if (*(s16 *)(p + 0x1C) != 0) p[0x33A] = 0xFF;
                func_002AD770(p);
                if (*(s8 *)(p + 0x151) != 0) {
                    *(s16 *)(p + 0x1C) = 1;
                    p[0x151] = 0;
                    if (*(u16 *)(p + 0x2C0) != 0) func_003958B0(p, 3);
                    else func_003958B0(p, 2);
                }
            }
        } else {
            func_00175700(p);
        }
    }
}

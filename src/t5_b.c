typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { V3 a; V3 b; f32 pad; } E28;
typedef struct { f32 f[4]; } V4;
typedef struct { u8 pad[8]; s16 idx; } G;
typedef struct { u8 *a; s32 b; } PS;
extern void func_001757E0(u8 *, int, int);
extern G *D_004C2840;
extern u32 D_004C2804;
extern E28 D_00442B50[];
extern V4 D_004439B0;
extern u32 D_00446CE0[];
extern void func_0018C970(u8 *);
extern u32 func_002810D0(u8 *);
extern s32 func_00280750(u8 *);
extern void func_00280D80(u8 *);
extern u32 func_00280AE0(u8 *, u32);
extern u32 D_00455470[];
extern u8 *D_004C2808;
extern u8 *D_004C283C;
extern void func_003DAA40(void);
extern void func_001444D0();
extern void func_00170E60(s32 a, s32 b, s32 c, s32 d, void *e, u8 *f);
extern void func_001446F0();
extern void func_0033D190();
extern u8 *func_003DA750(int, int, int);
extern void func_003447E0(u8 *);
extern void func_003BA360();
extern V3 D_00460D60[];

void func_00147F50(u8 *p) {
    E28 *e;
    p[4]++;
    p[0x13C] = 1;
    e = &D_00442B50[D_004C2840->idx];
    *(s16*)(p+0xCC) = 0x57;
    *(u32*)(p+0x84) = D_004C2804;
    *(V3*)(p+0x34) = e->a;
    *(V3*)(p+0x50) = e->b;
    *(u32*)(p+0xD0) |= 0x800420;
    *(V4*)(p+0x74) = D_004439B0;
    *(s32*)(p+0xD8) = D_004C2840->idx;
}

void func_00280600(u8 *p) {
    switch (p[0x451]) {
    case 0:
        p[0x451]++;
        *(u32*)(p+0x47C) = func_002810D0(p);
    case 1:
        p[0x451]++;
        if (func_00280750(p) != 0) *(u32*)(p+0x47C) = func_002810D0(p);
        func_00280D80(p);
        *(u32*)(p+0x47C) = func_00280AE0(p, *(u32*)(p+0x47C));
        break;
    case 2:
        ((void (*)(u8 *))D_00455470[p[0x454]])(p);
        break;
    }
}

void func_0033D0D0(u8 *p) {
    PS s;
    u8 *q;
    switch (p[4]) {
    case 0:
        if (*(u8*)(*(u8**)(p+0x14)+5) != 0) p[4]++;
        break;
    case 1:
        *(s16*)(p+0x1C) += 1;
        if (*(s16*)(p+0x1C) >= 400) {
            *(s16*)(p+0x1C) = 0;
            p[4]++;
        } else {
            q = *(u8**)(p+0x84);
            func_00170E60(*(s32*)(D_004C283C+0x14), *(s32*)(*(u8**)(q+0x1C)+0x84), *(s32*)(q+0x14), ((s32*)*(u8**)(q+0x1C))[*(s16*)(p+0xCC)], (void*)func_0033D190, p);
        }
        break;
    case 2:
        break;
    }
}

void func_00344740(s32 idx) {
    u8 *o;
    if ((o = func_003DA750(0, 0x5B, 1)) != 0) {
        o[0x13C] = 1;
        *(u32*)(o+0x10) = (u32)func_003447E0;
        *(s16*)(o+0xCC) = idx + 6;
        *(u8**)(o+0x84) = D_004C283C;
        *(u32*)(o+0xD0) = 0x800989;
        *(V3*)(o+0x34) = D_00460D60[idx];
        o[0x20] = idx;
    }
}

void func_003BA2C0(u8 *p) {
    s32 i;
    u8 *o;
    i = 0;
    do {
        if ((o = func_003DA750(0, 1, 1)) != 0) {
            *(u32*)(o+0x10) = (u32)func_003BA360;
            *(f32*)(o+0x34) = *(f32*)(p+0x34);
            *(f32*)(o+0x38) = *(f32*)(p+0x38);
            *(s32*)(o+0x18) = *(s32*)(p+0x18);
            o[1] = p[1];
            *(s16*)(o+0x26) = 0x3504;
            o[0x20] = 9;
            o[0x21] = i;
            *(s32*)(o+0xD0) = *(s32*)(p+0xD0);
            *(u8**)(o+0x14) = p;
        }
        i++;
    } while (i < 8);
}


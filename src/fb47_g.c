typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad0[4]; s32 w4; s32 w8; s32 wC; s32 w10; s32 w14; } B40;
typedef struct {
    u32 flags;
    u8 pad4[8];
    s32 wC;
    u8 pad10[0xC];
    s32 w1C;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2C;
    u8 pad30[0xC];
    s32 w3C;
    B40 *w40;
    u8 pad44[0x2C];
    u8 b70[0x20];
    u8 padsp[0x170 - 0x90];
} O3F0500;

extern O3F0500 D_005BF2F0[];
extern s32 D_004C2AD4;
extern s32 D_004C2AA0;
extern s32 D_00478DF0[];
extern s32 D_0062BFC8[];
extern s32 D_0062BFC4[];
extern u8 D_0062BBA0[];

#define BLK_X \
    if (v & 2) { \
        s3 = func_003DD030(o->w20); \
    } else { \
        s3 = func_003DD160(o->w28 * D_00478DF0[o->w40->w14], 16); \
        func_003EF9A0(o->w28, o->w40->w14, s3, (u8 *)o + 0x50); \
        func_003F01B0(o, 0); \
    }

s32 func_003F0500(s32 idx)
{
    extern void func_003F0470();
    extern void func_003DC9C0(void);
    extern void func_003DD020(s32);
    extern s32 func_003DD030(s32);
    extern void func_003DD040(void);
    extern s32 func_003DD160(s32, s32);
    extern void func_003EE930(O3F0500 *, u8 *);
    extern s32 func_003EE8C0(O3F0500 *, u8 *);
    extern void func_003EF9A0(s32, s32, s32, u8 *);
    extern void func_003F01B0(O3F0500 *, s32);
    extern void func_003EA660(s32, u8 *);
    extern void func_003EFF10(s32, s32, s32, u8 *);
    extern void func_003DC2F0(u32, u8 *);
    extern void func_003F04D0(void);
    O3F0500 *o;
    s32 s1;
    u32 v;
    s32 i;
    u32 *e;
    s32 s3;
    u8 tmp[0x30];
    i = idx - 1;
    o = &D_005BF2F0[i];
    func_003F0470(i);
    v = o->flags;
    if ((v & 4) == 0) {
        if (o->wC != D_004C2AD4) {
            func_003DC9C0();
            o->wC = D_004C2AD4;
            if (o->w1C != 0)
                func_003DD020(o->w1C);
            if (o->w20 != 0)
                func_003DD020(o->w20);
            if (o->w24 != 0)
                func_003DD020(o->w24);
            func_003EE930(o, tmp);
            if (func_003EE8C0(o, tmp) == 0)
                return 0;
            func_003DD040();
            s3 = func_003DD160(o->w28 * D_00478DF0[o->w40->w14], 16);
            func_003EF9A0(o->w28, o->w40->w14, s3, (u8 *)o + 0x50);
            func_003F01B0(o, 0);
        } else {
            BLK_X
        }
    } else {
        BLK_X
    }
    if (o->w2C != 0) {
        func_003EA660(o->w2C, (u8 *)o + 0xF0);
        func_003EFF10(o->w28, o->w40->w14, s3, (u8 *)o + 0x70);
    }
    D_0062BFC8[0] = (u32)(o->w40->wC - o->w40->w8) >> 3;
    s1 = (*(s32 (**)(O3F0500 *, u32))((u8 *)o->w40 + 0x10))(o, (u32)(o->w40->w4 - o->w40->w8) >> 3);
    D_004C2AA0 = 0;
    if (D_0062BFC4[0] != o->w3C) {
        D_0062BFC4[0] = o->w3C;
        func_003DC2F0((u32)*(u32 *)o->w40 & 0xFFFFFFF, D_0062BBA0);
    }
    e = (u32 *)func_003DD160(16, 16);
    e[1] = 0;
    e[2] = 0;
    e[3] = 0;
    e[0] = s1;
    if (s3 != 0) {
        e[1] = func_003DD030(o->w20);
        e[2] = o->w28 * D_00478DF0[o->w40->w14];
        e[3] = s3;
    }
    func_003DC2F0(((u32)e & 0xFFFFFFF) | 0x20000000, D_0062BBA0);
    func_003F04D0();
    return 1;
}

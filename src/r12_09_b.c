/* func_003EC160 (flInitialize-style platform init): MW 3.0 (./try30.sh) "-O3,p -sdatathreshold 8". */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long u64;
typedef float f32;


typedef struct { u32 a:12; u32 b:11; u32 c:9; } BF12;
typedef struct { u32 fbp:9; u32 rest:23; } BF9;
typedef struct { u32 en:1; u32 rest:31; } BF1;

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    u32 f0C;
    u32 f10;
    s32 f14;
    u32 f18;
    s32 f1C;
    s32 f20;
    u32 f24;
    u32 f28;
    u32 f2C;
    f32 f30;
    u32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
    u8 pad44[0x50 - 0x44];
    u8 f50[0x68 - 0x50];
    BF12 r68;
    u8 pad6C[0x88 - 0x6C];
    BF9 r88;
    u8 pad8C[0xB0 - 0x8C];
    BF9 rB0;
    u8 padB4[0xC0 - 0xB4];
    BF9 rC0;
    u8 padC4[0x110 - 0xC4];
    BF1 r110;
    u8 pad114[0x130 - 0x114];
    BF9 r130;
    u8 pad134[0x140 - 0x134];
    BF9 r140;
    u8 pad144[0x190 - 0x144];
    BF1 r190;
    u8 pad194[0x1D0 - 0x194];
    u64 r1D0;
    u8 pad1D8[0x230 - 0x1D8];
    BF9 r230;
    u8 pad234[0x280 - 0x234];
    BF1 r280;
    u8 pad284[0x2B0 - 0x284];
    BF9 r2B0;
    u8 pad2B4[0x300 - 0x2B4];
    BF1 r300;
    u8 pad304[0x340 - 0x304];
    u64 r340;
    u8 pad348[0x380 - 0x348];
} GB;
extern GB D_0062BC00;
typedef struct {
    s32 f80;
    s32 f84;
    s32 f88;
    s32 f8C;
    s32 f90;
    u32 f94;
    u32 f98;
    s32 f9C[10];
    s32 fC4;
    s32 fC8;
    s32 fCC;
    s32 fD0;
} GB2;
extern GB2 D_0062BF80;

extern u8 D_0062C020[];
typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
    s32 f44;
} GC;
extern GC D_0062C040;
extern s32 D_0062BF9C[];
extern void *D_004C2B0C;
extern void *D_004C2B08;
extern s32 D_004C2AE4;
extern s32 D_004C2AE0;
extern s32 D_004C2AEC;
extern s32 D_004C2AD8;
extern s32 D_0062BBD0[];
extern s32 D_0062BBA0[];
extern u8 D_004BAA40[];
extern u8 D_004BAA70[];
extern u8 D_004BAA90[];
extern u8 D_004BAAB0[];
extern u8 D_004BAAD0[];
extern u8 D_004BAAF0[];
extern u8 D_004BAB10[];
extern u8 D_004BAB20[];
extern u8 D_004BAB40[];

#define fb_size(w, h, bw, bh) ((((w) + (bw) - 1) / (bw)) * (((h) + (bh) - 1) / (bh)) << 5)

s32 func_003EC160(void)
{
    extern void func_003DCD40(void *, s32, s32);
    extern s32 func_0011CB70(s32);
    extern void func_003F12C0(u8 *);
    extern void func_003F0940(u8 *, s32, s32, s32);
    extern s32 func_003DCFC0(s32);
    extern void func_003DB980(s32, s32, s32);
    extern void func_003DCF70();
    extern void func_0011CBC8();
    extern void func_003DD070(void);
    extern void func_00106628(s32);
    extern void func_0010AC48(void);
    extern void func_0010F3C8(s32);
    extern void func_0010F8A0(s32);
    extern s32 func_0010C098(u8 *);
    extern s32 func_0010C060(void);
    extern void func_00107E58(void);
    extern void func_003DCAD0(u8 *, s32, u8 *, s32);
    extern void func_00418C70(void);
    extern void func_00419EE0(void);
    extern void func_00418B50(void);
    extern void func_00100478(void);
    extern void func_001025A8(s32);
    extern s32 func_00102580(s32);
    extern void func_00103958(void);
    extern void func_003DC3C0();
    extern void func_003DC250(s32 *, s32, void (*)());
    extern void func_001002D8(s32, s32, s32, s32);
    extern void func_001020E0(u8 *, s16, s16, s16, s32, s16, s32);
    extern void func_003ED0D0(u8 *);
    extern void func_003EB900(void);
    extern void func_00418CC0(void);
    extern void func_00419F70(void);
    extern void func_00418B80(void);
    extern void func_003DAD60(void);
    extern void func_003ED000(void);
    extern s32 func_00100E68(s32);
    extern void func_003ECBE0();
    extern void func_00101D50(void (*)());
    extern void func_003DF7D0(void);
    s32 i;
    s32 h;
    s32 w;
    s32 m;
    u32 bw;
    s32 k1;
    s32 k10;
    s32 k31;
    s32 k5;

    func_003DCD40(&D_0062BC00, 0, 0x420);
    m = func_0011CB70(0x1600000);
    if (m == 0) {
        func_003F12C0(D_004BAA40);
        return 0;
    }
    func_003F0940(D_0062C020, m, 0x1600000, 0x40);
    D_0062BF80.fD0 = 0x600000;
    m = func_003DCFC0(D_0062BF80.fD0);
    D_0062BF80.fCC = m;
    func_003DB980(m, D_0062BF80.fD0, 0x10);
    D_004C2B0C = func_003DCF70;
    D_004C2B08 = func_0011CBC8;
    func_003DD070();
    D_0062BC00.f00 = 0;
    D_0062BC00.f04 = 4;
    D_0062BC00.f1C = 4;
    w = 0x280;
    if (D_0062BC00.f00 == 0) {
        w = 0x280;
        h = 0xE0;
    } else {
        h = 0x1C0;
    }
    D_0062BF80.f8C = 0;
    D_0062BF80.f90 = 0;
    switch (D_0062BC00.f04) {
    case 2:
        D_0062BC00.f08 = 2;
        D_0062BC00.f0C = 0x40;
        D_0062BC00.f10 = 0x40;
        break;
    case 3:
        D_0062BC00.f08 = 1;
        D_0062BC00.f0C = 0x40;
        D_0062BC00.f10 = 0x20;
        break;
    case 4:
    default:
        D_0062BC00.f08 = 0;
        D_0062BC00.f0C = 0x40;
        D_0062BC00.f10 = 0x20;
        break;
    }
    D_0062BC00.f14 = 0;
    if (D_0062BC00.f00 == 1) {
        D_0062BC00.f18 = 0;
    } else {
        D_0062BC00.f18 = fb_size(w, h, D_0062BC00.f0C, D_0062BC00.f10);
    }
    switch (D_0062BC00.f1C) {
    case 2:
        if (D_0062BC00.f04 == 2) {
            D_0062BC00.f20 = 0x32;
        } else {
            D_0062BC00.f20 = 0x3A;
        }
        D_0062BC00.f24 = 0x40;
        D_0062BC00.f28 = 0x40;
        D_0062BC00.f30 = 65535.0f;
        break;
    case 3:
        D_0062BC00.f20 = 0x31;
        D_0062BC00.f24 = 0x40;
        D_0062BC00.f28 = 0x20;
        D_0062BC00.f30 = 16777000.0f;
        break;
    case 4:
    default:
        if (D_0062BC00.f04 == 2) {
            D_0062BC00.f08 = 10;
        }
        D_0062BC00.f20 = 0x30;
        D_0062BC00.f24 = 0x40;
        D_0062BC00.f28 = 0x20;
        D_0062BC00.f30 = 16777000.0f;
        break;
    }
    D_004C2AE4 = w;
    D_004C2AE0 = h;
    D_0062BF80.f84 = 0x800 - (w >> 1);
    bw = D_0062BC00.f0C;
    D_0062BC00.f2C = D_0062BC00.f18 + fb_size(w, h, bw, D_0062BC00.f10);
    D_0062BF80.f88 = 0x800 - (h >> 1);
    D_0062BC00.f34 = D_0062BC00.f2C + fb_size(w, h, D_0062BC00.f24, D_0062BC00.f28);
    func_00106628(0);
    func_0010AC48();
    func_0010F3C8(0);
    func_0010F8A0(1);
    while (func_0010C098(D_004BAA70) == 0) {
        __asm__ volatile("nop;nop;nop;nop;nop;nop");
    }
    while (func_0010C060() == 0) {
        __asm__ volatile("nop;nop;nop;nop;nop;nop");
    }
    func_00106628(0);
    func_0010AC48();
    func_0010F3C8(0);
    func_0010F8A0(1);
    func_00107E58();
    func_003DCAD0(D_004BAA90, 0, 0, 0);
    func_003DCAD0(D_004BAAB0, 0, 0, 0);
    func_003DCAD0(D_004BAAD0, 0, 0, 0);
    func_003DCAD0(D_004BAAF0, 0, 0, 0);
    {
        u8 *c = D_004BAB10;
        u8 *a = D_004BAB20;
        func_003DCAD0(a, 0x11, c, 0);
    }
    func_00418C70();
    func_00419EE0();
    func_00418B50();
    func_00100478();
    func_001025A8(1);
    for (i = 0; i < 10; i++) {
        D_0062BF9C[i] = func_00102580(i);
    }
    func_00103958();
    {
        void (*f)();
        s32 *q;
        f = func_003DC3C0;
        D_0062BBD0[0] = 2;
        q = D_0062BBD0;
        func_003DC250(q, 0x400, f);
    }
    {
        void (*f)();
        s32 *q;
        f = func_003DC3C0;
        D_0062BBA0[0] = 1;
        q = D_0062BBA0;
        func_003DC250(q, 0xC00, f);
    }
    if (D_0062BC00.f00 == 0) {
        func_001002D8(0, 1, 2, 1);
    } else {
        func_001002D8(0, 1, 2, 0);
    }
    func_001020E0(D_0062BC00.f50, D_0062BC00.f08, w, h, 3, D_0062BC00.f20, 1);
    if (D_0062BC00.f00 == 2) {
        D_0062BC00.r88.fbp = D_0062BC00.f18 >> 5;
        D_0062BC00.rB0.fbp = D_0062BC00.f18 >> 5;
        D_0062BC00.r130.fbp = D_0062BC00.f18 >> 5;
        D_0062BC00.rC0.fbp = D_0062BC00.f2C >> 5;
        D_0062BC00.r140.fbp = D_0062BC00.f2C >> 5;
        D_0062BC00.r230.fbp = D_0062BC00.f2C >> 5;
        D_0062BC00.r2B0.fbp = D_0062BC00.f2C >> 5;
    }
    if (D_0062BC00.f04 == 2) {
        D_0062BC00.r110.en = 1;
        D_0062BC00.r190.en = 1;
        D_0062BC00.r280.en = 1;
        D_0062BC00.r300.en = 1;
    }
    *(u64 *)&D_0062BC00.r340 = 0;
    *(u64 *)&D_0062BC00.r1D0 = 0;
    D_0062C040.f08 = h;
    D_0062C040.f04 = w;
    D_0062C040.f10 = 0;
    D_0062C040.f00 = 0;
    D_0062BF80.f94 = D_0062BC00.r68.a;
    D_0062BF80.f98 = D_0062BC00.r68.b;
    D_0062C040.f14 = D_0062BC00.f04;
    D_0062C040.f0C = w * D_0062BC00.f04;
    switch (D_0062BC00.f04) {
    default:
        func_003ED0D0(D_004BAB40);
        break;
    case 2:
        k5 = 5;
        k10 = 10;
        k31 = 31;
        k1 = 1;
        D_0062C040.f1C = 0;
        D_0062C040.f18 = k5;
        D_0062C040.f34 = k10;
        D_0062C040.f20 = k31;
        D_0062C040.f28 = k5;
        D_0062C040.f40 = 15;
        D_0062C040.f30 = k5;
        D_0062C040.f24 = k5;
        D_0062C040.f38 = k31;
        D_0062C040.f2C = k31;
        D_0062C040.f3C = k1;
        D_0062C040.f44 = k1;
        break;
    case 3:
        D_0062C040.f3C = 0;
        D_0062C040.f18 = 8;
        D_0062C040.f34 = 16;
        D_0062C040.f20 = 255;
        D_0062C040.f24 = 8;
        D_0062C040.f28 = 8;
        D_0062C040.f30 = 8;
        D_0062C040.f2C = 255;
        D_0062C040.f38 = 255;
        D_0062C040.f40 = 0;
        D_0062C040.f44 = 0;
        D_0062C040.f1C = 0;
        break;
    case 4:
        D_0062C040.f1C = 0;
        D_0062C040.f18 = 8;
        D_0062C040.f34 = 16;
        D_0062C040.f20 = 255;
        D_0062C040.f40 = 24;
        D_0062C040.f24 = 8;
        D_0062C040.f28 = 8;
        D_0062C040.f2C = 255;
        D_0062C040.f30 = 8;
        D_0062C040.f3C = 8;
        D_0062C040.f38 = 255;
        D_0062C040.f44 = 255;
        break;
    }
    D_0062BC00.f3C = 0;
    D_0062BC00.f38 = 1;
    D_0062BC00.f40 = 0;
    func_003EB900();
    D_004C2AEC = 1;
    func_00418CC0();
    func_00419F70();
    func_00418B80();
    func_003DAD60();
    D_004C2AD8 = 0x64;
    func_003ED000();
    while ((D_0062BC00.f38 = func_00100E68(0)) != 0) {
        __asm__ volatile("nop;nop;nop;nop;nop;nop");
    }
    func_00101D50(func_003ECBE0);
    D_0062BF80.fC8 = 0;
    D_0062BF80.fC4 = -1;
    func_003DF7D0();
    *(volatile u32 *)0x10000810 = 0x80;
    *(volatile u32 *)0x10000800 = 0;
    return 1;
}

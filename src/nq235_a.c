typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_0062BBA0[];

typedef struct {
    s32 f0;
    s32 x;
    s32 y;
    s32 n;
    s32 addr;
    s32 v[13];
} TX;

s32 func_003EA130(u8 *e)
{
    extern s32 func_003DD030(s32);
    extern u32 func_003DB9C0(u32);
    extern void func_003F5630(s32, s32, s32);
    extern s32 func_003F5E60(TX *, TX *);
    extern void func_003EBD00(u8 *);
    extern s32 func_003DBD20(s32);
    extern s32 func_003DBD70(s32);
    extern u8 *func_003DD160(s32, s32);
    extern void func_003DBD80(u8 *pkt, s32 a1, u32 addr, u32 total, s16 p4, s16 p5, s32 p6, s16 p7, s16 p8, s16 p9, s16 p10);
    extern void func_003DC2F0(u32, u8 *);
    extern void func_003DC120(u8 *, s32);
    TX a;
    TX b;
    u8 *s0;
    s32 s1;
    s32 src;
    s32 t;

    s1 = 0;
    switch (*(s32 *)(e + 0x34) & 3) {
    case 0:
        if (*(s32 *)(e + 0x28) != 0) {
            t = func_003DD030(*(s32 *)(e + 0x28));
            src = *(s32 *)(e + 0x30);
            s1 = t;
        } else {
            t = func_003DB9C0(*(u32 *)(e + 8));
            src = *(s32 *)(e + 0x30);
            s1 = t;
        }
        a.f0 = *(s32 *)(e + 4);
        a.x = *(s16 *)(e + 0x18);
        a.y = *(s16 *)(e + 0x1A);
        a.addr = src;
        b.f0 = *(s32 *)(e + 4);
        b.x = *(s16 *)(e + 0x18);
        b.y = *(s16 *)(e + 0x1A);
        b.addr = t;
        switch (*(s32 *)(e + 0x1C)) {
        case 0x14:
        case 0x13:
            func_003F5630(t, src, *(s32 *)(e + 8));
            break;
        case 2:
            a.v[0] = 2; a.v[1] = 5; a.v[2] = 10; a.v[3] = 31;
            a.v[4] = 5; a.v[5] = 5; a.v[6] = 31; a.v[7] = 5;
            a.v[8] = 0; a.v[9] = 31; a.v[10] = 1; a.v[11] = 15; a.v[12] = 1;
            a.n = a.x * a.v[0];
            b.v[0] = 2; b.v[1] = 5; b.v[2] = 10; b.v[3] = 31;
            b.v[4] = 5; b.v[5] = 5; b.v[6] = 31; b.v[7] = 5;
            b.v[8] = 0; b.v[9] = 31; b.v[10] = 1; b.v[11] = 15; b.v[12] = 1;
            b.v[2] = 0; b.v[8] = 10; b.v[4] = 5; b.v[6] = 31;
            b.n = b.x * b.v[0];
            func_003F5E60(&b, &a);
            break;
        case 1:
            a.v[0] = 3; a.v[1] = 8; a.v[2] = 16; a.v[3] = 255;
            a.v[4] = 8; a.v[5] = 8; a.v[6] = 255; a.v[7] = 8;
            a.v[8] = 0; a.v[9] = 255; a.v[10] = 0; a.v[11] = 0; a.v[12] = 0;
            a.n = a.x * a.v[0];
            b.v[0] = 3; b.v[1] = 8; b.v[2] = 16; b.v[3] = 255;
            b.v[4] = 8; b.v[5] = 8; b.v[6] = 255; b.v[7] = 8;
            b.v[8] = 0; b.v[9] = 255; b.v[10] = 0; b.v[11] = 0; b.v[12] = 0;
            b.v[2] = 0; b.v[8] = 16;
            b.n = b.x * b.v[0];
            func_003F5E60(&b, &a);
            break;
        case 0:
            a.v[0] = 4; a.v[1] = 8; a.v[2] = 16; a.v[3] = 255;
            a.v[4] = 8; a.v[5] = 8; a.v[6] = 255; a.v[7] = 8;
            a.v[8] = 0; a.v[9] = 255; a.v[10] = 8; a.v[11] = 24; a.v[12] = 255;
            a.n = a.x * a.v[0];
            b.v[0] = 4; b.v[1] = 8; b.v[2] = 16; b.v[3] = 255;
            b.v[4] = 8; b.v[5] = 8; b.v[6] = 255; b.v[7] = 8;
            b.v[8] = 0; b.v[9] = 255; b.v[10] = 8; b.v[11] = 24; b.v[12] = 255;
            b.v[2] = 0; b.v[8] = 16;
            b.n = b.x * b.v[0];
            func_003F5E60(&b, &a);
            break;
        }
        break;
    case 1:
        if (*(s32 *)(e + 0x28) != 0) {
            s1 = func_003DD030(*(s32 *)(e + 0x28));
            func_003F5630(s1, *(s32 *)(e + 0x30), *(s32 *)(e + 8));
        } else {
            s1 = *(s32 *)(e + 0x30);
        }
        break;
    case 2:
        s1 = *(s32 *)(e + 0x30);
        break;
    case 3:
        s1 = *(s32 *)(e + 0x30);
        break;
    }
    *(s32 *)(e + 4) &= ~2;
    if (s1 != 0) {
    if (*(s32 *)e == 1 || *(s32 *)e == 4) {
        func_003EBD00(e);
        return 1;
    }
    s0 = func_003DD160(func_003DBD20(*(s32 *)(e + 8)), 0x10);
    if (*(s32 *)(e + 0x20) == 0) {
        func_003DBD80(s0, 1, s1, *(u32 *)(e + 8), *(s16 *)(e + 0x12), *(s16 *)(e + 0x18) / 64, *(s16 *)(e + 0x1C), 0, 0, *(s16 *)(e + 0x18), *(s16 *)(e + 0x1A));
    } else {
        func_003DBD80(s0, 1, s1, *(u32 *)(e + 8), *(s16 *)(e + 0x12), *(s16 *)(e + 0x24) / 64, 0, 0, 0, *(s16 *)(e + 0x24), *(s16 *)(e + 0x26));
    }
    func_003DC2F0(((u32)s0 & 0xFFFFFFF) | 0x10000000, D_0062BBA0);
    s0 = func_003DD160(func_003DBD70(*(s32 *)(e + 8)), 0x10);
    func_003DC120(s0, 1);
    func_003DC2F0((u32)s0 & 0xFFFFFFF, D_0062BBA0);
    }
    return 1;
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef float f32;

typedef struct { s32 f0; f32 f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30, f34, f38, f3C, f40; s32 f44; s32 f48; } EntA;
extern EntA D_0061B420[];
extern s32 D_004C2AAC;

void func_003EFA40(u8 *a0, s32 a1, s32 a2) {
    EntA *d = &D_0061B420[a2];
    extern u8 *func_003DBB90(u8 *, s32, s32);
    extern u8 *func_003DBB40(u8 *);
    extern void func_003F0070(s32, u8 *, u8 *);
    extern void func_003F00E0(s32, u8 *, u8 *, s32, u8 *, u8 *);
    s32 x, y;
    u8 *o0;
    u8 *o1;
    u8 *o2;
    u8 *o3;
    u8 *o4;
    u8 *o5;

    switch (a1) {
    case 0:
        o0 = (u8 *)((s32)a0 + 0);
        func_003DBB90(o0, 6, 0);
        *(s32 *)(o0 + 0x10) = 0;
        *(s32 *)(o0 + 0x14) = 0;
        *(s32 *)(o0 + 0x18) = 0;
        *(s32 *)(o0 + 0x1C) = 0;
        *(u64 *)(o0 + 0x20) = 0x1000000000008002ULL;
        *(s32 *)(o0 + 0x28) = 0xE;
        *(s32 *)(o0 + 0x2C) = 0;
        func_003F0070(d->f44, o0 + 0x40, o0 + 0x30);
        *(f32 *)(o0 + 0x50) = d->f4;
        *(f32 *)(o0 + 0x54) = d->f8;
        *(f32 *)(o0 + 0x58) = d->fC;
        *(f32 *)(o0 + 0x5C) = 128.0f * d->f10;
        *(f32 *)(o0 + 0x60) = d->f24;
        *(f32 *)(o0 + 0x64) = d->f28;
        *(f32 *)(o0 + 0x68) = d->f2C;
        *(f32 *)(o0 + 0x6C) = d->f30;
        func_003DBB40(o0 + 0x70);
        break;
    case 1:
        o1 = (u8 *)((s32)a0 + 0);
        func_003DBB90(o1, 6, 0);
        *(s32 *)(o1 + 0x10) = 0;
        *(s32 *)(o1 + 0x14) = 0;
        *(s32 *)(o1 + 0x18) = 0;
        *(s32 *)(o1 + 0x1C) = 0;
        *(u64 *)(o1 + 0x20) = 0x1000000000008002ULL;
        *(s32 *)(o1 + 0x28) = 0xE;
        *(s32 *)(o1 + 0x2C) = 0;
        func_003F0070(0, o1 + 0x40, o1 + 0x30);
        *(f32 *)(o1 + 0x50) = d->f4;
        *(f32 *)(o1 + 0x54) = d->f8;
        *(f32 *)(o1 + 0x58) = d->fC;
        *(f32 *)(o1 + 0x5C) = 128.0f * d->f10;
        *(f32 *)(o1 + 0x60) = d->f24;
        *(f32 *)(o1 + 0x64) = d->f28;
        *(f32 *)(o1 + 0x68) = d->f2C;
        *(f32 *)(o1 + 0x6C) = d->f30;
        func_003DBB40(o1 + 0x70);
        break;
    case 2:
        o2 = (u8 *)((s32)a0 + 0);
        func_003DBB90(o2, 8, 0);
        *(s32 *)(o2 + 0x10) = 0;
        *(s32 *)(o2 + 0x14) = 0;
        *(s32 *)(o2 + 0x18) = 0;
        *(s32 *)(o2 + 0x1C) = 0;
        *(u64 *)(o2 + 0x20) = 0x1000000000008002ULL;
        *(s32 *)(o2 + 0x28) = 0xE;
        *(s32 *)(o2 + 0x2C) = 0;
        func_003F0070(d->f44, o2 + 0x40, o2 + 0x30);
        *(f32 *)(o2 + 0x50) = d->f4;
        *(f32 *)(o2 + 0x54) = d->f8;
        *(f32 *)(o2 + 0x58) = d->fC;
        *(f32 *)(o2 + 0x5C) = 128.0f * d->f10;
        *(f32 *)(o2 + 0x60) = d->f24;
        *(f32 *)(o2 + 0x64) = d->f28;
        *(f32 *)(o2 + 0x68) = d->f2C;
        *(f32 *)(o2 + 0x6C) = d->f30;
        *(f32 *)(o2 + 0x70) = d->f14;
        *(f32 *)(o2 + 0x74) = d->f18;
        *(f32 *)(o2 + 0x78) = d->f1C;
        *(f32 *)(o2 + 0x7C) = d->f20;
        switch (d->f48) {
        case 0:
        case 1:
        case 2: x = 1; y = x; break;
        case 4: x = 2; y = 1; break;
        case 8: x = 3; y = 1; break;
        case 0x10: x = 4; y = 1; break;
        case 0x20: x = 5; y = 1; break;
        case 0x40: x = 6; y = 1; break;
        case 0x80: x = 7; y = 1; break;
        case 0x100: x = 8; y = 1; break;
        default: x = d->f48 - 1; y = 0; break;
        }
        *(s32 *)(o2 + 0x80) = x;
        *(s32 *)(o2 + 0x84) = y;
        *(s32 *)(o2 + 0x88) = 0;
        *(s32 *)(o2 + 0x8C) = 0;
        func_003DBB40(o2 + 0x90);
        break;
    case 3:
        o3 = (u8 *)((s32)a0 + 0);
        func_003DBB90(o3, 4, 0);
        *(s32 *)(o3 + 0x10) = 0;
        *(s32 *)(o3 + 0x14) = 0;
        *(s32 *)(o3 + 0x18) = 0;
        *(s32 *)(o3 + 0x1C) = 0;
        *(u64 *)(o3 + 0x20) = 0x1000000000008002ULL;
        *(s32 *)(o3 + 0x28) = 0xE;
        *(s32 *)(o3 + 0x2C) = 0;
        func_003F0070(d->f44, o3 + 0x40, o3 + 0x30);
        func_003DBB40(o3 + 0x50);
        break;
    case 4:
        o4 = (u8 *)((s32)a0 + 0);
        func_003DBB90(o4, 5, 0);
        *(s32 *)(o4 + 0x10) = 0;
        *(s32 *)(o4 + 0x14) = 0;
        *(s32 *)(o4 + 0x18) = 0;
        *(s32 *)(o4 + 0x1C) = 0;
        *(u64 *)(o4 + 0x20) = 0x1000000000008002ULL;
        *(s32 *)(o4 + 0x28) = 0xE;
        *(s32 *)(o4 + 0x2C) = 0;
        func_003F0070(0, o4 + 0x40, o4 + 0x30);
        *(s32 *)(o4 + 0x50) = 0;
        *(s32 *)(o4 + 0x54) = 0;
        *(s32 *)(o4 + 0x58) = 0;
        *(s32 *)(o4 + 0x5C) = 0;
        func_003DBB40(o4 + 0x60);
        break;
    case 5:
        o5 = (u8 *)((s32)a0 + 0);
        func_003DBB90(o5, 7, 0);
        *(s32 *)(o5 + 0x10) = 0;
        *(s32 *)(o5 + 0x14) = 0;
        *(s32 *)(o5 + 0x18) = 0;
        *(s32 *)(o5 + 0x1C) = 0;
        *(u64 *)(o5 + 0x20) = 0x1000000000008004ULL;
        *(s32 *)(o5 + 0x28) = 0xE;
        *(s32 *)(o5 + 0x2C) = 0;
        func_003F00E0(d->f44, o5 + 0x40, o5 + 0x30, D_004C2AAC, o5 + 0x60, o5 + 0x50);
        *(f32 *)(o5 + 0x70) = d->f4;
        *(f32 *)(o5 + 0x74) = d->f8;
        *(f32 *)(o5 + 0x78) = d->fC;
        *(f32 *)(o5 + 0x7C) = 128.0f * d->f10;
        func_003DBB40(o5 + 0x80);
        break;
    }
}

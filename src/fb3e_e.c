typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x[16]; } W64;
typedef struct {
    u8 pad0[0x10];
    u32 w10;
    u8 pad14[0xC];
    f32 f20, f24, f28, f2C;
    u8 pad30[0x40];
    W64 m70;
    f32 fB0, fB4, fB8;
    u32 wBC;
    f32 fC0, fC4, fC8, fCC;
    f32 fD0, fD4, fD8;
    u32 wDC;
    u8 padE0[0x20];
    u8 m100[0x800];
} OE;
typedef struct { u8 pad[0x28]; f32 f28; } ZE;
typedef struct { u8 pad[0x1C]; s32 w1C; u8 pad20[0x20]; ZE *p40; } AE;

extern u32 D_004C2AC0;
extern s32 D_004C2AA0;
extern u8 D_0061BEE0[];
extern u8 D_0061C720[];
extern u8 D_0061BE20[];
extern W64 D_0061BDE0;
extern f32 D_0061B324[], D_0061B328[], D_0061B32C[];
extern f32 D_0061B2F4[], D_0061B2F8[], D_0061B2FC[], D_0061B300[];
extern f32 D_0061B314[], D_0061B318[], D_0061B31C[];

OE *func_003E4D50(AE *a, u8 *b)
{
    extern s32 func_003DD030(s32);
    extern OE *func_003DD160(s32, s32);
    extern void func_003DBA30(OE *, s32, s32, s32, s32);
    extern void func_003DBB60(u8 *, s32, s32);
    extern void func_003DE160(u8 *, u8 *, u8 *);
    extern void func_003DE3A0(u8 *, u8 *);
    extern void func_003DBB20(u8 *, u8 *);
    s32 s3;
    s32 i;
    s32 off;
    OE *o;
    s3 = func_003DD030(a->w1C);
    o = func_003DD160(0x910, 0x10);
    func_003DBA30(o, 0x90, s3, 0, 0);
    func_003DBB60((u8 *)o + 0x10, 0x8E, 0);
    o->w10 = 0x13000000;
    o->f20 = ((f32)((D_004C2AC0 >> 16) & 0xFF) / 255.0f) * a->p40->f28;
    o->f24 = ((f32)((D_004C2AC0 >> 8) & 0xFF) / 255.0f) * a->p40->f28;
    o->f28 = ((f32)(u8)D_004C2AC0 / 255.0f) * a->p40->f28;
    o->f2C = 0.5f * (f32)((D_004C2AC0 >> 24) & 0xFF);
    func_003DE3A0((u8 *)o + 0x30, D_0061BE20);
    i = 0;
    off = 0;
    do {
        if (D_004C2AA0 & (1 << i)) {
            func_003DE160(D_0061BEE0 + off, D_0061BEE0 + off, D_0061C720);
        }
        func_003DE3A0(o->m100 + off, D_0061BEE0 + off);
        i++;
        off += 0x40;
    } while (i < 0x20);
    o->m70 = D_0061BDE0;
    o->fB0 = -D_0061B324[0];
    o->fB4 = -D_0061B328[0];
    o->fB8 = -D_0061B32C[0];
    o->wBC = 0;
    o->fC0 = D_0061B2F4[0];
    o->fC4 = D_0061B2F8[0];
    o->fC8 = D_0061B2FC[0];
    o->fCC = D_0061B300[0];
    o->fD0 = D_0061B314[0] * a->p40->f28;
    o->fD4 = D_0061B318[0] * a->p40->f28;
    o->fD8 = D_0061B31C[0] * a->p40->f28;
    o->wDC = 0x43000000;
    func_003DBB20((u8 *)o + 0x900, b);
    return o;
}

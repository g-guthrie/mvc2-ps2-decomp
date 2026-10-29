/* MW 3.0 (try30) "-O3,p -sdatathreshold 8": exact. Replaces the asm-nop placeholder formerly in src/x5_b.c; the flat "if (t == 0) return;" early exit removes the extra loop-exit pad nop. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; u8 pad3c[0x161 - 0x3C]; s8 f161; u8 pad162[6]; u16 f168; } O;
typedef struct { u8 pad0[0x18]; O *owner; u8 pad1c[8]; u8 f24; u8 pad25[0xF]; f32 f34; f32 f38; u8 pad3c[0x100]; u8 f13c; u8 pad13d[0x24]; s8 f161; } P;
extern u16 *D_004C29DC;
void func_00394CD0(P *p) {
    extern void func_00395890(P *);
    extern s32 func_00175700(P *);
    s32 t;
    s8 v;
    u16 a = *D_004C29DC;
    if (a != p->owner->f168) {
        func_00395890(p);
        return;
    }
    p->f24 = 0;
    p->f34 = p->owner->f34;
    p->f38 = p->owner->f38;
    p->f13c = 0;
    t = (s8)(p->owner->f161 & ~1);
    v = t;
    if (t == 0) return;
    if (v < 0) {
        func_00395890(p);
        return;
    }
    p->f13c = 1;
    while (v != p->f161) func_00175700(p);
}

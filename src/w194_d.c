typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 f0, f4; s32 f8, fC, f10; s32 f14, f18, f1C, f20, f24; u8 pad[0x170 - 0x28]; } SL;
extern SL D_005BF2F0[];
extern void func_003DC9C0();
extern void func_003DD020(s32);
extern void func_003F55B0(SL *, s32, s32);

s32 func_003F0860(s32 n) {
    SL *s = &D_005BF2F0[n - 1];
    if (s->f4 == 0) return 0;
    func_003DC9C0();
    s->f4 = 0;
    if (s->f14 != 0) func_003DD020(s->f14);
    if (s->f1C != 0) func_003DD020(s->f1C);
    if (s->f20 != 0) func_003DD020(s->f20);
    if (s->f24 != 0) func_003DD020(s->f24);
    func_003F55B0(s, 0, 0x170);
    return 1;
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

/* EE GCC 2.96: ./tryee.sh src/ra39_a.c sn */
typedef struct { s8 b0; s8 b1; s8 b2; s8 b3; s32 f4; s32 f8; s32 fc; s32 f10; s32 f14; s32 f18; s32 f1c; s32 f20; s32 pad24[2]; s32 f2c; s32 f30; s32 f34; s32 f38; s32 f3c; } Slot;
extern Slot D_00487358[];
extern u8 D_004BD8C0[];
extern void func_0040EFE0(void);
extern void func_0040EFF8(void);
extern void func_0011EB60(u8 *, s32, s32);
extern void func_0011D8F8(Slot *, s32, s32);

Slot *func_00408DB0(s32 a, s32 b) {
    Slot *s;
    s32 i;
    s32 n;
    s32 m;
    func_0040EFE0();
    for (i = 0; i < 32; i++) {
        s = &D_00487358[i];
        if (s->b0 == 0) break;
    }
    if (i == 32) {
        func_0011EB60(D_004BD8C0, 32, 32);
        s = 0;
    } else {
        n = 0x40;
        func_0011D8F8(s, 0, 0x40);
        s->b1 = 0;
        s->f38 = n;
        s->f4 = a;
        s->f8 = b;
        s->b2 = 0;
        s->f30 = m = 1;
        s->b0 = m;
        s->f34 = 0;
    }
    func_0040EFF8();
    return s;
}

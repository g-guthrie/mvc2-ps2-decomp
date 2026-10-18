typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x34]; f32 f34; } Q85;
typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3[0x34 - 3];
    f32 f34;
    u8 pad38[0x204 - 0x38];
    s8 b204;
    u8 pad205[0x215 - 0x205];
    u8 b215, b216;
    u8 pad217[0x220 - 0x217];
    Q85 *q220;
    u8 pad224[0x354 - 0x224];
    u16 h354;
    u8 pad356[0x425 - 0x356];
    u8 b425;
} S85;

u8 func_00185BB0(S85 *p) {
    extern void func_00191210(S85 *);
    extern s32 func_00185DD0(S85 *);
    extern s32 func_00185F90(s32);
    extern s32 func_00186CE0(S85 *, s32);
    u8 b;
    func_00191210(p);
    if ((p->b216 & 0x80) || p->b204 != 0 || p->b215 != 0 || p->b425 != 0) return 0;
    if (func_00185DD0(p) == 0) return 0;
    b = (p->f34 > p->q220->f34) ? 0 : 1;
    if ((p->h354 & (1 << (b + 10))) == 0) return 0;
    if (func_00185F90(p->b2) != 0) return func_00186CE0(p, 0x13);
    return 0;
}

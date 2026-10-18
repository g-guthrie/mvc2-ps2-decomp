typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct R2 {
    u8 pad0[0x34];
    f32 f34;
    f32 f38;
    u8 pad3[0x5C - 0x3C];
    f32 f5C;
    f32 f60;
    u8 pad4[0x68 - 0x64];
    f32 f68;
    f32 f6C;
    u8 pad5[0x215 - 0x70];
    u8 b215;
    u8 pad6[0x354 - 0x216];
    u16 h354;
} R2;

extern s32 func_001884C0(R2 *);
extern s32 func_00187D70(R2 *);
extern s32 func_00184B30(R2 *);
extern s32 func_00184720(R2 *);
extern s32 func_00185A90(R2 *);
extern s32 func_00186120(R2 *);
extern void func_00186CE0(R2 *, s32);
extern void func_001757E0(R2 *, s32, s32);
extern void func_001863F0(R2 *);
extern s8 func_00175700(R2 *);

void func_0017A670(R2 *p) {
    if (p->b215 == 0) {
        if (func_001884C0(p)) return;
        if (func_00187D70(p)) return;
        if (func_00184B30(p)) return;
        if (func_00184720(p)) return;
        if (func_00185A90(p)) return;
        if (func_00186120(p)) return;
    }
    if ((p->h354 & 0x1000) == 0) {
        func_00186CE0(p, 7);
        func_001757E0(p, 3, 2);
        return;
    }
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    func_001863F0(p);
    if (func_00175700(p) < 0) {
        func_00186CE0(p, 6);
    }
}

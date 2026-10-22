typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

typedef struct O {
    u8 pad0[0x10];
    void *w10;
    u8 pad14[0x1C - 0x14];
    s16 s1C;
    s16 s1E;
    u8 pad20[3];
    u8 b23;
    u8 pad24[0x34 - 0x24];
    V3 v34;
    u8 pad40[0x50 - 0x40];
    f32 f50;
    f32 f54;
    f32 f58;
    u8 pad5C[0x84 - 0x5C];
    s32 w84;
    u8 pad88[0xCC - 0x88];
    s16 sCC;
    u8 padCE[2];
    s32 wD0;
    s32 wD4;
    u8 padD8[0x13C - 0xD8];
    u8 b13C;
} O;

extern s8 D_004D1917[];
extern s16 D_004BF448;
extern s32 D_004C2838;

void func_0015B000(s32 a0, V3 *pos, f32 x, s32 a2, s32 idx, u16 flags) {
    extern O *func_003DA750(s32, s32, s32);
    extern void func_0015AED0();
    extern void func_0015B160(u8 *);
    extern void func_00152550(void *, void (*)(u8 *));
    O *o;
    s32 big;
    if ((flags & 8) == 0) {
        D_004D1917[0]--;
        return;
    }
    big = flags & 0x200;
    if (big != 0) {
        if ((o = func_003DA750(0, 0x22, 1)) == 0) {
            D_004D1917[0]--;
            return;
        }
    } else {
        if ((o = func_003DA750(0, 0x23, 1)) == 0) {
            D_004D1917[0]--;
            return;
        }
    }
    o->b13C = 1;
    o->w10 = (void *)func_0015AED0;
    o->wD0 = 0x800031;
    o->v34 = *pos;
    if (big != 0) {
        o->v34.z -= 135.0f;
    }
    o->s1C = 0;
    o->s1E = 3;
    o->sCC = D_004BF448;
    o->w84 = D_004C2838;
    o->f50 = x;
    o->f54 = x;
    o->f58 = x;
    o->b23 = idx;
    o->wD4 = idx << 3;
    func_00152550(o, func_0015B160);
}

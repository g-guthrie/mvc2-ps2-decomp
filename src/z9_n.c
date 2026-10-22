typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct {
    u8 p0[0x10]; void (*fn10)(); u8 pad14[0x1C - 0x14]; s16 s1c; u8 pad1e[0x34 - 0x1E];
    V3 v34; u8 pad40[4]; u32 w44; u8 pad48[0x50 - 0x48]; u32 w50; u32 w54;
    u8 pad58[0x84 - 0x58]; void *w84; u8 pad88[0xCC - 0x88]; s16 sCC; u8 padce[2]; s32 wD0;
    u8 padd4[0xDC - 0xD4]; s32 wDC; u8 pade0[0x13C - 0xE0]; u8 b13c;
} O1;

extern void *D_004C2838;

void func_0015EF10(V3 *pos, s32 flag) {
    extern O1 *func_003DA750();
    extern s32 func_00174170();
    extern void func_0015ED20();
    extern void func_0015EE60(u8 *);
    extern void func_00152550(void *, void (*)(u8 *));
    O1 *o;
    s32 w;
    if ((o = func_003DA750(0, 0x34, 1)) != 0) {
        o->b13c = 0;
        o->fn10 = func_0015ED20;
        o->wD0 = 0x800035;
        o->w50 = 0x41200000;
        o->w54 = 0x41200000;
        w = flag ? 0 : 0x8000;
        o->w44 = w;
        o->wDC = func_00174170();
        o->wDC = o->wDC % 2;
        if (o->wDC != 0) {
            o->sCC = 0x1D;
            o->w84 = D_004C2838;
        } else {
            o->sCC = 0x19;
            o->w84 = D_004C2838;
        }
        o->v34 = *pos;
        o->s1c = 2;
        func_00152550(o, func_0015EE60);
    }
}

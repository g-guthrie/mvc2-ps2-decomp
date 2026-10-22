typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[7];
    u8 b7;
    u8 pad8[8];
    void (*fn10)(void);
    u8 pad14[4];
    s32 w18;
    u8 pad1C[7];
    u8 b23;
    u8 pad24[0x34 - 0x24];
    f32 f34;
    f32 f38;
    u8 pad3C[8];
    u32 w44;
    u8 pad48[8];
    f32 f50;
    f32 f54;
    u8 pad58[4];
    f32 f5C;
    f32 f60;
    u8 pad64[0x84 - 0x64];
    s32 w84;
    u8 pad88[0xCC - 0x88];
    s16 hCC;
    u8 padCE[2];
    s32 wD0;
    u8 padD4[4];
    s32 wD8;
    s32 wDC;
    u8 padE0[0x13C - 0xE0];
    u8 b13C;
    u8 pad13D[3];
    s16 h140;
    u8 pad142[0x14C - 0x142];
    u8 b14C;
    u8 pad14D;
    u8 b14E;
} O15E3A0;

extern s32 D_004C2838;
extern s32 fptosi(f32);

void func_0015E3A0(O15E3A0 *a)
{
    extern O15E3A0 *func_003DA750(s32, s32, s32);
    extern void func_0015E100(void);
    extern s32 func_00174170();
    extern s32 func_00417A40();
    O15E3A0 *o;
    u8 i;
    s32 r, n, x, v;

    for (i = 0; i < 5; i++) {
        if ((o = func_003DA750(0, 0x2C, 1)) == 0) break;
        o->b13C = 0;
        o->fn10 = func_0015E100;
        o->wD0 = 0x25;
        o->b23 = i;
        o->f50 = 1.0f;
        o->f54 = 1.0f;
        o->wD8 = o->b23 << 3;
        o->w18 = (s32)a;
        o->w44 = (a->h140 != 0) ? 0 : 0x8000;
        o->wDC = func_00174170();
        o->wDC = o->wDC % 2;
        if (o->wDC != 0) {
            o->hCC = 0x65;
            o->w84 = D_004C2838;
        } else {
            o->hCC = 0x63;
            o->w84 = D_004C2838;
        }
        r = func_00417A40();
        n = fptosi(1.6666666269302368f * (f32)(u32)a->b14E * a->f50);
        x = (r % 2 != 0) ? r % n : -(r % n);
        o->f5C += (f32)x;
        r = func_00417A40();
        n = fptosi(2.1428570747375488f * (f32)(u32)a->b14C * a->f54);
        o->f60 += (f32)(r % n);
        o->f34 = a->f34 + o->f5C;
        o->f38 = a->f38 + o->f60;
        o->w44 = (o->h140 != 0) ? 0 : 0x8000;
        o->b7 = 4;
    }
}

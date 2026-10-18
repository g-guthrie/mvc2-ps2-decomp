typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w189_f.c "-O3 -sdatathreshold 8" */
typedef struct P161 { u8 pad0[5]; u8 b5; } P161;
typedef struct O161 {
    u8 pad0[0x10]; void *w10; u8 pad14[4]; P161 *w18; s16 h1C; u8 pad1E[0x34 - 0x1E];
    f32 f34; f32 f38; f32 f3C; u8 pad40[0x84 - 0x40]; s32 w84; u8 pad88[0xC8 - 0x88];
    u8 *wC8; s16 hCC; u8 padCE[2]; s32 wD0; u8 pad_D4[0x13C - 0xD4]; u8 b13C;
} O161;
extern s32 D_004C2838;
extern f32 D_004F1FE8[];
extern O161 *func_003DA750(s32, s32, s32);
extern s32 func_00417A40(void);
extern void func_00162080(void);

void func_00161F20(u8 *p) {
    O161 *o;
    s32 v;
    s32 w;
    if ((o = func_003DA750(0, 0x11, 1)) != 0) {
        o->b13C = 1;
        o->w10 = (void *)func_00162080;
        o->hCC = 0x4C;
        o->w84 = D_004C2838;
        o->wD0 = 0x800401;
        o->wC8 = p + 0x88;
        o->w18 = (P161 *)p;
        v = func_00417A40() % 1500;
        v = (v % 2) ? v : -v;
        o->f34 += (f32)v;
        w = func_00417A40() % 240;
        w = (w % 2) ? w : -w;
        o->f38 += (f32)w;
        o->f38 += D_004F1FE8[0];
        o->f3C = 900.0f;
        o->h1C = 0x1E;
        o->w18->b5++;
    }
}

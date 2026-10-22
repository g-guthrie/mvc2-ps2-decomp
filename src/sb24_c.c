typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct P {
    u8 pad0[5]; u8 b5; u8 pad6; u8 b7; u8 pad8[0x1C - 8]; s16 h1C; s16 h1E; u8 b20; u8 pad21[0x34 - 0x21]; f32 f34;
    u8 pad38[0x44 - 0x38]; s32 s44; s32 s48; u8 pad4C[0x5C - 0x4C]; f32 f5C; u32 u60; u8 pad64[4]; u32 u68; u32 u6C;
    u8 pad70[0x140 - 0x70]; s16 h140;
} P;
extern s32 func_003367F0(P *);
extern s32 func_00336690(P *);
extern s32 func_00336460(P *);
extern s32 func_00335390(P *);

void func_00335FC0(P *p)
{
    f32 f;
    s16 h;
    if (func_003367F0(p) != 0) {
        *(u32 *)&p->f5C = 0;
        p->u60 = 0;
        p->u68 = 0;
        p->u6C = 0;
        return;
    }
    if (func_00336690(p) != 0)
        return;
    if (func_00336460(p) != 0) {
        *(u32 *)&p->f5C = 0;
        p->u60 = 0;
        p->u68 = 0;
        p->u6C = 0;
        return;
    }
    p->h1E = p->h1E + 1;
    if (p->h140 != 0)
        f = -p->f5C;
    else
        f = p->f5C;
    p->f34 += f;
    p->s44 = (p->h140 != 0) ? 0 : 0x8000;
    h = p->h1E % 4;
    p->h1E = h;
    if (h == 0)
        p->b20 ^= 1;
    p->s44 += (p->b20 != 0) ? 0xCCD : -0xCCD;
    p->s48 = (p->b20 != 0) ? 0xAAB : -0xAAB;
    h = p->h1C - 1;
    p->h1C = h;
    if (h == 0 || func_00335390(p) != 0) {
        p->s48 = 0;
        p->b7 = 0;
        p->b5 = 0;
    }
}

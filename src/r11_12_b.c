/* func_003F72F0: EE GCC 2.96, ./tryee.sh src/r11_12_b.c sn 0 O2 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 *func_003F6E70(u8 *, s32, s32 *, s32 *, s32 *, s32 *, s32 *);

extern s32 func_003F71E0(u8 *a, s32 n, s16 *out, s8 *p3, s8 *p4, s8 *p5, s8 *p6, s32 *p7, s32 *p8, s32 *p9, s32 *p10);
typedef struct {
    u8 p0[2];
    s16 h2;
    u8 p4[8];
    s8 b0c;
    s8 b0d;
    s8 b0e;
    s8 b0f;
    s32 w10;
    s32 w14;
    s32 w18;
    s16 h1c;
    u8 p1e[2];
    s32 w20;
    s16 h24;
    s16 h26;
    s32 w28;
    s32 w2c;
    s32 w30;
    s32 w34;
    u8 p38[4];
    void *w3c;
    s32 w40;
    s32 w44;
    u8 p48[8];
    s32 w50;
    s32 w54;
    s32 w58;
    void *w5c;
    s32 w60;
    s32 w64;
    u8 p68[0x88 - 0x68];
    s32 w88;
    s32 w8c;
    u8 p90[8];
    s16 h98;
    u16 h9a;
} P3F7;



s16 func_003F72F0(P3F7 *p, u8 *a, s32 b)
{
    s16 v;
    s16 t;
    s32 w;
    s32 r;
    s8 *q1;
    s32 *q2;
    s8 *q3;
    q2 = &p->w10;
    q3 = &p->b0f;
    q1 = &p->b0e;
    p->h2 = 1;
    r = func_003F71E0(a, b, &v, &p->b0c, &p->b0d, q3, q1, &p->w14, &p->w18, q2, &w);
    if (r < 0) {
        return 0;
    }
    p->w34 = 0;
    p->w30 = 0;
    p->w2c = 0;
    p->w28 = 0;
    p->w20 = 0;
    p->h1c = 0;
    p->h26 = 0;
    p->h24 = 0;
    p->w50 = *q1;
    t = v;
    p->w54 = *q3;
    p->w5c = p->w3c;
    p->w58 = *q2;
    p->w60 = p->w40;
    p->h98 = 4;
    p->w8c = 0;
    p->w64 = p->w44;
    p->w88 = 0;
    p->h9a = (u16)w;
    return t;
}

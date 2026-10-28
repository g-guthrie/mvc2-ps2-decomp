/* EE GCC 2.96: ./tryee.sh src/s5a_d.c sn */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;


extern s32 func_003F8D90();
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
    s32 w3c;
    s32 w40;
    s32 w44;
    u8 p48[8];
    s32 w50;
    s32 w54;
    s32 w58;
    s32 w5c;
    s32 w60;
    s32 w64;
    u8 p68[0x88 - 0x68];
    s32 w88;
    s32 w8c;
    u8 p90[8];
    s16 h98;
    u8 b9a[4];
} P3F8;


s16 func_003F8FB8(P3F8 *p, s32 a, s32 b)
{
    s16 v;
    s32 r;
    s8 *q1;
    s32 *q2;
    s8 *q3;
    q2 = &p->w10;
    q3 = &p->b0f;
    q1 = &p->b0e;
    p->h2 = 1;
    r = func_003F8D90(a, b, &v, &p->b0c, &p->b0d, q3, q1, &p->w14, &p->w18, q2, p->b9a);
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
    {
    s32 x = p->w3c, y = p->w40, z = p->w44, w;
    p->w50 = *q1;
    p->w54 = *q3;
    w = *q2;
    p->w5c = x;
    p->w60 = y;
    p->w58 = w;
    p->w64 = z;
    }
    p->w8c = 0;
    p->w88 = 0;
    p->h98 = 1;
    return v;
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_004C27A4;
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_003A4B50();

s32 func_003A4AC0(void *p)
{
    s32 i;
    if (D_004C27A4 < 5) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        u8 *o = func_003DA750(0, 1, 1);
        if (o != 0) {
            *(s16 *)(o + 0x26) = 0x2D02;
            o[0x20] = i;
            *(void **)(o + 0x10) = func_003A4B50;
            *(void **)(o + 0x18) = p;
        }
    }
    return i;
}

typedef struct { u8 a, b, c, d; s32 n; } E8;
extern void func_00176160(void *q, s32 a, s32 b, s32 c);

void func_001C1CA0(u8 *p, u8 *q, E8 *r)
{
    u8 *s = p + 0xD0;
    do {
        s[4] = r->a;
        func_00176160(q, r->b, r->c + q[0x25] * 0x57, r->d);
        if (r->n == 1) {
            s[5] = 0;
        } else {
            s[5] = 1;
        }
        r += r->n;
    } while (s[4] == 0);
    *(E8 **)s = r;
}

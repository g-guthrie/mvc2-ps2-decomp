typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x34]; f32 f34; u8 p38[0x24]; u32 u5C; } SA;

void residual_0035D4C0(u8 *p, u8 *o)
{
    extern void func_0035D600(u8 *, u8 *);
    s32 n;
    u32 *d, *s;
    SA *sa = (SA *)p;
    p[4]++;
    s = (u32 *)(o + 236);
    d = (u32 *)(p + 236);
    for (n = 49; n > 0; n--) *d++ = *s++;
    p[316] = 1;
    p[2] = o[2];
    p[1] = o[1];
    *(f32 *)(p + 80) = *(f32 *)(o + 80);
    *(f32 *)(p + 84) = *(f32 *)(o + 84);
    p[439] = o[439];
    p[440] = o[440];
    *(s8 *)(p + 48) = *(s8 *)(o + 48);
    *(V3 *)(p + 80) = *(V3 *)(o + 80);
    *(s8 *)(p + 36) = *(s8 *)(o + 36);
    p[316] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(o + 0x3C);
    *(f32 *)(p + 0x5C) = 0.0f;
    *(f32 *)(p + 0x60) = 0.0f;
    *(f32 *)(p + 0x68) = 0.0f;
    *(f32 *)(p + 0x6C) = 0.0f;
    if (*(s16 *)(p + 0x140) == 0) {
        sa->f34 -= 80.0f;
        sa->u5C = 0xC1200000;
    } else {
        sa->f34 += 80.0f;
        sa->u5C = 0x41200000;
    }
    *(s16 *)(p + 0x1C) = 1;
    if (p[0x1B7] == 0) *(s16 *)(p + 0x1E) = 0x18; else *(s16 *)(p + 0x1E) = 0x30;
    func_0035D600(p, o);
}

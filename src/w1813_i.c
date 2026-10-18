typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[7]; u8 b7; u8 pad8[0x2C]; f32 f34; f32 f38; u8 pad3c[0x20];
    f32 f5C; f32 f60; u8 pad64[4]; f32 f68; f32 f6C; u8 pad70[0xD0];
    s16 h140;
} S7960;
typedef struct { u8 pad[0x34]; f32 f34; u8 pad2[0x1AC]; u8 b1E4; } Q7960;

void func_001C7960(S7960 *p, Q7960 *q)
{
    extern void func_00175700(S7960 *);
    extern void func_001757E0(S7960 *, s32, s32);
    s16 h;
    f32 f;
    func_00175700(p);
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    if (q->b1E4 != 0x16) {
        p->b7 = 4;
    } else {
        h = p->h140;
        if (h == 0) {
            f = 90.0f + q->f34;
        } else {
            f = q->f34 - 90.0f;
        }
        if ((h == 0 && p->f34 <= f) || (h != 0 && !(p->f34 < f))) {
            u32 t = p->b7;
            p->b7 = t + 1;
            p->f34 = f;
            func_001757E0(p, 0x19, 0x1D);
        }
    }
}

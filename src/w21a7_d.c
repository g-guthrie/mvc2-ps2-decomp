typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 x; s16 y; s8 z; u8 pad[3]; } E8;
typedef struct {
    u8 pad0[3]; s8 f3; s16 f4; u8 pad6[2]; E8 *f8; s16 fC; s16 fE;
    u8 pad10[8]; f32 f18; f32 f1C;
} Q;

void func_00194FF0(u8 *p, u8 *b)
{
    extern s32 func_00197560(u8 *);
    extern void func_00195470(u8 *, u8 *);
    extern void func_00175670(u8 *);
    extern void func_001975C0(u8 *, u8 *);
    Q *q = (Q *)(p + 0x88);
    E8 *e;
    s16 a0, a2;
    f32 d;

    if (func_00197560(p) != 0) {
        if (b[5] == 0 && b[0x1E4] == 0) {
            *(u8 *)q = 3;
            p[5] = 0;
            func_00195470(p, b);
        }
        return;
    }
    if (p[0x21] < 4) {
        e = &q->f8[q->f4];
        a2 = e->y;
        a0 = e->x;
        if (a2 == 0) {
            if (!(*(f32 *)(p + 0x38) <= 120.0f + *(f32 *)(b + 0x430))) q->f3 = -1;
            if (*(f32 *)(p + 0x38) < 51.42856979370117f + *(f32 *)(b + 0x430)) q->f3 = 0;
        }
        if (q->f3 != 0) a2 = -a2;
        if (*(s16 *)(p + 0x140) == 0) a0 = -a0;
        d = 1.6666666269302368f * (f32)(a0 << 8) / 256.0f;
        *(f32 *)(p + 0x34) = q->f18 + (*(f32 *)(b + 0x34) + d);
        if (p[0x21] < 2) {
            d = 2.142857074737549f * (f32)(a2 << 8) / 256.0f;
            *(f32 *)(p + 0x38) = q->f1C + (*(f32 *)(b + 0x38) + d);
        } else {
            d = 2.142857074737549f * (f32)(a2 << 8) / 256.0f;
            *(f32 *)(p + 0x38) += d;
        }
        p[0x31] = e->z;
        q->f4 = q->f4 + q->fC;
        q->f4 = q->f4 & q->fE;
        func_00175670(p);
        func_001975C0(p, b);
    }
}

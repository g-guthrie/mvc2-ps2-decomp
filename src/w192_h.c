typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct Q { u8 pad[0x34]; f32 f34; f32 f38; f32 f3C; u8 pad40[0x168 - 0x40]; u16 h168; } Q;
typedef struct P {
    u8 pad0[4]; u8 b4; u8 pad5[0x18 - 5]; Q *q; u8 pad1C[2]; u16 h1E; u8 pad20; s8 b21;
    u8 pad22[0x34 - 0x22]; f32 f34; f32 f38; f32 f3C; u8 pad40[0x5C - 0x40]; f32 f5C; f32 f60;
    u8 pad64[0x13C - 0x64]; u8 b13C;
} P;
extern s8 func_00175700(P *);
extern s8 func_00175670(P *);
extern void func_001E7F60(P *);
extern void func_00381EC0(P *, s32);

void func_00382E20(P *p)
{
    Q *q = p->q;
    s8 r;
    p->b13C = 0;
    if (q->h168 != p->h1E && p->b21 < 0) {
        p->b4 = 2;
        return;
    }
    p->f34 = q->f34 + p->f5C;
    p->f38 = q->f38 + p->f60;
    p->f3C = q->f3C;
    if (p->b21 >= 0) {
        r = func_00175700(p);
        if (r < 0 && p->b21 >= 0) {
            p->b4++;
            func_00381EC0(p, 7);
            return;
        }
        func_001E7F60(p);
    } else {
        r = func_00175670(p);
        if (r < 0) {
            p->b4++;
            return;
        }
    }
    p->b13C = 1;
}

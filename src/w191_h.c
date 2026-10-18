typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x34];
    f32 f34;
} Q26A;

typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 pad7[0x34 - 7];
    f32 f34;
    u8 pad38[0x140 - 0x38];
    s16 h140;
    u8 pad142[0x1DC - 0x142];
    Q26A *q1DC;
} P26A;

extern f32 D_004F1FC8;
extern f32 D_004F1FCC;

void func_0026A6B0(P26A *p)
{
    extern s8 func_00175700(P26A *);
    extern void func_001757E0(P26A *, s32, s32);
    Q26A *q = p->q1DC;
    f32 k;
    u32 t;

    if (func_00175700(p) < 0) {
        t = p->b6;
        p->b6 = t + 1;
        if (p->h140 != 0) {
            if (!(p->f34 <= D_004F1FCC - 213.3333282470703f)) {
                p->h140 = 0;
            }
        } else {
            if (p->f34 < 213.3333282470703f + D_004F1FC8) {
                p->h140 = 1;
            }
        }
        q->f34 = p->f34;
        if (p->h140 != 0) {
            k = 186.66665649414062f;
        } else {
            k = -186.66665649414062f;
        }
        q->f34 += k;
        func_001757E0(p, 0x15, 0x1E);
    }
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3;
    u8 b4;
    u8 pad5[0x18 - 5];
    u8 *w18;
    s16 h1C;
    s16 h1E;
} P328;

extern u8 D_004D18A6;
extern s8 D_004F1F41;
extern s8 D_004F1F42;
extern s8 D_004F1F43;
extern s8 D_004F1F44;
extern u8 D_004D18A0[];

void func_00328160(P328 *p)
{
    extern void func_00183AD0(u8 *);
    s32 i;
    s32 off;
    u8 *q;
    s16 v;
    u32 t;

    if (D_004D18A6 == 0) {
        t = p->b4;
        p->b4 = t + 1;
    } else if (p->h1C != 0) {
        v = p->h1C - 1;
        p->h1C = v;
        if (v == 0) {
            D_004F1F43 = D_004F1F41;
            D_004F1F44 = D_004F1F42;
        }
    } else {
        v = p->h1E - 1;
        p->h1E = v;
        if (v < 0) {
            t = p->b4;
            p->b4 = t + 1;
            i = 0;
            off = 0;
            do {
                q = *(u8 **)((s32)D_004D18A0 + (p->b2 ^ 1) * 12 + off + 0x18);
                if (q[0] != 0 && q[5] != 2) {
                    q[0x1B4] = 10;
                }
                i++;
                off += 4;
            } while (i < 3);
            func_00183AD0(p->w18);
        }
    }
}

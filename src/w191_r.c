typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x94];
    u16 h94;
} T27D;

typedef struct {
    u8 pad0[5];
    u8 b5;
    u8 pad6[0x34 - 6];
    f32 f34;
    u8 pad38[0x78 - 0x38];
    s32 w78;
    u8 pad7C[0x13D - 0x7C];
    s8 b13D;
    s16 h13E;
    s16 h140;
    u8 pad142[0x1B3 - 0x142];
    s8 s1B3;
    s8 s1B4;
    u8 pad1B5[0x1B8 - 0x1B5];
    u8 b1B8;
    u8 pad1B9[0x294 - 0x1B9];
    u8 b294;
    u8 b295;
    u8 pad296;
    s8 s297;
} P27D;

extern s8 D_004ACD08[];
extern T27D *D_004C2840;

void func_0027D740(P27D *p)
{
    u32 a1;
    s32 a2;
    s32 v;
    s16 k;
    s8 w;

    p->b13D = -1;
    p->h13E = D_004ACD08[p->b1B8];
    a1 = p->b295;
    if (a1 == 0) {
        a2 = p->s1B4;
        if (a2 != 0 && p->b5 == 0 && p->s1B3 != 0) {
            p->b295 = a1 + 1;
        } else {
            w = p->s297;
            if (w != 0 && a2 == 0) {
                w = w - 1;
                p->s297 = w;
                if (w == 0) {
                    p->b294 = 0;
                }
            }
            return;
        }
    }
    if (p->s1B4 == 0) {
        p->b295 = 0;
        p->w78 = 0;
        return;
    }
    k = 4 - (((u32)D_004C2840->h94 & 1) << 3);
    if (p->h140 != 0) {
        k = -k;
    }
    p->f34 += 1.6666666269302368f * (f32)k;
    if ((p->s1B4 & 1) == 0 && p->b295 != 0) {
        p->b13D = 1;
        p->h13E = D_004ACD08[p->b1B8] + 3;
    }
}

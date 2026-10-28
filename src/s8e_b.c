typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    u8 pad0[4];
    u8 b4;
    u8 pad5[0x17];
    s16 h1C;
    u8 pad1E[0x16];
    f32 f34;
    u8 pad38[0x24];
    f32 f5C;
    u8 pad60[8];
    f32 f68;
    u8 pad6C[0x70];
    union { u32 w; s8 b; } uDC;
} S_00136A10;

extern u8 D_00583BC6;
extern s8 D_00583BC3;
extern f32 D_0043F180[];
extern f32 D_0043F184[];

void func_00136A10(S_00136A10 *p) {
    extern void func_0032D390(S_00136A10 *, s32, s32, s32, f32, f32);
    s32 x;
    s16 v;
    if (D_00583BC6 != 0) return;
    switch (p->b4) {
    case 0:
        x = D_00583BC3;
        x = (u8)(p->uDC.b ^ x);
        if (x == 0) return;
        p->b4 = p->b4 + 1;
        p->h1C = 0x19;
        if ((u8)D_00583BC3 == 3) {
            func_0032D390(p, p->h1C, 0, 0, D_0043F180[0], D_0043F184[0]);
        } else {
            func_0032D390(p, p->h1C, 0, 0, D_0043F180[(u8)x * 3], D_0043F184[(u8)x * 3]);
        }
        p->uDC.w |= (u8)x;
        break;
    case 1:
        v = p->h1C - 1;
        p->h1C = v;
        if (p->h1C <= 0) {
            p->b4 = 0;
        } else {
            p->f34 += p->f5C;
        }
        p->f5C += p->f68;
        break;
    }
}

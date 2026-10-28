typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s8 b0;
    s8 b1;
    s8 b2;
    s8 b3;
    s8 b4;
    s8 b5;
    s8 b6;
    s8 b7;
    s8 b8;
    s8 b9;
    u8 padA[6];
    s32 w10;
    s32 w14;
    u8 pad18[4];
    s8 b1C;
    s8 b1D;
    s8 b1E;
    s8 b1F;
    s16 h20[8];
    s16 h30[8];
    s8 b40;
    s8 b41;
} S_0012F710;

extern S_0012F710 D_004F7FC0;
extern s8 D_004C286C;
extern s8 D_004C2868;
extern s8 D_004C2864;
extern s8 D_004C2860;
extern s8 D_004C285C;
extern s8 D_004C2858;
extern s8 D_004C2854;

void func_0012F710(s32 mode) {
    extern s8 func_001E2120(void);
    extern s16 func_0012F6F0(s32);
    s32 i;
    S_0012F710 *d;
    s32 o;
    d = &D_004F7FC0;
    if (mode == 0xFF) {
        d->b4 = func_001E2120();
        d->b5 = 1;
        d->b6 = 0;
        D_004C286C = d->b4;
    }
    if (mode & 1) {
        d->b0 = 1;
        d->b1 = 2;
        d->b2 = 1;
        d->b3 = 0;
        d->b40 = 7;
        d->b41 = 7;
        D_004C286C = 1;
        D_004C2868 = d->b0;
        D_004C2864 = d->b1;
        D_004C2860 = d->b2;
        D_004C285C = d->b3;
        D_004C2858 = d->b40;
        D_004C2854 = d->b41;
        d->b7 = 0;
        d->b1F = 0;
    }
    if (mode & 2) {
        d->b8 = 0;
        d->b9 = 0;
        d->b1C = 0;
        i = 0;
        o = 0;
        do {
            *(s16 *)((u8 *)d->h20 + o) = func_0012F6F0(i);
            *(s16 *)((u8 *)d->h30 + o) = func_0012F6F0(i);
            i++;
            o += 2;
        } while (i < 8);
    }
    if (mode & 4) {
        d->w10 = 0;
        d->w14 = 0;
        d->b1D = 0;
        d->b1E = 0;
    }
}

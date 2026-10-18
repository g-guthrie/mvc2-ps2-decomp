typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 a, b; } P8;
extern s32 D_004CAAF0;
extern s32 D_004CAAF4[8];
extern P8 D_004CA210[128];
void func_0012E4C0(void) {
    u32 i;
    P8 *q;
    s32 *w = D_004CAAF4;
    D_004CAAF0 = 0;
    for (i = 0; i < 8; i++) w[i] = 0;
    q = D_004CA210;
    for (i = 0; i < 128; i++) {
        q->a = 0;
        q->b = 0;
        q++;
    }
}

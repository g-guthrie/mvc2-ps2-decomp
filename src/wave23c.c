typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;


typedef struct { f32 x, y; } V2_001CABF0;
typedef struct { u8 p0[6]; u8 c6; u8 p1[0x149]; union { V2_001CABF0 v150; struct { u8 pad[2]; s8 c152; s8 c153; } b; } u; s32 w158, w15C, w160; V2_001CABF0 *p164; u8 p2[0x10]; s32 w178; } S_001CABF0;
extern s8 D_0044DA50[];
void func_001CABF0(S_001CABF0 *a) {
    s8 c = a->u.b.c152 - 1;
    a->u.b.c152 = c;
    if (c == 0) {
        do {
            a->p164 = a->p164 + 1;
            if (a->u.b.c153 & 0x80) a->p164 = (V2_001CABF0 *)(a->w178 + *(s32 *)a->p164);
            a->u.v150 = *a->p164;
            a->w158 = 0;
            a->w15C = 0;
            a->w160 = 0;
            a->u.b.c152 = D_0044DA50[a->c6];
        } while (a->u.b.c152 == 0);
    }
}

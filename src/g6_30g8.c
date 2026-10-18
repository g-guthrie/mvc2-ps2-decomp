typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s8 *D_004C29C4;
typedef struct { u8 pad[0x1C]; s16 f; } S1C;
void func_0038E6B0(S1C *p) {
    s16 v = p->f - 1;
    p->f = v;
    if (v <= 0) {
        p->f = 2;
        *D_004C29C4 += 1;
        if (*D_004C29C4 >= 8) *D_004C29C4 = 5;
    }
}

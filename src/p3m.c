typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 pad0; s32 w; s32 h; } G3F5E60;
extern s32 func_003F5C30(s32, s32, s32);
extern void func_003F5C00(void *, s32, s32, s32);

s32 func_003F5E60(G3F5E60 *g, s32 c) {
    s32 j, i;
    for (i = 0; i < g->h; i++) {
        for (j = 0; j < g->w; j++) {
            func_003F5C00(g, j, i, func_003F5C30(j, i, c));
        }
    }
    return 1;
}

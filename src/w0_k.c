typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s8 b0; u8 b1; u8 b2; u8 b3; u8 b4; u8 pad[0x17]; s32 w1c; s32 w20[1]; u8 rest[0x4D8 - 0x24]; } R;
extern R D_00485F80[4];
R *func_004051B8(s32 n, s32 v, s32 *src) {
    s32 i;
    s32 j;
    R *r;
    for (i = 0; i < 4; i++) {
        if (D_00485F80[i].b0 == 0) break;
    }
    if (i == 4) return 0;
    r = &D_00485F80[i];
    r->w1c = v;
    r->b1 = 0;
    for (j = 0; j < n; j++) r->w20[j] = src[j];
    r->b2 = n;
    r->b3 = 0;
    r->b4 = 0;
    r->b0 = 1;
    return r;
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u32 D_00439940[];
extern u8 D_004AB388;
extern s32 func_0011FE88(void *, u32);

extern void func_00102498(void *, s32, s32);

s32 func_00102B88(u32 *p, u32 n, s32 mode, s32 x) {
    if (mode == 1) {
        return p[4] < n;
    }
    func_00102498(p, n, x);
    return 0;
}

typedef struct { u8 pad[0x1A]; s16 h; s32 w; } Q;
s32 func_003EAB40(Q *p) {
    if (p->h == 1) {
        return 2;
    }
    switch (p->w) {
    case 0:
    case 1:
        return 4;
    case 2:
        return 4;
    }
}

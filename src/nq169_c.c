/* MWCC 3.0.3: ./try.sh src/nq169_c.c "-O3 -Op -sdatathreshold 0" (also matches on 3.0) */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s8 D_004762D0[];

typedef struct {
    u8 pad0[0x34]; f32 f34; f32 f38;
} A;
typedef struct {
    u8 pad0[0x38]; f32 f38;
} C;
typedef struct {
    u8 pad0[0x34]; f32 f34; f32 f38;
    u8 pad1[0x180 - 0x3C]; u8 *p180;
    u8 pad2[0x1E6 - 0x184]; u8 b1E6;
    u8 pad3[0x430 - 0x1E7]; f32 f430;
} B;

void func_003C9CA0(u8 *a, u8 *b) {
    s16 *t;
    s8 fl;
    u8 dir;
    f32 d, dx, off, dy, lim2, v;
    if (b == 0) return;
    if (b[3] != 0) return;
    if (b[5] != 3) return;
    if ((fl = D_004762D0[a[0x22]]) == 0) return;
    t = (s16 *)(((B *)b)->p180 + 0x7E0);
    dir = ((B *)b)->b1E6;
    d = 1.6666666269302368f * (f32)t[0];
    if (dir) d = -d;
    d += ((B *)b)->f34;
    off = 0.0f;
    if (dir) off = -off;
    off += ((A *)a)->f34;
    d -= off;
    if (d < 0.0f) d = -d;
    dx = (106.66666412353516f + 1.6666666269302368f * (f32)t[1]) - d;
    if (dx < 0.0f) return;
    dy = 2.142857074737549f * (f32)t[2];
    dy = *(f32 *)((s32)b + 0x38) + dy;
    dy -= ((A *)a)->f38;
    if (dy < 0.0f) dy = -dy;
    lim2 = 137.14285278320312f + 2.142857074737549f * (f32)t[3];
    lim2 -= dy;
    if (lim2 < 0.0f) return;
    if (fl & 1) {
        if (*(s16 *)(a + 0x140) != 0) dx = -dx;
        *(f32 *)((s32)b + 0x34) += dx;
    }
    if (D_004762D0[a[0x22]] & 2) {
        if (lim2 < 0.0f) {
            ((C *)b)->f38 = *(f32 *)((s32)a + 0x38);
            lim2 = -lim2;
        }
        {
            f32 lo;
            v = ((B *)b)->f38;
            lo = ((B *)b)->f430;
            v -= lim2;
            ((A *)b)->f38 = v;
            if (v < lo) *(f32 *)(b + 0x38) = lo;
        }
    }
}

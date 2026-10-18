/* MWCC 3.0.3 -O3 -sdatathreshold 0 (try.sh src/p1c.c). */
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

/* Recipe 2: the leaf is static with a real body so $a3 stays live across it. */
static s32 func_003F1F90(s32 a, s32 b) {
    s32 t = a & b;
    s32 u = t | b;
    s32 w = u ^ a;
    return (t ^ w) + u + (a << 2);
}
s32 func_003F2550(s32 a, s32 i) {
    s32 r = func_003F1F90(a, 0x4000);
    s32 off = i * 8;
    if (r == 0) return 0;
    r += 12;
    return r + off;
}

/* Spin until both poll results are zero; the busy-wait carries six nops. */
extern s32 func_00104990(s32 n);
void func_0041BAD0(void) {
    while (func_00104990(2) | func_00104990(1)) {
        asm { nop; nop; nop; nop; nop; nop }
    }
}

typedef struct {
    f32 x, y, z;
    s32 c;
} V417CB0;
extern void func_00417AE0(s32 n, V417CB0 *v, f32 x, f32 y, f32 z, f32 w, f32 h);
void func_00417CB0(s32 c0, s32 c1, s32 c2, s32 c3, f32 x, f32 y, f32 z, f32 w, f32 h) {
    V417CB0 v[4];
    f32 xw, yh;
    if (w < 1.0f) w = 1.0f;
    if (h < 1.0f) h = 1.0f;
    yh = y + h;
    xw = x + w;
    v[0].c = c0;
    v[2].c = c1;
    v[1].c = c2;
    v[3].c = c3;
    v[0].x = x;
    v[0].y = y;
    v[2].y = y;
    v[1].x = x;
    v[1].y = yh;
    v[3].y = yh;
    v[2].x = xw;
    v[3].x = xw;
    v[2].z = z;
    v[1].z = z;
    v[0].z = z;
    func_00417AE0(4, v, x, y, z, w, h);
}

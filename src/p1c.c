/* MWCC 3.0.3 -O3 -sdatathreshold 0 (try.sh src/p1c.c). */
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

/* Native format-record lookup; matches the canonical w2_f implementation. */
extern u32 *func_003F1F90(u32 *p, u32 key);

/* func_003F2550: not yet matched without a stand-in callee. */

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

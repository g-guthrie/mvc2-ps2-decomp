typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F7FD0[];
extern f32 D_004F7FD4[];
extern s32 D_004C2888;

typedef struct {
    f32 x0, y0, z0, w0;
    f32 x1, y1, z1, w1;
    s32 c;
    f32 v[4];
} Q421;

void func_00421FB0(f32 f, s32 unused, s32 *a, f32 *b, s32 c) {
    extern void func_003EA660();
    extern void func_003DF850();
    extern void func_003DF490();
    Q421 q;
    func_003EA660(1, &D_004C2888);
    func_003DF850(4, D_004C2888);
    q.c = c;
    q.x0 = (f32)a[0] + 1.5f * D_004F7FD0[0];
    q.y0 = (f32)a[1] + D_004F7FD4[0];
    q.x1 = (f32)a[2] + 1.5f * D_004F7FD0[0];
    q.y1 = (f32)a[3] + D_004F7FD4[0];
    q.w1 = 1.0f;
    q.w0 = 1.0f;
    q.z1 = f;
    q.z0 = f;
    q.v[0] = b[0];
    q.v[1] = b[1];
    q.v[2] = b[2];
    q.v[3] = b[3];
    func_003DF490(&q);
}

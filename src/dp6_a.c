typedef signed int s32;
typedef float f32;
typedef struct { s32 a[6]; } S24;

void func_004180F0(f32 x, f32 y, f32 w, f32 h)
{
    extern S24 D_004F8040, D_004F8020;
    extern void func_003DF850();
    S24 v;
    v = D_004F8040;
    if (y < 0.0f) {
        v.a[1] = (s32)((f32)v.a[1] + y);
    } else {
        v.a[1] = (s32)((f32)v.a[1] + y);
    }
    if (x < 0.0f) {
        v.a[0] = (s32)((f32)v.a[0] + x);
    } else {
        v.a[0] = (s32)((f32)v.a[0] + x);
    }
    D_004F8020 = v;
    v.a[1] = -16;
    func_003DF850(24, &v);
}

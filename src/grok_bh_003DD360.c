typedef float f32;
typedef signed int s32;

extern void func_003DD260(f32 *);
extern f32 func_003DE790(f32);
extern f32 func_003DE710(f32);

void func_003DD360(f32 *m, f32 nearz, f32 farz, f32 fov, f32 aspect)
{
    f32 h, s, c, cot, d;
    h = fov * 0.5f;
    s = func_003DE790(h);
    c = func_003DE710(h);
    func_003DD260(m);
    cot = c / s;
    m[0] = cot / aspect;
    m[5] = cot;
    d = nearz - farz;
    m[10] = -(nearz + farz) / d;
    *(s32 *)&m[11] = 0xBF800000;
    m[14] = -(2.0f * nearz * farz) / d;
    *(s32 *)&m[15] = 0;
}

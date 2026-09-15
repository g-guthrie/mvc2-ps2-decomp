typedef signed int s32;
typedef float f32;

extern s32 D_0062BF8C;
extern s32 D_0062BF90;
extern s32 D_0062BC00;
extern f32 D_004F8094;
extern f32 D_004F8098;
extern f32 D_004F809C;
extern f32 D_004F8060[];
extern char D_00632770[];

extern void func_003DF850(s32, void *);
extern void func_003DD260(void *);

f32 func_003E0C20(f32 x)
{
    f32 t = (f32)D_0062BF8C;
    x = x - t;
    return x;
}

f32 func_003E0C40(f32 x)
{
    f32 t = (f32)D_0062BF90;
    x = x - t;
    if (D_0062BC00 == 0)
        x = x * 0.5f;
    return x;
}

s32 func_003F0B20(s32 *p)
{
    if (p[3])
        return (p[5] + p[1]) - p[4] - p[8];
    return (p[4] - (p[5] - p[1])) - p[8];
}

void func_00414C30(f32 *p)
{
    D_004F8094 = p[0];
    D_004F8098 = p[1];
    D_004F809C = p[2];
    func_003DF850(89, D_004F8060);
}

void func_00417950(void)
{
    func_003DD260(D_00632770);
    func_003DF850(25, D_00632770);
}

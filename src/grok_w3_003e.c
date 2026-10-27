typedef signed int s32;
typedef float f32;

extern s32 D_0062BF8C;
extern s32 D_0062BF90;
extern s32 D_0062BC00;
extern f32 D_004F8094;
extern f32 D_004F8098;
extern f32 D_004F809C;
extern f32 D_004F8060[];
extern f32 D_00632770[];

extern void func_003DF850(s32, void *);
extern void func_003DD260(f32 *);




void func_00414C30(f32 *p)
{
    D_004F8094 = p[0];
    D_004F8098 = p[1];
    D_004F809C = p[2];
    func_003DF850(89, D_004F8060);
}

/* All three direct callers supply the legacy 640x480 float parameters. */
void func_00417950(f32 width, f32 height)
{
    func_003DD260(D_00632770);
    func_003DF850(25, D_00632770);
}

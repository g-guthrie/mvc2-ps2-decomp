typedef float f32;
typedef signed int s32;

extern f32 D_0061BDA0[];
extern f32 D_0062BC30;
extern f32 D_004C2A8C;
extern f32 D_004C2A88;
extern void func_003DD260(f32 *);

void func_003DD930(s32 x, s32 y, s32 w, s32 h, f32 z0, f32 z1)
{
    f32 hw = (f32)(w / 2);
    f32 hh = (f32)(h / 2);
    func_003DD260(D_0061BDA0);
    D_0061BDA0[14] = z0;
    D_0061BDA0[0] = hw;
    D_0061BDA0[15] = 1.0f;
    D_0061BDA0[10] = z1 - z0;
    D_0061BDA0[12] = (f32)x + hw;
    D_0061BDA0[12] = D_004C2A8C;
    D_0061BDA0[13] = (f32)y + hh;
    D_0061BDA0[5] = -hh;
    D_0061BDA0[13] = D_004C2A88;
    D_0061BDA0[10] = 0.5f * (-D_0062BC30) * D_0061BDA0[10];
    D_0061BDA0[14] = 0.5f * D_0062BC30;
}

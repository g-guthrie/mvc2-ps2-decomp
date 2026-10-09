typedef signed int s32;
typedef float f32;

extern s32 D_004C2B40;
extern f32 D_00632770[];
extern f32 D_006327B0[];
extern void func_003DD260(f32 *matrix);
extern void func_003DDB60(f32 *matrix, f32 x, f32 y, f32 z);
extern void func_003DE160(f32 *destination, f32 *left, f32 *right);

void func_004173C0(f32 x, f32 y, f32 z)
{
    func_003DD260(D_00632770);
    func_003DDB60(D_00632770, x, y, z);
    func_003DE160(D_006327B0 + (D_004C2B40 << 4),
                  D_006327B0 + (D_004C2B40 << 4),
                  D_00632770);
}

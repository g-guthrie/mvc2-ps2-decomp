typedef float f32;

extern f32 D_0061BEE0[16];
extern f32 D_0061C720[16];
extern f32 D_0061BE60[16];
extern void func_003DD260(f32 *matrix);
extern void func_003DE160(f32 *destination, f32 *left, f32 *right);
extern void func_003DE480(f32 *destination, f32 *source, f32 *matrix);

void func_003DE680(f32 *destination, f32 *source)
{
    f32 matrix[16];

    func_003DD260(matrix);
    func_003DE160(matrix, D_0061BEE0, D_0061C720);
    func_003DE160(matrix, matrix, D_0061BE60);
    func_003DE480(destination, source, matrix);
}

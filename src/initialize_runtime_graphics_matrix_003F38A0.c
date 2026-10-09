typedef signed int s32;
typedef float f32;

extern void func_003F55B0(void *destination, s32 value, s32 size);

void func_003F38A0(f32 *matrix)
{
    func_003F55B0(matrix, 0, 64);
    matrix[0] = 1.0f;
    matrix[5] = 1.0f;
    matrix[10] = 1.0f;
    matrix[15] = 1.0f;
}

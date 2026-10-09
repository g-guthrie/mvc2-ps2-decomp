typedef float f32;
typedef signed int s32;

extern s32 D_004C2B40;
extern f32 D_006327B0[];
extern void func_003DE480(f32 *destination, f32 *source, f32 *matrix);

void func_00417E30(f32 *source, f32 *destination)
{
    f32 input[4];
    f32 output[4];

    input[0] = source[0];
    input[1] = source[1];
    input[2] = source[2];
    input[3] = 1.0f;
    func_003DE480(output, input, D_006327B0 + (D_004C2B40 << 4));
    destination[0] = output[0];
    destination[1] = output[1];
    destination[2] = output[2];
}

typedef float f32;

extern void func_003DE3D0(f32 *destination, f32 *left, f32 *right);

void func_003DE480(f32 *destination, f32 *source, f32 *matrix)
{
    f32 point[4];
    f32 w;
    f32 reciprocal;

    point[0] = source[0];
    point[1] = source[1];
    point[2] = source[2];
    point[3] = 1.0f;
    func_003DE3D0(destination, point, matrix);

    w = destination[3];
    if (w != 0.0f) {
        reciprocal = 1.0f / w;
        destination[0] *= reciprocal;
        destination[1] *= reciprocal;
        destination[2] *= reciprocal;
    } else {
        destination[3] = 0.0f;
        destination[2] = 0.0f;
        destination[1] = 0.0f;
        destination[0] = 0.0f;
    }
}

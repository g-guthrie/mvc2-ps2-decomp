/* Normalize three negated input vectors and finish the native matrix basis. */
typedef float f32;
typedef struct Vector4 { f32 x, y, z, w; } Vector4;
typedef struct Matrix4 { Vector4 row[4]; } Matrix4;
extern void func_00102ED8(void *destination, const void *source, f32 weight);
extern void func_00102D30(void *destination, const void *source);
extern void func_00102D70(void *destination, const void *source);
void func_00103358(Matrix4 *destination, const Vector4 *first, const Vector4 *second, const Vector4 *third) {
    Vector4 row;
    func_00102ED8(&row, first, -1.0f);
    func_00102D30(&destination->row[0], &row);
    func_00102ED8(&row, second, -1.0f);
    func_00102D30(&destination->row[1], &row);
    func_00102ED8(&row, third, -1.0f);
    func_00102D30(&destination->row[2], &row);
    destination->row[3].x = destination->row[3].y = destination->row[3].z = 0.0f;
    destination->row[3].w = 1.0f;
    func_00102D70(destination, destination);
}

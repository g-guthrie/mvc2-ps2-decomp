/* Project three float coordinates; callers need only the first two outputs. */
typedef float f32;
extern void func_00122FE0(void);
extern void func_00417950(f32 width, f32 height);
extern void func_00417980(f32 x, f32 y, f32 z, f32 *outX, f32 *outY, f32 *outZ);
void func_001741D0(const f32 *point, f32 *output)
{
    f32 depth;
    func_00122FE0();
    func_00417950(640.0f, 480.0f);
    func_00417980(point[0], point[1], point[2], output, output + 1, &depth);
}

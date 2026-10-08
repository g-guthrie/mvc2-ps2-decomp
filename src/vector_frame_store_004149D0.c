typedef float f32;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

extern volatile Vec3 D_00632730;
extern volatile Vec3 D_00632720;
extern volatile Vec3 D_00632710;
extern volatile f32 D_004C2B28;

void func_004149D0(const Vec3 *a, const Vec3 *b, const Vec3 *c, f32 marker)
{
    D_00632730 = *a;
    D_00632720 = *b;
    D_00632710 = *c;
    D_004C2B28 = marker;
}

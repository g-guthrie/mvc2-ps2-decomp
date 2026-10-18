typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
struct RuntimeVector3 { float x; float y; float z; };
extern s32 D_004C2B40;
extern u8 D_00632770[];
extern u8 D_006327B0[];
extern void func_003DD260(void *matrix);
extern void func_003DDB20(void *matrix, float x, float y, float z);
extern void func_003DDB60(void *matrix, float x, float y, float z);
extern void func_003DE160(void *destination, const void *source,
                         const void *matrix);
void func_00417170(const struct RuntimeVector3 *vector)
{
    void *object;
    func_003DD260(D_00632770);
    func_003DDB20(D_00632770, vector->x, vector->y, vector->z);
    object = D_006327B0 + (D_004C2B40 << 6);
    func_003DE160(object, object, D_00632770);
}
void func_00417200(const struct RuntimeVector3 *vector)
{
    void *object;
    func_003DD260(D_00632770);
    func_003DDB60(D_00632770, vector->x, vector->y, vector->z);
    object = D_006327B0 + (D_004C2B40 << 6);
    func_003DE160(object, object, D_00632770);
}

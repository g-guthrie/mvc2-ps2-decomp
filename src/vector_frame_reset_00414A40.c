typedef unsigned int u32;
typedef float f32;

extern void *func_0011D8F8(void *destination, int value, u32 size);
extern volatile f32 D_00632730[3];
extern volatile f32 D_00632720[3];
extern volatile f32 D_00632710[3];
extern volatile u32 D_004C2B2C;
extern volatile f32 D_004C2B28;

void func_00414A40(void)
{
    D_004C2B2C = 0;
    func_0011D8F8((void *)D_00632730, 0, 12);
    func_0011D8F8((void *)D_00632720, 0, 12);
    func_0011D8F8((void *)D_00632710, 0, 12);
    D_004C2B28 = 0.0f;
}

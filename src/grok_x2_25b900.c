typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);

void func_0025B900(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] != 2) {
        p[6]++;
        p[0x20D] = 2;
        *(int *)(p + 0x5C) = 0;
        *(int *)(p + 0x60) = 0;
        *(int *)(p + 0x68) = 0;
        *(int *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? 12.857142448425293f : -12.857142448425293f;
        *(f32 *)(p + 0x68) = p[0x1E6] ? -0.2678571343421936f : 0.2678571343421936f;
        *(f32 *)(p + 0x60) = 27.857141494750977f;
        *(f32 *)(p + 0x6C) = -1.0714285373687744f;
    }
}

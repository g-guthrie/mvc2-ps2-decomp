typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00184540(u8 *);
void func_0030DEF0(u8 *p)
{
    f32 *speed;
    f32 *acceleration;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) < 0)
        return;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    speed = (f32 *)(p + 0x5C);
    acceleration = (f32 *)(p + 0x68);
    if (*speed * *acceleration < 0.0f)
        return;
    *speed = 0.0f;
    *acceleration = 0.0f;
    if (p[0x20D] == 2) {
        *(u32 *)(p + 0x2C0) = 12;
        func_00184540(p);
        return;
    }
    p[6]++;
    func_001757E0(p, 21, (u8)(p[0x1B7] + 3));
}

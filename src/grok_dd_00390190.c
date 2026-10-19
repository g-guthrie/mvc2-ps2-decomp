typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);

void func_00390190(u8 *p)
{
    if ((*(u8 **)(p + 0x18))[0x1E4] != 0x14)
        p[0x22] = 1;
    if (*(s8 *)(p + 0x151) != 0) {
        p[6]++;
        *(f32 *)(p + 0x68) *= 4.0f;
        *(f32 *)(p + 0x6C) *= 4.0f;
    }
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34) + *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38) + *(f32 *)(p + 0x60);
    func_00175700(p);
}

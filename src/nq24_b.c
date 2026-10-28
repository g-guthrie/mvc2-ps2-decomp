typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void residual_0031A730(u8 *a, u8 *b)
{
    extern void func_00175700(u8 *);
    extern void func_00154790(f32 *, u8, s32, s32);
    extern void func_001E3B70(u32, s32);
    f32 v[4];
    u32 t;

    func_00175700(a);
    if (a[0x15B] == 0) return;
    a[0x15B] = 0;
    t = a[6];
    a[6] = t + 1;
    *(u8 **)(b + 0x1C8) = a;
    b[0x1B5] = 0x20;
    b[0x20A] = 0x12;
    *(u32 *)&v[0] = 0x42B40000;
    if (*(s16 *)(a + 0x140) != 0) v[0] = v[0];
    v[0] += *(f32 *)(a + 0x34);
    v[1] = 285.0f + *(f32 *)(a + 0x38);
    func_00154790(v, a[0x1E6], 2, 0);
    func_001E3B70(*(u32 *)(a + 0x1DC), 0);
}

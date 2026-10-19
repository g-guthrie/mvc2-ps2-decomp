typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_0018C4B0(u8 *, int);
extern void func_002D3230(u8 *);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);
extern f32 D_004F1F4C;

void residual_002D3D40(u8 *p, int a1)
{
    f32 t;

    p[6]++;
    func_0018C4B0(p, a1);
    func_002D3230(p);
    *(s16 *)(p + 0x1C) = 1;
    func_00183D10(p);
    {
        u16 f;
        if (*(s8 *)(p + 0x539))
            f = *(u16 *)(p + 0x20E);
        else
            f = *(u16 *)(p + 0x35E);
        if (f & 0x400) {
            *(s16 *)(p + 0x140) ^= 1;
            p[0x1E6] = *(s8 *)(p + 0x140);
        }
    }
    *(u32 *)(p + 0x60) = 0x41892492;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    if (p[0x1E6])
        t = 640.0f + D_004F1F4C;
    else
        t = D_004F1F4C - 746.66668701171875f;
    *(f32 *)(p + 0x5C) = (t - *(f32 *)(p + 0x34)) / 20.0f;
    *(u32 *)(p + 0x68) = 0;
    *(s16 *)(p + 0x1E) = 20;
    func_001757E0(p, 21, 15);
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_0018C4B0(u8 *, int);
extern void func_002D3230(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);
extern f32 D_004F1F4C;

void func_002D3D40(u8 *p, int a1)
{
    f32 t;
    u16 f;

    p[6]++;
    func_0018C4B0(p, a1);
    func_002D3230(p);
    *(s16 *)(p + 0x1C) = 1;
    func_00183D10(p);
    if (*(s8 *)(p + 0x539))
        f = *(u16 *)(p + 0x20E);
    else
        f = *(u16 *)(p + 0x35E);
    if (f & 0x400) {
        *(s16 *)(p + 0x140) ^= 1;
        p[0x1E6] = *(s8 *)(p + 0x140);
    }
    *(u32 *)(p + 0x60) = 0x41892492;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    if (p[0x1E6])
        t = 640.0f + D_004F1F4C;
    else
        t = D_004F1F4C - 746.66668701171875f;
    t -= *(f32 *)(p + 0x34);
    t /= 20.0f;
    *(f32 *)(p + 0x5C) = t;
    *(u32 *)(p + 0x68) = 0;
    *(s16 *)(p + 0x1E) = 20;
    func_001757E0(p, 21, 15);
}

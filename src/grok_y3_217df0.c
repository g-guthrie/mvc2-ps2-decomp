typedef unsigned char u8;
typedef signed short s16;
typedef int s32;
typedef float f32;

extern int func_001757E0(u8 *, int, int);
extern void func_00217EA0(u8 *);

void func_00217DF0(u8 *p)
{
    f32 f1;
    f32 f2;

    p[7]++;
    p[0x20D] = 2;
    *(s16 *)(p + 0x1C) = 0x20;
    *(s32 *)(p + 0x60) = 0x41AB6DB6;
    *(s32 *)(p + 0x6C) = 0xBF2B6DB6;
    f1 = -213.3333282470703f;
    f2 = 3.3333332538604736f;
    if (p[2]) {
        f1 = -f1;
        f2 = -f2;
    }
    *(f32 *)(p + 0x34) += f1;
    *(f32 *)(p + 0x5C) = f2;
    *(int *)(p + 0x68) = 0;
    func_001757E0(p, 18, 0);
    func_00217EA0(p);
}

extern void func_0031D380(u8 *);

/* Unary actor callback witnessed at jtbl_0045DB30[0]. */
void func_0031D2D0(u8 *p)
{
    f32 f1;
    f32 f2;

    p[7]++;
    p[0x20D] = 2;
    *(s16 *)(p + 0x1C) = 0x20;
    *(s32 *)(p + 0x60) = 0x41AB6DB6;
    *(s32 *)(p + 0x6C) = 0xBF2B6DB6;
    f1 = -213.3333282470703f;
    f2 = 3.3333332538604736f;
    if (p[2]) {
        f1 = -f1;
        f2 = -f2;
    }
    *(f32 *)(p + 0x34) += f1;
    *(f32 *)(p + 0x5C) = f2;
    *(int *)(p + 0x68) = 0;
    func_001757E0(p, 18, 0);
    func_0031D380(p);
}

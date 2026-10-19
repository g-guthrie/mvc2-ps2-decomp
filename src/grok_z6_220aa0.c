typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_001E3210(u8 *, int);
extern int func_001757E0(u8 *, int, int);

void func_00220AA0(u8 *p)
{
    u8 *q;
    u8 *r = p + 0x2B8;

    p[6]++;
    func_00185490(p);
    if (p[0x20D] != 2)
        func_00183D10(p);
    func_001E3210(p, 30);
    r[0xD] = 0;
    *(int *)(p + 0x5C) = 0;
    *(int *)(p + 0x60) = 0;
    *(int *)(p + 0x68) = 0;
    *(int *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x34);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x38);
    q = *(u8 **)(p + 0x220);
    if (*(s16 *)(q + 0x140) != 0)
        *(f32 *)(p + 0x68) += -160.0f + *(f32 *)(q + 0x34);
    else
        *(f32 *)(p + 0x68) += 160.0f + *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x6C) = *(f32 *)(*(u8 **)(p + 0x220) + 0x38);
    func_001757E0(p, 21, 43);
}

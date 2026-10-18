/* Place the actor effect relative to its owner and launch eight children. */
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y; } E8_36a;
extern E8_36a D_00463A40[];

void func_0036AE90(u8 *p)
{
    extern void func_0036AA70();
    extern s32 func_001757E0(u8 *, s32, s32);
    E8_36a *e;
    f32 k;
    u32 i;
    e = D_00463A40;
    p[0x13C] = 1;
    p[0x24] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    e += p[0x21];
    if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) k = e->x;
    else k = -e->x;
    *(f32 *)(p + 0x34) += k;
    *(f32 *)(p + 0x38) += e->y;
    for (i = 0; (u8)i < 8; i = (u8)(i + 1)) func_0036AA70(p, 4, i);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001757E0(p, 0x17, 3);
}

typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y; } V2;

extern void func_001757E0(u8 *, s32, s32);
extern void func_00163930(f32 *, s16);
extern void func_001E3710(u8 *, s32);

void func_0017CAA0(u8 *p)
{
    f32 buf[3];
    V2 *q;

    p[6]++;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    func_001757E0(p, 0x18, 1);
    p[0x268] = 3;
    q = (V2 *)buf;
    *q = *(V2 *)(p + 0x260);
    buf[2] = *(f32 *)(p + 0x3C);
    func_00163930(buf, *(s16 *)(p + 0x140));
    func_001E3710(p, 0x3F);
}

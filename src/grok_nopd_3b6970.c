typedef unsigned char u8;
typedef float f32;

extern void func_0015B200(u8 *, f32 *, int, int);
extern void func_001E3710(u8 *, int);

void residual_003B6970(u8 *p)
{
    u8 *owner;

    owner = *(u8 **)(p + 24);
    p[4]++;
    func_0015B200(owner, (f32 *)(p + 52), 1, 1033);
    func_001E3710(p, 73);
}

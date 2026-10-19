typedef unsigned char u8;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern void func_001E3210(u8 *, int);

void func_001FA860(u8 *p)
{
    p[6]++;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    func_001757E0(p, 20, 5);
    func_001E3210(p, 17);
}

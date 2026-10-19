typedef unsigned char u8;
typedef float f32;
typedef unsigned int u32;

extern void func_00185490(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_0021B410(u8 *p)
{
    p[6]++;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    func_00185490(p);
    func_001757E0(p, 20, 0);
}

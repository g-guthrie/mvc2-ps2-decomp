typedef unsigned char u8;
typedef signed short s16;
typedef float f32;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001E3210(u8 *, int);
void func_00302760(u8 *p)
{
    s16 timer;
    func_00175700(p);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    timer = *(s16 *)(p + 0x1C);
    timer--;
    *(s16 *)(p + 0x1C) = timer;
    if (timer != 0)
        return;
    p[6]++;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    *(s16 *)(p + 0x1C) = 10;
    func_001757E0(p, 18, 3);
    func_001E3210(p, 10);
}

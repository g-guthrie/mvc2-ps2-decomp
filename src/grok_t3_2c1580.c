typedef unsigned char u8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_002C1580(u8 *p)
{
    func_00175700(p);
    {
        f32 vx = *(f32 *)(p + 92);
        f32 z = 0;
        if (vx == z) {
        p[7]++;
        *(f32 *)(p + 92) = 0;
        *(f32 *)(p + 104) = 0;
        func_001757E0(p, 10, (p[0x1B7] + 6) & 0xFF);
        }
    }
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern s32 D_004BFEF8[8];
extern void func_001757E0(u8 *, int, int);

void residual_00219A20(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        *(u16 *)(p + 0x1C) = 4;
        p[0x206] = 3;
        {
            f32 f0;
            f32 f1;
            *(u32 *)&f0 = 0x47800000;
            *(u32 *)&f1 = 0x3FD55555;
            f1 = f1 * (f32)D_004BFEF8[p[0x1B7]];
            *(f32 *)(p + 0x5C) = f1 / f0;
        }
        if (p[0x1E6])
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        func_001757E0(p, 21, 0x27);
    }
}

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_001757E0(u8 *, int, int);

void residual_00350DA0(u8 *p)
{
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    if (--*(s16 *)(p + 28) == 0) {
        p[5]++;
        *(u32 *)(p + 96) = 0x404DB6DBu;
        *(u32 *)(p + 108) = 0x3E092492u;
        func_001757E0(p, 23, 1);
    }
}

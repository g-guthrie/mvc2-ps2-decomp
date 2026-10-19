typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);

void residual_00310DB0(u8 *p)
{
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[6]++;
        *(u32 *)(p + 92) = 0xC1700000u;
        *(u32 *)(p + 104) = 0x3DD55555u;
        *(u32 *)(p + 96) = 0xC11A4924u;
        *(u32 *)(p + 108) = 0xBE092492u;
        if (*(s16 *)(p + 320) != 0) {
            *(f32 *)(p + 92) = -*(f32 *)(p + 92);
            *(f32 *)(p + 104) = -*(f32 *)(p + 104);
        }
    }
}

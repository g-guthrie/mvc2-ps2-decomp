/* ./try.sh src/grok_bg_00319D90.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern int func_00175700(u8 *);
extern void func_00319D40(u8 *, f32 *);

void func_00319D90(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        int a = 86;
        int b = 84;
        p[0x151] = 0;
        p[6]++;
        p[0x1B5] = (u8)(b < p[0x1B7]);
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_00319D40(p, (f32 *)(0x0046D8F0u + ((u32)p[0x1B7] << 4)));
        (void)a;
    }
}

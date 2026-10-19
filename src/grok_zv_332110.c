typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_004B78D0[];
extern f32 D_004B78C8[];
extern double func_00119058(f32);
extern void func_00332270(u8 *);

void func_00332110(u8 *p)
{
    s16 *record = D_004B78D0;
    int i;
    f32 f;
    for (i = 0; i < p[4]; ++i)
        record += *record * 2;
    p[7] = *(s8 *)record;
    record += p[7];
    f = D_004B78C8[*record];
    *(u32 *)(p + 0x40) = (u16)(u32)(0.5 + 65536.0 * func_00119058(f) / 360.0);
    p[5] = p[5] + 1;
    func_00332270(p);
}

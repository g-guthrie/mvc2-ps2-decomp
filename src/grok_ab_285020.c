typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern s32 func_00185980(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00185770(u8 *, s32);
extern void func_00383B80(u8 *, s32, s32);
extern void func_00184540(u8 *);

void func_00285020(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (func_00185980(p) == 0) {
            p[6] = 5;
            p[0x210] = 0;
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            p[0x1ED] = 2;
            if (p[0x1E6])
                *(s32 *)(p + 0x5C) = 0x40200000;
            else
                *(s32 *)(p + 0x5C) = 0xC0200000;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x60) = 0x41892492;
            *(s32 *)(p + 0x6C) = 0xBF4DB6DB;
            func_001757E0(p, 0x16, 0xD);
        } else {
            p[6]++;
            p[0x20B] = 0xC2;
            func_00185770(p, *(s32 *)(p + 0x1C4));
            func_00383B80(p, 8, 0);
        }
    } else {
        if ((s16)(--*(s16 *)(p + 0x1C)) == 0) {
            p[0x1E7] = 0;
            func_00184540(p);
        }
    }
}

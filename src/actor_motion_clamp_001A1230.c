typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;

extern u16 D_004D18DC;
extern u8 D_004D18DB;

void func_001A1230(u8 *p, u8 *q)
{
    extern s32 func_00175700(u8 *);
    f32 *r5c, *r60, *r68, *r6c;

    if ((D_004D18DC & (1 << D_004D18DB)) == 0) {
        if ((s8)func_00175700(p) < 0) {
            p[4] = 2;
            p[0x13C] = 0;
        } else {
            r5c = (f32 *)(p + 0x5C);
            r68 = (f32 *)(p + 0x68);
            r60 = (f32 *)(p + 0x60);
            r6c = (f32 *)(p + 0x6C);
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
            if (*(f32 *)(p + 0x38) < *(f32 *)(q + 0x430)) {
                *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
                *r5c = 0;
                *r60 = 0;
                *r68 = 0;
                *r6c = 0;
            }
        }
    }
}

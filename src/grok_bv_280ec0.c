typedef unsigned char u8;
typedef signed int s32;

extern s32 func_00280D80(void);
extern s32 func_00281040(u8 *, u8 *);
extern s32 func_00174170(void);
extern u8 D_004B7500[];
extern s32 D_004554D0[];

s32 func_00280EC0(u8 *p)
{
    u8 n;
    if (*(s32 *)(p + 0x4C4) & 1)
        return 0;
    n = (u8)func_00280D80();
    if (n >= 4) {
        *(s32 *)(p + 0x4C4) |= 1;
        if (func_00281040(p, D_004B7500)) {
            p[0x450] = 2;
            p[0x451] = 0;
            p[0x452] = 0;
            p[0x453] = 0;
            p[0x495] = 0;
            p[0x496] = 1;
            *(s32 *)(p + 0x484) = D_004554D0[func_00174170() & 3];
            return 1;
        }
    }
    return 0;
}

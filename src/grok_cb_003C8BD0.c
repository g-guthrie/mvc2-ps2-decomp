typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern s32 func_00174240(u8 *);
extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern s16 D_004C2170[];

void func_003C8BD0(u8 *p)
{
    s16 v;
    if (D_004D18DC & (1 << D_004D18DB)) {
        if (func_00174240(p))
            p[0x13C] = 1;
        else
            p[0x13C] = 0;
        return;
    }
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = D_004C2170[p[0x20]];
        *(s16 *)(p + 0x1E) = 1;
        return;
    }
    if (func_00174240(p))
        p[0x13C] = 1;
    else
        p[0x13C] = 0;
}

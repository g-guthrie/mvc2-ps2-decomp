typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern void func_001E7F60(u8 *);
extern void func_003C80A0(u8 *, u8 *);
extern u8 *D_004C2794;
extern f32 D_004F1FD0;

void func_003C7740(u8 *p, u8 *q)
{
    if (*(s8 *)(p + 0x1B4) != 0) {
        p[0x1B4] = *(s8 *)(p + 0x1B4) - 1;
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s16 *)(p + 0x1C) != 0 && *(s8 *)(p + 0x1B2) != 0) {
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
        p[0x1B5] = 0x26;
        *(s16 *)(p + 0x1C0) = 0;
        p[0x1B2] = 0;
        *(s32 *)(p + 0x1D8) = 0;
        *(s16 *)(D_004C2794 + p[2] * 2 + 0x7C) += 1;
    }
    if (D_004F1FD0 <= *(f32 *)(p + 0x38))
        func_003C80A0(p, q);
    else
        func_001E7F60(p);
}

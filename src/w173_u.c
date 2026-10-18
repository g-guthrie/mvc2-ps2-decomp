typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FE0;
extern u8 D_00448FB0[];

s32 func_0018A580(u8 *p)
{
    u32 a;
    f32 f;
    if (*(s8 *)(p + 0x206) != 0 || *(s8 *)(p + 0x207) != 0) return 0;
    a = p[0x1E4];
    if (a == 0x12 || a == 0x13) {
        if (*(s8 *)(p + 0x1F2) != 0) return 0;
    }
    if (p[0x15A] & 0x20) return 0;
    if (p[5] != 0) return 0;
    if (a == 0x15) return 0;
    if (a == 0x1C) return 0;
    if ((*(u8 **)(p + 0x220))[0x249] != 0) return 0;
    if (p[0x20D] == 2) {
        f = *(f32 *)(p + 0x38);
        if (f <= *(f32 *)(p + 0x430)) return 0;
        if (!(f < D_004F1FE0 - 68.57142639160156f)) return 0;
    }
    if (D_00448FB0[a & 0xFF] == 0) goto ok;
    return 0;
ok:
    return 1;
}

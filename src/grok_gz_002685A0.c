typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FC8;
extern f32 D_004F1FCC;

void func_002685A0(u8 *p, u8 *q)
{
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    extern s32 func_00268A60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 f2;

    func_001266A0(p, 1, 7);
    *(s16 *)(q + 0x1C) -= 0x800;
    *(s32 *)(p + 0x48) = *(s16 *)(q + 0x1C);
    p[0x209] = 2;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    if (func_00268A60(p) != 0)
        return;
    if (*(s16 *)(p + 0x140) != 0) {
        f2 = D_004F1FC8;
        if (!(*(f32 *)(p + 0x34) <= 40.0f + f2))
            return;
        *(f32 *)(p + 0x34) = 3.3333332538604736f + f2;
    } else {
        f2 = D_004F1FCC;
        if (*(f32 *)(p + 0x34) < f2 - 40.0f)
            return;
        *(f32 *)(p + 0x34) = f2 - 3.3333332538604736f;
    }
    p[6]++;
    *(f32 *)(p + 0x38) -= 51.428569793701172f;
    *(f32 *)(p + 0x60) = -*(f32 *)(p + 0x60);
    p[0x211] = 0;
    *(s32 *)(p + 0x48) = 0;
    func_001757E0(p, 0x15, 0x1D);
    *(s16 *)(q + 0x1C) = 0;
}

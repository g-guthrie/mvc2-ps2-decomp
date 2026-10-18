typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FC8;
extern f32 D_004F1FCC;

void func_00268130(u8 *p, u8 *q)
{
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00186A20(u8 *);
    s16 v;
    u32 t;
    func_001266A0(p, 1, 7);
    v = *(s16 *)(q + 0x1C) - 0x800;
    *(s16 *)(q + 0x1C) = v;
    *(s32 *)(p + 0x48) = *(s16 *)(q + 0x1C);
    p[0x209] = 2;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    if (*(s16 *)(p + 0x140) != 0) {
        if (*(f32 *)(p + 0x34) < D_004F1FCC - 40.0f) {
            return;
        }
        *(f32 *)(p + 0x34) = D_004F1FCC - 3.3333332538604736f;
    } else {
        if (!(*(f32 *)(p + 0x34) <= 40.0f + D_004F1FC8)) {
            return;
        }
        *(f32 *)(p + 0x34) = 3.3333332538604736f + D_004F1FC8;
    }
    *(f32 *)(p + 0x38) += 34.28571319580078f;
    t = p[6];
    p[6] = t + 1;
    *(s32 *)(p + 0x48) = 0;
    func_001757E0(p, 0x15, 0x1C);
    func_00186A20(p);
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FC8[];
void func_001266A0(u8 *p, s32 a, s32 b);
void func_001757E0(u8 *p, s32 a, s32 b);
void func_001E3710(u8 *p, s32 a);
void func_00185490(u8 *p);
void func_00184540(u8 *p);

#define BLOCK9(p) \
    func_001266A0(p, 0, 0); \
    *(s32 *)(p + 0x48) = 0; \
    p[6] = 9; \
    p[0x1E6] = 1; \
    lim = 320.0f + D_004F1FC8[0]; if (lim < *(f32 *)(p + 0x34)) p[0x1E6] = 0; \
    *(s16 *)(p + 0x140) = p[0x1E6]; \
    func_001757E0(p, 0x15, 0x19); \
    *(s32 *)(p + 0x5C) = 0; \
    *(s32 *)(p + 0x60) = 0; \
    *(s32 *)(p + 0x68) = 0; \
    *(s32 *)(p + 0x6C) = 0; \
    *(u32 *)(p + 0x60) = 0xC1809249; \
    v = (p[0x1E6] != 0) ? 20.833332061767578f : -20.833332061767578f; \
    *(f32 *)(p + 0x5C) = v; \
    func_001E3710(p, 0x15);

s32 func_00268A60(u8 *p)
{
    u16 h;
    s32 r;
    f32 v;
    f32 lim;
    f32 x;
    if (*(s8 *)(p + 0x539) != 0) {
        s16 t = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = t;
        if (t < 0) {
            BLOCK9(p)
            return 1;
        }
        return 0;
    }
    if (*(f32 *)(p + 0x38) <= 137.14285278320312f + *(f32 *)(p + 0x430)) return 0;
    h = *(u16 *)(p + 0x4F4);
    if ((h & 0x300) != 0) {
        func_001266A0(p, 0, 0);
        *(s32 *)(p + 0x48) = 0;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        if (p[6] == 5) *(f32 *)(p + 0x38) -= 102.85713958740234f;
        func_00185490(p);
        p[0x210] = 2;
        func_00184540(p);
        return 1;
    }
    if ((h & 0x60) != 0) {
        BLOCK9(p)
        return 1;
    }
    return 0;
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 t[1]; } G230060;
extern G230060 *D_004C2794;
static void func_0022FFB0(u8 *p, u8 *q) {
    f32 a = 16.6666660309f;
    f32 b = 18.3333320618f;
    f32 c = -0.208333328366f;
    if (*(s16 *)(p + 0x140) == 0) { a = -a; b = -b; c = -c; }
    if (p[0x1B7] != 0) *(f32 *)(p + 0x5C) = b; else *(f32 *)(p + 0x5C) = a;
    *(f32 *)(p + 0x68) = c;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
}
void func_00230060(u8 *p, u8 *q) {
    extern void func_00175700(u8 *);
    extern void func_001863F0(u8 *);
    extern void func_0019DE50(u8 *, s32, s32);
    extern void func_002301C0(u8 *, u8 *);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_001863F0(p);
        return;
    }
    {
        u32 t = p[7];
        p[7] = t + 1;
    }
    func_0022FFB0(p, q);
    func_0019DE50(p, 4, 0);
    func_0019DE50(p, 4, 1);
    func_0019DE50(p, 4, 2);
    if (p[0x269] == 3) {
        p[0x1B5] = 0x43;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->t[p[2]] += 1;
    } else {
        p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x42;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->t[p[2]] += 1;
    }
    func_002301C0(p, q);
}

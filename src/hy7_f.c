typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[16]; } HY7G;
typedef struct { s16 x, y; } HY7T;
extern HY7G *D_004C2794;
extern HY7T D_00475B60[];

void func_003BED80(u8 *p, void *owner) {
    extern void func_00175700(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_001DC0F0(u8 *, u16, f32, f32);
    extern void func_001E7F60(u8 *);
    s16 i;
    s16 v;
    u32 t;
    HY7T *q;
    func_00175700(p);
    v = *(s16 *)(p + 0x1E) + 0x2000;
    *(s16 *)(p + 0x1E) = v;
    if (v == 0) p[0x1B2] = 0;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        t = p[4];
        p[4] = t + 1;
        if (p[0x20] == 0) func_001E3210(p, 0x23);
        q = D_00475B60;
        for (i = 0; i < 8; i++) {
            func_001DC0F0(p, 1, *(f32 *)(p + 0x34) + 1.666666627f * (f32)q->x, *(f32 *)(p + 0x38) + 2.142857075f * (f32)(q++)->y);
        }
        p[0x1B5] = 0x3D;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    func_001E7F60(p);
}

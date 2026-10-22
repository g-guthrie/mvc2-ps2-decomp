typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 f0;
    u8 pad[0x7B];
    s16 f7c[1];
} G24;
extern G24 *D_004C2794;
extern s32 D_004568C0[];
extern s32 D_004568C4[];
extern s8 D_004C097C[8];

void func_00289AE0(u8 *p)
{
    extern void func_00185490(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_0018C4B0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00289C90(u8 *);
    u32 t;
    f32 f;
    t = p[7];
    p[7] = t + 1;
    func_00185490(p);
    func_00175C00(p, 0);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_0018C4B0(p, 5);
    if (p[0x1E6] == 0) {
        f = 1.6666666269302368f * (f32)D_004568C0[p[0x1B7] * 2] / 65536.0f;
        *(f32 *)(p + 0x5C) = f;
        *(f32 *)(p + 0x68) = 0.7291666269302368f;
    } else {
        f = 1.6666666269302368f * (f32)D_004568C0[p[0x1B7] * 2] / 65536.0f;
        *(f32 *)(p + 0x5C) = -f;
        *(f32 *)(p + 0x68) = -0.7291666269302368f;
    }
    f = 2.142857074737549f * (f32)D_004568C4[p[0x1B7] * 2] / 65536.0f;
    *(f32 *)(p + 0x60) = f;
    *(f32 *)(p + 0x6C) = -0.9375f;
    p[0x1B5] = D_004C097C[p[0x1B7] * 2];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0x10));
    func_00289C90(p);
}

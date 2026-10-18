typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define S8(p, o) (*(s8 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(u8 **)((u8 *)(p) + (o)))


extern s32 func_00189310(u8 *, void *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, s32);
extern u8 D_0045CB30[];
extern s32 func_00182E80(u8 *);
extern void func_00175700(u8 *);
extern u8 D_004D18A0[];

s32 func_003050F0(u8 *a0) {
    u8 *s0 = a0 + 0x2B8;
    if (func_00189310(a0, D_0045CB30, a0 + 0x390) == 0) {
        return 0;
    }
    if (U8(s0, 5) != 0) {
        return 0;
    }
    U8(s0, 6) = 0;
    U8(s0, 7) = 0;
    func_0018A990(a0, a0 + 0x390);
    U8(a0, 5) = 0;
    U8(a0, 7) = 0;
    U8(a0, 6) = 0;
    U8(a0, 0x1FD) = 2;
    func_00186A60(a0, 0x15);
    return 1;
}

s32 func_00182C90(u8 *a0) {
    s16 r;
    s16 v;
    if (D_004D18A0[0] >= 5) {
        return 1;
    }
    if (S16(a0, 0x434) == 0) {
        return 1;
    }
    r = func_00182E80(a0);
    if (r == 0) {
        return 0;
    }
    U8(a0, 0x152) = 1;
    func_00175700(a0);
    v = S16(a0, 0x270) - r;
    S16(a0, 0x270) = v;
    return v <= 0;
}

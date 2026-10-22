typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;

typedef struct { u8 pad0[0x12]; s16 h12; u8 pad14[0x40 - 0x14]; } SE;

extern s32 D_004C2AEC;
extern s32 D_004C2AD0;
extern SE D_006207A0[];
extern s32 D_0062BF84[];
extern s32 D_0062BF88[];
extern u64 D_00477928[];
extern u8 D_00477918[];
extern u8 D_00477920[];
extern u8 D_004BA520[];
extern u8 D_004778F0[];

s32 func_003DF0C0(u8 *p)
{
    extern s32 func_003E0DB0();
    extern u32 func_003E0CB0(u32, s32);
    extern f32 func_003E0C20(f32);
    extern f32 func_003E0C40(f32);
    extern f32 func_003E0C80(f32);
    extern s32 fptosi(f32);
    extern s32 func_00119098(f32);
    extern void func_003ED0D0(u8 *);
    extern void func_003DECC0(u8 *);
    u32 c;
    s32 ii;
    u64 *d;
    u32 hi, lo;
    f32 sa, sb;
    f32 fx, fy, fz;
    long long xx, yy;
    u64 xy, z64;

    ii = (u16)D_004C2AEC;
    ii = ii - 1;
    if (*(s16 *)((u8 *)D_006207A0 + (ii << 6) + 0x12) == 0) {
        func_003ED0D0(D_004BA520);
        return 0;
    }
    if (func_003E0DB0(D_004C2AEC, D_00477918, D_00477920, D_004C2AD0) == 0) return 0;

    d = (u64 *)D_00477928;
    c = func_003E0CB0(*(u32 *)(p + 0x30), 0);
    d[0] = ((c >> 16) & 0xFF) | ((u64)((c >> 8) & 0xFF) << 8) | ((u64)(c & 0xFF) << 16) | ((u64)((c >> 24) & 0xFF) << 24) | ((u64)*(u32 *)(p + 0xC) << 32);
    sa = *(f32 *)(p + 0x3C) * *(f32 *)(p + 0xC);
    sb = *(f32 *)(p + 0x40) * *(f32 *)(p + 0xC);
    lo = *(u32 *)&sa;
    hi = *(u32 *)&sb;
    d[1] = lo | ((u64)hi << 32);
    fx = func_003E0C20(*(f32 *)(p + 0x0));
    fy = func_003E0C40(*(f32 *)(p + 0x4));
    fz = func_003E0C80(*(f32 *)(p + 0x8));
    xx = fptosi((f32)D_0062BF84[0] + fx) << 4;
    yy = fptosi((f32)D_0062BF88[0] + fy) << 4;
    xy = (u64)xx | ((u64)yy << 16);
    z64 = (u64)(u32)func_00119098(fz) << 32;
    z64 |= xy;
    d[2] = z64;

    c = func_003E0CB0(*(u32 *)(p + 0x34), 0);
    d[3] = ((c >> 16) & 0xFF) | ((u64)((c >> 8) & 0xFF) << 8) | ((u64)(c & 0xFF) << 16) | ((u64)((c >> 24) & 0xFF) << 24) | ((u64)*(u32 *)(p + 0x1C) << 32);
    sa = *(f32 *)(p + 0x44) * *(f32 *)(p + 0x1C);
    sb = *(f32 *)(p + 0x48) * *(f32 *)(p + 0x1C);
    lo = *(u32 *)&sa;
    hi = *(u32 *)&sb;
    d[4] = lo | ((u64)hi << 32);
    fx = func_003E0C20(*(f32 *)(p + 0x10));
    fy = func_003E0C40(*(f32 *)(p + 0x14));
    fz = func_003E0C80(*(f32 *)(p + 0x18));
    xx = fptosi((f32)D_0062BF84[0] + fx) << 4;
    yy = fptosi((f32)D_0062BF88[0] + fy) << 4;
    xy = (u64)xx | ((u64)yy << 16);
    z64 = (u64)(u32)func_00119098(fz) << 32;
    z64 |= xy;
    d[5] = z64;

    c = func_003E0CB0(*(u32 *)(p + 0x38), 0);
    d[6] = ((c >> 16) & 0xFF) | ((u64)((c >> 8) & 0xFF) << 8) | ((u64)(c & 0xFF) << 16) | ((u64)((c >> 24) & 0xFF) << 24) | ((u64)*(u32 *)(p + 0x2C) << 32);
    sa = *(f32 *)(p + 0x4C) * *(f32 *)(p + 0x2C);
    sb = *(f32 *)(p + 0x50) * *(f32 *)(p + 0x2C);
    lo = *(u32 *)&sa;
    hi = *(u32 *)&sb;
    d[7] = lo | ((u64)hi << 32);
    fx = func_003E0C20(*(f32 *)(p + 0x20));
    fy = func_003E0C40(*(f32 *)(p + 0x24));
    fz = func_003E0C80(*(f32 *)(p + 0x28));
    xx = fptosi((f32)D_0062BF84[0] + fx) << 4;
    yy = fptosi((f32)D_0062BF88[0] + fy) << 4;
    yy <<= 16;
    xy = xx;
    xy |= yy;
    z64 = (u64)(u32)func_00119098(fz) << 32;
    z64 |= xy;
    d[8] = z64;
    func_003DECC0(D_004778F0);
    return 1;
}

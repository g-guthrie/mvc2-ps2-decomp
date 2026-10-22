typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;

extern s32 D_0062BF84[];
extern s32 D_0062BF88[];
extern u64 D_004778B8[];
extern u8 D_00477890[];

s32 func_003DEE00(u8 *p)
{
    extern u32 func_003E0CB0(u32, s32);
    extern f32 func_003E0C20(f32);
    extern f32 func_003E0C40(f32);
    extern f32 func_003E0C80(f32);
    extern s32 fptosi(f32);
    extern s32 func_00119098(f32);
    extern void func_003DECC0(u8 *);
    u32 c;
    u64 *d;
    f32 fx, fy, fz;
    long long xx, yy;
    u64 xy, z64;

    d = (u64 *)D_004778B8;
    c = func_003E0CB0(*(u32 *)(p + 0x30), 1);
    d[0] = ((c >> 16) & 0xFF) | ((u64)((c >> 8) & 0xFF) << 8) | ((u64)(c & 0xFF) << 16) | ((u64)((c >> 24) & 0xFF) << 24) | ((u64)*(u32 *)(p + 0xC) << 32);
    fx = func_003E0C20(*(f32 *)(p + 0x0));
    fy = func_003E0C40(*(f32 *)(p + 0x4));
    fz = func_003E0C80(*(f32 *)(p + 0x8));
    xx = fptosi((f32)D_0062BF84[0] + fx) << 4;
    yy = fptosi((f32)D_0062BF88[0] + fy) << 4;
    xy = (u64)xx | ((u64)yy << 16);
    z64 = (u64)(u32)func_00119098(fz) << 32;
    z64 |= xy;
    d[1] = z64;

    c = func_003E0CB0(*(u32 *)(p + 0x34), 1);
    d[2] = ((c >> 16) & 0xFF) | ((u64)((c >> 8) & 0xFF) << 8) | ((u64)(c & 0xFF) << 16) | ((u64)((c >> 24) & 0xFF) << 24) | ((u64)*(u32 *)(p + 0x1C) << 32);
    fx = func_003E0C20(*(f32 *)(p + 0x10));
    fy = func_003E0C40(*(f32 *)(p + 0x14));
    fz = func_003E0C80(*(f32 *)(p + 0x18));
    xx = fptosi((f32)D_0062BF84[0] + fx) << 4;
    yy = fptosi((f32)D_0062BF88[0] + fy) << 4;
    xy = (u64)xx | ((u64)yy << 16);
    z64 = (u64)(u32)func_00119098(fz) << 32;
    z64 |= xy;
    d[3] = z64;

    c = func_003E0CB0(*(u32 *)(p + 0x38), 1);
    d[4] = ((c >> 16) & 0xFF) | ((u64)((c >> 8) & 0xFF) << 8) | ((u64)(c & 0xFF) << 16) | ((u64)((c >> 24) & 0xFF) << 24) | ((u64)*(u32 *)(p + 0xC) << 32);
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
    d[5] = z64;
    func_003DECC0(D_00477890);
    return 1;
}

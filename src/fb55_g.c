typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;

extern s32 D_004C2AEC;
extern s32 D_004C2AD0;
extern s32 D_0062BF84[];
extern s32 D_0062BF88[];
extern s32 D_0062BF8C[];
extern s32 D_0062BF90[];
extern s32 D_0062BC00[];
extern f32 D_0062BC30[];
extern u8 D_00477970[];

s32 func_003DF490(u8 *p)
{
    extern void func_003DCDC0();
    extern s32 func_003E0DB0();
    extern u32 func_003E0CB0(u32, s32);
    extern s32 fptosi(f32);
    extern s32 func_00119098(f32);
    extern void func_003DECC0();
    u32 c;
    u32 hi, lo;
    f32 sa, sb;
    f32 fx;
    f32 fz;
    f32 fy;
    long long xx, yy;
    u64 xy, z64;

    func_003DCDC0(0x70000000, D_00477970, 0x28);
    if (func_003E0DB0(D_004C2AEC, 0x70000028, 0x70000030, D_004C2AD0) == 0) return 0;

    c = func_003E0CB0(*(u32 *)(p + 0x20), 0);
    *(u64 *)0x70000038 = ((c >> 16) & 0xFF) | ((u64)((c >> 8) & 0xFF) << 8) | ((u64)(c & 0xFF) << 16) | ((u64)((c >> 24) & 0xFF) << 24) | ((u64)*(u32 *)(p + 0xC) << 32);
    sa = *(f32 *)(p + 0x24) * *(f32 *)(p + 0xC);
    sb = *(f32 *)(p + 0x28) * *(f32 *)(p + 0xC);
    lo = *(u32 *)&sa;
    hi = *(u32 *)&sb;
    *(u64 *)0x70000040 = lo | ((u64)hi << 32);
    fx = *(f32 *)(p + 0x0) - (f32)D_0062BF8C[0];
    if (D_0062BC00[0] == 0) {
        fy = 0.5f * (*(f32 *)(p + 0x4) - (f32)D_0062BF90[0]);
    } else {
        fy = *(f32 *)(p + 0x4) - (f32)D_0062BF90[0];
    }
    fz = -0.5f * (*(f32 *)(p + 0x8) - 1.0f) * D_0062BC30[0];
    xx = fptosi((f32)D_0062BF84[0] + fx) << 4;
    yy = fptosi((f32)D_0062BF88[0] + fy) << 4;
    xy = (u64)xx | ((u64)yy << 16);
    z64 = (u64)(u32)func_00119098(fz) << 32;
    z64 |= xy;
    *(u64 *)0x70000048 = z64;

    sa = *(f32 *)(p + 0x2C) * *(f32 *)(p + 0x1C);
    sb = *(f32 *)(p + 0x30) * *(f32 *)(p + 0x1C);
    lo = *(u32 *)&sa;
    hi = *(u32 *)&sb;
    *(u64 *)0x70000050 = lo | ((u64)hi << 32);
    fx = *(f32 *)(p + 0x10) - (f32)D_0062BF8C[0];
    if (D_0062BC00[0] == 0) {
        fy = 0.5f * (*(f32 *)(p + 0x14) - (f32)D_0062BF90[0]);
    } else {
        fy = *(f32 *)(p + 0x14) - (f32)D_0062BF90[0];
    }
    yy = fptosi((f32)D_0062BF88[0] + fy) << 4;
    xy = (u64)(yy << 16);
    xx = fptosi((f32)D_0062BF84[0] + fx) << 4;
    xy = xx | xy;
    z64 = (u64)(u32)func_00119098(-0.5f * (*(f32 *)(p + 0x18) - 1.0f) * D_0062BC30[0]) << 32;
    z64 |= xy;
    *(u64 *)0x70000058 = z64;
    func_003DECC0(0x70000000);
    return 1;
}

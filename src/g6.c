typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_00182050(u8 *p) {
    f32 v;
    if (((s32)(*(u16*)(p + 0x35E) & 0x400)) >> 10) v = -2.5f; else v = 2.916666507720947f;
    if (p[0x1E6]) *(f32*)(p + 0x5C) = v; else *(f32*)(p + 0x5C) = -v;
}
void func_0034E880(u8 *p) {
    f32 f;
    *(s16 *)(p + 0x140) = (*(u8 **)(p + 0x18))[0x1E6];
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s16 *)(p + 0x140) != 0) f = -56.666664123535156f; else f = 56.666664123535156f;
    *(f32 *)(p + 0x34) += f;
    *(f32 *)(p + 0x38) += 107.14285278320312f;
}
extern void func_0018C4B0(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);
void func_0022FDA0(u8 *p) {
    f32 f; u32 t = p[6]; p[6] = t + 1; f = 8.333333015441895f; if (*(s16 *)(p + 0x140) == 0) f = -f; *(f32 *)(p + 0x5C) = f;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_0018C4B0(p, 4);
    p[0x169] = 0x15;
    p[0x168] = 4;
    func_001757E0(p, p[0x169], p[0x168]);
}

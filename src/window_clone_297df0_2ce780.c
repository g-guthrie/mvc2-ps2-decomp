typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, s32);
extern int func_001757E0(u8 *, s32, s32);

void func_00297DF0(u8 *p) {
    u32 t = p[6];
    p[6] = t + 1;
    func_00185490(p);
    func_0018C4B0(p, 2);
    p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x40;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    *(f32 *)(p + 0x5C) /= 16.0f;
    *(f32 *)(p + 0x60) /= 8.0f;
    *(f32 *)(p + 0x6C) /= 64.0f;
    *(s32 *)(p + 0x68) = 0;
    func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0xE));
}

void func_002CE780(u8 *p) {
    u32 t = p[6];
    p[6] = t + 1;
    func_00185490(p);
    func_0018C4B0(p, 2);
    p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x40;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    *(f32 *)(p + 0x5C) /= 16.0f;
    *(f32 *)(p + 0x60) /= 8.0f;
    *(f32 *)(p + 0x6C) /= 64.0f;
    *(s32 *)(p + 0x68) = 0;
    func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0xE));
}

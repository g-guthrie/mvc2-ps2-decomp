typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00185490(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
extern u8 *func_001E0CC0(u8 *, u32);
extern u8 *D_004C2794;

void func_00325B50(u8 *p) {
    f32 v;
    s16 *e;
    u32 t = p[6];
    p[6] = t + 1;
    p[0x20D] = 0;
    func_00185490(p);
    v = -6.666666507720947f;
    if (*(s16 *)(p + 0x140) != 0) {
        v = -v;
    }
    *(f32 *)(p + 0x5C) = v;
    p[0x1B5] = 0x30;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    e = (s16 *)((p[2] << 1) + (u32)D_004C2794);
    e[0x7C / 2] += 1;
    func_001757E0(p, 0x15, 0x10);
    func_001E0CC0(p, 3);
}

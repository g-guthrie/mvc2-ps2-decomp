typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, s32);
extern s32 func_001757E0(u8 *, s32, s32);

void func_002983D0(u8 *p) {
    f32 a, b;
    u32 t = p[6];
    p[6] = t + 1;
    func_00185490(p);
    func_0018C4B0(p, 2);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    *(s16 *)(p + 0x1C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x6C) = 0;
    a = (p[0x212] != 0) ? 16.66666603088379f : 25.0f;
    b = (p[0x212] != 0) ? -0.6770833134651184f : -0.78125f;
    *(f32 *)(p + 0x5C) = (p[0x1E6] != 0) ? a : -a;
    *(f32 *)(p + 0x68) = (p[0x1E6] != 0) ? b : -b;
    func_001757E0(p, 0x15, 0x15);
}

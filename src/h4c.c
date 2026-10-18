typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_00189660(u8 *, void *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, s32);
extern u8 D_00458028[];
s32 func_0029B690(u8 *p) {
    if (func_00189660(p, D_00458028, p + 0x3C0) == 0) return 0;
    if (*(s32 *)(p + 0x30C) != 0) return 0;
    func_0018A990(p, p + 0x3C0);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 8;
    func_00186A60(p, 0x15);
    return 1;
}

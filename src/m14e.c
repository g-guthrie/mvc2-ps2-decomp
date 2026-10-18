typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00189310(void *p, void *t, void *q);
extern void func_0018A990();
extern void func_00186A60(void *p, s32 a);
extern u8 D_00454520[];
s32 func_0026B350(u8 *p) {
    if (!func_00189310(p, D_00454520, p + 0x390)) return 0;
    if (p[0x20D] == 2) {
        s8 t = *(s8 *)(p + 0x1E8);
        if (t != 0) return 0;
        p[0x1E8] = t + 1;
    }
    func_0018A990(p, p + 0x390);
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 2;
    func_00186A60(p, 0x15);
    return 1;
}

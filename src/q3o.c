typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 D_0045BA50[];
extern s32 func_00189310(void *p, void *q, void *r);
extern void func_00186A60(void *p, s32 a);

s32 func_002F2440(u8 *p) {
    if (func_00189310(p, D_0045BA50, p + 0x3B0) == 0) return 0;
    if (p[0x210] == 0) {
        s8 t = p[0x1E8];
        if (t != 0) return 0;
        p[0x1E8] = t + 1;
    }
    p[0x1B7] = 4;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 3;
    func_00186A60(p, 0x15);
    return 1;
}

/* v2_b: mw30 -O3 -sdatathreshold 0 */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
extern u8 D_00453970[];
extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
s32 func_0025C570(u8 *p) {
    if (func_00189310(p, D_00453970, p + 0x390) == 0) {
        return 0;
    }
    if (p[0x20D] == 2) {
        s8 t = *(s8 *)(p + 0x1E8);
        if (t != 0) {
            return 0;
        }
        p[0x1E8] = t + 1;
    }
    if (**(s8 **)(p + 0x420) == 0) {
        return 0;
    }
    func_0018A990(p, p + 0x390);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 3;
    func_00186A60(p, 0x1D);
    return 1;
}

extern u8 D_00459840[];
extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
typedef struct { u8 pad[0x2B8]; u8 b[8]; } S_002BFD10;
s32 func_002BFD10(u8 *p) {
    u8 *q;
    q = ((S_002BFD10 *)p)->b;
    if (func_00189310(p, D_00459840, p + 0x380) == 0) {
        return 0;
    }
    if (p[0x20D] == 2 && p[0x210] == 0) {
        s8 t = *(s8 *)(p + 0x1E8);
        if (t != 0) {
            return 0;
        }
        p[0x1E8] = t + 1;
    }
    if (q[6] != 0) {
        return 0;
    }
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}


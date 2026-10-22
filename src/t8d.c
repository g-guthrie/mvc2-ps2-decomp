/* t8 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { float x, y, z; } Float3;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_003359E0();
extern void func_00335640();
extern u32 D_004C283C;
extern Float3 D_004B7F30[];
extern void func_001266A0();
extern void func_0015D010();
extern void func_0018C6E0(void *);
extern void func_001757E0();
extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
extern u8 D_0044FBA0[];
extern void func_0018A920();

s32 func_001F7770(u8 *p) {
    if (func_00189310(p, D_0044FBA0, p + 0x3A8) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            if (*(s8 *)(p + 0x1E8) != 0) return 0;
        }
    }
    func_0018A990(p, p + 0x3A8);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 7;
    func_00186A60(p, 0x1D);
    return 1;
}

u8 func_00189C10(u8 *a0, s8 *a1, u8 *a2) {
    u16 a3;
    u32 v;
    u8 r;
    v = (u16)(*(s16 *)(a0 + 0x35E) & 0x3C00);
    a3 = v;
    if (v == 0) {
        return a2[0] = 0;
    }
    if (a3 != 0x2000 && a3 != 0x1000 && a3 != 0x800 && a3 != 0x400) {
        return a2[0] = 0;
    }
    if (a3 == 0x2000) r = 0;
    if (a3 == 0x800) r = 1;
    if (a3 == 0x1000) r = 2;
    if (a3 == 0x400) r = 3;
    a2[0] += 1;
    a2[2] = a1[0] - 1;
    a2[3] = r;
    func_0018A920(a0, a2);
    return 0;
}

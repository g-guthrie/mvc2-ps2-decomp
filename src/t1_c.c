typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { f32 x, y, z, w; } V4;

extern void func_00134710(u8 *p, u8 *q);
extern s32 func_00134230(u8 *p, u8 *q);
extern s32 func_001342D0(u8 *p, u8 *q);
extern s32 func_001341B0(u8 *p, u8 *q);
extern s32 func_00134370(u8 *p, u8 *q);
extern void func_001345B0(u8 *p, u8 *q);

void func_00133A70(u8 *p, u8 *q) {
    s16 v;
    func_00134710(p, q);
    v = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = v + 1;
    if (v < 0x97) {
        if (v >= 0x78) {
            if (func_00134230(p, q)) {
                if (func_001342D0(p, q)) {
                    if (func_001341B0(p, q)) {
                        if (func_00134370(p, q)) {
                            p[5] = 0;
                            p[0x20] = 1;
                            func_001345B0(p, q);
                        }
                    }
                }
            }
        }
    }
}

extern s32 func_00189310(u8 *p, void *t, u8 *q);
extern void func_0018A990(u8 *p, u8 *q);
extern void func_00186A60(u8 *p, s32 a);
extern u8 D_0044FB68[];

s32 func_001F7590(u8 *p) {
    s8 v;
    if (func_00189310(p, D_0044FB68, p + 0x390) == 0) return 0;
    if (*(f32 *)(p + 0x38) < 112.0f + *(f32 *)(p + 0x430)) return 0;
    v = *(s8 *)(p + 0x1E8);
    if (v != 0) return 0;
    p[0x1E8] = v + 1;
    func_0018A990(p, p + 0x390);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 2;
    func_00186A60(p, 0x15);
    return 1;
}

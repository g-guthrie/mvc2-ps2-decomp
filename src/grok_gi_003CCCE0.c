typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern int func_00174470(const void *);
extern void func_003CAB00(u8 *, u8 *);
extern int func_00175700(u8 *);
extern void func_003CAB20(u8 *, u8 *, unsigned int);

void func_003CCCE0(u8 *p, u8 *q)
{
    s16 v;
    u8 *r;
    s32 mode;
    f32 vx;
    if (q[5] != 0) {
        func_003CAB20(p, q, 0xF);
        return;
    }
    if (func_00174470(p) == 0) {
        func_003CAB00(p, q);
        return;
    }
    *(s32 *)(q + 0x2B8) = 4;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v >= 0) {
        r = *(u8 **)(p + 0xD8);
        if (r == 0)
            return;
        if (r[5] == 0xD || r[5] == 9) {
            func_003CAB20(p, q, 0xF);
            return;
        }
        if (*(s8 *)(r + 0x1B2) != 0) {
            mode = 0xE;
            if ((*(s8 *)(p + 0x1B2) & 0x11) != 0)
                mode = 0xF;
            func_003CAB20(p, q, mode);
            return;
        }
        vx = 6.666666507720947265625f;
        if (*(s16 *)(p + 0x140) != 0)
            vx = -vx;
        *(f32 *)(r + 0x34) = *(f32 *)(p + 0x34) + vx;
        *(f32 *)(r + 0x38) = 38.5714263916015625f + *(f32 *)(p + 0x38);
    } else {
        func_003CAB20(p, q, 0x15);
    }
}

/* func_0027A160: MW 3.0.3 (also 3.0) -O3 -Op -sdatathreshold 0, exact.
   opt_lifetimes/opt_propagation off; loop-body pointer b first, shift built in a block temp. */
#pragma opt_lifetimes off
#pragma opt_propagation off
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x2B8];
    u8 b[2];
} PB;

void func_0027A160(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00343E80(f32 *, f32 *, s32);
    extern void func_00154790(f32 *, s32, s32, s32);
    extern void func_003801F0(u8 *, f32 *, u8);
    u8 i;
    u8 m;
    s32 k;
    u8 *q;
    u8 *b;
    f32 lo;
    f32 hi;
    f32 v[4];

    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 1) {
        { u32 t = p[6]; p[6] = t + 1; }
        if (*(s16 *)(p + 0x140) == 0) {
            lo = *(f32 *)(p + 0x34) - 160.0f;
            hi = *(f32 *)(p + 0x34) - 186.6666565f;
        } else {
            lo = 160.0f + *(f32 *)(p + 0x34);
            hi = 186.6666565f + *(f32 *)(p + 0x34);
        }
        for (i = 0; (k = i) < 4; i++) {
            b = ((PB *)p)->b;
            { s32 t = 1; t <<= k; m = t; }
            q = b + 1;
            if ((((PB *)p)->b[1] & m) == 0) {
                func_00343E80(&v[0], &v[1], k);
                {
                f32 x;
                f32 vx;
                if (k == 1 || k == 2) {
                    x = lo;
                } else {
                    x = hi;
                }
                vx = v[0];
                if (x - 40.0f <= vx && vx <= 40.0f + x) {
                    *q |= m;
                    func_00154790(v, *(s16 *)(p + 0x140), 3, 0);
                    func_003801F0(p, v, i);
                }
                }
            }
        }
    }
    if (*(u16 *)(p + 0x160) != 0) {
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x34) += 1.666666627f * (s16)*(u16 *)(p + 0x160);
        } else {
            *(f32 *)(p + 0x34) -= 1.666666627f * (s16)*(u16 *)(p + 0x160);
        }
        *(u16 *)(p + 0x160) = 0;
    }
}

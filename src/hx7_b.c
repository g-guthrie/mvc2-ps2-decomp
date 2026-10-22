typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x160]; s8 b[8]; } SB;

extern s16 D_0044A710[];
extern s16 D_0044A712[];
extern u8 *D_004C2840;

void func_0019A210(u8 *p)
{
    extern s8 func_00175670(u8 *);
    extern void func_0019A070(u8 *, s32);
    u8 *src;
    s8 *bp;
    s8 *q;
    s32 f;
    f32 v;
    f32 w;
    f32 k;
    s16 h;
    u32 t;
    src = *(u8 **)(p + 0x18);
    p[0x13C] = 0;
    *(s8 *)(p + 0x24) = *(s8 *)(src + 0x24);
    if (p[0x20] == 0) {
        *(V3 *)(p + 0x34) = *(V3 *)(src + 0x34);
        p[0x13C] = 0;
        if (*(s8 *)(src + 0x13C) != 0) {
            bp = ((SB *)src)->b;
            f = bp[1];
            q = bp + 1;
            if (f != 0) {
                k = 1.666666627f;
                v = k * (f32)D_0044A710[(s8)f * 2];
                if (*(s16 *)(src + 0x140) == 0) {
                    v = -v;
                }
                *(f32 *)(p + 0x34) += v;
                k = 2.142857075f;
                w = k * (f32)D_0044A712[*q * 2];
                *(f32 *)(p + 0x38) += w;
                h = *(s16 *)(p + 0x1C) - 1;
                *(s16 *)(p + 0x1C) = h;
                if (h < 0) {
                    *(s16 *)(p + 0x1C) = 3;
                    func_0019A070(p, 1);
                }
                func_00175670(p);
                p[0x13C] = D_004C2840[0x1C] & 1;
            }
        }
    } else {
        if (func_00175670(p) < 0) {
            t = p[4];
            p[4] = t + 1;
        } else {
            p[0x13C] = D_004C2840[0x1C] & 1;
        }
    }
}

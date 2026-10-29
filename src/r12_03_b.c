/* func_0014A8B0: MW 3.0 (try30.sh) -O3 -Op -sdatathreshold 8 -fp off */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F7F90[];
extern f32 func_00417D50(f32 a, f32 b);
extern s32 D_004C27FC;

#pragma push
#pragma opt_dead_assignments off
void func_0014A8B0(u8 *p)
{
    u8 *s0;
    s32 q;
    s32 d;
    u32 t;
    f32 k;

    s0 = D_004F7F90;
    t = p[0x20];
    if (t != 0) {
        switch ((u8)t) {
        case 1:
            k = 10.0f;
            d = (s32)func_00417D50(k, (f32)(1 - p[0x21]));
            q = s0[0x1F] / d;
            break;
        case 2:
            k = 10.0f;
            d = (s32)func_00417D50(k, (f32)(1 - p[0x21]));
            q = s0[0x20] / d;
            break;
        case 3:
            d = (s32)func_00417D50(10.0f, (f32)(1 - p[0x21]));
            q = s0[0x21] / d;
            break;
        default:
            break;
        }
        q %= 10;
        *(s16 *)(p + 0xCC) = q + 0x25;
        *(s32 *)(p + 0x84) = D_004C27FC;
    }
}
#pragma pop

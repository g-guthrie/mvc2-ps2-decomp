typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
#define P(t,o) (*(t*)(p+(o)))
#define Q(t,o) (*(t*)(*(u8**)(p+0x18)+(o)))

extern u8 D_004531E0[];
extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
s32 func_0024DE60(u8 *p) {
    u8 *s = p + 0x2B8;
    if (func_00189310(p, D_004531E0, p + 0x3C0) == 0) return 0;
    if (*(s8 *)(*(u8 **)(p + 0x420)) == 0) return 0;
    func_0018A990(p, p + 0x3C0);
    s[5] = 0;
    P(u8,5) = 0;
    P(u8,7) = 0;
    P(u8,6) = 0;
    P(u8,0x1FD) = 8;
    func_00186A60(p, 0x1D);
    return 1;
}

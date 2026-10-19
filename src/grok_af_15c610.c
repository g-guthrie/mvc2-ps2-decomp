typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } Float3;

extern u8 *func_003DA750(void *, int, int);
extern void func_0015C740(u8 *);
extern double func_00119058(f32);
extern s8 D_004D1900;

void func_0015C610(Float3 *pos, int a1, int a2, u32 ang, int kind)
{
    u8 *p = func_003DA750(0, kind, 1);
    if (p) {
        D_004D1900++;
        p[0x13C] = 0;
        *(void (**)(u8 *))(p + 0x10) = func_0015C740;
        *(Float3 *)(p + 0x34) = *pos;
        p[0x23] = (u8)kind;
        *(u32 *)(p + 0x48) = (u16)(65536.0 * func_00119058(11.25f * (f32)ang) / 360.0 + 0.5) + 32767 + 16385;
        *(u32 *)(p + 0xD0) = 0x800189;
    }
}

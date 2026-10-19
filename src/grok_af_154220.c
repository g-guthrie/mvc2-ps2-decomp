typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } Float3;

extern u8 *func_003DA750(void *, int, int);
extern void func_00154190(u8 *);
extern f32 func_00417440(u32);
extern f32 func_00417500(u32);
extern s32 func_00417A40(u32);
extern f32 D_00444960[];
extern Float3 D_00444970[];

void func_00154220(Float3 *pos, int idx, int ang)
{
    u8 *p = func_003DA750(0, 0x13, 1);
    if (p) {
        u32 a;
        s32 v, v1;
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 0x10) = func_00154190;
        *(u32 *)(p + 0xD0) = 0x800109;
        *(Float3 *)(p + 0x34) = *pos;
        a = (u16)(65536.0 * (double)(ang * 60) / 360.0 + 0.5);
        *(f32 *)(p + 0x5C) = D_00444960[idx] * func_00417440(a);
        *(f32 *)(p + 0x64) = D_00444960[idx] * func_00417500(a);
        v = func_00417A40(a);
        v1 = v & 0x3FFF;
        if (v < 0 && v1)
            v1 -= 0x4000;
        *(s32 *)(p + 0x48) = v1;
        *(Float3 *)(p + 0x50) = D_00444970[idx];
    }
}

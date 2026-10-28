/* MW 3.0 (try30.sh) -O4 -Op -sdatathreshold 0 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_0044FF90[], D_0044FF94[], D_0044FF98[], D_0044FF9C[];

typedef struct { u8 pad0[0x5C]; f32 f5c, f60, f64, f68, f6c; } FM;

void func_001FE0D0(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q = p + 0x2B8;
    if ((s8)func_00175700(p) < 0) {
        u16 i;
        f32 c1, c2;
        u32 t = p[6];
        p[6] = t + 1;
        q[0x1C] = 1;
        func_001E3210(p, 0x1F);
        *(s16 *)(p + 0x1C) = 0x20;
        i = *(u16 *)(p + 0x35E);
        if (*(s8 *)(p + 0x539) != 0)
            i = *(u16 *)(q + 0xA);
        i = (i & 0x3000) / 0x1000;
        c1 = 1.6666666f;
        c2 = 2.142857074737549f;
        ((FM *)p)->f5c = c1 * (f32)D_0044FF90[i * 4] / 65536.0f;
        ((FM *)p)->f68 = c1 * (f32)D_0044FF94[i * 4] / 65536.0f;
        ((FM *)p)->f60 = c2 * (f32)D_0044FF98[i * 4] / 65536.0f;
        ((FM *)p)->f6c = c2 * (f32)D_0044FF9C[i * 4] / 65536.0f;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        func_001757E0(p, 2, (u8)((u16)i + 5));
    }
}

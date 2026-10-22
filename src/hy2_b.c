typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct { f32 x, y, z; } V3A;
extern V3A D_00583B70;

void func_00260D70(u8 *p)
{
    extern void func_0015B200(u8 *, V3A *, s32, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_0018FC10(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_00175700(u8 *);
    u8 *o;
    V3A v;
    f32 k;
    s32 h;
    o = (u8 *)*(u32 *)(p + 0x220);
    v = D_00583B70;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s16 *)(p + 0x1C) == 10) {
        if (p[7] != 0) {
        p[0x23] = 1;
        {
            u32 t = p[0x21];
            p[0x21] = t + 1;
        }
        if (*(s16 *)(p + 0x140) != 0) k = 400.0f;
        else k = -400.0f;
        v.x += k;
        *(u32 *)&v.y = 0x43892492;
        v.x = *(f32 *)(p + 0x34) + v.x;
        v.y = *(f32 *)(p + 0x38) + v.y;
        func_0015B200(p, &v, 1, 0xC9);
        func_001E3710(p, 0x49);
        func_0018FC10(o, (s16)(-(p[0x21] << 2)));
        } else {
            p[6] = 0xC;
            func_001757E0(p, 0x16, 0xD);
            return;
        }
    }
    h = *(s16 *)(p + 0x1C);
    if (h <= 0) {
        if (*(s16 *)(p + 0x1E) == 3) {
            p[6] = 9;
        } else {
            u32 t = p[6];
            p[6] = t + 1;
            *(s16 *)(p + 0x1C) = 0x17;
            p[0x23] = 0;
            func_001E3210(p, 0x10);
        }
    } else {
        *(s16 *)(p + 0x1C) = h - 1;
        func_00175700(p);
    }
}

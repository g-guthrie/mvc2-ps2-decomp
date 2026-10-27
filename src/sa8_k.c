typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3k;

void func_002AB590(u8 *p)
{
    extern int func_00175700(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3A40(u8 *);
    extern void func_0018FDB0(u8 *);
    extern void func_001548D0(u8 *, V3k *, s32);
    extern void func_001843A0(u8 *);
    V3k vec;
    u8 *o;
    s8 r;
    s32 v;
    u32 a;
    u32 t;
    if (p[6] == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(s8 *)(p + 0x151) == 0) func_00175700(p);
        a = p[7];
        if (a == 0 && *(f32 *)(p + 0x38) <= 342.85711669921875f) {
            p[7] = a + 1;
            func_001E3210(p, 5);
        }
        if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
            t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0xF, 3);
            func_001E3A40(p);
            return;
        }
    } else {
        r = func_00175700(p);
        if (r >= 0) {
            v = *(s8 *)(p + 0x151);
            if (v < 0) {
                p[0x151] = 0;
                (*(u8 **)(p + 0x1DC))[0x1B5] = 0x24;
                func_0018FDB0(p);
                vec.x = -53.33333206176758f;
                vec.y = 68.57142639160156f;
                vec.z = 0;
                func_001548D0(p, &vec, 1);
            } else if (v > 0) {
                p[0x151] = 0;
                o = *(u8 **)(p + 0x1DC);
                *(u8 **)(o + 0x1C8) = p;
                o[0x20A] = 1;
                o[0x1B5] = 0x22;
            }
            return;
        }
        {
            func_001843A0(p);
        }
    }
}

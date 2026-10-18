typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_001F31E0(u8 *p)
{
    extern s32 func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3A40(u8 *);
    extern void func_001548D0(u8 *, f32 *, s32);
    extern void func_0015B660(f32 *, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_0018FDB0(u8 *);
    f32 v[3];
    u8 *q;
    u32 t;
    if ((s8)func_00175700(p) < 0) {
        t = p[7];
        p[7] = t + 1;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x34) += 160.0f;
        } else {
            *(f32 *)(p + 0x34) -= 160.0f;
        }
        func_001757E0(p, 0xF, 0x28);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        D_004F1F45 = 1;
        D_004F1F46 = 1;
        func_001E3A40(p);
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        p[0x1B5] = 0x46;
        q[0x1B5] = 0x46;
        if (p[0x216] == 0) {
            *(u32 *)&v[0] = 0xC3200000;
            *(u32 *)&v[1] = 0;
            func_001548D0(p, v, 2);
        } else {
            v[0] = *(f32 *)(q + 0x34);
            v[1] = *(f32 *)(p + 0x430);
            func_0015B660(v, 1);
            func_001E3710(p, 0x49);
        }
        func_0018FDB0(p);
    }
}

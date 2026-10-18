typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_001F4AD0(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3A40(u8 *);
    extern void func_0015B660(f32 *, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_0018FDB0(u8 *);
    f32 v[4];
    u8 *q;
    if (func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x34) += 160.0f;
        } else {
            *(f32 *)(p + 0x34) -= 160.0f;
        }
        func_001757E0(p, 0xF, 0x3B);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        D_004F1F45 = 1;
        D_004F1F46 = 1;
        func_001E3A40(p);
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        p[0x1B5] = 0x51;
        q[0x1B5] = 0x51;
        v[0] = *(f32 *)(q + 0x34);
        v[1] = *(f32 *)(p + 0x430);
        func_0015B660(v, 1);
        func_001E3710(p, 0x49);
        func_0018FDB0(p);
    }
}

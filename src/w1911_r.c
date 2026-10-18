typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;
typedef int s32;
extern f32 D_004F1F4C[];
void func_0021EF90(u8 *p) {
    extern s32 func_003D92F0(void);
    extern void func_001843A0(u8 *);
    extern void func_00175700(u8 *);
    extern s32 func_00417A40(void);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    s32 r;
    f32 c;
    if (p[6] != 0) {
        if (func_003D92F0() != 0) {
            func_001843A0(p);
            return;
        }
        func_00175700(p);
        return;
    }
    t = p[6];
    p[6] = t + 1;
    switch (p[0x20]) {
    case 0:
        r = func_00417A40();
        r &= 3;
        if (-186.66665649414062f + D_004F1F4C[0] > *(f32 *)(p + 0x34) || 186.66665649414062f + D_004F1F4C[0] < *(f32 *)(p + 0x34)) r = 1;
        func_001757E0(p, 0x13, (u8)r);
        break;
    case 1:
        func_001757E0(p, 0x13, 4);
        break;
    case 2:
        func_001757E0(p, 0x13, 3);
        break;
    case 3:
    case 4:
        func_001757E0(p, 0x13, 5);
        break;
    default:
        break;
    }
}

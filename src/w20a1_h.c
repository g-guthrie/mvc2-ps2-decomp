typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004CA040[];
extern u8 *D_004C2840;
extern void *D_0043CD08[];

void func_0012CB90(u16 pad)
{
    extern s32 func_0012C5C0(u8 *, s32, s32);
    extern void func_0014C280(s32, s32, s32);
    extern s32 func_00131660();
    extern s32 func_00131720();
    extern void func_001E3CE0(s32);
    extern void func_003298B0(u32, s32, s32);
    extern void func_0012CE00();
    extern void func_0012D2B0();
    extern void func_0012CF80();
    s32 r;
    s32 a;
    u8 *p;

    p = D_004CA040;
    if (pad & 0x3000) {
        if (pad & 0x1000) {
            if (*(s16 *)(p + 0x12) != 3) r = func_0012C5C0(p, 2, 1);
        }
        if (pad & 0x2000) {
            if (*(s16 *)(p + 0x12) == 3) r = func_0012C5C0(p, 3, 1);
        }
    } else {
        if (pad & 0x400) {
            if (*(s16 *)(p + 0x12) != 3) r = func_0012C5C0(p, 0, 1);
        }
        if (pad & 0x800) {
            if (*(s16 *)(p + 0x12) != 3) r = func_0012C5C0(p, 1, 1);
        }
    }
    if (r == -1) {
        D_004C2840[5] = 3;
        func_0014C280(0, 0, 1);
        func_0014C280(1, 0, 1);
        func_0014C280(2, 0, 1);
        func_0014C280(3, 0, 1);
        D_0043CD08[0] = (void *)func_0012CE00;
    } else if (r == 1) {
        D_004C2840[5] = 4;
        func_0014C280(0, 0, 2);
        func_0014C280(1, 0, 2);
        func_0014C280(2, 0, 2);
        func_0014C280(3, 0, 2);
        D_0043CD08[0] = (void *)func_0012CE00;
    } else {
        a = func_00131660();
        if (func_00131720() != 0 || (a != 0 && *(s16 *)(p + 0x12) == 3)) {
            D_004C2840[5] = 0;
            if (a != 0) {
                func_001E3CE0(2);
            } else {
                func_001E3CE0(3);
            }
            func_003298B0(0xFF000000, 10, 1);
            D_0043CD08[0] = (void *)func_0012D2B0;
        } else if (a != 0) {
            D_004C2840[5] = 0;
            func_001E3CE0(2);
            (*(u8 **)(p + 8))[4] = 1;
            (*(u8 **)(p + 4))[0x23] = 3;
            D_0043CD08[0] = (void *)func_0012CF80;
        }
    }
}

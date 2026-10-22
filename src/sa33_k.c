typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[5]; s8 b5; } K2840;
extern s16 D_004CA078[];
extern s16 D_004CA052[];
extern s16 D_004CA040[];
extern s16 D_004CA054[];
extern u32 D_0043CD08[];
extern K2840 *D_004C2840;
extern void func_0012CB90();
static s16 func_0012B8D0(s16 a, s16 b) {
    if (b >= 3) return 4;
    return (a + b + 4) % 4;
}


void func_0012CE00(void)
{
    extern s32 func_0014C390(s32, s32);
    extern void func_0012C5C0(s16 *, s32, s32);
    extern void func_0014C280(s32, s32, s32);
    s32 r;
    s32 v;
    s16 *q;
    r = 1;
    r &= func_0014C390(0, 0);
    r &= func_0014C390(1, 0);
    r &= func_0014C390(2, 0);
    r &= func_0014C390(3, 0);
    if (r != 0) {
        q = D_004CA040;
        v = func_0012B8D0(D_004CA078[0], D_004CA052[0]);
        if ((s16)D_004CA054[(s16)v] != -1) {
            D_004C2840->b5 = 2;
            D_0043CD08[0] = (u32)func_0012CB90;
        } else if (D_004C2840->b5 == 3) {
            func_0012C5C0(q, 0, 1);
            func_0014C280(0, 0, 1);
            func_0014C280(1, 0, 1);
            func_0014C280(2, 0, 1);
            func_0014C280(3, 0, 1);
        } else {
            func_0012C5C0(q, 1, 1);
            func_0014C280(0, 0, 2);
            func_0014C280(1, 0, 2);
            func_0014C280(2, 0, 2);
            func_0014C280(3, 0, 2);
        }
    }
}

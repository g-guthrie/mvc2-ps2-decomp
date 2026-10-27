typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } Position3;
extern s8 D_004D1900;

void func_00154790(Position3 *a0, s32 a1, u32 a2, s32 a3) {
    extern void func_00154A20(Position3 *, s32, s32, s32, s32);
    extern void func_00156520(Position3 *, s32, s32, s32, s32);
    extern void func_00156650(Position3 *, s32, s32, s32, s32);
    extern void func_0015C610(Position3 *, s32, s32, u32, s32);
    extern void func_001571D0(const Position3 *, s32, s32);
    extern void func_00162FE0(Position3 *, s32, s32, s32, u8);
    if (D_004D1900 < 6) {
        switch (a2) {
        case 0:
            func_00154A20(a0, a1, a2, a3, 9);
            return;
        case 1:
            func_00156520(a0, a1, a2, a3, 9);
            break;
        case 2:
            func_00156520(a0, a1, a2, a3, 9);
            break;
        case 3:
        case 8:
            func_00156650(a0, a1, a2, a3, 9);
            break;
        case 4:
        case 5:
        case 6:
            if (D_004D1900 < 4) func_0015C610(a0, a1, a2, a3, 9);
            break;
        case 7:
            func_001571D0(a0, a2, 9);
            break;
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
            func_00162FE0(a0, a1, a2, a3, 9);
            break;
        }
    }
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
extern void func_00154A20(u8 *, s32, s32, s32, s32);
extern void func_00156520(u8 *, s32, s32, s32, s32);
extern void func_00162FE0(u8 *, s32, s32, s32, s32);
void func_00154850(u8 *a0, s32 a1, s32 a2, s32 a3) {
    switch (a2) {
    case 0:
        func_00154A20(a0, a1, a2, a3, 10);
        break;
    case 1:
        func_00156520(a0, a1, a2, a3, 10);
        break;
    case 2:
        func_00156520(a0, a1, a2, a3, 10);
        break;
    case 3:
    case 8:
        func_00156520(a0, a1, a2, a3, 10);
        break;
    case 4: case 5: case 6: case 7:
    case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16:
        func_00162FE0(a0, a1, a2, a3, 10);
        break;
    }
}

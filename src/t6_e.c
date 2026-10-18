typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00143370();
extern void func_001433D0();
extern s32 D_004C2634;
void func_00143430(void) {
    switch (D_004C2634) {
    case 0:
    case 1:
    case 3:
    case 4:
        func_00143370();
        break;
    case 2:
        func_001433D0();
        break;
    }
}


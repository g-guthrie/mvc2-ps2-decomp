typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_00131B50(s32 a);
void func_00131F90(s32 a, s32 b);
void func_00131AE0(void) {
    s32 i = 0;
    do { func_00131B50(i); i++; } while (i < 6);
    i = 0;
    do {
        func_00131F90(i, 0);
        func_00131F90(i, 1);
        i++;
    } while (i < 2);
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern u8 *D_004C2840;
extern s8 D_004F7F51[];
extern void func_003D9980(s32);
void func_003D9AF0(void) {
    if (*D_004C2794 == 4 && *(s8 *)(D_004C2840 + 0xB2) != 0) {
        if (D_004F7F51[0] & 1) func_003D9980(1);
        if (D_004F7F51[0] & 2) func_003D9980(0);
    }
}

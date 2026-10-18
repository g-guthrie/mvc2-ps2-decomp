typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 *func_003DA750();
extern u8 *func_003DA780();
extern void func_00378690();
extern void func_00160990();
extern void func_003413B0();
extern s32 D_004C2838;
extern s32 D_004C283C;

void func_00378620(u8 *p) {
    s32 i = 0;
    do {
        u8 *o = func_003DA750(0, 1, 0);
        if (o == 0) {
            break;
        }
        *(void **)(o + 0x10) = func_00378690;
        *(u8 **)(o + 0x18) = p;
        *(s16 *)(o + 0x26) = 0x1601;
        o[0x21] = i;
        i++;
    } while (i < 0x10);
}

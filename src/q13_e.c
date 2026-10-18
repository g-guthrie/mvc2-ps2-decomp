typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_0016CF80(void);
extern void func_0016CFE0(void);
extern void func_0016CFB0(void);
extern void func_0016D010(void);
extern void func_0016D040(void);
extern s32 D_004F1CB8;
extern s32 D_004F1CB4;
extern s32 D_004F1CB0;

void func_0016D070(void) {
    if (D_004F1CB8 != 0) {
        switch (D_004F1CB4) {
        case 0: func_0016CF80(); break;
        case 1: func_0016CFE0(); break;
        case 2: func_0016CFB0(); break;
        case 3:
        case 4:
        case 5:
        case 6: func_0016CFE0(); break;
        case 7:
        case 8: func_0016D010(); break;
        case 9: func_0016D040(); break;
        case 10:
        case 11:
        case 12: break;
        }
    } else {
        D_004F1CB0 = 0;
    }
}

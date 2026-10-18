typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void (*D_004C23F8)(void);
void func_00401400(void) {
    if (D_004C23F8 != 0) {
        D_004C23F8();
    }
}

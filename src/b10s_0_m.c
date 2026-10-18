typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 D_00485F80[];
extern void func_00405CC0(u8 *);
void func_00405D38(void) {
    s32 i;
    u8 *p = D_00485F80;
    for (i = 3; i >= 0; i--) {
        if (*(s8 *)p == 1) func_00405CC0(p);
        p += 0x4D8;
    }
}

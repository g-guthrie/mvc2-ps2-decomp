typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_0047C5B0, D_0047C5B4;

void func_003FC028(void) {
    extern s32 func_003FD530(s32);
    extern void func_003FD138(s32);
    extern void func_003FBFD8(void);
    if (D_0047C5B0 != 0 && D_0047C5B4 >= 0) {
        if (func_003FD530(D_0047C5B0) != 1) func_003FD138(D_0047C5B0);
        func_003FBFD8();
    }
}

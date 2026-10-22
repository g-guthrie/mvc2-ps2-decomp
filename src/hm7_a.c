typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;


void func_0041BAD0(void) {
    extern s32 func_00104990(s32);
    s32 s0;
    while (((s0 = func_00104990(2)) | func_00104990(1)) != 0) {
        asm { nop; nop; nop; nop; nop; nop }
    }
}

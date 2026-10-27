typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef float f32;

extern s32 func_003FEAD0(void);
extern s32 func_003FEBD8(void);
void func_00418B10(void) {
    asm { nop; nop; nop; nop; nop; nop; nop }
    func_003FEAD0();
    func_003FEBD8();
}

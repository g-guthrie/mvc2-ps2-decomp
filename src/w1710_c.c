typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004463C0;
extern f32 D_004463C4, D_004463C8, D_004463CC, D_004463D0, D_004463D4, D_004463E0, D_004463E4, D_004463EC;
extern s32 D_004463D8, D_004463DC, D_004463E8, D_004463F0, D_004463F4, D_004463F8, D_004463FC;
extern f32 D_004F7FD0, D_004F7FD4;
void func_0016DF90(void) {
    extern void func_00153AB0();
    D_004463D8 = 0;
    D_004463C0 = 0xD11;
    D_004463DC = 0;
    D_004463C4 = 40.0f;
    D_004463C8 = 394.0f;
    D_004463E8 = 0;
    *(u32 *)&D_004463CC = 0x3F75C28F;
    D_004463E0 = 1.0f;
    D_004463E4 = 0.625f;
    D_004463D4 = 0.625f;
    D_004463D0 = 1.0f;
    D_004463EC = 1.0f;
    D_004463F0 = -1;
    D_004463F4 = 5;
    D_004463F8 = -1;
    D_004463FC = 0;
    D_004463C4 += D_004F7FD0;
    D_004463C8 += D_004F7FD4;
    func_00153AB0(&D_004463C0, 0);
}

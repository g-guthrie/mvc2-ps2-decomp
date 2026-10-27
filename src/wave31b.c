typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004ACC08[];
extern s8 D_004F1F46[];
extern u8 D_004C25C8;
/* Provisional: callback signatures and selector bounds span separate data owners. */
extern void (*D_004BF310[4])(u32) __attribute__((section(".sdata")));

void func_00126080(u32 a) {
    u8 *tbl = D_004ACC08;
    if (a != 0) {
        if (D_004F1F46[0] != 0) {
            D_004C25C8 = 0;
            D_004F1F46[0] = 0;
        }
        tbl += (u8)a - 1;
        D_004BF310[*tbl](a);
    }
}

extern u8 *D_004C2840;
extern s32 D_004C27FC;
extern void func_003DA410(void);
extern void func_001515D0(s32, s32);
extern void func_00146C80(s32);
extern void func_001489E0(s32, s32);
extern void func_0014D7A0(void);
extern void func_00148AA0(s32);
extern void func_003298B0(u32, s32, s32);
extern void func_00129060(s32, void (*)(void));
extern void func_0012D570(void);
void func_0012D4F0(void) {
    D_004C2840[3] = 2;
    D_004C2840[5] = 0;
    func_003DA410();
    func_001515D0(8, D_004C27FC);
    func_00146C80(7);
    func_001489E0(0xD, 0xD);
    func_0014D7A0();
    func_00148AA0(0xD);
    func_003298B0(0xFF000000, 10, 0);
    func_00129060(8, func_0012D570);
}

